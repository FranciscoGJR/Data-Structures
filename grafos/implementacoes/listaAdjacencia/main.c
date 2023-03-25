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

// Funcao para criar lista de adjacencia
AdjList* createAdjList(){
    AdjList* newAdjList = (AdjList*) malloc(sizeof(AdjList));
    newAdjList->head = NULL;
    return newAdjList;
}

// Funcao para criar Graph
Graph* createGraph(int num_vertices){
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));
    newGraph->num_vertices = num_vertices;
   
    newGraph->array = (AdjList*) malloc(sizeof(AdjList) * num_vertices);

    int i;
    for(i = 0; i < num_vertices; i++){
        newGraph->array[i].head = NULL;
    }
    return newGraph;
}

// Funcao para adicionar adjacencia

//      OUTRAS FUNCOES 
// dellEdge
// searchEdge
// grau de entrada
// grau de saida
// grafos identicos


// Funca main
void main(){
    int num_vertices;
    printf("num_vertices: ");
    scanf("%d", &num_vertices);

    Graph* graph =  createGraph(num_vertices);
    printf("num vertices: %d\n", graph->num_vertices); 
}
