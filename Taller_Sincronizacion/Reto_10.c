/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Juan Felipe Rodríguez
        Fecha: Mayo 2025
        Materia: Sistemas Operativos
        Tema: Taller Sincronización
        Fichero: Reto_9
        Descripción: Programa que utiliza semaforos para sincronizar la impresión de 3 mensajes en
        3 hilos distintos en orden
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <semaphore.h>

// Declaración de una variable de semaforo
sem_t mutex;

// Funciones que imprimen un mensaje con semaforos
void *f1(void *arg){

    // -> Espera con el semaforo
    sem_wait(&mutex);
    printf(" porque soy el mejor!!");
    // -> Da la señal
    sem_post(&mutex);
}

void *f2(void *arg){

    // -> Espera con el semaforo
    sem_wait(&mutex);
    printf(" de forma rapida y divertida");
    // -> Da la señal
    sem_post(&mutex);
}

void *f3(void *arg){
    // -> Espera con el semaforo
    sem_wait(&mutex);
    printf("Estoy aprendiendo ");
    // -> Da la señal
    sem_post(&mutex);
}


int main(){

    // Inicialización de 3 hilos pthread
    pthread_t thread01, thread02, thread03;

    // Incializa el semaforo binario
    sem_init(&mutex, 0, 1);
    
    // Crea los hilos, les asigna una función de mensaje en orden y los une con join
    pthread_create(&thread01, NULL, f3, NULL);
    pthread_join(thread01, NULL);

    pthread_create(&thread02, NULL, f2, NULL);
    pthread_join(thread02, NULL);

    pthread_create(&thread03, NULL, f1, NULL);
    pthread_join(thread03, NULL);

    // Destruye el semaforo
    sem_destroy(&mutex);

    return 0;
}
