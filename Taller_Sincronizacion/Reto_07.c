/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Juan Felipe Rodríguez
        Fecha: Mayo 2025
        Materia: Sistemas Operativos
        Tema: Taller Sincronización
        Fichero: Reto_7
        Descripción: Programa que simula el uso de semaforos mediante la función sleep, para garantizar
	la sincronización (Es importante tener en cuenta que el tiempo de espera entre creación de 
	hilos debe ser mayor al de la función para garantizar que se ejecuta completa
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

/* Función que imprime un mensaje de entrada y uno de salida, utilizando un tiempo de espera entre ambos */
void *operation(void *arg){
        
    // -> Espera
    printf("\nEntro a la carrera...\n");

    // Sección critica
    sleep(2);

    // -> Señal
    printf("\n Justo salgo de la carrera...\n");
}

int main(){

    // Inicialización de 2 hilos pthread
    pthread_t thread01, thread02;

    // Crea el primer hilo que hace operation
    pthread_create(&thread01, NULL, operation, NULL);

    // Espera a que termine el primer hilo
    sleep(3);

    // Crea el segundo hilo que hace operation
    pthread_create(&thread02, NULL, operation, NULL);

    // Espera a que termine el segundo hilo
    sleep(3);

    return 0;
}
