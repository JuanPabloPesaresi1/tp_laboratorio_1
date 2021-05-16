/*
 * empleados.c
 *
 *  Created on: 7 may. 2021
 *      Author: Juan Pablo
 */

#include "empleados.h"

int idIncremental=0;
int ObtenerId()
{
	return idIncremental += 1;
}
int Buscarid(eEmpleados lista[],int tam)
{
	int idIngresada;
	int index=-1;
	int i;

	idIngresada=GetInt("Ingrese el ID que desee:");

	for(i=0;i<tam;i++)
	{
		if(idIngresada == lista[i].id)
		{
			index = i;
			break;
		}
	}
return index;
}
int Entrada(eEmpleados trabajos[],int tam)
{
    int index;
    int i;

    index=-1;

    for(i=0;i<tam;i++)
    {
        if(trabajos[i].isEmpty!=EMPTY)
        {
            index=1;
            break;
        }
    }
    return index;
}
void InicializarEmpleados(eEmpleados parametro[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        parametro[i].isEmpty = EMPTY;
    }
}
int CargarEmpleado(eEmpleados lista[], int tam)
{
    int index;
    index = BuscarLibre(lista, tam);
    if(index==-1)
    {
       printf("No hay mas espacio en la fabrica");

    }else
    {
    	lista[index]=PedirDatosEmpleados();
    }

    return 0;
}
eEmpleados PedirDatosEmpleados()
{
    eEmpleados miEmpleado;

    miEmpleado.id=ObtenerId();
    GetString("Ingrese su nombre: ",miEmpleado.nombre);
    GetString("Ingrese su apellido: ",miEmpleado.apellido);
    miEmpleado.salario=GetFloat("Ingrese un salario:");
    miEmpleado.sector=GetInt("Ingrese el numero del sector:");
    printf("\nEmpleado registrado con exito!!\n\n");

    miEmpleado.isEmpty=OCUPADO;

    return miEmpleado;
}
int BuscarLibre(eEmpleados lista[], int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==EMPTY)
        {
            index = i;
            break;
        }
    }
    return index;
}
void MostrarEmpleado(eEmpleados Empleado)
{
     printf("ID -%d- Nombre -%s- Apellido -%s- Salario -%.2f- Sector-%d \n",
    		 	 	 	 	 	 	 	  Empleado.id,
    		 	 	 	 	 	 	 	  Empleado.nombre,
    		 	 	 	 	 	 	 	  Empleado.apellido,
										  Empleado.salario,
										  Empleado.sector
                                   	   	   	   	   	   	   	   );
}
void ListadoDeEmpleados(eEmpleados lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
        	MostrarEmpleado(lista[i]);
        }

    }
}
void ModificarEmpleado(eEmpleados lista[], int index)
{
	int menu;

	printf("1.MODIFICAR nombre\n");
	printf("2.MODIFICAR apellido \n");
	printf("3.MODIFICAR salario\n");
	printf("4.MODIFICAR sector\n");
	menu=GetInt("Ingrese una opcion:");
	switch(menu)
	{
	case 1:
		GetString("Ingrese el nuevo nombre: ",lista[index].nombre);
		printf("Empleado modificado con exito!\n");
	break;
	case 2:
	   GetString("Ingrese el nuevo apellido: ",lista[index].apellido);
	   printf("Empleado modificado con exito!\n");
	break;
	case 3:
		lista[index].salario=GetFloat("Ingrese el nuevo salario:");
		printf("Empleado modificado con exito!\n");
	break;
	case 4:
		lista[index].sector=GetFloat("Ingrese el nuevo sector:");
		printf("Empleado modificado con exito!\n");
	break;
	}

}
void OrdenarEmpleadosPorApellido(eEmpleados lista[], int tam)
{
    int i;
    int j;

    eEmpleados auxiliarEmpleado;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].apellido, lista[j].apellido)>0)
            {
                auxiliarEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliarEmpleado;
            }
        }
    }
}
int BajaEmpleado(eEmpleados lista[], int tam)
{
	int index;
	index=Buscarid(lista,tam);

	if(index==-1)
	{
		printf("No se encontro el ID ingresado!\n");
	}
	else
	{
			lista[index].isEmpty = EMPTY;
			printf("Se dio de baja al empleado con exito\n");
	}

return 0;
}
void EditarEmpleado(eEmpleados lista[],int tam)
{
	int index;
	index=Buscarid(lista,tam);

	if(index==-1)
	{
		printf("ERROR , no se encontro el id que usted ingreso\n");
	}
	else
	{
		ModificarEmpleado(lista,index);
	}
}
void OrdenarEmpleadosPorSector(eEmpleados lista[],int tam)
{
	 int i;
	 int j;

	 eEmpleados auxiliarEmpleado;

	  for(i=0; i<tam-1; i++)
	   {
	       for(j=i+1; j<tam; j++)
	       {
	           if(lista[i].sector>lista[j].sector)
	           {
	                auxiliarEmpleado = lista[i];
	                lista[i] = lista[j];
	                lista[j] = auxiliarEmpleado;
	           }
	       }
	   }
}
void OrdenarEmpleados(eEmpleados lista[],int tam)
{
	int menu;


	printf("1. Ordenar a los empleados por sector\n");
	printf("2. Ordenar a loas empleados por apellido\n");
	printf("Eliga una opcion:");
	scanf("%d",&menu);

	switch(menu)
	{
	case 1:
		OrdenarEmpleadosPorSector(lista,tam);
		ListadoDeEmpleados(lista,tam);
	break;

	case 2:
		OrdenarEmpleadosPorApellido(lista,tam);
		ListadoDeEmpleados(lista,tam);
	break;
	}
}
float SalarioTotal(eEmpleados lista[],int tam)
{
	int i;
	float suma;
	for(i=0;i<tam;i++)
	{
		if(lista[i].isEmpty == OCUPADO)
		{
			suma+=lista[i].salario;
		}

	}
	return suma;
}
float PromedioSalarios(float sueldos,int empleados)
{
	float promedio;

	promedio =sueldos/empleados;

	return promedio;
}
int PromedioSalarioMax(eEmpleados empleados[],int tam ,float promedio)
{
	int contador;
	int i;

	contador=0;

	for(i=0;i<tam;i++)
	{
		if(empleados[i].isEmpty!=EMPTY)
		{
			if(empleados[i].salario>promedio)
			{
				contador++;
			}
		}

	}
	return contador;
}
