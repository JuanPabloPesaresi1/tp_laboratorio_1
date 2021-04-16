/*
 * Funciones.c
 *
 *  Created on: 11 abr. 2021
 *      Author: Juan
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

float PedirOperando(float numero)
{

	printf("Ingrese un valor al operando=");
	scanf("%f",&numero);

	return numero;
}

float Sumar(float numero1,float numero2)
{
	float resultado;

	resultado=	numero1		+	numero2;

	return resultado;
}

float Restar(float numero1,float numero2)
{
	float resultado;

	resultado= numero1 - numero2;

	return resultado;
}

float Multiplicacion(float numero1,float numero2)
{
	float resultado;

	resultado= numero1 * numero2;

	return resultado;
}

float Division(float numero1,float numero2)
{
	float resultado;
	if(numero2 == 0)
	{
		printf("\nError,no se puede dividir por 0, porfavor reingrese valores validos");
	}else
	{
		resultado= numero1 / numero2;
	}

	return resultado;
}

int Factorial(float numero)
{
	int factorial;
	int i;

	factorial=1;

	for(i=numero;i>1;i--)
	    {
	        factorial*= i;

	    }

	return factorial;
}
