/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Juan Felipe Rodríguez
        Fecha: Abril 2025
        Materia: Sistemas Operativos
        Tema: Taller Sincronización
        Fichero: Reto_4
        Descripción: Crea un arreglo de 3 hilos, cada uno corresponde a un trabajo que cuenta de
	0 hasta un número muy grande. Cuando termina se acaba y por medio de mutex se hace en orden
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>

//Inicializa el arreglo de hilos, el contador y el mutex
pthread_t tid[3];
int counter = 0;
pthread_mutex_t lock;

//Función que cuenta de 0 a un número muy grande
void* compute(void *arg){
        unsigned long i=0;
	
	//Usa el mutex para que se realicen en orden
	pthread_mutex_lock(&lock);
        counter++;
        printf("\n Job %d ha empezado\n", counter);

	//Cuenta de 0 a un número muy grande (Se usa como un wait)
	for(i=0; i<(0xFFFFFFFF);i++);
        printf("\n Job %d ha terminado\n", counter); 
	pthread_mutex_unlock(&lock); 

        return NULL;
}

int main(void){
        int i = 0;
        int error;

	//Crea los 3 hilos uno por uno usando la función de compute
        while (i < 3){
                error = pthread_create(&(tid[i]), NULL, &compute, NULL);
		
		//En caso de haber error, returna un mensaje de error
                if(error != 0){
                        printf("\nThread no pudo ser creado: [%s]", strerror(error));
                }
                i++;
        }
	
	//Une los 3 hilos
        pthread_join(tid[0], NULL);
        pthread_join(tid[1], NULL);
        pthread_join(tid[2], NULL);

        return 0;
}



