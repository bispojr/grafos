#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <stdlib.h>

typedef struct grafo {
   char *nome;
   int n;       // Número de vértices
   int m;       // Número de arestas
   int **adj;   // Ponteiro para a matriz de adjacências
} Grafo;

int **gerarMatriz(int n) {

   int i, j;

   // Aloca um vetor de n ponteiros (do tipo int) na memória
   int **m = malloc( n * sizeof (int *));

   // Para cada ponteiro, aloca n elementos (do tipo int) na memória
   for (i = 0; i < n; i++)
      m[i] = malloc( n * sizeof (int));

   // Preenche cada célula da matriz com valor 0
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         m[i][j] = 0;

   return m;
}
void inicializar(Grafo *g, char *nome, int n) {

    // Inicializa os parâmetros da estrutura Grafo
    g->nome = nome;
    g->n = n;
    g->m = 0;
    g->adj = gerarMatriz(n);

}
void inserirAresta(Grafo *g, int v, int w) {

    // Garantindo que os argumentos estão entre
    // 0 e n-1 (fechado)
    if( (v >= 0) && (v < g->n) ){
        if( (w >= 0) && (w < g->n) ){

            if (g->adj[v][w] == 0) { // Verifica se a aresta não existe
              // É necessário preencher as duas células com 1
              g->adj[v][w] = 1;
              g->adj[w][v] = 1;
              g->m++;
            }
        }
    }

}
void removerAresta(Grafo *g, int v, int w) {

    // Garantindo que os argumentos estão entre
    // 0 e n-1 (fechado)
    if( (v >= 0) && (v < g->n) ){
        if( (w >= 0) && (w < g->n) ){

            if (g->adj[v][w] == 1) { // Verifica se a aresta existe
              // É necessário preencher as duas células com 0
              g->adj[v][w] = 0;
              g->adj[w][v] = 0;
              g->m--;
            }
        }
    }

}
void exibir(Grafo *g) {

   int v, w;


    printf("\n=================");
    printf("\n%s", g->nome);
    printf("\n=================");

    // Imprime o conjunto de vértices
    printf("\nV = {");

    for(v = 0; v < g->n; v++ )
        printf("%d, ", v);

    if(g->n > 0)
        printf("\b\b");
    printf("}");


    // Imprime o conjunto de arestas
    printf("\nA = {");
    for (v = 0; v < g->n; v++)
        for (w = 0; w < g->n; w++)
            if (g->adj[v][w] == 1)                  // Se os vértices são vizinhos
                if (v < w)                          // Considera apenas a região superior à diagonal principal
                    printf("(%d, %d); ", v, w);   // Imprime

    if(g->m > 0)
        printf("\b\b");
    printf("}");

    printf("\n=================\n");
}
int grau(Grafo *g, int v){

    int soma;

    // Garantindo que os argumentos estão entre
    // 0 e n-1 (fechado)
    if( (v >= 0) && (v < g->n) ){

        soma = 0;
        for(int i=0; i<g->n; i++)
            soma += g->adj[v][i];

    }

    return soma;

}
int grauMinimo(Grafo *g){

    int minimo = g->n;

    for(int i=0; i < g->n; i++){

        int grauI = grau(g, i);

        if( grauI < minimo )
            minimo = grauI;
    }

    return minimo;
}
int grauMaximo(Grafo *g){

    int maximo = -1;

    for(int i=0; i < g->n; i++){

        int grauI = grau(g, i);

        if( grauI > maximo )
            maximo = grauI;
    }

    return maximo;
}
int ehRegular(Grafo *g){

    if(g->n != 1){
        int valorGrau = grau(g, 0);

        for(int i=1; i<g->n; i++)
            if( grau(g,i) != valorGrau )
                return 0;
    }

    return 1;
}
int eh3Regular(Grafo *g){

    if(g->n != 1){
        int valorGrau = grau(g, 0);

        if(valorGrau != 3)
            return 0;

        for(int i=1; i<g->n; i++)
            if( grau(g,i) != valorGrau )
                return 0;

        return 1;
    }

    return 0;

}
Grafo *gMenosV(Grafo *g, int v){

    Grafo *h = malloc(sizeof (Grafo));
    inicializar(h, "G - v", g->n - 1);

    for(int i=0; i<g->n; i++){

        int l = i;

        if(i == v) continue;
        else
            if(i > v)
                l = i - 1;

        for(int j=0; j<g->n; j++){

            int c = j;

            if(j == v) continue;
            else
                if(j > v)
                    c = j - 1;

            h->adj[l][c] = g->adj[i][j];
        }
    }

    return h;
}
int ehCaminho(Grafo *g){

    if( g->n == 1)
        return 1;
    else{
        //Encontrar um vértice de grau 1 e
        //contar a qtd de vértices de grau 1.
        int vGrau1 = -1;
        int qtdGrau1 = 0;
        for(int v=0; v<g->n; v++){
            if( grau(g,v) == 1){
                vGrau1 = v;
                qtdGrau1++;
            }
        }

        //Se não houver vértice de grau 1 ou
        //se não houver dois vértices de grau 1, não é caminho
        if( vGrau1 == -1 || qtdGrau1 != 2)
            return 0;

        //Criar H = G - v (vértice de grau 1)
        Grafo *h = gMenosV(g, vGrau1);

        //Chamada recursiva para H
        return ehCaminho(h);
    }
}
int ehConexo(Grafo *g){

    int parteConexa[g->n];
    int naoVisitado[g->n];

    for(int i=0; i < g->n; i++){
        parteConexa[i] = 0;
        naoVisitado[i] = 0;
    }

    //Escolher um vértice para iniciar o processo
    //de crescimento do subgrafo maximal a partir do K_1
    parteConexa[0] = 1;
    naoVisitado[0] = 1;
    int novoVertice = 1;
    int nParteConexa = 1;

    while(novoVertice == 1){
        novoVertice = 0;
        for(int i=0; i < g->n; i++){
            if(naoVisitado[i] == 1){
                for(int j=0; j < g->n; j++){
                    if(g->adj[i][j] == 1){
                        if(parteConexa[j] == 0){
                            parteConexa[j] = 1;
                            naoVisitado[j] = 1;
                            novoVertice = 1;
                            nParteConexa++;
                        }
                    }
                }
                naoVisitado[i] = 0;
            }
        }
    }

    if(nParteConexa == g->n)
        return 1;
    else
        return 0;
}
#endif // GRAFO_H_INCLUDED
