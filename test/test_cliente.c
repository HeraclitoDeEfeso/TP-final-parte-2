#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "test_cliente.h"
#include "../cliente.h"

void test_crear_cliente_con_creditos_nulos()
{
    Cliente *miCliente = crearCliente();
    int i;
    for(i = 0; i < MAX_CREDITOS; i++)
        assert(esNuloCredito(&(miCliente->creditos[i])));
}

void test_es_posible_credito_de_cliente_nuevo()
{
    Cliente *miCliente = crearCliente();
    assert(esposibleOtroCredito(miCliente));
}

void test_no_es_posible_credito_despues_del_maximo()
{
    Cliente *miCliente = crearCliente();
    Credito *miCredito;
    int i;
    for (i = 0; i < MAX_CREDITOS; i++) {
        miCredito = crearCreditoCliente(miCliente);
        miCredito->fecha = 2010;
        miCredito->saldo = 200;
    }
    assert(!esposibleOtroCredito(miCliente));
}

void test_borrar_credito()
{
    Cliente *miCliente = crearCliente();
    Credito *unCredito;
    int i;
    for (i = 0; i < MAX_CREDITOS; i++) {
        unCredito = crearCreditoCliente(miCliente);
        unCredito->fecha = 2010;
        unCredito->saldo = 200;
    }
    assert(!esposibleOtroCredito(miCliente));
    borrarCreditoCliente(miCliente, unCredito);
    assert(esposibleOtroCredito(miCliente));
}

void test_no_es_posible_borrar_credito_que_no_tengo()
{
    Cliente *miCliente = crearCliente();
    Cliente *otroCliente = crearCliente();
    Credito *unCredito;
    int i;
    for (i = 0; i < MAX_CREDITOS; i++) {
        unCredito = crearCreditoCliente(miCliente);
        unCredito->fecha = 2010;
        unCredito->saldo = 200;
        unCredito = crearCreditoCliente(otroCliente);
        unCredito->fecha = 2010;
        unCredito->saldo = 200;
    }
    borrarCreditoCliente(miCliente, unCredito);
    assert(!esposibleOtroCredito(miCliente));
}

void test_guardar_recuperar_cliente()
{
    FILE *archivo = fopen("test_guardar_recuperar.bin", "w");
    Cliente miCliente = { 22, 40111222, "Ernesto", "Pascuale", 0};
    Cliente *clienteRecuperado;
    int i;
    guardarCliente(&miCliente, archivo);
    fclose(archivo);
    archivo = fopen("test_guardar_recuperar.bin", "r");
    clienteRecuperado = recuperarCliente(archivo);
    fclose(archivo);
    assert(strcmp(clienteRecuperado->apellido, miCliente.apellido) == 0);
    for(i = 0; i < MAX_CREDITOS; i++)
        assert(clienteRecuperado->creditos[i].fecha == miCliente.creditos[i].fecha
               && clienteRecuperado->creditos[i].saldo == miCliente.creditos[i].saldo);
    assert(clienteRecuperado->dni == miCliente.dni);
    assert(clienteRecuperado->edad == miCliente.edad);
    assert(clienteRecuperado->inicial == miCliente.inicial);
    assert(strcmp(clienteRecuperado->nombre, miCliente.nombre) == 0);
    assert(clienteRecuperado->referencia == miCliente.referencia);
}

void test_cliente()
{
    test_crear_cliente_con_creditos_nulos();
    test_guardar_recuperar_cliente();
    test_es_posible_credito_de_cliente_nuevo();
    test_no_es_posible_credito_despues_del_maximo();
    test_borrar_credito();
    test_no_es_posible_borrar_credito_que_no_tengo();
}
