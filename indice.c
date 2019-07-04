#include <stdlib.h>
#include <string.h>
#include "indice.h"

Indice *agregarClaveIndice(Indice *indice, void *clave, Comparador funcion)
{
    return insertarArbol(indice, clave, funcion);
}

Indice *borrarClaveIndice(Indice *indice, void *clave, Comparador funcion)
{
    return eliminarArbol(indice, clave, funcion);
}

Indice *obtenerVistaMenorIndice(Indice *indice, void *clave, Comparador funcion)
{
    Indice *vista = NULL;
    Indice **arista = &vista;
    while (NULL != indice) {
        if (funcion(indice->clave, clave) > 0) {
            indice = indice->izquierda;
        } else {
            *arista = malloc(sizeof(Indice));
            memcpy(*arista, indice, sizeof(Indice));
            arista = &((*arista)->derecha);
            *arista = NULL;
            indice = indice->derecha;
        }
    }
    return vista;
}

Indice *obtenerVistaMayorIndice(Indice *indice, void *clave, Comparador funcion)
{
    Indice *vista = NULL;
    Indice **arista = &vista;
    while (NULL != indice) {
        if (funcion(indice->clave, clave) < 0) {
            indice = indice->derecha;
        } else {
            *arista = malloc(sizeof(Indice));
            memcpy(*arista, indice, sizeof(Indice));
            arista = &((*arista)->izquierda);
            *arista = NULL;
            indice = indice->izquierda;
        }
    }
    return vista;
}

Iterador *obtenerIterador(Indice *indice)
{
    Iterador *iterador = NULL;
    while (NULL != indice) {
        iterador = apilarLista(iterador, indice);
        indice = indice->izquierda;
    }
    return iterador;
}

void *siguienteIterador(Iterador **iterador)
{
    void *clave = NULL;
    if (NULL != *iterador) {
        clave = ((Arbol*) (*iterador)->dato)->clave;
        *iterador = avanzarIterador(desapilarLista(*iterador));
    }
    return clave;
}

Iterador *avanzarIterador(Iterador *iterador)
{
    void *proximoDato;
    if (NULL != iterador) {
        proximoDato = iterador->dato;
        iterador = desapilarLista(iterador);
        iterador = unirLista(obtenerIterador(((Arbol*) proximoDato)->derecha),
                            iterador);
        iterador = apilarLista(iterador, proximoDato);
    }
    return iterador;
}

void persistirIndice(Indice *indice, Persistente funcion, FILE* archivo){}

Indice *recuperarIndice(Recuperador funcion, FILE* archivo){return 0;}
