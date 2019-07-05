#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

Menu crearMenu(char *titulo, char **opciones, int dimension) {
    Menu menu = malloc(sizeof *menu);
    menu->titulo = titulo;
    menu->opciones = opciones;
    menu->dimension = dimension;
    return menu;
}

int activarMenu(Menu menu){
    int i;
    printf("\n%s.\n", menu->titulo);
    for(i = 0; i < menu->dimension; i++){
        printf("%d. %s\n", i+1, menu->opciones[i]);
    }
    do {
        printf("\nElija su opcion [1-%i]: ", menu->dimension);
        if (scanf("%d", &i) < 1) while (fgetc(stdin) != '\n');
    } while (i < 1 || i > menu->dimension);
    return i;
}
