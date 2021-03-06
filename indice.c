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
    Arbol *actual = NULL;
    void *clave = NULL;
    if (NULL != *iterador) {
        actual = (Arbol*) ((*iterador)->dato);
        clave = actual->clave;
        *iterador = unirLista(obtenerIterador(actual->derecha),
                              desapilarLista(*iterador));
    }
    return clave;
}

void persistirIndice(Indice *indice, Persistente persistir, FILE* archivo)
{
    enum HijosArbol estado;
    unsigned char valor;
    if (NULL != indice) {
        if (NULL == indice->izquierda)
            if (NULL == indice->derecha)
                estado = SIN_HIJOS;
            else
                estado = HIJO_DER;
        else if (NULL == indice->derecha)
            estado = HIJO_IZQ;
        else
            estado = DOS_HIJOS;
        valor = (unsigned char) estado;
        fwrite(&valor, sizeof(unsigned char), 1, archivo);
        persistir(indice->clave, archivo);
        persistirIndice(indice->izquierda, persistir, archivo);
        persistirIndice(indice->derecha, persistir, archivo);
    }
}

Indice *recuperarIndice(Recuperador recuperar, FILE* archivo)
{
    Indice *indice = NULL;
    enum HijosArbol estado;
    unsigned char valor;
    void *clave;
    if (!feof(archivo)) {
        fread(&valor, sizeof(unsigned char), 1, archivo);
        recuperar(&clave, archivo);
        indice = crearArbol(clave);
        estado = (enum HijosArbol) valor;
        switch (estado) {
        case DOS_HIJOS:
            indice->izquierda = recuperarIndice(recuperar, archivo);
        case HIJO_DER:
            indice->derecha = recuperarIndice(recuperar, archivo);
            break;
        case HIJO_IZQ:
            indice->izquierda = recuperarIndice(recuperar, archivo);
        case SIN_HIJOS:
            break;
        }
    }
    return indice;
}

void *buscarClaveIndice(Indice *indice, void *clave, Comparador funcion)
{
    Arbol *encontrado = buscarArbol(indice, clave, funcion);
    return (NULL != encontrado)? encontrado->clave : encontrado;
}

void liberarVistaMayor(Indice *vista)
{
    if (NULL != vista) {
        liberarVistaMayor(vista->izquierda);
        free(vista);
    }
}

void liberarVistaMenor(Indice *vista)
{
    if (NULL != vista) {
        liberarVistaMenor(vista->derecha);
        free(vista);
    }
}
