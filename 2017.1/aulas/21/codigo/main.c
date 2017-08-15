#include <stdio.h>
#include "grafo.h"
#include "fabrica.h"

int main (void){

    //Grafo *g = caminho(4);
    Grafo *h = malloc(sizeof (Grafo));

    //printf("\nEh conexo: %d\n\n", ehConexo(g));

    inicializar(h, "Arvore Peh de Pato", 4);
    inserirAresta(h, 0, 2);
    inserirAresta(h, 2, 3);
    inserirAresta(h, 2, 1);

    printf("\n\nEh conexo: %d\n\n", ehConexo(h));

    //exibir(h);

    return 0;
}
