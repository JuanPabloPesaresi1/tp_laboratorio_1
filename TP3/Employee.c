#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


Employee* employee_new()
{
    Employee* empleado = malloc(sizeof(Employee));
    return empleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	int bandera=0;
	Employee* auxEmployee = NULL;
	auxEmployee = employee_new();
	if(auxEmployee != NULL)
	{
	 if(!employee_setNombre(auxEmployee,nombreStr))
	 {
	  if(!employee_setHorasTrabajadas(auxEmployee,atoi(horasTrabajadasStr)))
	  {
	   if(!employee_setSueldo(auxEmployee,atoi(sueldoStr)))
	   {
		if (!employee_setId(auxEmployee,atoi(idStr)))
		{
		   bandera=1;
		}
	   }
	  }
	 }
	}
	if(bandera==0)
	{
		employee_delete(auxEmployee);
		auxEmployee = NULL;
	}

	return auxEmployee;

}
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/*********FUNCIONES SET*********/

int employee_setId(Employee* this, int id)
{
	int bandera = 0;
	if(id > 0)
	{
		this->id = id;
		bandera =1;
	}

	return bandera;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int bandera = 0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		bandera = 1;
	}
	return bandera;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int bandera =0;
	if(horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		bandera=1;
	}
	return bandera;
}
int employee_setSueldo(Employee* this, int sueldo)
{
	int bandera=0;
    if(sueldo > 0)
    {
    	this->sueldo = sueldo;
    	bandera=1;
    }

    return bandera;
}

/*********FUNCIONES GET**********/
int employee_getId(Employee* this,int* id)
{
	int bandera = 0;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		bandera = 1;
	}
	return bandera;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int bandera = 0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		bandera = 1;
	}
	return bandera;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int bandera = 0;
	if(this!=NULL && horasTrabajadas>=0)
	{
		*horasTrabajadas = this->horasTrabajadas;
		bandera = 1;
	}
	return bandera;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int bandera = 0;
	if(this!=NULL && sueldo>=0)
	{
		*sueldo = this->sueldo;
		bandera = 1;
	}
	return bandera;
}

