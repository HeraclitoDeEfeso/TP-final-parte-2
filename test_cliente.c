#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test_cliente.h"

void test_cliente()
{
    test_crear_cliente_con_creditos_nulos();
    test_guardar_recuperar_cliente();
    test_es_posible_credito_de_cliente_nuevo();
    test_no_es_posible_credito_despues_de_tres();
    test_borrar_credito();
    test_no_es_posible_borrar_credito_ajeno();
}

void test_crear_cliente_con_creditos_nulos()
{
    Cliente *miCliente = crearCliente();
    int i;
    for(i = 0; i < MAX_CREDITOS; i++)
        assert(esNuloCredito(&(miCliente->creditos[i])));
}

void test_guardar_recuperar_cliente()
{
    FILE *archivo = fopen("test_guardar_recuperar.bin", "w");
    Cliente *miCliente = crearCliente();
    miCliente->dni = 26803512;
    guardarCliente(miCliente, archivo);
    fclose(archivo);
    free(miCliente);
    archivo = fopen("test_guardar_recuperar.bin", "r");
    miCliente = recuperarCliente(archivo);
    fclose(archivo);
    assert(miCliente->dni == 26803512);
}

void test_es_posible_credito_de_cliente_nuevo(){};
void test_no_es_posible_credito_despues_de_tres(){};
void test_borrar_credito(){};
void test_no_es_posible_borrar_credito_ajeno(){};
