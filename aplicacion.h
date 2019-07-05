
#ifndef __APLICACION__
#define __APLICACION__
#include "cliente.h"
#include "credito.h"
#include "indice.h"
#include "aplicacion.h"
#define CLIENTES_NUEVOS 20
//include de los paquetes Avl y menu

typedef struct {
	FILE base;
	Cliente nuevos[CLIENTES_NUEVOS];
	Indice *indices;
	int persistidos;
	int siguienteID;
} Aplicacion;

int seleccionarCredito(Credito credito[]);
int seleccionarOperacion(Credito *credito);
int formularioMonto(Credito *credito);
int formularioClaves(enum clave, char minimo[], char maximo[] );

#endif //__APLICACION__
