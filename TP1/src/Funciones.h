/*
 * Funciones.h
 *
 *  Created on: 11 abr. 2021
 *      Author: Juan
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/**
 * @fn float Sumar(float, float)
 * @brief Realiza la suma de los operandos ingresados
 *
 * @param numero1 primer float a sumar
 * @param numero2 segundo float a sumar
 * @return float resultado
 */
float Sumar(float numero1,float numero2);

/**
 * @fn float Restar(float, float)
 * @brief Realiza la resta de los operandos ingresados
 *
 * @param numero1 primer float a restar
 * @param numero2 segundo float a restar
 * @return float resultado
 */
float Restar(float numero1,float numero2);

/**
 * @fn float Multiplicacion(float, float)
 * @brief Realiza la multiplicacion de los operandos ingresados
 *
 * @param numero1 primer float ingresado a multiplicacar
 * @param numero2 segundo float ingresado a multiplicar
 * @return float resultado
 */
float Multiplicacion(float numero1,float numero2);

/**
 * @fn float Division(float, float)
 * @brief Realiza la division de los operandos ingresados
 *
 * @param numero1 primer float ingresado a dividir
 * @param numero2 segundo float ingresado a dividir
 * @return float resultado
 */
float Division(float numero1,float numero2);

/**
 * @fn int Factorial(float)
 * @brief Realiza el factorial de los operando ingresados
 *
 * @param numero se calcula el factorial de los operandos
 * @return int resultado
 */
int Factorial(float numero);

/**
 * @fn float PedirOperando(float)
 * @brief Almencena el valor de numero1 y numero2
 *
 * @param numero se calcula el valor de los operandos
 * @return float resultado
 */
float PedirOperando(float numero);

#endif /* FUNCIONES_H_ */
