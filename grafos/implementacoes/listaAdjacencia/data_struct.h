#ifndef GRAPH_STRUCT
#define GRAPH_STRUCT

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define false 0
#define true 1

// Estrutura de um nó da lista de adjacência
typedef struct NODE{
    struct NODE* next;
    int value;
} NODE;

// Estrutura de uma lista de adjacência
typedef struct AdjList {
    NODE* head;
} AdjList;

// Estrutura do grafo
typedef struct Graph {
    int num_vertices;
    AdjList* vertices;
} Graph;

// Funcao para criar um novo NO
NODE* creatNODE(int value);

// Funcao para criar lista de adjacencia
AdjList* createAdjList();

// Funcao para criar Graph
Graph* createGraph(int num_vertices);

// Funcao para identificar se existe aresta entre dois no
NODE* searchNode(Graph *graph, int nodeA, int nodeB, NODE *** ant);

// Funcao para adicionar adjacencia em um nodeA
bool insertAdjacent(Graph *graph, int nodeA, int value);

// Funcao para imprimir o grafo
void printGraph(Graph* graph);
#endif
