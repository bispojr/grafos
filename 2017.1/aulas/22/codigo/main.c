#include <stdio.h>
#include "grafo.h"
#include "fabrica.h"

int main (void){

    //Grafo *g = caminho(4);
    Grafo *h = malloc(sizeof (Grafo));

    //printf("\nEh conexo: %d\n\n", ehConexo(g));

    inicializar(h, "Gravata Borboleta Esticada", 6);
    inserirAresta(h, 0, 1);
    inserirAresta(h, 1, 2);
    inserirAresta(h, 2, 0);
    inserirAresta(h, 2, 3);
    inserirAresta(h, 3, 4);
    inserirAresta(h, 4, 5);
    inserirAresta(h, 5, 3);
    inserirAresta(h, 0, 4);

    h = k(10);

    for(int i=0; i<h->n; i++)
        for(int j=0; j<h->n; j++)
            if(h->adj[i][j] == 1 && i>j)
                printf("\nEh ponte (%d,%d)? %d", i, j, ehPonte(h, i, j));

    //exibir(h);

    return 0;
}
