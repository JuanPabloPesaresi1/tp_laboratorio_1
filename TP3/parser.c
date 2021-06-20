#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int r;
	char idStr[50];
	char nombreStr[50];
	char horasTrabajadasStr[50];
	char sueldoStr[50];
	Employee* p;

	if (pFile == NULL)
	{
	   printf ("Error Archivo no encontrado!!");
	}
	else
	{
	  do{
	      r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
	      if(r==4)
	      {
	    	 //printf("%s--%s--%s--%s\n",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
	         p = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
	         ll_add(pArrayListEmployee,p);
	      }
	      else
	      {
	    	  break;
	      }

	     }while(!feof(pFile));
	  	  retorno=1;
	}
  return retorno;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee * employee;
	int r;

	if(pFile==NULL)
	{
	  printf("Error al leer el archivo solicitado");
	}
	else
	{
	   do{
		   	employee=employee_new();
	        r= fread(employee, sizeof(Employee), 1, pFile);

	        if(r==1)
	        {
	        	ll_add(pArrayListEmployee,employee);
	        }

	      }while(!feof(pFile));

	}

   return 1;
}


