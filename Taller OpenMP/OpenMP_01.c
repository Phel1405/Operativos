/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Juan Felipe Rodríguez Amador
        Fecha: 13 Mayo 2025
        Materia: Sistemas Operativos
        Tema: OpenMP
        Fichero: Hello world
        Descripción: 
****************************************************************/z

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("OpenMP ejecutando con %d hilos\n", omp_get_max_threads());
    #pragma omp parallel
    {
        prtinf("Hello World desde el thread %d\n", omp_get_thread_num());
    }
    return 0;
}