#include <stdio.h>
#include "busca_profundidade.c"
#include <stdlib.h>
#include "data_struct.c"

#define bool int
#define false 0
#define true 1

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
    insertAdjacent(graph, 4, 2);

    printGraph(graph);
    dfs(graph);

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
