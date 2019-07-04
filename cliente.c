#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente *crearCliente(int edad, int dni, char nombre[15], char apellido[15], int referencia) {
    Cliente *cliente = malloc(sizeof(Cliente));
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
        Credito credito;
        cliente->creditos[i] = credito;
        cliente->creditos[i].fecha = 0;
        cliente->creditos[i].saldo = 0;
    }
    return cliente;
}

void mostrarCliente(Cliente *cliente){
    printf("\nNombre del cliente: %s %s\nDocumento: %i\nEdad: %i\nReferencia: %i",
           cliente->nombre,cliente->apellido, cliente->dni, cliente->edad,cliente->referencia);
    //printf("CREDITOS")
}

Cliente *formularioCliente(Cliente *cliente){
    int edad;
    int dni;
    char nombre[15];
    char apellido[15];
    int referencia;
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
    cliente = crearCliente(edad, dni, nombre, apellido, referencia);
    return cliente;
}

Cliente *recuperarCliente(FILE *archivo){
    Cliente *cliente = malloc(sizeof(Cliente));
    if(archivo){
        fread(cliente,sizeof(Cliente),1,archivo);
    }
    else printf("el archivo no es valido");
    return cliente;
}

void guardarCliente(Cliente *cliente, FILE *archivo){
    if(archivo){
        fwrite(cliente,sizeof(Cliente),1,archivo);
    }
    else printf("el archivo no es valido");
}

int esposibleOtroCredito(Cliente *cliente){
    return esNuloCredito(&(cliente->creditos[MAX_CREDITOS -1]));
}

Credito *crearCreditoCliente(Cliente *cliente, int fecha, int monto){
    int i = 0;
    int sigo = 1;
    Credito *credito = malloc(sizeof(Credito));
    credito->fecha = fecha;
    credito->saldo = monto;
    while(sigo){
        if(esNuloCredito(&(cliente->creditos[i]))){
            cliente->creditos[i] = *credito;
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
        if(cliente->creditos[i].fecha == credito->fecha && cliente->creditos[i].saldo == credito->saldo){
            borrarCredito(&(cliente->creditos[i]));
        }
    }
}
