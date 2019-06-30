#ifndef __INDICE__
#define __INDICE__
#include "iterador.h"
//include del paquete Avl

typedef struct {
    int avl; //agregar un avl
}Indice;

Indice *obtenerVistaIndice(Indice *indice,char minimo[], char maximo[]);
void agregarClaveIndice(Indice *indice, char clave[],int  posicion);
void borrarClaveIndice(Indice *indice, char clave[] );
struct Iterador obtenerIterador(Indice *indice);

#endif //__INDICE__
