#ifndef __APLICACION__
#define __APLICACION__
#include <stdio.h>
#include "credito.h"
#include "cliente.h"
#include "indice.h"
#define ARCHIVO_BASE "base.bin"

enum OperacionesCredito {PAGAR_CREDITO, CANCELAR_CREDITO, NO_OPERAR};

enum OperacionesCredito seleccionarOperacion(Credito *credito);

int formularioMonto(Credito *credito);

int seleccionarCredito(Credito *creditos);

void operarCredito(Cliente *cliente);

void listarCreditos(Cliente *cliente);

void altaCredito(Cliente *cliente);

void altaCliente(Indice **indice, Comparador comparadorClave);

void listarClientes(Indice *vista);

Cliente *seleccionarCliente(Indice *indice, Comparador funcion);

Indice *cargarIndice();

#endif //__APLICACION__
