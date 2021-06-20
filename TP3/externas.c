/*
 * externas.c
 *
 *  Created on: 15 jun. 2021
 *      Author: Juan
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "inputs.h"

int menu(void)
{
	setbuf(stdout, NULL);
	int opcion;
	printf("---------BIENVENIDO---------");
	printf("\nElija la opcion que quiera\n");
	printf("\n1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
	printf("\n2- Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
	printf("\n3- Alta de empleado");
	printf("\n4- Modificar datos de empleado");
	printf("\n5- Baja de empleado");
	printf("\n6- Listar empleados");
	printf("\n7- Ordenar empleados");
	printf("\n8- Guardar los datos de los empleados en el archivo data.csv (modo texto)");
	printf("\n9- Guardar los datos de los empleados en el archivo data.csv (modo binario)");
	printf("\n10-Salir\n");
	printf("\nElija una opcion: ");
	scanf("%d",&opcion);

return opcion;
}

