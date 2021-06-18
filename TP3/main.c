#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"
#include "externas.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int opciones = 0;
    int bandera=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    opciones=menu();

    do{
        switch(opciones)
        {
            case 1:
            	system("cls");
            	if(bandera== 1)
            	{
            		printf("\nSolo se puede cargar a los empleados 1 sola vez\n\n");
            	}
            	else
            	{
            		controller_loadFromText("data.csv",listaEmpleados);
            	}
                bandera=1;
                break;
            case 2:
            	system("cls");
            	if(bandera== 1)
            	{
            		printf("\nSolo se puede cargar a los empleados 1 sola vez\n\n");
            	}
            	else
            	{
            		controller_loadFromBinary("data.bin",listaEmpleados);
            	}
            	bandera=1;
            	break;
            case 3:
            	if(bandera==1)
            	{
            		system("cls");
            		controller_addEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\nError, Ingrese la opcion 1 o 2 antes de usar esta funcion\n\n");
            	}
            	break;
            case 4:
            	if(bandera==1)
            	{
            		system("cls");
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            	  printf("\nError, Ingrese la opcion 1 o 2 antes de usar esta funcion\n\n");
            	}
            break;
            case 5:
            	if(bandera==1)
            	{
            		system("cls");
            		controller_removeEmployee(listaEmpleados);
            	}
            	else
            	{
            	  printf("\nError, Ingrese la opcion 1 o 2 antes de usar esta funcion\n\n");
            	}
            	break;
            case 6:
            	if(bandera==1)
            	{
            		system("cls");
            		controller_ListEmployee(listaEmpleados);
            		system("pause");
            		system("cls");
            	}
            	else
            	{
            	  printf("\nError, Ingrese la opcion 1 o 2 antes de usar esta funcion\n\n");
            	}
            	break;
            case 7:
            	system("cls");
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
                 system("cls");
                 controller_saveAsText("data.csv", listaEmpleados);
                 break;
            case 9:
                 system("cls");
                 controller_saveAsBinary("bin.dat",listaEmpleados);
                 break;
        }
        opciones=menu();
    }while(opciones != 10);
    return 0;
}
