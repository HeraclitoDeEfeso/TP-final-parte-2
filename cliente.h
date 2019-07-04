#ifndef __CLIENTE__
#define __CLIENTE__

#include <stdio.h>
#include "credito.h"
#define MAX_CREDITOS 3


/*El struct cliente contiene toda la informacion del cliente necesaria para la aplicacion,
 ademas contiene una cantidad de creditos variables ya que estan definidos por una constante*/

typedef struct {
    int edad;
    int dni;
    char nombre[15];
    char apellido[15];
    char inicial;
    int referencia;
    Credito creditos[MAX_CREDITOS];
} Cliente;

/*Crea un cliente con los datos ingresados por parametro y sus creditos disponibles y devuelve un puntero hacia el*/
Cliente *crearCliente(int edad, int dni, char nombre[15],char apellido[15],int referencia);

/*Imprime en pantalla la informacion del cliente*/
void mostrarCliente(Cliente *cliente);

/*Le pide al usuario que complete los datos necesarios del nuevo cliente, utilza la funcion crearCliente() para crearlo
y devuelve un puntero hacia el nuevo cliente*/
Cliente *formularioCliente();

/*Recupera la informacion de un cliente de un archivo que es ingresado por parametro, y devuelve un puntero de cliente con esa informacion*/
Cliente *recuperarCliente(FILE *archivo);

/*Guarda la informacion de un cliente en un archivo que es ingresado por parametro*/
void guardarCliente(Cliente *cliente, FILE *archivo);

/*Funcion que permite saber si un cliente ya pidio todos sus creditos disponibles o puede pedir otro*/
int esposibleOtroCredito(Cliente *cliente);

/*Crea un credito en el cliente especificado con los datos ingresados por parametros, no se debe ingresar dos creditos con los mismos datos
y debe haber creditos desiponibles para ser usados, devuelve un puntero al credito otorgado*/
Credito *crearCreditoCliente(Cliente *cliente, int fecha, int monto);

/*Borra los datos del credito del cliente especificado por parametros*/
void borrarCreditoCliente(Cliente *cliente, Credito *credito);

#endif //__CLIENTE__
