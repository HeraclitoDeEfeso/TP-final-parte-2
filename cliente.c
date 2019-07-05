#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente *crearCliente()
{
    return formularioCliente((Cliente *) calloc(sizeof(Cliente), 1));
}

void mostrarCliente(Cliente *cliente){
    printf("\nNombre del cliente: %s %s\nDocumento: %i\nEdad: %i\nReferencia: %i",
           cliente->nombre,cliente->apellido, cliente->dni, cliente->edad,cliente->referencia);
    //printf("CREDITOS")
}

Cliente *formularioCliente(Cliente *cliente){
    printf("Edad del cliente: ");
    scanf("%i", &(cliente->edad));
    printf("dni : ");
    scanf("%i", &(cliente->dni));
    printf("Nombre: ");
    scanf("%s", cliente->nombre);
    printf("Apellido: ");
    scanf("%s", cliente->apellido);
    printf("Referencia : ");
    scanf("%i", &(cliente->referencia));
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

Credito *crearCreditoCliente(Cliente *cliente, Credito *credito){
    int i = 0;
    int sigo = 1;
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
