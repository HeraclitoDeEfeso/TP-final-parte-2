#ifndef TEST_AVL_H_INCLUDED
#define TEST_AVL_H_INCLUDED
#include "avl.h"

void test_avl();
void testCrearUnArbol();
void testCrearUnArbolConDosNodosUnoADerecha();
void testBuscarUnaClave();
void testBorrarLaRaizDeUnArbolConMasDeUnElemento();
void testBorrarLaRaizDeUnArbolConUnElemento();
void testBorrarUnElementoEnLaMitadDelArbol();
void testInOrder();
void testPostOrder();
void testPreOrder();
void testArbolConUnElementoEsAvl();
void testBalanceoSimpleIzquierda();
void testBalanceoSimpleDerecha();
void testBalanceoDobleALaDerecha();
void testBalanceoDobleALaIzquierda();
void testBalanceoaLaDerechaDespuesDeBorrar();
void testBalanceoaLaIzquierdaDespuesDeBorrar();
void testBalanceoDobleALaDerechaDespuesDeBorrar();
void testBalanceoDobleALaIzquierdaDespuesDeBorrar();
void testBorradoPrecisaDobleBalanceo();

/* Funciones auxiliares */

/* Implementación de comparación de enteros */
int comparar(void *clave1, void *clave2);

/* Impresión de un árbol en pantalla para inspección de código */
void mostrarArbol(Arbol *arbol, int level);

/* Función de máximo */
int max(int a, int b);

/* Cálculo recursivo de altura de un árbol */
int altura(Arbol *arbol);

/* Condición que debe cumplir un árbol para ser un AVL */
int esAVL(Arbol *arbol);

#endif // TEST_AVL_H_INCLUDED
