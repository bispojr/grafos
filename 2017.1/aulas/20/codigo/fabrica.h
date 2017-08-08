#ifndef FABRICA_H_INCLUDED
#define FABRICA_H_INCLUDED

#include <stdlib.h>
#include "grafo.h"

Grafo *k(int n){

    Grafo *g = malloc(sizeof (Grafo));

    inicializar(g, "K_x", n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i != j)
                inserirAresta(g, i, j);

    return g;
}

Grafo *caminho(int n){  // Comprimento n-1

    Grafo *g = malloc(sizeof (Grafo));

    inicializar(g, "Caminho (Comp. x)", n);

    for(int i=0; i < n-1; i++)
        inserirAresta(g, i, i+1);

    return g;
}

Grafo *circuito(int n){  // Comprimento n-1

    Grafo *g = caminho(n);

    inserirAresta(g, 0, n-1);

    return g;
}

#endif // GRAFO_H_INCLUDED
