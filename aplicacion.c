#include <stdlib.h>
#include "aplicacion.h"
#include "cliente.h"
#include "indice.h"
#include "claves.h"
#include "menu/menu.h"


int main()
{
    FILE *base = NULL;
    long posicionArchivo = 0;
    FILE *archivoIndice = NULL;
    Indice *indice = NULL;
    Comparador comparadorClave = &compararClave;
    base = fopen("base.bin", "a+b"); printf("Abrio la base.\n");
    fseek(base, 0, SEEK_END); printf("Posiciono al final de la base.\n");
    posicionArchivo = ftell(base); printf("Leyo posicion final %lu .\n", posicionArchivo);
    archivoIndice = fopen("indice.bin", "rb"); printf("Abrio el indice\n");
    if (archivoIndice) {
        indice = recuperarIndice(&recuperarClave, archivoIndice); printf("Recupero el indice.\n");
    }
    fclose(archivoIndice); printf("Cerro el indice.\n");
    listarClientes(indice, base); printf("Listo clientes.\n");
    altaCliente(base, posicionArchivo, indice, comparadorClave); printf("Realizo un alta.\n");
    archivoIndice = fopen("indice.bin", "wb"); printf("Abrio el indice.\n");
    persistirIndice(indice, &persistirClave, archivoIndice); printf("Guardo el indice.\n");
    return 0;
}

void altaCliente(FILE *base, long posicionArchivo, Indice *indice, Comparador comparadorClave)
{
    Cliente *nuevoCliente = formularioCliente(crearCliente());
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

void listarClientes(Indice *vista, FILE* base)
{
    Iterador *iterador = obtenerIterador(vista);
    Clave *clave;
    Cliente *cliente = NULL;
    while (NULL != iterador) { printf("El iterador no es nulo.\n");
        clave = (Clave*) siguienteIterador(&iterador); printf("Obtuvo la clave %s %i.\n", clave->apellido, clave->edad);
        fseek(base, clave->posicion, SEEK_SET); printf("Se posiciono en la posicion %ld\n", clave->posicion);
        cliente = recuperarCliente(base); printf("Recupero el cliente");
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
    Menu menuOperacion = crearMenu("Operaciones disponibles", operaciones, 3);
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
