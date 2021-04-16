/*
 ============================================================================
 Name        : Calculadora.c
 Author      :Juan Pablo Pesaresi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void)
{
	setbuf(stdout, NULL);
	float numero1=0;
	float numero2=0;
	int loop=0;
	int menuDeOperaciones;
	float resultadoDeLaSuma;
	float resultadoDeLaResta;
	float resultadoDeLaMultiplicacion;
	float resultadoDeLaDivision;
	float factorialA;
	float factorialB;

	printf("******************CALCULADORA**********************");
	while(loop==0)
	{
		printf("\n1.Ingrese el valor del operando (A=X)\n");
		printf("2.Ingrese el valor del operando (B=Y)\n");
		printf("3.Calcular todas las operaciones\n");
		printf("4.Mostar resultados\n");
		printf("5. Salir\n\n");
		printf("Elija una opcion:");
		scanf("%d",&menuDeOperaciones);
		switch(menuDeOperaciones)
		{
		 	case 1:
		 	 	numero1= PedirOperando(numero1);
		 	 	printf("*************************************");
		 	 	printf("\nEl valor del primer operando es A= %.2f",numero1);
		 	 	printf("\n*************************************");
		    break;

		 	case 2:
		 		numero2= PedirOperando(numero2);
		 		printf("*************************************");
		 		printf("\nEl valor del segundo operando es B= %.2f",numero2);
		 		printf("\n*************************************");
		  	break;

		 	case 3:
		 		if(numero1==0 && numero2==0)
		 		{
		 			printf("Error, no ingreso valor a los operando, porfavor empiece con la opcion 1");
		 		}
		 		if(numero2 == 0)
		 		{
		 			printf("\nError,no se puede dividir por 0, porfavor reingrese valores validos\n");
		 		}else

		 		{
		 			printf("\nCalculando las operaciones...");
		 			printf("\nIngrese 4 para ver los resultados\n");

		 			resultadoDeLaSuma = Sumar(numero1,numero2);
		 			resultadoDeLaResta= Restar(numero1,numero2);
		 			resultadoDeLaMultiplicacion= Multiplicacion(numero1,numero2);
		 		    resultadoDeLaDivision= Division(numero1,numero2);
		 		    factorialA= Factorial(numero1);
		 			factorialB= Factorial(numero2);
		 			break;
		 		}
		 		break;

		 	case 4:
		 		if(numero1 == 0 && numero2 == 0)
		 		{
		 			printf("Error no ingreso valores a los operando, porfavor elija la opcion 1 y 2");
		 			break;
		 		}else
		 		{
		 			printf("\nEl resultado de la suma es= %.2f",resultadoDeLaSuma);
		 			printf("\nEl resultado de la resta es= %.2f",resultadoDeLaResta);
		 			printf("\nEl resultado de la multiplicacion es= %.2f",resultadoDeLaMultiplicacion);
		 			printf("\nEl resultado de la division es= %.2f",resultadoDeLaDivision);
		 			printf("\nEl factorial de (A=X) es =%.2f\n",factorialA);
		 			printf("El factorial de (B=Y) es =%.2f\n",factorialB);
		 			break;
		 		}

		 	case 5:
		 		printf("\nGracias por usar mi calculadora, vuelva pronto!\n");
		 	    loop=1;
		 	    break;

		 	default:
		 		printf("\nError, empiece ingresando el 1 hasta el 5 \n");
		 	  	break;
		}
	}
return 0;
}
