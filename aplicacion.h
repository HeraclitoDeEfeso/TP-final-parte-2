
#ifndef __APLICACION__
#define __APLICACION__
#include "cliente.h"
#include "credito.h"
#include "iterador.h"
#include "indice.h"
#include "aplicacion.h"
//include de los paquetes Avl y menu

typedef struct {
	//FILE base;
	Cliente nuevos[0];
	Indice indices[0];
	int persistidos;
	int siguienteID;
} Aplicacion;

int seleccionarCredito(Credito credito[]);
int seleccionarOperacion(Credito *credito);
int formularioMonto(Credito *credito);
int formularioClaves(enum clave, char minimo[], char maximo[] );

#endif //__APLICACION__
