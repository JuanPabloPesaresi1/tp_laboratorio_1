/*
 * inputs.c
 *
 *  Created on: 10 jun. 2021
 *      Author: Juan
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

void getInt(int* puntero)
{
    int numero;
    scanf("%d",&numero);
    *puntero = numero;
}

void getFloat(float* puntero)
{
    float numero;
    scanf ("%f",&numero);
    *puntero = numero;
}

void getChar(char* mensaje)
{
    char letra;
    fflush(stdin);
    scanf("%c",&letra);
    *mensaje = letra;

}

int getString(char* input)
{
scanf("%s",input);
return 0;
}
