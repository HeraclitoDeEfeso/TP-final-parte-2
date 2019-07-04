#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente *crearCliente(int edad, int dni, char nombre[15], char apellido[15], int referencia) {
    Cliente *cliente;
    cliente->edad = edad;
    cliente->dni = dni;
    strncpy(cliente->nombre, nombre, 15);
    cliente->nombre[15] = '\0';
    strncpy(cliente->apellido, apellido, 15);
    cliente->apellido[15] = '\0';
    cliente->inicial = nombre[0];
    cliente->referencia = referencia;
    int i;
    for(i = 0; i < MAX_CREDITOS; i++){
        Credito *credito;
        cliente->creditos[i] = credito;
        cliente->creditos[i]->fecha = 0;
        cliente->creditos[i]->saldo = 0;
    }
    return cliente;
}

void mostrarCliente(Cliente *cliente){
    printf("\nNombre del cliente: %s+" "+%s\nDocumento: %i\nEdad: %i\nReferencia: %i",
           cliente->nombre,cliente->apellido, cliente->dni, cliente->edad,cliente->referencia);
}

Cliente *formularioCliente(Cliente *cliente){
    int edad;
    int dni;
    char nombre[15];
    char apellido[15];
    char inicial;
    int referencia;
    //--------------------------------
    //se deberian testear los datos ingresados para ver si son correctos
    printf("Edad del cliente: ");
    scanf("%i", &edad);
    printf("dni : ");
    scanf("%i", &dni);
    printf("Nombre: ");
    scanf("%s", &nombre);
    printf("Apellido: ");
    scanf("%s", &apellido);
    printf("Referencia : ");
    scanf("%i", &referencia);
    return cliente;
}

Cliente *recuperarCliente(FILE *archivo){
    return 0;
}

void guardarCliente(Cliente *cliente, FILE *archivo){
}

void borrarCliente(Cliente *cliente){
//---------------------------
// borrar del File y el arbol?
}

int esposibleOtroCredito(Cliente *cliente){
    return esNuloCredito(cliente->creditos[MAX_CREDITOS -1]);
}

Credito *crearCreditoCliente(Cliente *cliente, int fecha, int monto){
    int i = 0;
    int sigo = 1;
    Credito *credito;
    while(sigo && i < MAX_CREDITOS){
        if(esNuloCredito(cliente->creditos[i])){
            credito->fecha = fecha;
            credito->saldo = monto;
            cliente->creditos[i] = credito;
            sigo = 0;
        }
        else i++;
    }
    return credito;
}

void borrarCreditoCliente(Cliente *cliente, Credito *credito){
    int i;
    for(i=0;i < MAX_CREDITOS; i++){
        //no deberia haber dos creditos con misma fecha y saldo
       if ((credito->fecha == cliente->creditos[i]->fecha) && credito->saldo == cliente->creditos[i]->saldo){
            borrarCredito(cliente->creditos[i]);
        }
    }
}
