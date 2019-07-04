#ifndef __CREDITO__
#define __CREDITO__

/*El struct Credito contiene informacion sobre la fecha de creacion y la deuda de un credito*/
typedef struct {
    int saldo;
    int fecha;

} Credito;

/*Se resta de la deuda del credito ingresado por parametro la cantidad indicada por el monto
si este no es superior a la deuda, si la deuda llega a 0 se borra el credito*/
void pagarCredito(Credito *credito,int monto);

/*Imprime en pantalla la informacion sobre el credito especificado por parametro*/
void mostrarCredito(Credito *credito);

/*Pide por consola los datos para crear un credito y devuelve un puntero hacia el*/
Credito *formularioCredito(Credito *credito);

/*Funcion para saber si un credito esta disponible para ser usado*/
int esNuloCredito(Credito *credito);

/*Establece la fecha y la deuda de un credito en 0, es decir el credito esta disponible para que un cliente lo use*/
void borrarCredito(Credito *credito);

#endif //__CREDITO__
