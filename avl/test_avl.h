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

/* Implementaci�n de comparaci�n de enteros */
int comparar(void *clave1, void *clave2);

/* Impresi�n de un �rbol en pantalla para inspecci�n de c�digo */
void mostrarArbol(Arbol *arbol, int level);

/* Funci�n de m�ximo */
int max(int a, int b);

/* C�lculo recursivo de altura de un �rbol */
int altura(Arbol *arbol);

/* Condici�n que debe cumplir un �rbol para ser un AVL */
int esAVL(Arbol *arbol);

#endif // TEST_AVL_H_INCLUDED
