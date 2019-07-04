#include <stdio.h>
#include <stdlib.h>
#include "credito.h"

void pagarCredito(Credito *credito,int monto){
    if(monto <= credito->saldo && monto > 0){
         credito->saldo = credito->saldo - monto;
         if(credito->saldo ==0){
            borrarCredito(credito);
         }
    }
}

void borrarCredito(Credito *credito){
    credito->saldo = 0;
    credito->fecha = 0;
}

void mostrarCredito(Credito *credito){
    printf("\nFecha del credito: %i\nMonto a pagar: %i\n",
           credito->fecha, credito->saldo);
}

Credito *formularioCredito(Credito *credito){
    int monto;
    int fecha;
    printf("Fecha del credito: ");
    scanf("%i", &fecha);
    printf("Monto : ");
    scanf("%i", &monto);
    credito->fecha = fecha;
    credito->saldo = monto;
    if(monto < 0 ){
        printf("el monton del credito no es valido");
        credito = formularioCredito(credito);
    }
    else if(fecha == 0 ){
        printf("la fecha del credito no es valida");
        credito = formularioCredito(credito);
    }
    return credito;
}

int esNuloCredito(Credito *credito){
    return(credito->fecha == 0 && credito->saldo == 0);
}
