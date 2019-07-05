#include <stdlib.h>
#include "aplicacion.h"
#include "cliente.h"
#include "indice.h"
#include "claves.h"
#include "menu/menu.h"

int main()
{
    char *opcionesCliente[] = {"Dar de alta un Cliente.",
                               "Listar Clientes por Nombre.",
                               "Listar Clientes por Edad.",
                               "Operar Credito de Cliente.",
                               "Salir."};
    Menu *menuClientes = crearMenu("Operaciones disponibles con Clientes", opcionesCliente, 5);
    int opcion = 0;
    Indice *indice = cargarIndice();
    Comparador comparadorClave = &compararClave;
    printf("Bienvenidos a la Base de Clientes.\n");
    while (opcion != 5) {
        switch (opcion = activarMenu(menuClientes)) {
        case 1:
            printf("Indice: %p\n", indice);
            altaCliente(&indice, comparadorClave);
            printf("Indice: %p\n", indice);
            break;
        case 2:
            printf("Indice: %p\n", indice);
            listarClientes(indice);
            break;
        case 3:
            listarClientes(indice);
            break;
        case 4:
            operarCredito(seleccionarCliente(indice, comparadorClave));
            break;
        case 5:
            persistirIndice(indice, &persistirClave, fopen("indice.bin", "wb"));
        }
    }
    return 0;
}

void altaCliente(Indice **indice, Comparador comparadorClave)
{
    FILE* base;
    int posicionArchivo;
    base = fopen(ARCHIVO_BASE, "ab");
    fseek(base, 0, SEEK_END);
    posicionArchivo = ftell(base);
    Cliente *nuevoCliente = formularioCliente(crearCliente());
    guardarCliente(nuevoCliente, base);
    *indice = agregarClaveIndice(*indice, crearClave(nuevoCliente, posicionArchivo), comparadorClave);
    free(nuevoCliente);
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
    int i = 0;
    mostrarCliente(cliente);
    for (; i < MAX_CREDITOS; i++) {
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

void listarClientes(Indice *vista)
{
    FILE* base = fopen(ARCHIVO_BASE, "rb");
    Iterador *iterador = obtenerIterador(vista);
    Clave *clave;
    Cliente *cliente = NULL;
    while (NULL != iterador) {
        clave = (Clave*) siguienteIterador(&iterador);
        fseek(base, clave->posicion, SEEK_SET);
        cliente = recuperarCliente(base);
        mostrarCliente(cliente);
        free(cliente);
    }
}

enum OperacionesCredito seleccionarOperacion(Credito *credito)
{
    char *operaciones[] = {"Pagar Credito.",
                           "Cancelar Credito.",
                           "Salir."};
    enum OperacionesCredito seleccion[] = {PAGAR_CREDITO, CANCELAR_CREDITO, NO_OPERAR};
    Menu *menuOperacion = crearMenu("Operaciones disponibles", operaciones, 3);
    return seleccion[activarMenu(menuOperacion) - 1];
}

int formularioMonto(Credito *credito)
{
    int monto;
    do {
        printf("\nIngrese el monto a pagar [0-%i]: ", credito->saldo);
        if (scanf("%d", &monto) < 1) while (fgetc(stdin) != '\n');
    } while (monto < 0 || monto > credito->saldo);
    return monto;
}

int seleccionarCredito(Credito *creditos)
{
    int credito;
    do {
        printf("\nIngrese el credito con el que va operar [1-3]: ");
        if (scanf("%d", &credito) < 1) while (fgetc(stdin) != '\n');
    } while (credito < 1 || credito > 3 || esNuloCredito(&creditos[credito - 1]));
    return credito;
}

Cliente *seleccionarCliente(Indice *indice, Comparador funcion)
{
    FILE* base = fopen(ARCHIVO_BASE, "rb");
    Clave *clave = formularioClave();
    clave = (Clave*) buscarClaveIndice(indice, clave, funcion);
    fseek(base, clave->posicion, SEEK_SET);
    return recuperarCliente(base);
}

Indice *cargarIndice()
{
    FILE *archivoIndice = NULL;
    Indice *indice = NULL;
    archivoIndice = fopen("indice.bin", "rb");
    if (archivoIndice) {
        indice = recuperarIndice(&recuperarClave, archivoIndice);
    }
    fclose(archivoIndice);
    return indice;
}
