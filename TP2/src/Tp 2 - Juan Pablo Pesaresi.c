/*
 ============================================================================
 Name        : Tp.c
 Author      : Juan Pablo Pesaresi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "empleados.h"
#define T 1000

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int entrada;
	float resultado;
	float resultadoPromedio;
	int superaPromedio;
	int contador=0;
	eEmpleados listaEmpleados[T];
	InicializarEmpleados(listaEmpleados, T);
	printf("-------------Bienvenido!-------------\n");
	printf("Elija la opcion que desee:\n");
    do
    {
        printf("1.ALTA empleado\n");
        printf("2.MODIFICAR empleado \n");
        printf("3.BAJA empleado\n");
        printf("4.INFORMAR empleado por apellido y sector\n");
        printf("5.PROMEDIO SALARIO Y TOTAL DEL MISMO\n");
        printf("6.SALIR\n");
        opcion=GetInt("\nIngrese una opcion:");

        switch(opcion)
        {
        case 1:
        	CargarEmpleado(listaEmpleados,T);
        	contador++;
        	break;
        case 2:
        	entrada=Entrada(listaEmpleados,T);
        	if(entrada==1)
        	{
        		ListadoDeEmpleados(listaEmpleados, T);
        		EditarEmpleado(listaEmpleados,T);
        	}else
        	{
        		printf("ERROR, debe cargar al menos un empleado para usar esta opcion\n");
        	}
        	break;
        case 3:
        	entrada=Entrada(listaEmpleados,T);
        	if(entrada==1)
        	{
        		ListadoDeEmpleados(listaEmpleados, T);
        		BajaEmpleado(listaEmpleados, T);
        		contador--;
        	}else
        	{
        		printf("ERROR, debe cargar al menos un empleado para usar esta opcion\n");
        	}
        	break;
        case 4:
        	entrada=Entrada(listaEmpleados,T);
        	if(entrada==1)
        	{
        		OrdenarEmpleados(listaEmpleados,T);
        		OrdenarEmpleadosPorSector(listaEmpleados,T);
        		OrdenarEmpleadosPorApellido(listaEmpleados,T);
        	}else
        	{
        		printf("ERROR, debe cargar al menos un empleado para usar esta opcion\n");
        	}
        	break;
        case 5:
        	entrada=Entrada(listaEmpleados,T);
        	if(entrada==1)
        	{
        		resultado=SalarioTotal(listaEmpleados,T);
        		printf("\nLa suma de los salarios es:%.2f\n",resultado);
        		resultadoPromedio=PromedioSalarios(resultado,contador);
        		printf("El promedio de los salarios es:%.2f\n",resultadoPromedio);
        		superaPromedio=PromedioSalarioMax(listaEmpleados,T,resultadoPromedio);
        		printf("La cantidad de empleados que superan el salario promedio son :%d\n\n",superaPromedio);

        	}else
        	{
        		printf("ERROR, debe cargar al menos un empleado para usar esta opcion\n");
        	}

        	break;

        	default:
        				printf("Error.Ingrese una opcion valida.");
        	break;
        }
    }while(opcion!=6);

    return 0;
}
