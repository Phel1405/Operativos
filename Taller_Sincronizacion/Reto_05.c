/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Juan Felipe Rodríguez
        Fecha: Abril 2025
        Materia: Sistemas Operativos
        Tema: Taller Sincronización
        Fichero: Reto_5
        Descripción: 
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

pthread_mutex_t lock;

//Funciones para imprimir un mensaje

void *f1(void *arg){
        pthread_mutex_lock(&lock);
        printf("porque soy el mejor!!");
        pthread_mutex_unlock(&lock);
}

void *f2(void *arg){
        pthread_mutex_lock(&lock);
        printf("de forma rápida y divertida ");
        pthread_mutex_unlock(&lock);
}

void *f3(void *arg){
        pthread_mutex_lock(&lock);
        printf("Estoy aprendiendo ");
        pthread_mutex_unlock(&lock);
}

int main(){

        // Inicializa 3 hilos
        pthread_t thread01, thread02, thread03;

        // Crea los 3 hilos usando las funciones que imprimen un mensaje
        pthread_create(&thread01, NULL, f3, NULL);
        pthread_join(thread01, NULL);
        pthread_create(&thread02, NULL, f2, NULL);
        pthread_join(thread02, NULL);
        pthread_create(&thread03, NULL, f1, NULL);
        pthread_join(thread03, NULL);

        // Une los hilos 
        /*
        pthread_join(thread01, NULL);
        pthread_join(thread02, NULL);
        pthread_join(thread03, NULL); */

        printf("\n");
        return 0;
}




