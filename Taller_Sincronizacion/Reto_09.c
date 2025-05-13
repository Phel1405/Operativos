/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Juan Felipe Rodríguez
        Fecha: Mayo 2025
        Materia: Sistemas Operativos
        Tema: Taller Sincronización
        Fichero: Reto_9
        Descripción: Programa que utiliza semaforos para poder sincronizar las operaciones
        de incremento y decremento sobre una variable global y garantizar siempre un resultado 
        de 0.
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <semaphore.h>

// Declaración de una variable global de balance en 0
long balance = 0;

// Declaración de una variable de semaforo
sem_t mutex;

// Función que incrementa el balance en 10000000
void *increment(void *arg){
    sem_wait(&mutex);
    for(long i=0; i < 10000000;i++){
        balance++;
    }
    sem_post(&mutex);
    pthread_exit(NULL);
}

// Función que decrementa el balance en 10000000
void *decrement(void *arg){
    sem_wait(&mutex);
    for(long i=0; i < 10000000;i++){
        balance--;
    }
    sem_post(&mutex);
    pthread_exit(NULL);
}

int main(){

    // Inicialización de 2 hilos pthread
    pthread_t thread01, thread02;

    // Incializa el semaforo binario
    sem_init(&mutex, 0, 1);
    
    // Crea el primer hilo que incrementa el balance
    pthread_create(&thread01, NULL, increment, NULL);

    // Crea el segundo hilo que decrementa el balance
    pthread_create(&thread02, NULL, decrement, NULL);

    // Une ambos hilos con join para sincronizarlos
    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);

    // Imprime el valor del balance
    printf("Valor del balance es: %ld\n", balance);

    // Destruye el semaforo
    sem_destroy(&mutex);

    return 0;
}
