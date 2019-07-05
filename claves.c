#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "claves.h"

int compararClave(void *clave1, void *clave2)
{
    Clave *c1 = (Clave*) clave1;
    Clave *c2 = (Clave*) clave2;
    int comparacion = strcmp(c1->apellido, c2->apellido);
    return (comparacion == 0)? c1->edad - c2->edad : comparacion;
}

void recuperarClave (void **clave, FILE *archivo)
{
    *clave = malloc(sizeof(Clave));
    fread(*clave, sizeof(Clave), 1, archivo);
}

int persistirClave(void *clave, FILE *archivo)
{
    return fwrite(clave, sizeof(Clave), 1, archivo);
}

Clave *crearClave(Cliente *cliente, long posicionArchivo)
{
    Clave *nuevaClave = malloc(sizeof(Clave));
    nuevaClave->posicion = posicionArchivo;
    nuevaClave->edad = cliente->edad;
    strncpy(nuevaClave->apellido, cliente->apellido, 15);
    return nuevaClave;
}
