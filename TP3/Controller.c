#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "inputs.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int bandera = 0;
	FILE* pArchivo;
	pArchivo = fopen(path,"r");
	if(pArchivo == NULL)
	{
	   printf("Error al leer el archivo\n");
	   bandera=0;
	}
	else
	{
	    parser_EmployeeFromText(pArchivo,pArrayListEmployee);
	    printf("\nDatos cargados con Exito!\n\n");
	    bandera=1;
	}
	fclose(pArchivo);
	return bandera;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int bandera =0;
	if((pArchivo = fopen(path,"r+b")) == NULL)
	{
	  printf("Error, NO se encontro el archivo\n");
	  bandera=0;
	}
	 else
	 {
	    parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
	    printf("\nDatos cargados con Exito!\n\n");
	    bandera=1;
	 }
	fclose(pArchivo);
	return bandera;
}
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
   Employee* pB;
   int cantidad;
   char idStr[50];
   char nombreStr[50];
   char horasTrabajadasStr[50];
   char sueldoStr[50];


   cantidad = ll_len(pArrayListEmployee);
   sprintf(idStr,"%d",cantidad);
   GetString("Ingrese el nombre del nuevo empelado: ",nombreStr);
   GetString("Ingrese la cantidad de horas a trabajar del empleado: ",horasTrabajadasStr);
   GetString("Ingrese el sueldo del nuevo empleado: ",sueldoStr);
   pB = employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
   ll_add(pArrayListEmployee,pB);
   system("cls");

    return 1;
}
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int auxid;
    int resp;
    char auxNombre[51];
    int auxSueldo;
    int auxHoras;
    Employee* puntero;

    controller_ListEmployee(pArrayListEmployee);
    auxid=GetInt("\nIngrese el ID del empleado que desea modificar:");
    if (pArrayListEmployee != NULL)
    {
        puntero = ll_get(pArrayListEmployee,auxid);
        resp=GetInt("1-Modificar nombre\n2-Modificar sueldo\n3-Modificar horas trabajadas\nElija una opcion:");
        switch(resp)
        {
            case 1:
                GetString("\nIngrese el nuevo nombre:",auxNombre);
                employee_setNombre(puntero,auxNombre);
                printf("\nNombre modificado con exito!\n");
                break;
            case 2:
                auxSueldo=GetInt("\nIngrese el nuevo suelo:");
                employee_setSueldo(puntero,auxSueldo);
                printf("\nSueldo modificado con exito!\n");
                break;
            case 3:
                auxHoras=GetInt("\nIngrese las horas trabajadas:");
                employee_setHorasTrabajadas(puntero,auxHoras);
                printf("\nHoras Trabajadas modificadas con exito!\n");
                break;
            default:
            	printf("\nError,ingrese una opcion valida\n\n");
            	break;
        }
    }
    return 1;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int lista;
	int id;
    Employee* aux;

    controller_ListEmployee(pArrayListEmployee);
    id=GetInt("\nIngrese el ID del empleado a borrar: ");
    if (pArrayListEmployee != NULL)
    {
    	lista = ll_len(pArrayListEmployee);
        if (id >0 && id <= lista)
        {
        	aux = ll_get(pArrayListEmployee,id);
            free(aux);
            ll_remove(pArrayListEmployee,id);
            printf ("\nSe dio de baja al empleado con exito!\n\n");
         }
        else
        {
            printf("\nEl codigo debe estar entre 1 y %d\n\n",lista);
        }
    }
    else
    {
        printf("\n\nError a dar de baja al empleado\n\n");
    }
    return 1;
}
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* aux;
	int i;
	int lista;
	int bandera = 0;

	if(pArrayListEmployee!=NULL)
	{
		lista=ll_len(pArrayListEmployee);

		printf("\n\nID - Nombre - Horas Trabajadas - Sueldo \n");
		for(i=0;i<lista;i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee,i);
			printf("%d - %s - %d - %d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
			bandera =1;
		}
	}
    return bandera;
}
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	ll_sort(pArrayListEmployee,employee_compareName,1);

    return 1;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	int tamanio;
	Employee* aux;
	FILE* Archivo;

	tamanio=ll_len(pArrayListEmployee);

	Archivo = fopen(path,"w");

	if(Archivo!=NULL)
	{
	    for(i=0;i<tamanio;i++)
	    {
	       aux = ll_get(pArrayListEmployee, i);
	       fprintf(Archivo,"%d,%s,%d,%d\n", aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
	    }
	   printf("Se guardaron los datos con exito!!\n");
	   fclose(Archivo);
	 }

 return 1;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	FILE* Archivo;
	Employee* empleado;
	int tamanio;

	Archivo=fopen(path,"wb");

	if(pArrayListEmployee!=NULL)
	{
	  tamanio= ll_len(pArrayListEmployee);

	    if(Archivo!=NULL)
	    {
	       for(i=0;i<tamanio;i++)
	       {
	         empleado= (Employee*) ll_get(pArrayListEmployee, i);
	          fwrite(empleado,sizeof(Employee), 1, Archivo);
	       }
	       printf("Se han guardado los datos cone exito!\n");
	       fclose(Archivo);
	    }
	 }
return 1;
}

