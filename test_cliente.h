#ifndef TEST_CLIENTE_H_INCLUDED
#define TEST_CLIENTE_H_INCLUDED

#include "cliente.h"

void test_cliente();
void test_crear_cliente_con_creditos_nulos();
void test_guardar_recuperar_cliente();
void test_es_posible_credito_de_cliente_nuevo();
void test_no_es_posible_credito_despues_de_tres();
void test_borrar_credito();
void test_no_es_posible_borrar_credito_ajeno();

#endif // TEST_CLIENTE_H_INCLUDED
