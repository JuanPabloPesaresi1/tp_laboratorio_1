#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int r;
	int i=0;
	char idStr[50];
	char nombreStr[50];
	char horasTrabajadasStr[50];
	char sueldoStr[50];
	Employee* p;

	if (pFile == NULL)
	{
	   printf ("Error al leer el archivo");
	}
	else
	{
	  do{
	      r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
	      if(r==4)
	      {
	         p = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
	         i++;
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
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int r;
	int i;
	char idStr[50];
	char nombreStr[50];
	char horasTrabajadasStr[50];
	char sueldoStr[50];
	Employee* pBinario;

	if (pFile == NULL)
	    {
	        printf ("Error al leer el archivo");
	    }
	    else{
	        do{
	            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
	            if(r==4)
	            {
	               pBinario = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
	                i++;
	                ll_add(pArrayListEmployee,pBinario);
	            }
	            else
	            {
	            	break;
	            }

	        }while(!feof(pFile));
	    }
	return 1;
}
