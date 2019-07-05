#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "aplicacion.h"

int compararIndice(void *clave1, void *clave2)
{
    return (int) clave1 - (int) clave2;
}
void altaCliente()
{
    int posicionArchivo;
    Cliente *nuevoCliente = crearCliente();
}

int main(){
    char *opciones[] = {"Alta de Cliente",
                        "Buscar Clientes",
                        "Listar Clientes",
                        "Alta de Crédito",
                        "Listar Créditos",
                        "Operar Crédito",
                        "Cancelar credito",
                        "Salir."};
    int i;
    Aplicacion *app = malloc(sizeof(Aplicacion));
    /** case1 Alta cliente **/
    Cliente *nuevo =  malloc(sizeof(Cliente));
    nuevo = formularioCliente(nuevo);
    while(&app->nuevos[i] != 0){
        i= i+1;
    }
    app->nuevos[i] = *nuevo;
    app->indices = agregarClaveIndice(app->indices, (void*) app->nuevos[i].nombre , &compararIndice);
    app->indices = agregarClaveIndice(app->indices, (void*) app->nuevos[i].edad , &compararIndice);

    //asumiendo que se guardan los vivos al final/exit

}

