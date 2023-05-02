#include <stdio.h>
#include "data_struct.h"

// implementationn depth-first search busca em profundidade
void dfs(Graph *graph, int search, int init){
    // 0 = DESCONHECIDO
    // 1 = DESCOBERTO
    // 2 = CONCLUIDO

    graph->vertices[init].flag = 1;
    NODE* current = graph->vertices[init].head;

    printf("Averiguando o NODE= %d\n", init);
    
    while(current){

        if(graph->vertices[current->value].flag == 0)
            dfs(graph, search, current->value);
        current = current->next;
    }
    graph->vertices[init].flag = 2;
}


