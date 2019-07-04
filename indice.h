#ifndef __INDICE__
#define __INDICE__
#include "avl/avl.h"

/**
 * typedef Indice: TAD de Indice implementado como Arbol AVL.
 *
 * Este TAD será utilizado para representar el Indice implementado como
 * un Árbol AVL. Como no posee otro atributo, pues se utilizará un solo
 * Indice, es directamente un sinónimo del Árbol AVL: el registro de
 * Clave y su función comparadora son directamente parte de la
 * implementación.
 */
typedef Arbol Indice;

/**
 * typedef Iterador: TAD de Iterador para Indice implementado con árbol AVL.
 *
 * Este TAD será utilizado para representar el Iterador del Indice
 * implementado como Árbol AVL. Como no posee otro atributo es
 * directamente un sinónimo de Lista/Pila de subarboles.
 */
typedef Lista Iterador;

/**
 * agregarClaveIndice() - Método para agregar una nueva clave al Indice.
 * @indice: indice al que se quiere insertar la nueva clave.
 * @clave: una nueva clave.
 * @funcion: función comparadora de claves.
 *
 * Método para insertar una nueva clave al Indice. Precondición: memoria
 * suficiente para el nodo de la estructura con la que se haya implementado
 * el Indice. Postcondicion: si la clave no existe en el Indice se aloca
 * memoria el nodo de la estructura con la que se haya implementado el Indice;
 * el Indice puede haber cambiado.
 *
 * Return: un Indice que contiene la clave.
 */
Indice *agregarClaveIndice(Indice *indice, void *clave, Comparador funcion);

/**
 * borrarClaveIndice() - Método para borrar una clave existente del Indice.
 * @indice: Indice al que se quiere borrar la clave.
 * @clave: una clave existente en el Indice.
 * @funcion: función comparadora de claves.
 *
 * Método para borrar una clave existente en del Indice. Precondición: ninguna.
 * Postcondicion: si la clave existe en el árbol se liberará la memoria de
 * un nodo de la estructura que implementa el Indice; el Indice puede haber
 * cambiado.
 *
 * Return: un Indice que no contiene la clave.
 */
Indice *borrarClaveIndice(Indice *indice, void *clave, Comparador funcion);

/**
 * obtenerVistaMenorIndice() - Obtener un sub Indice con claves menores.
 * @indice: Indice del que se quiere obtener un sub Indice.
 * @clave: una clave que será mayor o igual a todas las del sub Indice.
 * @funcion: función comparadora de claves.
 *
 * Método para obtener un sub Indice con las claves menores a la clave.
 * Precondición: memoria suficiente para crear los nodos de la estructura
 * elegida para implementar el Indice en cantidad necesaria para obtener
 * un sub Indice con las claves menores. Postcondicion: se crearan los
 * nodos de la estructura elegida para implementar el Indice en cantidad
 * suficiente para obtener un sub Indice con las claves menores.
 *
 * Return: un nuevo Indice sólo con las claves menores a la clave.
 */
Indice *obtenerVistaMenorIndice(Indice *indice, void *clave, Comparador funcion);

/**
 * obtenerVistaMayorIndice() - Obtener un sub Indice con claves mayores.
 * @indice: Indice del que se quiere obtener un sub Indice.
 * @clave: una clave que será menor o igual a todas las del sub Indice.
 * @funcion: función comparadora de claves.
 *
 * Método para obtener un sub Indice con las claves mayores a la clave.
 * Precondición: memoria suficiente para crear los nodos de la estructura
 * elegida para implementar el Indice en cantidad necesaria para obtener
 * un sub Indice con las claves mayores. Postcondicion: se crearan los
 * nodos de la estructura elegida para implementar el Indice en cantidad
 * suficiente para obtener un sub Indice con las claves mayores.
 *
 * Return: un nuevo Indice sólo con las claves mayores a la clave.
 */
Indice *obtenerVistaMayorIndice(Indice *indice, void *clave, Comparador funcion);

/**
 * obtenerIterador() - Método para obtener un Iterador en orden del Indice.
 * @indice: Indice que se desea recorre.
 *
 * Método para obtener un Iterador en orden del Indice. Precondición:
 * memoria suficiente para crear la estructura con la que se haya
 * implementado el Iterador del Indice. Postcondicion: se alocará la memoria
 * suficiente para la estructura que implementa el Iterador.
 *
 * Return: un Iterador.
 */
Iterador *obtenerIterador(Indice *indice);

/**
 * siguienteIterador() - Método para obtener la siguiente clave de un Iterador.
 * @iterador: Iterador que recorre el Indice.
 *
 * Método para obtener la siguiente clave en la iteracion de un Indice.
 * Precondición: el Indice no debe modificarse durante la iteración; memoria
 * suficiente para modificar la estructura con la que se haya implementado el
 * Iterador del Indice. Postcondicion: se liberará y alocará la memoria
 * suficiente para la estructura que implementa el Iterador; el Iterador
 * se modificará.
 *
 * Return: una clave.
 */
void *siguienteIterador(Iterador **iterador);

#endif //__INDICE__
