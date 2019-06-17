#ifndef __CLIENTE__
#define __CLIENTE__
#include "credito.h"

typedef struct {
    int edad;
    int dni;
    char nombre[15];
    char apellido[15];
    char inicial;
    int referencia;
} Cliente;

Cliente *crearCliente(Cliente *cliente);
void mostrarCliente(Cliente *cliente);
Cliente *formularioCliente(Cliente *cliente);
Cliente *recuperarCliente(Cliente *cliente);
void guardarCliente(Cliente *cliente);
void borrarCliente(Cliente *cliente);
int esposibleOtroCredito(Cliente *cliente);
Credito *crearCreditoCliente(Cliente *cliente);
void borrarCreditoCliente(Cliente *cliente, Credito *credito);//Aca deberiamos analizar si es conveniente permitir pagar parte del credito en vez de anularlo

#endif //__CLIENTE__
