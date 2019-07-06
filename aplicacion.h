#ifndef __APLICACION__
#define __APLICACION__
#include <stdio.h>
#include "credito.h"
#include "cliente.h"
#include "indice.h"
#include "claves.h"
#define ARCHIVO_BASE "base.bin"
#define PAGINACION 25

void operarCredito(Cliente *cliente, int posicionArchivo);

void listarCreditos(Cliente *cliente);

void altaCredito(Cliente *cliente);

Cliente *altaCliente(int *posicionArchivo);

void listarClientes(Indice *vista, Accesor posicion);

void actualizarCliente(Cliente *cliente, long posicionArchivo);

enum OperacionesCredito {TOMAR_CREDITO, PAGAR_CREDITO, CANCELAR_CREDITO, NO_OPERAR};

enum OperacionesCredito seleccionarOperacion();

Cliente *seleccionarCliente(Indice *i, int* posicion);

int formularioMonto(Credito *credito);

Credito *seleccionarCredito(Credito *creditos);

Indice *cargarIndiceEdad();

Indice *cargarIndiceNombre();

#endif //__APLICACION__
