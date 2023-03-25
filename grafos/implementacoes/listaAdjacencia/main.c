#include <stdio.h>
#include <stdlib.h>

#define bool int
#define false 0
#define true 1

	// ESTRUTURA DO NO
typedef struct s{
	struct s* prox;
	int valorNo;
} NO;

	// ESTRUTURA DA LISTA
typedef struct{
	int flag;       // o atributo flag sera usado mais a frente para busca em profundidade
	NO* inicio;
} VERTICE;



void main(){

	// CRIAR LISTA E PREENCHER COM NULL
    VERTICE* grafoEmLista = (VERTICE*) malloc(sizeof(VERTICE) * 5);
    printf("=== FINAL DO PROGRAMA ===\n");

}
