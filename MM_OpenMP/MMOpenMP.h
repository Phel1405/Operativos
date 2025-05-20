
#ifndef _MMOPENMP_H_
#define _MMOPENMP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>

//Inicio de la muestra para la experimentación
void InicioMuestra();
void FinMuestra();

// Función de impresión de una matriz
void impMatrix(size_t *matrix, int D);

// Función que inicializa una matriz
void iniMatrix(size_t *m1, size_t *m2, int D);

// Función que multiplica dos matrices dadas A,B y guarda el resultado en la matriz C
void multiMatrix(size_t *mA, size_t *mB, size_t *mC, int D);

#endif
