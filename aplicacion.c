#include "aplicacion.h"
#include "cliente.h"
#include "indice.h"
#include "claves.h"

void altaCliente()
{
    FILE *base; // suponemos que está abierta para escribir
    int posicionArchivo; // suponemos que está seteado
    Indice *indice; // suponemos que es el correcto
    Cliente *nuevoCliente = crearCliente();
    guardarCliente(nuevoCliente, base);
    agregarClaveIndice(indice, crearClave(nuevoCliente, posicionArchivo), &compararClave);
}
void altaCredito()
{
    Cliente *nuevoCliente;//cliente correcto
    if(esposibleOtroCredito(nuevoCliente)){
            Credito *nuevoCredito = malloc(sizeof(Credito));
            nuevoCredito = formularioCredito(nuevoCredito);
            crearCreditoCliente(nuevoCliente, nuevoCliente);
    }
}
void listarCreditos()
{
    Cliente *nuevoCliente;//cliente correcto
    int i;
    for(i=0;i<MAX_CREDITOS;i++){
        mostrarCredito(&(nuevoCliente->creditos[i]));
    }


}
void operarCredito()
{
    Cliente *nuevoCliente;//cliente correcto
    Credito *nuevoCredito;//credito correcto
    int opcionSeleccionada;//opcion seleccionada por el usuario
    if(opcionSeleccionada == 1){
        int monto;
        printf("seleccionar monto a pagar %i", &monto);
        pagarCredito(nuevoCredito, monto);
    }
    else if(opcionSeleccionada == 2){
        borrarCreditoCliente(nuevoCliente, nuevoCredito);
    }

}

int main(){}
