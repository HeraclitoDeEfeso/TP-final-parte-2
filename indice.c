#include <stdlib.h>
#include "indice.h"

Indice *agregarClaveIndice(Indice *indice, void *clave, Comparador funcion)
{
    return insertarArbol(indice, clave, funcion);
}

Indice *borrarClaveIndice(Indice *indice, void *clave, Comparador funcion)
{
    return eliminarArbol(indice, clave, funcion);
}

Indice *obtenerVistaMenorIndice(Indice *indice, void *clave, Comparador funcion){return 0;}
Indice *obtenerVistaMayorIndice(Indice *indice, void *clave, Comparador funcion){return 0;}

Iterador *obtenerIterador(Indice *indice){return 0;}

void *siguienteIterador(Iterador **iterador)
{
    void *clave = NULL;
    if (NULL != *iterador) {
        if (NULL != (*iterador)->dato)
            clave = ((Arbol*) (*iterador)->dato)->clave;
        *iterador = desapilarLista(*iterador);
        if (NULL != *iterador && NULL != (*iterador)->dato)
            *iterador = unirLista(
                            obtenerIterador(
                                ((Arbol*) (*iterador)->dato)->derecha
                            ),
                            *iterador
                        );
    }
    return clave;
}
