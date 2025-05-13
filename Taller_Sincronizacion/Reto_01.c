/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Juan Felipe Rodríguez
        Fecha: Abril 2025
        Materia: Sistemas Operativos
        Tema: Taller Sincronización
        Fichero: Reto_1
        Descripción: Crea 2 hilos con pthread a los que le asigna una función de imprimir mensaje.
		Imprime el resultado de la creación de los hilos
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


//Función para imprimir un mensaje dado su apuntador
void *print_message_function(void *ptr){
	char *message;
	message = (char *)ptr;
	printf("%s \n", message);
}

void main(){

	//Instanciación de los hilos
	pthread_t thread1, thread2;

	//Creación de los mensajes
	char *message1 = "Thread 1";
	char *message2 = "Thread 2";
	int iret1, iret2;

	//Creación de los hilos con pthread_create
	iret1 = pthread_create(&thread1, NULL, print_message_function, (void*) message1);
	iret2 = pthread_create(&thread2, NULL, print_message_function, (void*) message2);
	
	//Resultado de la creación de los hilos, 0 si se crearon correctamente, 1 si no se pudieron crear
	printf("Thread 1 retuns: %d\n", iret1);
	printf("Thread 2 returns: %d\n", iret2);
	exit(0);
}
