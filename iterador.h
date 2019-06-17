#ifndef __INDICE__
#define __INDICE__
#include "indice.h"

typedef struct {
    int ID;
} Iterador;

Iterador crearIterador(Iterador iter);
Iterador siguienteIterador(Iterador iter);
void borrarIterador(Iterador iter);

#endif //__INDICE__
