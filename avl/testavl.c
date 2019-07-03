#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

int comparar(void *clave1, void *clave2)
{
    return (int) clave1 - (int) clave2;
}

void mostrarArbol(Arbol *arbol, int level)
{
    if (arbol) {
        printf("%.4i(%2i)\n", (int) arbol->clave, arbol->balance);
        if (arbol->izquierda) {
            printf("%*s", 4 * level + 4, "izq:" );
            mostrarArbol(arbol->izquierda, level + 1);
        }
        if (arbol->derecha) {
            printf("%*s", 4 * level + 4, "der:" );
            mostrarArbol(arbol->derecha, level + 1);
        }
    } else {
        printf("\n");
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int altura(Arbol *arbol)
{
    return (arbol != NULL)
           ? 1 + max(altura(arbol->izquierda), altura(arbol->derecha))
           : 0;
}

int esAVL(Arbol *arbol)
{
    return  arbol == NULL
            || (abs(altura(arbol->izquierda) - altura(arbol->derecha)) <= 1
                && esAVL(arbol->izquierda)
                && esAVL(arbol->derecha));
}

void testCrearUnArbol()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    assert((int) arbol->clave == 5);
}

void testCrearUnArbolConDosNodosUnoADerecha()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 7, &comparar);
    assert(esAVL(arbol));
    assert((int) arbol->clave == 5);
    assert((int) arbol->derecha->clave == 7);
}

void testBuscarUnaClave()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 4, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 1, &comparar);
    assert(esAVL(arbol));
    assert(buscarArbol(arbol, (void*)12, &comparar) == NULL);
    assert(buscarArbol(arbol, (void*)1, &comparar) != NULL);
}

void testBorrarLaRaizDeUnArbolConUnElemento()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    assert(arbol == NULL);
}

void testBorrarLaRaizDeUnArbolConMasDeUnElemento()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    assert((int) arbol->clave == 8);
}

void testBorrarUnElementoEnLaMitadDelArbol()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 18, &comparar);
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    assert(buscarArbol(arbol, (void*) 8, &comparar) == NULL);
    assert(buscarArbol(arbol, (void*) 18, &comparar) != NULL);
    assert((int) arbol->clave == 5);
}

void testInOrder()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 18, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 4, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 2, &comparar);
    assert(esAVL(arbol));
    Lista *lista = enordenArbol(arbol);
    Lista *ordenada = NULL;
    apilarLista(ordenada,(int *) 2);
    apilarLista(ordenada,(int *) 4);
    apilarLista(ordenada,(int *) 5);
    apilarLista(ordenada,(int *) 8);
    apilarLista(ordenada,(int *) 18);
    while(ordenada) {
        assert(lista->dato == ordenada->dato);
        desapilarLista(ordenada);
        desapilarLista(lista);
    }
}

void testPreOrder()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 18, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 4, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 2, &comparar);
    assert(esAVL(arbol));
    Lista *lista = preordenArbol(arbol);
    Lista *ordenada = NULL;
    apilarLista(ordenada,(int *) 5);
    apilarLista(ordenada,(int *) 4);
    apilarLista(ordenada,(int *) 2);
    apilarLista(ordenada,(int *) 8);
    apilarLista(ordenada,(int *) 18);
    while(ordenada){
        assert(lista->dato == ordenada->dato);
        desapilarLista(ordenada);
        desapilarLista(lista);
    }
}

void testPostOrder()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 18, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 4, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 2, &comparar);
    assert(esAVL(arbol));
    Lista *lista = postordenArbol(arbol);
    Lista *ordenada = NULL;
    apilarLista(ordenada,(int *) 2);
    apilarLista(ordenada,(int *) 4);
    apilarLista(ordenada,(int *) 18);
    apilarLista(ordenada,(int *) 8);
    apilarLista(ordenada,(int *) 5);
    while(ordenada){
        assert(lista->dato == ordenada->dato);
        desapilarLista(ordenada);
        desapilarLista(lista);
    }
}

void testArbolConUnElementoEsAvl()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*)5, &comparar);
    assert(esAVL(arbol));
}

void testBalanceoSimpleIzquierda()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 18, &comparar);
    assert(esAVL(arbol));
    assert((int) arbol->clave == 8);
}

void testBalanceoSimpleDerecha()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 5, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 4, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 1, &comparar);
    assert((int) arbol->clave == 4);
    assert(esAVL(arbol));
}

void testBalanceoDobleALaDerecha()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 18, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 14, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 15, &comparar);
    assert((int) arbol->clave == 15);
    assert(esAVL(arbol));
}

void testBalanceoDobleALaIzquierda()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 4, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 6, &comparar);
    assert((int) arbol->clave == 6);
    assert(esAVL(arbol));
}

void testBalanceoaLaDerechaDespuesDeBorrar()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 4, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 9, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 3, &comparar);/*hasta aca esta balanceado*/
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, (void*) 9, &comparar);
    assert((int) arbol->clave == 4);
    assert((int) arbol->derecha->clave == 8);
    assert((int) arbol->izquierda->clave == 3);
    assert(esAVL(arbol));
}

void testBalanceoaLaIzquierdaDespuesDeBorrar()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 4, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 9, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 11, &comparar);/*hasta aca esta balanceado*/
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, (void*) 4, &comparar);
    assert((int) arbol->clave == 9);
    assert((int) arbol->derecha->clave == 11);
    assert((int) arbol->izquierda->clave == 8);
    assert(esAVL(arbol));
}

void testBalanceoDobleALaIzquierdaDespuesDeBorrar()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 4, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*)13, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 11, &comparar);/*hasta aca esta balanceado*/
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, (void*) 4, &comparar);
    assert((int) arbol->clave == 11);
    assert((int) arbol->derecha->clave == 13);
    assert((int) arbol->izquierda->clave == 8);
    assert(esAVL(arbol));
}

void testBalanceoDobleALaDerechaDespuesDeBorrar()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, (void*) 8, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 4, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 13, &comparar);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, (void*) 5, &comparar);/*hasta aca esta balanceado*/
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, (void*) 13, &comparar);
    assert((int) arbol->clave == 5);
    assert((int) arbol->derecha->clave == 8);
    assert((int) arbol->izquierda->clave == 4);
    assert(esAVL(arbol));
}

void testBorradoPrecisaDobleBalanceo()
{
    Arbol *arbol = NULL;
    int i, numeros[] = {50, 25, 75, 80, 60, 40, 15, 90, 65, 55, 35, 62};
    for(i = 0; i < sizeof(numeros) / sizeof(int); i++) {
        arbol = insertarArbol(arbol, (void*) numeros[i], &comparar);
        assert(esAVL(arbol));
    }
    arbol = eliminarArbol(arbol, (void*) 15, &comparar);
    assert(esAVL(arbol));
    assert((int) arbol->clave == 60);
}

void test_avl()
{
    testCrearUnArbol();
    testCrearUnArbolConDosNodosUnoADerecha();
    testBuscarUnaClave();
    testBorrarLaRaizDeUnArbolConMasDeUnElemento();
    testBorrarLaRaizDeUnArbolConUnElemento();
    testBorrarUnElementoEnLaMitadDelArbol();
    testInOrder();
    testPostOrder();
    testPreOrder();
    testArbolConUnElementoEsAvl();
    testBalanceoSimpleIzquierda();
    testBalanceoSimpleDerecha();
    testBalanceoDobleALaDerecha();
    testBalanceoDobleALaIzquierda();
    testBalanceoaLaDerechaDespuesDeBorrar();
    testBalanceoaLaIzquierdaDespuesDeBorrar();
    testBalanceoDobleALaDerechaDespuesDeBorrar();
    testBalanceoDobleALaIzquierdaDespuesDeBorrar();
    testBorradoPrecisaDobleBalanceo();
    return 0;
}
