#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente *crearCliente(int edad, int dni, char nombre[15],char apellido[15],char inicial,int referencia) {
    Cliente *cliente;
    cliente->edad = edad;
    cliente->dni = dni;
    memcpy(cliente->nombre, nombre,15);
    memcpy(cliente->apellido, apellido,15);
    cliente->inicial = inicial;
    cliente->referencia = referencia;
    int i;
//    for(i = 0; i < MAX_CREDITOS; i++){
//        Credito *credito;
//        cliente->creditos[i] = credito;
//        cliente->creditos[i]->fecha = 0;
//        cliente->creditos[i]->saldo = 0;
//    }
    return cliente;
}

void mostrarCliente(Cliente *cliente){
}

Cliente *formularioCliente(Cliente *cliente){
    return cliente;
}

Cliente *recuperarCliente(FILE *archivo){
    return 0;
}

void guardarCliente(Cliente *cliente, FILE *archivo){
}

void borrarCliente(Cliente *cliente){
    free(cliente);
}

int esposibleOtroCredito(Cliente *cliente){
    return 0; //esNuloCredito(cliente->creditos[MAX_CREDITOS -1]);
}

Credito *crearCreditoCliente(Cliente *cliente, int fecha, int monto){
    int i = 0;
    int sigo = 1;
    while(sigo && i < MAX_CREDITOS){
//        if(esNuloCredito(cliente->creditos[i])){
//            Credito *credito;
//            credito->fecha = fecha;
//            credito->saldo = monto;
//            cliente->creditos[i] = credito;
//            sigo = 0;
//        }
//        else i++;
    }
    return 0;
}

void borrarCreditoCliente(Cliente *cliente, Credito *credito){
    int i;
    for(i=0;i < MAX_CREDITOS; i++){
        //no deberia haber dos creditos con misma fecha y saldo
//        if ((credito->fecha == cliente->creditos[i]->fecha) && credito->saldo == cliente->creditos[i]->saldo){
//            borrarCredito(cliente->creditos[i]);
//        }
    }
}
