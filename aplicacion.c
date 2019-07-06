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
    Menu *menuClientes = NULL;
    int opcion = 0;
    int posicion = 0;
    Indice *indiceNombre = cargarIndiceNombre();
    Indice *indiceEdad = cargarIndiceEdad();
    Indice *vistaMenor = NULL;
    Indice *vistaMayor = NULL;
    Cliente *cliente = NULL;
    void *clave = NULL;
    menuClientes = crearMenu("Operaciones con Clientes", opcionesCliente, 5);
    printf("Bienvenidos a la Base de Clientes.\n");
    while (opcion != 5) {
        switch (opcion = activarMenu(menuClientes)) {
        case 1:
            cliente = altaCliente(&posicion);
            indiceNombre = agregarClaveIndice(
                                indiceNombre,
                                crearClaveNombreDNI(cliente, posicion),
                                &compararClaveNombreDNI);
            indiceEdad = agregarClaveIndice(
                                indiceEdad,
                                crearClaveEdadDNI(cliente, posicion),
                                &compararClaveEdadDNI);
            free(cliente);
            break;
        case 2:
            printf("\nLimite superior del listado\n");
            formularioClaveNombreDNI(&clave);
            vistaMenor = obtenerVistaMenorIndice(
                            indiceNombre,
                            clave,
                            &compararClaveNombreDNI);
            printf("\nLimite inferior del listado\n");
            formularioClaveNombreDNI(&clave);
            vistaMayor = obtenerVistaMayorIndice(
                            vistaMenor,
                            clave,
                            &compararClaveNombreDNI);
            listarClientes(vistaMayor, &obtenerPosicionClaveNombreDNI);
            liberarVistaMayor(vistaMayor);
            liberarVistaMenor(vistaMenor);
            break;
        case 3:
            printf("\nLimite superior del listado\n");
            formularioClaveEdadDNI(&clave);
            vistaMenor = obtenerVistaMenorIndice(
                            indiceEdad,
                            clave,
                            &compararClaveEdadDNI);
            printf("\nLimite inferior del listado\n");
            formularioClaveEdadDNI(&clave);
            vistaMayor = obtenerVistaMayorIndice(
                            vistaMenor,
                            clave,
                            &compararClaveEdadDNI);
            listarClientes(vistaMayor, &obtenerPosicionClaveEdadDNI);
            liberarVistaMayor(vistaMayor);
            liberarVistaMenor(vistaMenor);
            break;
        case 4:
            cliente = seleccionarCliente(indiceNombre, &posicion);
            if (cliente)
                operarCredito(cliente, posicion);
            else
                printf("\nNo existe Cliente con esos Datos\n");
            break;
        case 5:
            persistirIndice(indiceNombre,
                            &persistirClaveNombreDNI,
                            fopen("nombre.bin", "wb"));
            persistirIndice(indiceEdad,
                            &persistirClaveEdadDNI,
                            fopen("edad.bin", "wb"));
        }
    }
    return 0;
}

Cliente *altaCliente(int *posicionArchivo)
{
    Cliente *nuevoCliente = formularioCliente(crearCliente());
    FILE *base = fopen(ARCHIVO_BASE, "ab");
    fseek(base, 0, SEEK_END);
    *posicionArchivo = ftell(base);
    guardarCliente(nuevoCliente, base);
    return nuevoCliente;
}

void altaCredito(Cliente *cliente)
{
    if (esposibleOtroCredito(cliente))
        formularioCredito(crearCreditoCliente(cliente));
}

void listarCreditos(Cliente *cliente)
{
    Credito *creditos = cliente->creditos;
    int i = 0;
    printf("\nCliente seleccionado:\n");
    listarAtributosCliente();
    mostrarCliente(cliente);
    printf("\nCreditos:\n");
    listarAtributosCredito();
    for (; i < MAX_CREDITOS; i++) {
        if (!esNuloCredito(creditos + i))
            mostrarCredito(creditos + i);
    }
}

void operarCredito(Cliente *cliente, int posicionArchivo)
{
    Credito *credito;
    int montoPago;
    enum OperacionesCredito operacion;
    do {
        listarCreditos(cliente);
        switch (operacion = seleccionarOperacion()) {
        case TOMAR_CREDITO:
            if (esposibleOtroCredito(cliente)) {
                formularioCredito(crearCreditoCliente(cliente));
            }
            break;
        case PAGAR_CREDITO:
            credito = seleccionarCredito(cliente->creditos);
            montoPago = formularioMonto(credito);
            pagarCredito(credito, montoPago);
            break;
        case CANCELAR_CREDITO:
            credito = seleccionarCredito(cliente->creditos);
            borrarCreditoCliente(cliente, credito);
        case NO_OPERAR:
            break;
        }
        if (operacion != NO_OPERAR) {
            actualizarCliente(cliente, posicionArchivo);
        }
    } while (operacion != NO_OPERAR);
}

void listarClientes(Indice *vista, Accesor posicion)
{
    FILE* base = fopen(ARCHIVO_BASE, "rb");
    Iterador *iterador = obtenerIterador(vista);
    Cliente *cliente = NULL;
    int lineas = 0;
    printf("\nListado de Clientes:\n");
    listarAtributosCliente();
    while (NULL != iterador) {
        if (lineas == PAGINACION) {
            printf("\n-- PRESIONE UNA TECLA PARA CONTINUAR --\n");
            getchar();
            getchar();
            lineas = 0;
        }
        fseek(base, posicion(siguienteIterador(&iterador)), SEEK_SET);
        cliente = recuperarCliente(base);
        mostrarCliente(cliente);
        lineas++;
        free(cliente);
    }
}

enum OperacionesCredito seleccionarOperacion()
{
    char *operaciones[] = {"Tomar Credito",
                           "Pagar Credito.",
                           "Cancelar Credito.",
                           "Salir."};
    enum OperacionesCredito seleccion[] = {TOMAR_CREDITO,
                                           PAGAR_CREDITO,
                                           CANCELAR_CREDITO,
                                           NO_OPERAR};
    Menu *menuOperacion = crearMenu("Operaciones de Creditos disponibles",
                                    operaciones,
                                    4);
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

Credito *seleccionarCredito(Credito *creditos)
{
    int credito;
    do {
        printf("\nIngrese el credito con el que va operar [1-3]: ");
        if (scanf("%d", &credito) < 1) while (fgetc(stdin) != '\n');
    } while (credito < 1 || credito > 3);
    return &creditos[credito - 1];
}

Cliente *seleccionarCliente(Indice *indice, int* posicion)
{
    Cliente *cliente = NULL;
    FILE* base = fopen(ARCHIVO_BASE, "rb");
    void *clave;
    formularioClaveNombreDNI(&clave);
    clave = buscarClaveIndice(indice, clave, &compararClaveNombreDNI);
    if (clave) {
        *posicion = ((ClaveNombreDNI*) clave)->posicion;
        fseek(base, *posicion, SEEK_SET);
        cliente = recuperarCliente(base);
    }
    fclose(base);
    return cliente;
}

void actualizarCliente(Cliente *cliente, long posicionArchivo)
{
    FILE* base = fopen(ARCHIVO_BASE, "r+b");
    fseek(base, posicionArchivo, SEEK_SET);
    guardarCliente(cliente, base);
    fclose(base);
}

Indice *cargarIndiceNombre()
{
    FILE *archivoIndice = NULL;
    Indice *indice = NULL;
    archivoIndice = fopen("nombre.bin", "rb");
    if (archivoIndice) {
        indice = recuperarIndice(&recuperarClaveNombreDNI, archivoIndice);
    }
    fclose(archivoIndice);
    return indice;
}

Indice *cargarIndiceEdad()
{
    FILE *archivoIndice = NULL;
    Indice *indice = NULL;
    archivoIndice = fopen("edad.bin", "rb");
    if (archivoIndice) {
        indice = recuperarIndice(&recuperarClaveEdadDNI, archivoIndice);
    }
    fclose(archivoIndice);
    return indice;
}
