#ifndef CLAVES_H_INCLUDED
#define CLAVES_H_INCLUDED
#include <stdio.h>
#include "cliente.h"

/**
 * typedef Clave: TAD que representa la Clave de un Cliente
 * @posicion: posici�n del registro Cliente en el archivo (no es clave).
 * @edad: edad del Cliente y clave secundaria.
 * @apellido: apellido del Cliente y clave primaria.
 *
 * Este TAD ser� utilizado para representar la Clave de un Cliente
 * en el Indice y por consecuencia el tipo de los argumentos para la
 * funci�n comparadora en los m�todos del AVL y en las funciones de
 * persistencia y recuperaci�n del Indice.
 */
typedef struct {
    long posicion;
    int dni;
    char nombre[15];
} Clave;

int compararClave(void *clave1, void *clave2);
int recuperarClave (void **clave, FILE *archivo);
int persistirClave(void *clave, FILE *indice);
Clave *crearClave(Cliente *cliente, long posicionArchivo);
Clave *formularioClave();

#endif // CLAVES_H_INCLUDED
