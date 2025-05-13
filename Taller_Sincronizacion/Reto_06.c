/**************************************************************
                Pontificia Universidad Javeriana
        Autor: Juan Felipe Rodríguez
        Fecha: Mayo 2025
        Materia: Sistemas Operativos
        Tema: Taller Sincronización
        Fichero: Reto_6
        Descripción: Programa que realiza la multiplicación de un valor dado
        por una constante NUM_LOOPS mediante una suma en ciclo.
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

//Pragma que manda instrucción al compilador
//Define una constante para el num de iteraciones del ciclo for de Function
#define NUM_LOOPS 900000000
//Declara una variable muy grande para almacenar una suma
long long sum = 0;

//Función que se encarga de sumar un valor dado, NUM_LOOPS veces (Equivalente a multiplicar NUM_LOOPS * valor dado)
void function(int valor){
        for(int i=0;i< NUM_LOOPS;i++){
                sum += valor;
        }
}

int main(){

        // Llama a la función para los valores de prueba 1 y -1
        function(1);
        function(-1);

        //Imprime la suma resultante
        printf("Sum = %lld\n", sum);
        return 0;
}




