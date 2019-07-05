#ifndef __APLICACION__
#define __APLICACION__
#include <stdio.h>
#include "credito.h"
#include "cliente.h"
#include "indice.h"

enum OperacionesCredito {PAGAR_CREDITO, CANCELAR_CREDITO, NO_OPERAR};

enum OperacionesCredito seleccionarOperacion(Credito *credito);

int formularioMonto(Credito *credito);

int seleccionarCredito(Credito *creditos);

void operarCredito(Cliente *cliente);

void listarCreditos(Cliente *cliente);

void altaCredito(Cliente *cliente);

void altaCliente(FILE *base, int posicionArchivo, Indice *indice, Comparador comparadorClave);

#endif //__APLICACION__
