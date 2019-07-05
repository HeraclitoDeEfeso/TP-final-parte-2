#include <stdlib.h>
#include "aplicacion.h"
#include "cliente.h"
#include "indice.h"
#include "claves.h"
#include "menu/menu.h"

void altaCliente(FILE *base, int posicionArchivo, Indice *indice, Comparador comparadorClave)
{
    Cliente *nuevoCliente = crearCliente();
    guardarCliente(nuevoCliente, base);
    agregarClaveIndice(indice, crearClave(nuevoCliente, posicionArchivo), comparadorClave);
}

void altaCredito(Cliente *cliente)
{
    if (esposibleOtroCredito(cliente)) {
            Credito *nuevoCredito = malloc(sizeof(Credito));
            nuevoCredito = formularioCredito(nuevoCredito);
            crearCreditoCliente(cliente, nuevoCredito->fecha, nuevoCredito->saldo);
    }
}

void listarCreditos(Cliente *cliente)
{
    Credito *creditos = cliente->creditos;
    mostrarCliente(cliente);
    int i;
    for (i = 0; i < MAX_CREDITOS; i++) {
        mostrarCredito(creditos + i);
    }
}

void operarCredito(Cliente *cliente)
{
    Credito *creditos = cliente->creditos;
    Credito *credito;
    int creditoSeleccionado;
    int montoPago;
    enum OperacionesCredito operacionSeleccionada;
    listarCreditos(cliente);
    creditoSeleccionado = seleccionarCredito(creditos);
    credito = &creditos[creditoSeleccionado];
    operacionSeleccionada = seleccionarOperacion(credito);
    switch (operacionSeleccionada) {
    case PAGAR_CREDITO:
        montoPago = formularioMonto(credito);
        pagarCredito(credito, montoPago);
        break;
    case CANCELAR_CREDITO:
        borrarCreditoCliente(cliente, credito);
    case NO_OPERAR:
        break;
    }
}

enum OperacionesCredito seleccionarOperacion(Credito *credito)
{
    char *operaciones[] = {"Pagar Credito.",
                           "Cancelar Credito.",
                           "Salir."};
    enum OperacionesCredito seleccion[] = {PAGAR_CREDITO, CANCELAR_CREDITO, NO_OPERAR};
    Menu menuOperacion = crearMenu("Operaciones disponibles", operaciones, 3);
    return seleccion[activarMenu(menuOperacion) - 1];
}

int formularioMonto(Credito *credito){return 0;}

int seleccionarCredito(Credito *creditos){return 0;}

int main()
{
    return 0;
}
