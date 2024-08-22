#ifndef _funciones_
#define _funciones_

#include <stdio.h>
#include <stdlib.h>

//lee de consola un entero y lo retorna
int obtenerTamanioVarilla();

//Inicializa un arreglo dinamico de un determinado tamanio al cual se le asigna valor en todas sus casillas
void initArreglo(int **arreglo, int tamanio, int valor);

//Solicita confirmacion previo a usar tamanios/precios por defecto
int preguntarValoresPorUsuario();

//Ingresa el precio para cada corte posible entre 1 y tamanio, tamanio 0 siempre vale 0
void ingresarPrecios(int *arreglo, int tam);

//Imprime la solucion basandose en el arreglo devuelto por el algoritmo
void imprimirSolucion(int* solucion, int tam);

//Solucion de fuerza bruta, para corroborar la respuesta, complejidad 2^n
int cortarFuerzaBruta(int* precios, int tam, int nPrecios);

//Confirma si se desea obtener la solucin por la via alternativa
int preguntarFuerzaBruta();

#endif