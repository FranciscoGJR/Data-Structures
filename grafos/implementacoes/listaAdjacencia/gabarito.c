#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Estrutura de um nó da lista de adjacência
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Estrutura de uma lista de adjacência
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// Estrutura do grafo
typedef struct Graph {
    int num_vertices;
    AdjList* array;
} Graph;

// Função para criar um novo nó da lista de adjacência
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com n vértices
Graph* createGraph(int num_vertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;

    // Aloca memória para a lista de adjacência
    graph->array = (AdjList*) malloc(num_vertices * sizeof(AdjList));

    // Inicializa cada lista de adjacência como vazia
    for (int i = 0; i < num_vertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(Graph* graph, int src, int dest) {
    // Adiciona a aresta src -> dest
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Adiciona a aresta dest -> src (caso seja um grafo não direcionado)
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Função para imprimir o grafo
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        AdjListNode* node = graph->array[i].head;
        printf("Adjacências do vértice %d: ", i);
        while (node != NULL) {
            printf("%d ", node->dest);
            node = node->next;
        }
        printf("\n");
    }
}

// Função principal
int main() {
    // Cria um grafo com 4 vértices
    Graph* graph = createGraph(4);

    // Adiciona algumas arestas
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Imprime o grafo
    printGraph(graph);

    return 0;
}

