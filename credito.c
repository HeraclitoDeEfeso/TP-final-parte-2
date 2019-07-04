#include <stdio.h>
#include <stdlib.h>
#include "credito.h"

void pagarCredito(Credito *credito,int monto){
    if(monto <= credito->saldo && monto > 0){
         credito->saldo = credito->saldo - monto;
    }
    //modificar File
}

void borrarCredito(Credito *credito){
    credito->saldo = 0;
    credito->fecha = 0;
    //modificar File
}

void mostrarCredito(Credito *credito){
}

Credito *formularioCredito(Credito *credito){
return 0;
}

int esNuloCredito(Credito *credito){
    return(credito->fecha == 0 && credito->saldo == 0);
}
