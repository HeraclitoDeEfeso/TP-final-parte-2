#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista {
    void *dato;
    struct Lista *siguiente;
} Lista;

/**
 * agregarLista() - Método para agregar un dato al final de la lista.
 * @lista: lista a la que se desea agregar el dato.
 * @dato: dato que se desea agregar.
 *
 * Método para agregar un dato al final de la lista. Precondición: memoria
 * suficiente. Postcondicion: se alocará memoria para una lista unitaria;
 * se inicializarán sus atributos, la arista del último en la lista cambiará.
 *
 * Return: la misma lista con el dato agregado.
 */
Lista *agregarLista(Lista *lista, void *dato);

/**
 * apilarLista() - Método para agregar un dato al principio de la lista.
 * @lista: lista a la que se desea agregar el dato.
 * @dato: dato que se desea agregar.
 *
 * Método para agregar un dato al principio de la lista. Precondición: memoria
 * suficiente. Postcondicion: se alocará memoria para una lista unitaria;
 * se inicializarán sus atributos.
 *
 * Return: una nueva lista con el dato agregado al principio.
 */
Lista *apilarLista(Lista *lista, void *dato);

/**
 * desapilarLista() - Método para eliminar de la lista el primer dato.
 * @lista: lista a la que se le desea eliminar el dato.
 *
 * Método para eliminar de la lista el primer dato. Precondición: ninguna.
 * Postcondicion: es posible que se desaloque memoria para una lista unitaria.
 *
 * Return: una nueva lista sin el primer dato que tenía la lista original.
 */
Lista *desapilarLista(Lista *lista);

/**
 * unirLista() - Método para concatenar dos listas.
 * @destino: lista a la que se le desea concatenar al final otra lista.
 * @origen: lista que será concatenada al final de la otra lista.
 *
 * Método para concatenar dos listas. Precondición: ninguna.
 * Postcondicion: es posible que se modifique la arista del último
 * elemento de la lista destino; si una o ambas listas son nulas, el
 * resultado es inocuo;
 *
 * Return: la lista destino con la lista origen concatenada al final.
 */
Lista *unirLista(Lista *destino, Lista *origen);

/**
 * borrarLista() - Método para borrar una lista.
 * @lista: lista que se desea borrar.
 *
 * Método para borrar una lista. Precondición: ninguna.
 * Postcondicion: es posible que se desaloque memoria ocupada por la
 * lista; si la lista es nula el resultado es inocuo;
 */
void borrarLista(Lista *lista);

/* Métodos privados */

/**
 * crearLista() - Método para crear una lista unitaria.
 * @dato: dato de la lista.
 * @lista: arista a otro lista que será la continuación.
 *
 * Método para crear una lista unitaria. Precondición: memoria suficiente.
 * Postcondicion: se alocará memoria para una lista unitaria.
 *
 * Return: una nueva lista con el dato por elemento y la lista por continuación
 */
Lista *crearLista(void *dato, Lista *lista);

#endif // LISTA_H_INCLUDED
