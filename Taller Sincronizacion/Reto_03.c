/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Juan Felipe Rodríguez
        Fecha: Abril 2025
        Materia: Sistemas Operativos
        Tema: Taller Sincronización
        Fichero: Reto_3
        Descripción: Simula un problema de sincronización entre hilos que aumentan
                una variable global (count) bajo ciertas condiciones usando mutex y variables
                condición para evitar condiciones de carrera
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//Inicialización de los mutex y las variables de condición
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

//Crea un contador global
int count = 0;

//Define unas variables globales
#define COUNT_DONE 15
#define COUNT_HALT1 4
#define COUNT_HALT2 11

//Función
void *count01(){

        //Bucle infinito
        for(;;){

                pthread_mutex_lock(&condition_mutex);
                
                //Mientras el contador sea mayor a HALT1 y menos a HALT2 espera
                while(count >= COUNT_HALT1 && count <= COUNT_HALT2){
                        pthread_cond_wait(&condition_cond, &condition_mutex);
                }
                pthread_mutex_unlock(&condition_mutex);

                pthread_mutex_lock(&count_mutex);

                //Aumenta el contador
                count++;
                printf("Valor contador functionCount ==> 01 <==: %d\n", count);
                pthread_mutex_unlock(&count_mutex);

                //Si el contador llega al COUNT_DONE se acaba la función
                if(count >= COUNT_DONE) return NULL;
        }
}

//Función
void *count02(){

        //Bucle infinito
        for(;;){
                pthread_mutex_lock(&condition_mutex);

                //El contador aumenta solo si se encuentra entre HALT1 y HALT2
                if(count < COUNT_HALT1 || count > COUNT_HALT2){
                        pthread_cond_signal(&condition_cond);
                }

                pthread_mutex_unlock(&condition_mutex);

                pthread_mutex_lock(&count_mutex);
                count++;
                printf("Valor contador funcionCount ==> 02 <==: %d\n", count);
                pthread_mutex_unlock(&count_mutex);

                //Si el contador llega al COUNT_DONE se acaba la función
                if(count >= COUNT_DONE) return(NULL);

        }
}

void main(){

        //Inicializa dos hilos
        pthread_t thread1, thread2;

        //Crea ambos hilos con el pthread_create
        pthread_create(&thread1, NULL, &count01, NULL);
        pthread_create(&thread2, NULL, &count02, NULL);

        //Une ambos hilos con join
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);

        exit(0);
}

