#include <stdio.h>
#include "grafo.h"
#include "fabrica.h"

int main (void){

    Grafo *g = circuito(5000);
    Grafo *h = malloc(sizeof (Grafo));

    printf("Eh regular: %d", ehRegular(g));

    inicializar(h, "Pentagono", 5);
    inserirAresta(h, 0, 1);
    inserirAresta(h, 1, 2);
    inserirAresta(h, 2, 3);
    inserirAresta(h, 3, 4);
    inserirAresta(h, 4, 0);

    h->nome = "Caminho (Comp. 4)";
    removerAresta(h, 4, 0);

    //exibir(h);

    return 0;
}
