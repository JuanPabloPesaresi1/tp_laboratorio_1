#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "inputs.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	pArchivo = fopen(path,"r");
	if(pArchivo == NULL)
	{
	   printf("Error al leer el archivo\n");
	}
	else
	{
	    parser_EmployeeFromText(pArchivo,pArrayListEmployee);
	    printf("\n\nDatos cargados con Exito!\n\n");
	}
	fclose(pArchivo);
	return 0;
}
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	if((pArchivo = fopen(path,"r+b")) == NULL)
	{
	  printf("Error, NO se encontro el archivo\n");
	}
	 else
	 {
	    parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
	    printf("\n\nDatos cargados con Exito!\n\n");
	 }
	fclose(pArchivo);
	return 0;
}
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
   Employee* pB;
   int bandera;
   int cantidad;
   char idStr[50];
   char nombreStr[50];
   char horasTrabajadasStr[50];
   char sueldoStr[50];
   bandera = 1;
   while (bandera == 1)
   {
	   cantidad = ll_len(pArrayListEmployee);
       sprintf(idStr,"%d",cantidad);
       printf("\nIngrese el nombre del nuevo empleado: ");
       fflush(stdin);
       getString(nombreStr);
       printf("\nIngrese las horas que va a trabajar el nuevo empleado: ");
       fflush(stdin);
       getString(horasTrabajadasStr);
       printf("\nIngrese el sueldo del nuevo empleado: ");
       fflush(stdin);
       getString(sueldoStr);
       pB = employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
       ll_add(pArrayListEmployee,pB);
       printf("\nSi quiere cargar otro empleado marque 1 sino marque 0: ");
       getInt(&bandera);
       system("cls");
   }
    return 1;
}
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int auxid;
    int resp;
    char auxNombre[51];
    int auxSueldo;
    int auxHoras;
    Employee* puntero;

    controller_ListEmployee(pArrayListEmployee);
    printf ("\nIngrese el ID del empleado que desea modificar: ");
    getInt(&auxid);
    if (pArrayListEmployee != NULL)
    {
        puntero = ll_get(pArrayListEmployee,auxid);
        printf("1-Modificar nombre\n2-Modificar sueldo\n3-Modificar horas trabajadas\nElija una opcion:");
        getInt(&resp);
        switch(resp)
        {
            case 1:
                printf("\nIngrese el nuevo nombre:");
                getString(auxNombre);
                employee_setNombre(puntero,auxNombre);
                printf("\nNombre modificado con exito!\n");
                break;
            case 2:
                printf("\nIngrese el nuevo suelo:");
                getInt(&auxSueldo);
                employee_setSueldo(puntero,auxSueldo);
                printf("\nSueldo modificado con exito!\n");
                break;
            case 3:
                printf("\nIngrese las horas trabajadas:");
                getInt(&auxHoras);
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

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int cant;
	int id;
    Employee* aux;

    controller_ListEmployee(pArrayListEmployee);
    printf ("\nIngrese el ID del empleado a borrar: ");
    getInt(&id);
    if (pArrayListEmployee != NULL)
    {
      cant = ll_len(pArrayListEmployee);
        if (id >0 && id <= cant)
        {
        	aux = ll_get(pArrayListEmployee,id);
            free(aux);
            ll_remove(pArrayListEmployee,id);
            printf ("\nSe dio de baja al empleado con exito!\n\n");
            system("cls");
         }
        else
        {
            printf("\nEl codigo debe estar entre 1 y %d\n\n",cant);
            system("pause");
            system("cls");
        }
    }
    else
    {
        printf("\n\nError a dar de baja al empleado\n\n");
    }
    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* aux;
	int i;
	int lista;

	if(pArrayListEmployee!=NULL)
	{
		lista=ll_len(pArrayListEmployee);

		printf("\n\nID - Nombre - Horas Trabajadas - Sueldo \n");
		for(i=0;i<lista;i++)
		{
		aux = (Employee*) ll_get(pArrayListEmployee,i);
		printf("%d - %s - %d - %d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
		}
	}
    return 0;
}
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    /*int i;
    int j;
    int len;
    Employee* Empleado;
    Employee* EmpleadoSiguiente;
    Employee* aux;

    len = ll_len(pArrayListEmployee);

    for (i=1;i<len;i++)
    {
    	Empleado = ll_get(pArrayListEmployee,i);
        for(j=i+1;j<len;j++)
        {
        	EmpleadoSiguiente = ll_get(pArrayListEmployee,j);

        	if (employee_getSueldo(Empleado) > employee_getSueldo(EmpleadoSiguiente))
            {
                aux = Empleado;
                Empleado = EmpleadoSiguiente;
                EmpleadoSiguiente = aux;
            }
        }
    }*/
    return 1;
}
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

