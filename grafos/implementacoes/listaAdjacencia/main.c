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
    AdjList* array;
} Graph;


// Funcao para criar um novo NO
NODE* creatNODE(int value){
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}

// Funcao para criar um grafo

// Funcao para adicionar adjacencia


//      OUTRAS FUNCOES 
// dellEdge
// searchEdge
// grau de entrada
// grau de saida
// grafos identicos


// Funca main
void main(){
    NODE* node0 = creatNODE(2);
    printf("Value new node: %d\n", node0->value);
}
