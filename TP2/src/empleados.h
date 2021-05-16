/*
 * empleados.h
 *
 *  Created on: 7 may. 2021
 *      Author: Juan Pablo
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#define EMPTY 0
#define OCUPADO 1

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	float promedio;
	int isEmpty;
}eEmpleados;

int ObtenerId();
int Entrada(eEmpleados[],int );
void InicializarEmpleados(eEmpleados [],int );
void IdAutoIncremental(eEmpleados[],int);
int CargarEmpleado(eEmpleados [],int );
eEmpleados PedirDatosEmpleados();
int BuscarLibre(eEmpleados [],int );
void ListadoDeEmpleados(eEmpleados [],int );
void MostrarEmpleado(eEmpleados Empleado);
void ModificarEmpleado(eEmpleados [],int );
void OrdenarEmpleadosPorApellido(eEmpleados [],int);
void OrdenarEmpleadosPorSector(eEmpleados[],int);
void OrdenarEmpleados(eEmpleados[],int);
int BajaEmpleado(eEmpleados [],int);
int Buscarid(eEmpleados [],int);
void EditarEmpleado(eEmpleados[],int);
float SalarioTotal(eEmpleados[],int);
float PromedioSalarios(float,int);
int PromedioSalarioMax(eEmpleados[],int,float);
#endif /* EMPLEADOS_H_ */
