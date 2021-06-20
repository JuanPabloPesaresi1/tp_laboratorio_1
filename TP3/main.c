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
    int text;
    LinkedList* listaEmpleados = ll_newLinkedList();
    opciones=menu();

    do{
        switch(opciones)
        {
            case 1:
            	if(bandera==0)
            	{
            		text=controller_loadFromText("data.csv",listaEmpleados);

            		if(text!=0)
            		{
            			bandera++;
            		}
            	}
            	else
            	{
            		printf("\nSolo se puede cargar a los empleados 1 sola vez\n\n");
            	}
                break;
            case 2:
            	if(bandera== 0)
            	{
            		text=controller_loadFromBinary("data.bin",listaEmpleados);

            		if(text!=0)
            		{
            			bandera++;
            		}
            	}
            	else
            	{
            		printf("\nSolo se puede cargar a los empleados 1 sola vez\n\n");
            	}
            	break;
            case 3:
            	if(bandera==1)
            	{
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
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            	  printf("\nError, Ingrese la opcion 1 o 2 antes de usar esta funcion\n\n");
            	}
            	break;
            case 7:
            	if(bandera==1)
            	{
            		printf("Ordenando empleados, porfavor espere unos segundos");
            		controller_sortEmployee(listaEmpleados);
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("\nError, Ingrese la opcion 1 o 2 antes de usar esta funcion\n\n");
            	}
            	break;
            case 8:
            	if(bandera==1)
            	{
            		controller_saveAsText("data.csv", listaEmpleados);
            	}
            	else
            	{
            		printf("\nError, Ingrese la opcion 1 o 2 antes de usar esta funcion\n\n");
            	}
                 break;
            case 9:
            	if(bandera==1)
            	{
            		controller_saveAsBinary("data.bin",listaEmpleados);
            	}
            	else
            	{
            		printf("\nError, Ingrese la opcion 1 o 2 antes de usar esta funcion\n\n");
            	}
                break;
        }
        opciones=menu();
    }while(opciones != 10);
    return 0;
}
