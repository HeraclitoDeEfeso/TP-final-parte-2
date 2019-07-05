#ifndef __APLICACION__
#define __APLICACION__
#include "credito.h"

enum OperacionesCredito {PAGAR_CREDITO, CANCELAR_CREDITO};

enum OperacionesCredito seleccionarOperacion(Credito *credito);

int formularioMonto(Credito *credito);

int seleccionarCredito(Credito *creditos);

#endif //__APLICACION__
