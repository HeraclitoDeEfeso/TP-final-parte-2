#ifndef __CLIENTE__
#define __CLIENTE__

#include <stdio.h>
#include "credito.h"
#define MAX_CREDITOS 3

typedef struct {
    int edad;
    int dni;
    char nombre[15];
    char apellido[15];
    char inicial;
    int referencia;
    Credito *creditos[MAX_CREDITOS];
} Cliente;

Cliente *crearCliente(int edad, int dni, char nombre[15],char apellido[15],char inicial,int referencia);
void mostrarCliente(Cliente *cliente);
Cliente *formularioCliente(Cliente *cliente);
Cliente *recuperarCliente(FILE *archivo);
void guardarCliente(Cliente *cliente, FILE *archivo);
void borrarCliente(Cliente *cliente);
int esposibleOtroCredito(Cliente *cliente);
Credito *crearCreditoCliente(Cliente *cliente, int fecha, int monto);
void borrarCreditoCliente(Cliente *cliente, Credito *credito);//Aca deberiamos analizar si es conveniente permitir pagar parte del credito en vez de anularlo

#endif //__CLIENTE__
