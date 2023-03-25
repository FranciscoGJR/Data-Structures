#include <stdio.h>
#include <stdlib.h>

#define bool int
#define false 0
#define true 1

// Estrutura de um nó da lista de adjacência
typedef struct NODE{
    struct NODE* next;
    int dest;
} NODE;

// Estrutura de uma lista de adjacência
typedef struct AdjList {
    NODE* head;
} AdjList;

// Estrutura do grafo
typedef struct Graph {
    int num_vertices;
    AdjList* array;
} Graph;


void main(){


    printf("=== FINAL DO PROGRAMA ===\n");


}
