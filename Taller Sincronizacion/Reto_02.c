/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Juan Felipe Rodríguez
        Fecha: Abril 2025
        Materia: Sistemas Operativos
        Tema: Taller Sincronización
        Fichero: Reto_2
        Descripción: Crea un arreglo de hilos y por la creación de cada uno aumenta un contador una sola
                vez con el uso de Mutex.
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//Define una variable global que define un máximo de hilos a crear
#define NTHREADS 10

//Inicializa una variable mutex
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

//Crea una variable de contador global
int counter = 0;

//Función que imprime la identificación de un hilo
void *thread_function(void *arg){

        int i = *(int *)(arg);

        //Imprime la información del hilo
        printf("Thread number: %d | Thread ID %ld\n", i, pthread_self());
        
        //Garantiza que aumente una sola vez por hilo
        pthread_mutex_lock(&mutex1);
        counter++;
        pthread_mutex_unlock(&mutex1);
}

void main(){

        //Inicializa un arreglo de hilos de tamaño NTHREADS
        pthread_t thread_id[NTHREADS];

        //Crea NTHREADS-1 hilos
        for(int i = 0; i < NTHREADS; i++){
                pthread_create(&thread_id[i], NULL, thread_function, &i);
        }

        for(int j = 0; j < NTHREADS; j++){
                pthread_join(thread_id[j], NULL);
        }

        //Imprime el valor final del contador
        printf("Final counter value: %d\n", counter);
}



