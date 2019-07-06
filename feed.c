#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cliente.h"
#include "indice.h"
#include "claves.h"
#define ARCHIVO_BASE "base.bin"

int main()
{
    char *nombres[] = {"ALEJANDRO",
                       "BEATRIZ",
                       "CARLOS",
                       "DANIEL",
                       "EUGENIA",
                       "FRANCISCO",
                       "GASTON",
                       "HELENA",
                       "IGNACIO",
                       "JAVIER",
                       "KARINA",
                       "LAURA",
                       "MARIA",
                       "NORBERTO",
                       "MANUEL",
                       "OSCAR",
                       "PATRICIA",
                       "QUIQUE",
                       "ROBERTO",
                       "SOLEDAD",
                       "TERESA",
                       "ULISES",
                       "VERONICA",
                       "WALTER",
                       "XAVIER",
                       "YANINA",
                       "ZULEMA"};
    Cliente *cliente = NULL;
    Indice *indiceNombre = NULL;
    Indice *indiceEdad = NULL;
    FILE *base = fopen(ARCHIVO_BASE, "wb");
    int posicionArchivo;
    int i, j, k, l;
    for (i = 0; i < 24; i++) {
        for (j = 0; j < 24; j++) {
            for (k = 0; k < 99; k++) {
                for (l = 0; l < 15; l++) {
                    cliente = crearCliente();
                    strcpy(cliente->apellido, nombres[i]);
                    strcpy(cliente->nombre, nombres[j]);
                    cliente->edad = k + 1;
                    cliente->dni = (l + 1) * 1000000 + i * 10000 + j * 100 + k;
                    cliente->referencia = cliente->dni + 1;
                    posicionArchivo = ftell(base);
                    guardarCliente(cliente, base);
                    indiceNombre = agregarClaveIndice(
                        indiceNombre,
                        crearClaveNombreDNI(cliente, posicionArchivo),
                        &compararClaveNombreDNI);
                    indiceEdad = agregarClaveIndice(
                        indiceEdad,
                        crearClaveEdadDNI(cliente, posicionArchivo),
                        &compararClaveEdadDNI);
                    free(cliente);
                }
            }
        }
    }
    persistirIndice(indiceNombre, &persistirClaveNombreDNI, fopen("nombre.bin", "wb"));
    persistirIndice(indiceEdad, &persistirClaveEdadDNI, fopen("edad.bin", "wb"));
    return 0;
}
