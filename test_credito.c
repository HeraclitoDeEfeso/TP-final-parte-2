#include <assert.h>
#include "credito.h"

void test_credito_es_nulo()
{
    Credito credito;
    credito.saldo = 0;
    credito.fecha = 0;
    assert(esNuloCredito(&credito));
}

void test_credito_no_es_nulo()
{
    Credito credito;
    credito.saldo = 0;
    credito.fecha = 20190101;
    assert(!esNuloCredito(&credito));
}

void test_no_pagar_credito_nulo()
{
    Credito credito;
    credito.saldo = 0;
    credito.fecha = 0;
    pagarCredito(&credito, 10);
    assert(credito.saldo == 0);
}

void test_no_pagar_credito_saldado()
{
    Credito credito;
    credito.saldo = 0;
    credito.fecha = 20190101;
    pagarCredito(&credito, 10);
    assert(credito.saldo == 0);
}

void test_no_pagar_credito_demas()
{
    Credito credito;
    credito.saldo = 10;
    credito.fecha = 20190101;
    pagarCredito(&credito, 100);
    assert(credito.saldo == 10);
}

void test_pagar_credito()
{
    Credito credito;
    credito.saldo = 10;
    credito.fecha = 20190101;
    pagarCredito(&credito, 10);
    assert(credito.saldo == 0);
}

void test_credito()
{
    test_credito_es_nulo();
    test_credito_no_es_nulo();
    test_no_pagar_credito_nulo();
    test_no_pagar_credito_saldado();
    test_no_pagar_credito_demas();
    test_pagar_credito();
}

