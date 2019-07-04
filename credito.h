#ifndef __CREDITO__
#define __CREDITO__

typedef struct {
    int saldo;
    int fecha;

} Credito;

/*Si el pago es mayor que el saldo a pagar no se recibe el pago*/
void pagarCredito(Credito credito,int monto);
void mostrarCredito(Credito credito);
Credito *formularioCredito(Credito credito);
int esNuloCredito(Credito credito);

#endif //__CREDITO__
