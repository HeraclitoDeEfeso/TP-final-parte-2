#ifndef CLAVES_H_INCLUDED
#define CLAVES_H_INCLUDED
#include <stdio.h>
#include "cliente.h"

/**
 * typedef Clave: TAD que representa la Clave de un Cliente
 * @posicion: posición del registro Cliente en el archivo (no es clave).
 * @edad: edad del Cliente y clave secundaria.
 * @apellido: apellido del Cliente y clave primaria.
 *
 * Este TAD será utilizado para representar la Clave de un Cliente
 * en el Indice y por consecuencia el tipo de los argumentos para la
 * función comparadora en los métodos del AVL y en las funciones de
 * persistencia y recuperación del Indice.
 */
typedef struct {
    int posicion;
    int edad;
    char apellido[15];
} Clave;

int compararClave(void *clave1, void *clave2);
Clave *recuperarClave(FILE *indice);
int persistirClave(Clave *clave, FILE *indice);

#endif // CLAVES_H_INCLUDED
