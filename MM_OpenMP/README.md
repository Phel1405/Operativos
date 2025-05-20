# Multiplicación de Matrices en C con OpenMP

Este proyecto implementa el algoritmo **clásico de multiplicación de matrices (filas por columnas)** en lenguaje C, utilizando paralelismo mediante **OpenMP** para mejorar el rendimiento.

## Objetivo

Explorar el uso de OpenMP para paralelizar la multiplicación de matrices cuadradas, evaluando tanto la correcta implementación como el impacto en el rendimiento frente a una versión secuencial.

## Estructura del Proyecto

- `MMclasicoOpenMP.c`: Contiene el `main`, manejo de argumentos, inicialización y control del experimento.
- `MMOpenMP.c`: Funciones auxiliares para inicializar matrices, imprimir resultados, realizar la multiplicación y medir el tiempo de ejecución.
- `MMOpenMP.h`: Archivo de cabecera con las declaraciones de las funciones usadas.

## Cómo Compilar

Requiere GCC con soporte para OpenMP:

```bash
gcc -fopenmp MMclasicoOpenMP.c MMOpenMP.c -o clasicaOpenMP
```

## Requisitos

- Sistema operativo basado en Unix (Linux o macOS).

- GCC con soporte para OpenMP (-fopenmp).

- Memoria suficiente para alojar matrices grandes (uso de calloc).
