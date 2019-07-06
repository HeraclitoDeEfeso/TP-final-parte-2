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
void listarAtributosCredito() {
    printf("\n  Fecha    |  Saldo    \n"
             "-----------+-----------\n");
}

void borrarCredito(Credito *credito){
    credito->saldo = 0;
    credito->fecha = 0;
}

void mostrarCredito(Credito *credito){
    printf("%10i | %9i\n",
           credito->fecha, credito->saldo);
}

void formularioCredito(Credito *credito) {
    int monto = 0;
    int fecha = 0;
    printf("\nIngrese los datos del Credito \n");
    printf("Fecha del Credito: ");
    scanf("%i", &fecha);
    printf("Monto del Credito: ");
    scanf("%i", &monto);
    credito->fecha = fecha;
    credito->saldo = monto;
    if (monto < 0 ) {
        printf("El monto del Credito no es valido. Reintente.\n");
        formularioCredito(credito);
    } else if (fecha == 0 ) {
        printf("La fecha del Credito no es valida. Reintente.\n");
        formularioCredito(credito);
    }
}

int esNuloCredito(Credito *credito){
    return(credito->fecha == 0 && credito->saldo == 0);
}
