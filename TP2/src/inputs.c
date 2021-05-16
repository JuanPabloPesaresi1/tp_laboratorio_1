/*
 * inputs.c
 *
 *  Created on: 7 may. 2021
 *      Author: Juan
 */

#include "inputs.h"


int GetInt(char *msj)
{
    int value;

    printf(msj);
    scanf("%d", &value);

    return value;
}

float GetFloat(char *msj)
{
    float value;

    printf(msj);
    scanf("%f", &value);

    return value;
}

void GetString(char *msj, char value[])
{
    printf(msj);
    fflush(stdin);
    scanf("%[^\n]", value);
}

char GetChar(char *msj)
{
    char value;

    printf(msj);
    fflush(stdin);
    scanf("%c", &value);

    return value;
}
