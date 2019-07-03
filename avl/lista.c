#include <stdlib.h>
#include "lista.h"

Lista *agregarLista(Lista *lista, void *dato)
{
    if (lista)
        lista->siguiente = agregarLista(lista->siguiente, dato);
    else
        lista = crearLista(dato, lista);
    return lista;
}

Lista *apilarLista(Lista *lista, void *dato)
{
    return crearLista(dato, lista);
}

Lista *desapilarLista(Lista *lista)
{
    Lista *borrar = lista;
    lista = lista? lista->siguiente : lista;
    free(borrar);
    return lista;
}

void borrarLista(Lista *lista)
{
    while (desapilarLista(lista));
}

Lista *crearLista(void *dato, Lista *lista)
{
    Lista *nuevaLista = malloc(sizeof(Lista));
    nuevaLista->dato = dato;
    nuevaLista->siguiente = lista;
    return nuevaLista;
}

Lista *unirLista(Lista *destino, Lista *origen)
{
    Lista **enlace = &destino;
    while (*enlace)
        enlace = &((*enlace)->siguiente);
    *enlace = origen;
    return destino;
}
