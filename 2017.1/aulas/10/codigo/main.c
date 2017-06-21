#include <stdio.h>
#include "grafo.h"

int main (void){

    Grafo *g = malloc(sizeof (Grafo));

    inicializar(g, "Exemplo", 12);
    exibir(g);

    return 0;
}
