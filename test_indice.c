#include <stdio.h>
#include <assert.h>
#include "test_indice.h"
#include "indice.h"

int compararIndice(void *clave1, void *clave2)
{
    return (int) clave1 - (int) clave2;
}

int sonIgualesIndice(Indice *a, Indice *b)
{
    return (a == NULL && b == NULL)
            || (compararIndice(a->clave, a->clave) == 0
                && sonIgualesIndice(a->izquierda, b->izquierda)
                && sonIgualesIndice(a->derecha, b->derecha));
}

void mostrarArbolIndice(Arbol *arbol, int level)
{
    if (arbol) {
        printf("%.4i(%2i)\n", (int) arbol->clave, arbol->balance);
        if (arbol->izquierda) {
            printf("%*s", 4 * level + 4, "izq:" );
            mostrarArbolIndice(arbol->izquierda, level + 1);
        }
        if (arbol->derecha) {
            printf("%*s", 4 * level + 4, "der:" );
            mostrarArbolIndice(arbol->derecha, level + 1);
        }
    } else {
        printf("\n");
    }
}

void test_vista_menor_con_limite_externo()
{
    int ingresados[] = {7, 3, 10, 2, 6, 8, 12};
    int esperados[] = {2, 3};
    int i = 0;
    Indice *indice = NULL;
    Indice *vista;
    Iterador *iterador;
    for (; i < sizeof(ingresados) / sizeof(int); i++)
        indice = agregarClaveIndice(indice, (void*) ingresados[i], &compararIndice);
    vista = obtenerVistaMenorIndice(indice, (void*) 5, &compararIndice);
    iterador = obtenerIterador(vista);
    i = 0;
    while (NULL != iterador)
        assert(((int) siguienteIterador(&iterador)) == esperados[i++]);
}

void test_vista_menor_con_limite_interno()
{
    int ingresados[] = {7, 3, 10, 2, 6, 8, 12};
    int esperados[] = {2, 3, 6, 7, 8};
    int i = 0;
    Indice *indice = NULL;
    Indice *vista;
    Iterador *iterador;
    for (; i < sizeof(ingresados) / sizeof(int); i++)
        indice = agregarClaveIndice(indice, (void*) ingresados[i], &compararIndice);
    vista = obtenerVistaMenorIndice(indice, (void*) 8, &compararIndice);
    iterador = obtenerIterador(vista);
    i = 0;
    while (NULL != iterador)
        assert(((int) siguienteIterador(&iterador)) == esperados[i++]);
}

void test_vista_mayor_con_limite_externo()
{
    int ingresados[] = {7, 3, 10, 2, 6, 8, 12};
    int esperados[] = {6, 7, 8, 10, 12};
    int i = 0;
    Indice *indice = NULL;
    Indice *vista;
    Iterador *iterador;
    for (; i < sizeof(ingresados) / sizeof(int); i++)
        indice = agregarClaveIndice(indice, (void*) ingresados[i], &compararIndice);
    vista = obtenerVistaMayorIndice(indice, (void*) 5, &compararIndice);
    iterador = obtenerIterador(vista);
    i = 0;
    while (NULL != iterador)
        assert(((int) siguienteIterador(&iterador)) == esperados[i++]);
}

void test_vista_mayor_con_limite_interno()
{
    int ingresados[] = {7, 3, 10, 2, 6, 8, 12};
    int esperados[] = {8, 10, 12};
    int i = 0;
    Indice *indice = NULL;
    Indice *vista;
    Iterador *iterador;
    for (; i < sizeof(ingresados) / sizeof(int); i++)
        indice = agregarClaveIndice(indice, (void*) ingresados[i], &compararIndice);
    vista = obtenerVistaMayorIndice(indice, (void*) 8, &compararIndice);
    iterador = obtenerIterador(vista);
    i = 0;
    while (NULL != iterador)
        assert(((int) siguienteIterador(&iterador)) == esperados[i++]);
}

void test_indice()
{
    test_vista_menor_con_limite_externo();
    test_vista_menor_con_limite_interno();
}
