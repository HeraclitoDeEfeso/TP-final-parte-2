#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "claves.h"

int compararClaveNombreDNI(void *clave1, void *clave2)
{
    ClaveNombreDNI *c1 = (ClaveNombreDNI*) clave1;
    ClaveNombreDNI *c2 = (ClaveNombreDNI*) clave2;
    int comparacion = strcmp(c1->nombre, c2->nombre);
    return (comparacion == 0)? c1->dni - c2->dni : comparacion;
}

int recuperarClaveNombreDNI(void **clave, FILE *archivo)
{
    *clave = malloc(sizeof(ClaveNombreDNI));
    return fread(*clave, sizeof(ClaveNombreDNI), 1, archivo);
}

int persistirClaveNombreDNI(void *clave, FILE *archivo)
{
    return fwrite(clave, sizeof(ClaveNombreDNI), 1, archivo);
}

void *crearClaveNombreDNI(Cliente *cliente, long posicionArchivo)
{
    ClaveNombreDNI *nuevaClave = malloc(sizeof(ClaveNombreDNI));
    nuevaClave->posicion = posicionArchivo;
    nuevaClave->dni = cliente->dni;
    strncpy(nuevaClave->nombre, cliente->nombre, 15);
    return nuevaClave;
}

void formularioClaveNombreDNI(void **destino)
{
    ClaveNombreDNI *clave = calloc(sizeof(ClaveNombreDNI), 1);
    printf("\nDatos del Cliente a buscar\n");
    printf("Nombre del cliente: ");
    scanf("%s", clave->nombre);
    printf("               DNI: ");
    scanf("%i", &(clave->dni));
    *destino = clave;
}

int obtenerPosicionClaveNombreDNI(void *clave)
{
    return ((ClaveNombreDNI*) clave)->posicion;
}

int compararClaveEdadDNI(void *clave1, void *clave2)
{
    ClaveEdadDNI *c1 = (ClaveEdadDNI*) clave1;
    ClaveEdadDNI *c2 = (ClaveEdadDNI*) clave2;
    int comparacion = c1->edad - c2->edad;
    return (comparacion == 0)? c1->dni - c2->dni : comparacion;
}

int recuperarClaveEdadDNI(void **clave, FILE *archivo)
{
    *clave = malloc(sizeof(ClaveEdadDNI));
    return fread(*clave, sizeof(ClaveEdadDNI), 1, archivo);
}

int persistirClaveEdadDNI(void *clave, FILE *archivo)
{
    return fwrite(clave, sizeof(ClaveEdadDNI), 1, archivo);
}

void *crearClaveEdadDNI(Cliente *cliente, long posicionArchivo)
{
    ClaveEdadDNI *nuevaClave = malloc(sizeof(ClaveEdadDNI));
    nuevaClave->posicion = posicionArchivo;
    nuevaClave->dni = cliente->dni;
    nuevaClave->edad = cliente->edad;
    return nuevaClave;
}

void formularioClaveEdadDNI(void **destino)
{
    ClaveEdadDNI *clave = calloc(sizeof(ClaveEdadDNI), 1);
    printf("\nDatos del Cliente a buscar\n");
    printf("Edad del cliente: ");
    scanf("%i", &(clave->edad));
    printf("             DNI: ");
    scanf("%i", &(clave->dni));
    *destino = clave;
}

int obtenerPosicionClaveEdadDNI(void *clave)
{
    return ((ClaveEdadDNI*) clave)->posicion;
}
