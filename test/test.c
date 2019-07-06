#include "test_credito.h"
#include "test_cliente.h"
#include "test_indice.h"
#include "../avl/test_avl.h"

int main()
{
    test_avl();
    test_indice();
    test_credito();
    test_cliente();
    return 0;
}
