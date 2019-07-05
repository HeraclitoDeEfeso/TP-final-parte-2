#include "aplicacion.h"
#include "cliente.h"
#include "indice.h"
#include "claves.h"

void altaCliente()
{
    FILE *base; // suponemos que est� abierta para escribir
    int posicionArchivo; // suponemos que est� seteado
    Indice *indice; // suponemos que es el correcto
    Cliente *nuevoCliente = crearCliente();
    formularioCliente(nuevoCliente);
    guardarCliente(nuevoCliente, base);
    agregarClaveIndice(indice, crearClave(nuevoCliente, posicionArchivo), &compararClave);
}

int main(){}
