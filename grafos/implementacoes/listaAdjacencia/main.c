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


//      OUTRAS FUNCOES 
// dellEdge
// searchEdge
// grau de entrada
// grau de saida
// grafos identicos



// Funca main
int main(){
    int num_vertices = 6;
    Graph* graph = createGraph(num_vertices);

    // Adiciona algumas arestas ao grafo
    insertAdjacent(graph, 0, 5);
    insertAdjacent(graph, 1, 3);
    insertAdjacent(graph, 1, 4);
    insertAdjacent(graph, 2, 2);
    insertAdjacent(graph, 3, 5);
    insertAdjacent(graph, 5, 2);
    
    printGraph(graph);

    // Gera arquivo com visualização do grafo
    FILE* fp = fopen("graph.dot", "w");
    fprintf(fp, "digraph G {\n");
    fprintf(fp, "rankdir=LR;\n");
    fprintf(fp, "node [shape=ellipse, style=filled, color=gray90];\n");
    fprintf(fp, "edge [color=gray50, arrowhead=vee];\n");

    for(int i = 0; i < graph->num_vertices; i++) {
        NODE* node = graph->vertices[i].head;
        while(node) {
            fprintf(fp, "%d -> %d;\n", i, node->value);
            node = node->next;
        }
    }

    fprintf(fp, "}\n");
    fclose(fp);
    system("dot -Tpng graph.dot -o graph.png");

    return 0;
}
