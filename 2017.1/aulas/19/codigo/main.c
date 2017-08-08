#include <stdio.h>
#include "grafo.h"
#include "fabrica.h"

int main (void){

    Grafo *g = caminho(50);
    Grafo *h = malloc(sizeof (Grafo));

    printf("Eh caminho: %d", ehCaminho(g));

    inicializar(h, "Caminho 4", 5);
    inserirAresta(h, 0, 3);
    inserirAresta(h, 3, 2);
    inserirAresta(h, 2, 4);
    inserirAresta(h, 3, 1);

    h->nome = "Caminho (Comp. 4)";

    printf("\nEh caminho: %d", ehCaminho(h));

    //exibir(h);

    return 0;
}
