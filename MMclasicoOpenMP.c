/*#######################################################################################
 #* Fecha: 20 sep 2025
 #* Autor: J.Corredor
 #* Documentado por: Felipe Rodriguez Amador
 #* Tema: Programación Modular en C
 #* 	- Programa Multiplicación de Matrices algoritmo clásico
 #* 	- Paralelismo con OpenMP
 #* Conclusiones:
	- Para el caso de multiplicación de matrices utilizando el algoritmo clásico
	de filas por columnas la implementación de OpenMP resulto ser sencilla ya que
	solo se utilizo una directiva de parallel for
	- Es importante a la hora de hacer la directiva de paralelismo privatizar las variables
	correctas para evitar condiciones de carrera y garantizar que el resultado de la multiplicación
	sea el correcto.
	- Una vez validado que no hay condiciones de carrera debido al paralelismo se confirma que los
	resultados de la multiplicación son correctos validando por una entidad externa que no tiene ningun
	sesgo como es WolframAlpha en su parte de matrices.
	- OpenMP demuestra una flexibilidad a la hora de usar el paralelismo ya que el usuario puede
	escoger la cantidad de hilos usados.
	- OpenMP demuestra ser una herramienta muy útil en el caso de multiplicación de matrices ya que
	mejora el rendimiento de ejecución comparado con hacerlo en serie aprovechando mejor los recursos
	de hardware del equipo. Además de ser más fácil la implementación en comparación a otros sabores como
	Posix o Fork.
######################################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>
#include "MMOpenMP.h"

int main(int argc, char *argv[]){

	// Revisa que la cantidad de argumentos sea la correcta
	if(argc < 3){
		printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
		exit(0);
	}

	//Primero guarda el tamaño de la matriz en una variable N
	int N = (int) atoi(argv[1]);

	// Guarda el numero de hilos digitado por el usuario en una variable TH
	int TH = (int) atoi(argv[2]);

	// Se inicializan las matrices A, B y C alojando la memoria para cada una con la función calloc
	size_t *matrixA  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixB  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixC  = (size_t *)calloc(N*N, sizeof(size_t));
	
	// Verifica si hubo algún error al asignar memoria a las matrices
	if (!matrixA || !matrixB || !matrixC) {
		fprintf(stderr, "Error: No se pudo asignar memoria. Reduce el tamaño de la matriz (N=%d).\n", N);
		free(matrixA); free(matrixB); free(matrixC);
		return EXIT_FAILURE;
	}

	// Se usa la función rand para el llenado de datos
	srand(time(NULL));

	// Se define el numero de hilos que va a ser utilizado para el paralelismo
	omp_set_num_threads(TH);

	//Inicializa las matrices con el respectivo tamaño digitado por el usuario
	iniMatrix(matrixA, matrixB, N);

	// Imprime las matrices creadas para la multiplicación
	impMatrix(matrixA, N);
	impMatrix(matrixB, N);

	//Se hace la instancia del experimento para la multiplicación de matrices
	InicioMuestra();
	multiMatrix(matrixA, matrixB, matrixC, N);
	FinMuestra();

	//Imprime la matriz de resultado C
	impMatrix(matrixC, N);

	/*Libera la memoria de las matrices utilizadas*/
	free(matrixA);
	free(matrixB);
	free(matrixC);
	
	return 0;
}

