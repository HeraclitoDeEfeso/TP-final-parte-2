#ifndef __CLIENTE__
#define __CLIENTE__

#include <stdio.h>
#include "credito.h"
#define MAX_CREDITOS 3

/**
 * typedef Cliente:
 *
 * Este tipo será utilizado para almacenar y modificar la informacion de los clientes.
 */
typedef struct {
    int edad;
    int dni;
    char nombre[15];
    char apellido[15];
    char inicial;
    int referencia;
    Credito creditos[MAX_CREDITOS];
} Cliente;

/**
 * crearCliente() - crea un cliente.
 *
 * Método que crea un Cliente y carga sus atributos mediante un formulario.
 *
 * Return: devuelve un puntero al cliente creado
 */
Cliente *crearCliente();

/**
 * mostrarCliente() - muestra un cliente.
 * @cliente: cliente que se desea mostrar.
 * Método imprime en pantalla la informacion del cliente.
 */
void mostrarCliente(Cliente *cliente);

/**
 * formularioCliente() - modifica o crea un cliente.
 * @cliente: cliente que sera modificado
 * Método que modifica/crea un cliente segun los datos que ponga el usuaria en la aplicacion
 * luego de que esta se los solicite
 *
 * return: devuelve un puntero al cliente creado
 */
Cliente *formularioCliente(Cliente *cliente);

/**
 * recuperarCliente() - levanta la informacion de un cliente del archivo.
 * @archivo: archivo que sera leido.
 * Método para recuperar la informacion de un cliente del archivo especificado.
 *
 * return: devuelve un puntero al cliente recuperado del archivo.
 */
Cliente *recuperarCliente(FILE *archivo);

/**
 * guardarCliente() - guarda la informacion de un cliente en el archivo.
 * @archivo: archivo que sera escrito.
 * Método para guardar la informacion de un cliente en el archivo especificado.
 */
void guardarCliente(Cliente *cliente, FILE *archivo);

/**
 * esposibleOtroCredito() - dice si es posible crear otro credito.
 * @cliente: cliente del cual se desea saber si puede sacar otro credito
 * Método para chequear si el cliente alcanzo su maximo de creditos disponibles
 *
 * return: devuelve un entero que indicara si hay espacio para un nuevo credito
 */
int esposibleOtroCredito(Cliente *cliente);

/**
 * crearCreditoCliente() - crea un credito para un cliente.
 * @cliente: cliente que obtendra el credito.
 * @fecha: fecha de inicio del credito.
 * @monto: deuda a pagar del credito.
 * Método para crear un nuevo credito en el cliente especificado en el cual ya se chequeo que tiene un
 * credito disponible.
 * return: devuelve un puntero del credito creado
 */
Credito *crearCreditoCliente(Cliente *cliente, int fecha, int monto);

/**
 * borrarCreditoCliente() - borra un credito de un cliente.
 * @cliente: dueño del credito que sera borrado
 * @credito: credito que sera borrado.
 * Método para cancelar un credito de un cliente especificado en el parametro, que deja
 * un credito disponible para que pueda realizar el cliente.
 */
void borrarCreditoCliente(Cliente *cliente, Credito *credito);

#endif //__CLIENTE__
