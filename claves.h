#ifndef CLAVES_H_INCLUDED
#define CLAVES_H_INCLUDED
#include <stdio.h>
#include "cliente.h"
#include "indice.h"

/**
 * typedef ClaveNombreDNI: representa la Clave Nombre más DNI de un Cliente
 * @posicion: posición del registro Cliente en el archivo (no es clave).
 * @dni: DNI del Cliente y clave secundaria.
 * @nombre: nombre del Cliente y clave primaria.
 *
 * Este TAD será utilizado para representar la Clave de un Cliente
 * en el Indice y por consecuencia el tipo de los argumentos para la
 * función comparadora en los métodos del AVL y en las funciones de
 * persistencia y recuperación del Indice.
 */
typedef struct {
    int posicion;
    int dni;
    char nombre[15];
} ClaveNombreDNI;

/**
 * typedef ClaveEdadDNI: representa la Clave Edad más DNI de un Cliente
 * @posicion: posición del registro Cliente en el archivo (no es clave).
 * @dni: DNI del Cliente y clave secundaria.
 * @nombre: nombre del Cliente y clave primaria.
 *
 * Este TAD será utilizado para representar la Clave de un Cliente
 * en el Indice y por consecuencia el tipo de los argumentos para la
 * función comparadora en los métodos del AVL y en las funciones de
 * persistencia y recuperación del Indice.
 */
typedef struct {
    int posicion;
    int dni;
    int edad;
} ClaveEdadDNI;


typedef int (*Accesor) (void *clave);
typedef void (*Formulario) (void **clave);

int compararClaveNombreDNI(void *clave1, void *clave2);
int recuperarClaveNombreDNI(void **clave, FILE *archivo);
int persistirClaveNombreDNI(void *clave, FILE *indice);
void *crearClaveNombreDNI(Cliente *cliente, long posicionArchivo);
void formularioClaveNombreDNI(void **clave);
int obtenerPosicionClaveNombreDNI(void *clave);

int compararClaveEdadDNI(void *clave1, void *clave2);
int recuperarClaveEdadDNI(void **clave, FILE *archivo);
int persistirClaveEdadDNI(void *clave, FILE *indice);
void *crearClaveEdadDNI(Cliente *cliente, long posicionArchivo);
void formularioClaveEdadDNI(void **clave);
int obtenerPosicionClaveEdadDNI(void *clave);

#endif // CLAVES_H_INCLUDED
