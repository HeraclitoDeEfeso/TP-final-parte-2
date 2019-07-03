#ifndef __INDICE__
#define __INDICE__
#include "avl/avl.h"

/**
 * typedef Indice: TAD de Indice implementado como Arbol AVL.
 *
 * Este TAD ser� utilizado para representar el Indice implementado como
 * un �rbol AVL. Como no posee otro atributo, pues se utilizar� un solo
 * Indice, es directamente un sin�nimo del �rbol AVL: el registro de
 * Clave y su funci�n comparadora son directamente parte de la
 * implementaci�n.
 */
typedef Arbol Indice;

/**
 * typedef Iterador: TAD de Iterador implementado como Lista/Pila.
 *
 * Este TAD ser� utilizado para representar el Iterador del Indice
 * implementado como �rbol AVL. Como no posee otro atributo es
 * directamente un sin�nimo de Lista/Pila de subarboles.
 */
typedef Lista *Iterador;

Indice *agregarClaveIndice(Indice *indice, void *clave, Comparador funcion);
Indice *borrarClaveIndice(Indice *indice, void *clave, Comparador funcion);
Indice *obtenerVistaMenorIndice(Indice *indice, void *clave, Comparador funcion);
Indice *obtenerVistaMayorIndice(Indice *indice, void *clave, Comparador funcion);
Iterador *obtenerIterador(Indice *indice);
Iterador *siguienteIterador(Iterador *iterador);

#endif //__INDICE__
