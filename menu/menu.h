#ifndef __MENU__
#define __MENU__

/**
 * typedef Menu: TAD de un menú
 * @titulo: título del menú
 * @opciones: descripciones de las opciones
 * @dimension: cantidad de opciones
 *
 * Este TAD será utilizado para presentar opciones y obtener la selección del
 * usuario, encapsulando las operaciones de entrada/salida permitiendo abstraer
 * la apariencia de la aplicación.
 */
typedef struct {
    char *titulo;
    char **opciones;
    int dimension;
} *Menu;

/**
 * crearMenu() - Método para crear un menú e inizializar sus atributos.
 * @titulo: título del menú.
 * @opciones: descripción de cada una de las opciones.
 * @dimension: cantidad de opciones.
 *
 * Método para crear un menú e inizializar sus atributos. Precondición: ninguna.
 * Postcondicion: se aloca memoria para un Menu, se inicializan sus atributos y
 * se devuelve la direccion.
 *
 * Return: un Menu.
 */
Menu crearMenu(char *titulo, char **opciones, int dimension);

/**
 * activarMenu() - Método para para solicitar la elección del usuario.
 * @menu: un Menu para activar.
 *
 * Método para para solicitar la elección del usuario. Precondición: el menu
 * debe haberse creado antes. Postcondicion: a través de las funciones de
 * entrada/salida se muestran el título del menú y sus opciones. Se solicita
 * la entrada de la opción elegida por el usuario.
 *
 * Return: el índice de la opción seleccionada comenzando por el 1.
 */
int activarMenu(Menu menu);

#endif
