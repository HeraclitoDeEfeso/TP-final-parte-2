#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "claves.h"

int compararClave(void *clave1, void *clave2)
{
    Clave *c1 = (Clave*) clave1;
    Clave *c2 = (Clave*) clave2;
    int comparacion = strcmp(c1->apellido, c2->apellido); printf("Compara el apellido %s con %s y obtiene %i\n", c1->apellido, c2->apellido, comparacion);
    printf("Compara edad %i con %i y obtiene %i\n", c1->edad, c2->edad, (c1->edad - c2->edad));
    return (comparacion == 0)? c1->edad - c2->edad : comparacion;
}

void recuperarClave (void **clave, FILE *archivo)
{
    Clave *recuperada = malloc(sizeof(Clave)); printf("Crea la clave en la posicion de memoria %p\n", recuperada);
    int fallo = fread(recuperada, sizeof(Clave), 1, archivo); printf("Fallo lectura %i\n", fallo);
    printf("En la clave recuperada hay posicion %ld edad %i y apellido %15s\n", recuperada->posicion, recuperada->edad, recuperada->apellido);
    *clave = recuperada; printf("Escribio en la memoria %p la direccion %p\n", clave, *clave);
}

int persistirClave(void *clave, FILE *archivo)
{
    int fallo = fwrite(clave, sizeof(Clave), 1, archivo); printf("Fallo persistencia %i\n", fallo);
    return fallo;
}

Clave *crearClave(Cliente *cliente, long posicionArchivo)
{
    Clave *nuevaClave = malloc(sizeof(Clave)); printf("Crea la clave en la posicion de memoria %p\n", nuevaClave);
    nuevaClave->posicion = posicionArchivo; printf("Guarda en la clave la posicion de archivo %ld\n", nuevaClave->posicion);
    nuevaClave->edad = cliente->edad; printf("Guarda en la clave la edad %i\n", nuevaClave->edad);
    strncpy(nuevaClave->apellido, cliente->apellido, 15); printf("Guarda en la clave el apellido %s\n", nuevaClave->apellido);
    return nuevaClave;
}
