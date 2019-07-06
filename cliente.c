#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente *crearCliente()
{
    return (Cliente *) calloc(sizeof(Cliente), 1);
}

void listarAtributosCliente() {
    printf("\n       Nombre y apellido        | Edad | DNI      | Referencia\n"
             "--------------------------------+------+----------+-----------\n");
}
void mostrarCliente(Cliente *cliente){
        printf("%15.15s %-15.15s | %4i | %8i | %7i\n",
           cliente->nombre,cliente->apellido,
           cliente->edad,
           cliente->dni,
           cliente->referencia);
}

Cliente *formularioCliente(Cliente *cliente){
    printf("\nIngrese los datos del Cliente\n");
    printf("Edad del cliente: ");
    scanf("%i", &(cliente->edad));
    printf("             DNI: ");
    scanf("%i", &(cliente->dni));
    printf("          Nombre: ");
    scanf("%s", cliente->nombre);
    printf("        Apellido: ");
    scanf("%s", cliente->apellido);
    printf("      Referencia: ");
    scanf("%i", &(cliente->referencia));
    return cliente;
}

Cliente *recuperarCliente(FILE *archivo){
    Cliente *cliente = malloc(sizeof(Cliente));
    if(archivo){
        fread(cliente,sizeof(Cliente),1,archivo);
    }
    else printf("el archivo no es valido");
    return cliente;
}

void guardarCliente(Cliente *cliente, FILE *archivo){
    if(archivo){
        fwrite(cliente, sizeof(Cliente), 1, archivo);
    }
    else printf("el archivo no es valido");
}

int esposibleOtroCredito(Cliente *cliente){
    return esNuloCredito(&(cliente->creditos[MAX_CREDITOS -1]));
}

Credito *crearCreditoCliente(Cliente *cliente)
{
    Credito *credito = NULL;
    int i = 0;
    for (; i < MAX_CREDITOS && credito == NULL; i++) {
        if (esNuloCredito(cliente->creditos + i)) {
            credito = cliente->creditos + i;
        }
    }
    return credito;
}

void borrarCreditoCliente(Cliente *cliente, Credito *credito){
    int i = 0;
    for(; i < MAX_CREDITOS; i++) {
        if (cliente->creditos + i == credito) {
            memmove(credito, credito + 1, (2 - i) * sizeof(Credito));
            borrarCredito(cliente->creditos + (MAX_CREDITOS - 1));
        }
    }
}
