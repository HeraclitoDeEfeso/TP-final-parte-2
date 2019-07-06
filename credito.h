#ifndef __CREDITO__
#define __CREDITO__

/**
 * typedef Credito:
 *
 * Este tipo será utilizado para manejar las operaciones sobre los creditos de los clientes
 */
typedef struct {
    int saldo;
    int fecha;

} Credito;

/**
 * pagarCredito() - Paga parte o totalidad de un credito.
 * @credito:Credito del cual se descontara la cantidad deseada
 * @monto: Cantidad que se descontara de la deuda, que debe ser inferior o igual a la cantidad que se debe pagar
 *
 * Método para descontar cierto monto de la deuda en un credito especifico.
 * si el monto es igual a la cantidad adeudada en dicho credito, el credito se cancela y el cliente podra pedir otro credito
 */
void pagarCredito(Credito *credito,int monto);

/**
 * mostrarCredito() - Muestra en Pantalla un credito.
 * @credito:Credito que sera mostrado
 *
 * Método para imprimir en pantalla la informacion reelevante de un credito especifico
 */
void mostrarCredito(Credito *credito);

/**
 * formularioCredito() - Modifica los valores de un credito.
 * @credito: Credito que sera modificado
 *
 * Método para modificar un credito con la informacion
 * que proporcionara el usuario desde la consola.
 */
void formularioCredito(Credito *credito);

/**
 * esNuloCredito() - Dice si un credito esta disponible.
 * @credito:Credito que se desea saber si esta en uso
 *
 * Método que devuelve 0 en el caso de que este en uso el credito especificado.
 *
 * Return: devuelve un entero que indica si verdaderos o falso segun el estado del credito.
 */
int esNuloCredito(Credito *credito);

/**
 * borrarCredito() - Borra un credito.
 * @credito:Credito que se desea borrar
 *
 * Establece los datos del credito en 0 lo cual lo deja como disponibles si el cliente desea usarlo
 */
void borrarCredito(Credito *credito);

void listarAtributosCredito();

#endif //__CREDITO__
