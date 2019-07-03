#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include "lista.h"

/**
 * typedef Arbol: TAD de un arbol AVL
 * @clave: clave de ordenamiento
 * @balance: factor de balance entre altura izquierda y derecha
 * @hijos: vector arista hacia los hijos
 *
 * Este TAD será utilizado para representar el Árbol Binario de
 * Búsqueda Balanceado AVL. Existe el arbol nulo, el árbol unitario
 * es asimilable a un nodo y cada hijo de un nodo es un subárbol,
 * por lo que se omite la definición de nodo.
 */
typedef struct Arbol {
    void *clave;
    int balance;
    struct Arbol *izquierda;
    struct Arbol *derecha;
} Arbol;

/**
 * typedef Comparador: firma de función para la comparación de claves
 * @clave1: clave que se va a comparar.
 * @clave2: clave que se va a comparar.
 *
 * Este tipo será utilizado para definir la firma de la función
 * comparadora de claves en el ordenamiento del árbol. La función no
 * debe tener ninguna precondición, en particular, las claves podrían
 * ser nulas. Debe retornar un valor entero en la forma definida por
 * la función standar `strcmp`:
 *  - negativo cuando clave1 es menor que clave2.
 *  - positivo cuando clave1 es mayor que clave2.
 *  - cero cuando clave1 es igual en valor a clave2.
 */
typedef int (*Comparador) (void* clave1, void* clave2);

/**
 * insertarArbol() - Método para insertar una nueva clave en el árbol.
 * @arbol: árbol al que se quiere insertar la nueva clave.
 * @clave: una nueva clave.
 * @funcion: función comparadora de claves.
 *
 * Método para insertar una nueva clave en el árbol. Precondición: memoria
 * suficiente. Postcondicion: si la clave no existe en el árbol se aloca
 * memoria para un nuevo árbol unitario con la clave a insertar; la raiz del
 * árbol puede haber cambiado; un enlace del árbol puede haber cambiado para
 * incluir el árbol unitario con la nueva clave.
 *
 * Return: un Arbol que contiene la clave.
 */
Arbol *insertarArbol(Arbol *arbol, void *clave, Comparador funcion);

/**
 * eliminarArbol() - Método para borrar una clave existente en el árbol.
 * @arbol: árbol al que se quiere borrar la clave.
 * @clave: una clave existente en el árbol.
 * @funcion: función comparadora de claves.
 *
 * Método para borrar una clave existente en el árbol. Precondición: ninguna.
 * Postcondicion: si la clave existe en el árbol se liberará la memoria de
 * un árbol unitario; la raiz del árbol puede haber cambiado; un enlace del
 * árbol puede haber cambiado para saltear el arbol unitario eliminado; el
 * árbol unitario que contenía la clave originalmente puede haber cambiado
 * la clave ahora.
 *
 * Return: un Arbol que no contiene la clave.
 */
Arbol *eliminarArbol(Arbol *arbol, void *clave, Comparador funcion);

/**
 * buscarArbol() - Método para buscar una clave existente en el árbol.
 * @arbol: árbol en el que se quiere buscar la clave.
 * @clave: una clave existente en el árbol.
 * @funcion: función comparadora de claves.
 *
 * Método para buscar una clave existente en el árbol. Precondición: ninguna.
 * Postcondicion: ninguna.
 *
 * Return: un Arbol que contiene la clave en su raiz o el arbol nulo si no.
 */
Arbol *buscarArbol(Arbol *arbol, void *clave, Comparador funcion);

/**
 * preordenArbol() - Genera una lista con el recorrido pre orden del árbol.
 * @arbol: árbol que se desea recorrer.
 *
 * El método genera una lista con recorrido pre orden del árbol. Precondición:
 * memoria suficiente. Postcondicion: se alocará memoria para una lista con
 * cada sublista apuntando a cada subarbol en recorrido "pre orden": la raiz
 * se recorre antes que los hijos.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *preordenArbol(Arbol *arbol);

/**
 * postordenArbol() - Genera una lista con recorrido post orden del árbol.
 * @arbol: árbol que se desea recorrer.
 *
 * El método genera una lista con recorrido post orden del árbol. Precondición:
 * memoria suficiente. Postcondicion: se alocará memoria para una lista con
 * cada sublista apuntando cada subarbol en recorrido "post orden": la raiz se
 * recorre después de los hijos.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *postordenArbol(Arbol *arbol);

/**
 * preordenArbol() - Genera una lista con recorrido en orden del árbol.
 * @arbol: árbol que se desea recorrer.
 *
 * El método genera una lista con recorrido en orden del árbol. Precondición:
 * memoria suficiente. Postcondicion: se alocará memoria para una lista con cada
 * sublista apuntando cada subarbol en recorrido "en orden": la raiz se recorre
 * después del hijo con claves menores y antes del hijo con claves mayores.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *enordenArbol(Arbol *arbol);

/* Tipos y métodos privados */

/**
 * crearArbol() - Método para crear un árbol unitario.
 * @clave: clave con la que se creará el arbol unitario.
 *
 * Método para crear un árbol unitario. Precondición: memoria suficiente.
 * Postcondicion: se alocará memoria para un árbol unitario; se inicializarán
 * sus atributos, sus aristas no conducen a ningún subárbol y está balanceado
 *
 * Return: un árbol.
 */
Arbol *crearArbol(void *clave);

/**
 * insertarArbolBalanceado() - Inserción balanceada.
 * @destino: arista al subárbol dónde se desea insertar la clave.
 * @clave: clave que se desea insertar.
 * @funcion: función comparadora de claves.
 *
 * Método que realiza la inserción balanceada de la @clave en el subárbol al
 * que conduce la arista @destino. Precondición: memoria suficiente.
 * Postcondicion: es posible que se aloque memoria para un árbol unitario y se
 * inicialicen sus atributos; es posible que se modifiquen aristas del árbol
 * para que esté balanceado y se alteren los factores de equilibrio de varios
 * subárboles; puede cambiar el subárbol al que conduce la arista @destino.
 *
 * Return: el cambio relativo entre la altura del árbol al que conducía la
 *.        arista @destino y la altura del árbol al que conduce ahora.
 */
int insertarArbolBalanceado(Arbol **destino, void *clave, Comparador funcion);

/**
 * borrarArbolBalanceado() - Borrado balanceado.
 * @destino: arista al subárbol del que se desea borrar la clave.
 * @clave: clave que se desea borrar.
 * @funcion: función comparadora de claves.
 *
 * Método que realiza el borrado balanceado de la @clave en el subárbol al
 * que conduce la arista @destino. Precondición: ninguna.
 * Postcondicion: es posible que se desaloque memoria para un árbol unitario;
 * es posible que se modifiquen aristas del árbol para que esté balanceado y
 * se alteren los factores de equilibrio de varios subárboles; puede cambiar
 * el subárbol al que conduce la arista @destino.
 *
 * Return: el cambio relativo entre la altura del árbol al que conducía la
 *.        arista @destino y la altura del árbol al que conduce ahora.
 */
int eliminarArbolBalanceado(Arbol **destino, void *clave, Comparador funcion);

/**
 * balancearArbol() - Método para balancear un árbol.
 * @destino: arista al subárbol que se desea balancear.
 *
 * Método para balancear un árbol según su factor de equilibrio. Precondición:
 * la arista @destino no conduce a un árbol nulo. Postcondicion: es posible
 * que se modifiquen aristas del árbol para que esté balanceado y se alteren
 * los factores de equilibrio de los subárboles; puede cambiar el subárbol
 * al que conduce la arista @destino.
*/
void balancearArbol(Arbol **destino);

/**
 * rotarDerecha() - Cambia la raíz de un árbol por la del subárbol derecho.
 * @arbol: arista al subárbol que se desea rotar.
 *
 * Método para cambiar la raíz de un árbol por la de su subárbol derecho.
 * Precondición: la arista @arbol no debe conducir a un árbol nulo.
 * Postcondicion: se modificaran aristas del árbol y el subárbol derecho y
 * aumentarán sus factores de equilibrio; la arista @destino conducirá a su
 * subárbol derecho.
 */
void rotarDerecha(Arbol **arbol);

/**
 * rotarIzquierda() - Cambia la raíz de un árbol por la del subárbol izquierdo.
 * @arbol: arista al subárbol que se desea rotar.
 *
 * Método para cambiar la raíz de un árbol por la de su subárbol izquierdo.
 * Precondición: la arista @arbol no debe conducir a un árbol nulo.
 * Postcondicion: se modificarán aristas del árbol y el subárbol izquierdo y
 * disminuirán sus factores de equilibrio; la arista @destino conducirá a su
 * subárbol izquierdo.
 */
void rotarIzquierda(Arbol **arbol);

/**
 * buscarMaximo() - Método hallar el máximo valor de la clave en un árbol.
 * @arbol: árbol del que se desea hallar el máximo.
 *
 * Método hallar el máximo valor de la clave en un árbol. Precondición:
 * el árbol no debe ser nulo. Postcondicion: ninguna.
 *
 * Return: la máxima clave del @arbol.
 */
void *buscarMaximo(Arbol *arbol);

#endif // AVL_H_INCLUDED
