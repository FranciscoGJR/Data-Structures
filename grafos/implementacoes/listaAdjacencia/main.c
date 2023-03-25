#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
NODE* createNODE(int value){
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}

// Funcao para criar lista de adjacencia
void createAdjList(AdjList  **newAdjList){
    *newAdjList= (AdjList*) malloc(sizeof(AdjList)); 
    (*newAdjList)->head = NULL;
}

// Funcao para criar Graph
Graph* createGraph(int num_vertices){
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));
    newGraph->num_vertices = num_vertices;
   
    newGraph->array = (AdjList*) malloc(sizeof(AdjList) * num_vertices);

    int i;
    for(i = 0; i < num_vertices; i++){
        AdjList *newList;
        createAdjList(&newList);
        newGraph->array[i].head = newList->head;
    }
 
    return newGraph;
}

// Funcao para adicionar adjacencia

//      OUTRAS FUNCOES 
// dellVertices
// // searchVertices
// grau de entrada
// grau de saida
// grafos identicos


// Funca main
int main(){
    int num_vertices;
    printf("num_vertices: ");
    scanf("%d", &num_vertices);

    Graph* graph =  createGraph(num_vertices);
    printf("num vertices: %d\n", graph->num_vertices); 

    return 0;
}
