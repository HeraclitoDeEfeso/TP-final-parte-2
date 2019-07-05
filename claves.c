#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "claves.h"

int compararClave(void *clave1, void *clave2)
{
    Clave *c1 = (Clave*) clave1;
    Clave *c2 = (Clave*) clave2;
    int comparacion = strcmp(c1->nombre, c2->nombre);
    return (comparacion == 0)? c1->dni - c2->dni : comparacion;
}

int recuperarClave (void **clave, FILE *archivo)
{
    *clave = malloc(sizeof(Clave));
    return fread(*clave, sizeof(Clave), 1, archivo);
}

int persistirClave(void *clave, FILE *archivo)
{
    return fwrite(clave, sizeof(Clave), 1, archivo);
}

Clave *crearClave(Cliente *cliente, long posicionArchivo)
{
    Clave *nuevaClave = malloc(sizeof(Clave));
    nuevaClave->posicion = posicionArchivo;
    nuevaClave->dni = cliente->dni;
    strncpy(nuevaClave->nombre, cliente->nombre, 15);
    return nuevaClave;
}

Clave *formularioClave()
{
    Clave *clave = calloc(sizeof(Clave), 1);
    printf("Nombre del cliente: ");
    scanf("%s", clave->nombre);
    printf("DNI: ");
    scanf("%i", &(clave->dni));
    return clave;
}
