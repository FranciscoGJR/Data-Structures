#include "data_struct.h"

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define false 0
#define true 1

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
   
    newGraph->vertices= (AdjList*) malloc(sizeof(AdjList) * num_vertices);

    int i;
    for(i = 0; i < num_vertices; i++){
        newGraph->vertices[i].head = NULL;
        newGraph->vertices[i].flag = 0;
    }
    return newGraph;
}

// Funcao para identificar se existe aresta entre dois no
NODE* searchNode(Graph *graph, int nodeA, int nodeB, NODE *** ant){
    if (nodeA < 0 || nodeA >= graph->num_vertices || nodeB < 0 || nodeB >= graph->num_vertices) {
        printf("\nerro em searchNode(): Valores dos parâmetros invalidos. Imcompatíveis com o num-vertices\n");
        return NULL;
    }
    *ant = NULL;
    NODE* node = graph->vertices[nodeA].head;
    // percorrer todos os elementos adjacente ao nodeA
    while(node){
        if(node->value == nodeB) return node;
        *ant = &node->next;
        node = node->next;
    }
    return NULL;
}

// Funcao para adicionar adjacencia em um nodeA
bool insertAdjacent(Graph *graph, int nodeA, int value){
	NODE** nodePrecedent = NULL;
	NODE* nodeCurrent= searchNode(graph, nodeA, value, &nodePrecedent);
	if(nodeCurrent) return false;
	nodeCurrent = (NODE*) malloc(sizeof(NODE));
	nodeCurrent->value = value;
	nodeCurrent->next = graph->vertices[nodeA].head;
	graph->vertices[nodeA].head = nodeCurrent;
	return true;
}

// Funcao para imprimir o grafo
void printGraph(Graph* graph) {
    int i;
    for (i = 0; i < graph->num_vertices; i++) {
        printf("%d = ", i);
        NODE* current = graph->vertices[i].head;
        while (current != NULL) {
            printf("%d -> ", current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}
