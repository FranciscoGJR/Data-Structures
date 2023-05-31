//--------------------------------------------------------------
// NOMES DOS RESPONSAVEL: FRANCISCO OLIVEIRA GOMES JUNIOR
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <stdbool.h>

#define INFINITO INT_MAX

int grupo() {
  return 0;
}


// ######### ESCREVA O NROUSP AQUI
int nroUSP1() {
    return 12683190;
}


int nroUSP2() {
    return 0;
}


// elemento das listas de adjac�ncia e de resposta - NAO ALTERE ESTA DEFINICAO
typedef struct estr {

    int adj; // elemento
	int peso; // custo (n�o precisa ser usado na resposta)
    struct estr *prox;
} NO;


// vertices do grafo (salas) - use este tipo ao criar o grafo  - NAO ALTERE ESTA DEFINICAO
typedef struct {

    int flag;    // para uso na busca em largura e profundidade, se necessario
    bool aberto; // vale true se a sala em questao esta aberta
    int via;     // use este campo se precisar computar algum caminho etc.
    int dist;    // use este campo se precisar computar alguma dist�ncia etc.
    NO* inicio;
} VERTICE;


// Função de exemplo para criar um grafo
VERTICE* criarGrafo(int num_vertices) {
    VERTICE* grafo = malloc(num_vertices * sizeof(VERTICE));

    for (int i = 0; i < num_vertices; i++) {
        grafo[i].flag = 0;
        grafo[i].aberto = true;
        grafo[i].via = -1;
        grafo[i].dist = INFINITO;
        grafo[i].inicio = NULL;
    }

    return grafo;
}


// Função de exemplo para adicionar uma aresta ao grafo não dirigido
void adicionarAresta(VERTICE* grafo, int vertice1, int vertice2, int peso) {
    NO* novo_no1 = malloc(sizeof(NO));
    novo_no1->adj = vertice2;
    novo_no1->peso = peso;
    novo_no1->prox = NULL;

    if (grafo[vertice1].inicio == NULL) {
        grafo[vertice1].inicio = novo_no1;
    } else {
        NO* atual = grafo[vertice1].inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo_no1;
    }

    NO* novo_no2 = malloc(sizeof(NO));
    novo_no2->adj = vertice1;
    novo_no2->peso = peso;
    novo_no2->prox = NULL;

    if (grafo[vertice2].inicio == NULL) {
        grafo[vertice2].inicio = novo_no2;
    } else {
        NO* atual = grafo[vertice2].inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo_no2;
    }
}


void inicializarGrafo(VERTICE *vertice, int *distancia, int *predecessor, int inicio, int num_vertices){

    int v;
    for(v = 0; v < num_vertices; v++){

        distancia[v] = INT_MAX/2;
        predecessor[v] = -1;
    }
    
    distancia[inicio] = 0;
}


void relaxa(VERTICE *vertice, int *distancia, int *predecessor, int u, int v){

    NO *no = vertice[u].inicio;
    while(no && no->adj != v)
        no = no->prox;

    if(no){

        if(distancia[v] > distancia[u] + no->peso){

            distancia[v] = distancia[u] + no->peso;
            predecessor[v] = u;
        }
    }
}


bool existeAberto(VERTICE *vertice, bool *aberto, int num_vertices){
	int i;
	for(i = 0; i < num_vertices; i++)
		if(aberto[i]) return(true);
	return(false);
}	


int menorDist(VERTICE *vertice, bool *aberto, int *distancia, int num_vertices){
	int i;
	for(i = 0; i < num_vertices; i++)
		if(aberto[i]) break;
	if(i == num_vertices) return (-1);
	int menor = i;
	for(i = menor+1; i < num_vertices; i++)
		if(aberto[i] && (distancia[menor] > distancia[i]))
			menor = i;
	return(menor);
}


int *dijkstra(VERTICE *vertice, int inicio, int num_vertices){

    int *distancia = (int *) malloc(num_vertices * sizeof(int));

    // incializando arranjo de predecessor e abertos
    int predecessor[num_vertices];
    bool aberto[num_vertices];

    inicializarGrafo(vertice, distancia, predecessor, inicio, num_vertices);

    // incializando arranjo de abertos
    int i;
    for(i = 0; i < num_vertices; i++)
        aberto[i] = true;

    while(existeAberto(vertice, aberto, num_vertices)){
        int u = menorDist(vertice, aberto, distancia, num_vertices);
        aberto[u] = false;

        NO *no = vertice[u].inicio;
        while(no){
            relaxa(vertice, distancia, predecessor, u, no->adj);
            no = no->prox;
        }
    }
    
    return(distancia);
}


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO *caminho(int N, int A, int *ijpeso, int *aberto, int inicio, int fim, int chave){

	NO* resp;
	resp = NULL;

	// seu codigo AQUI

	//...

	return resp;
}



//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {

    int num_vertices = 5;
    VERTICE* grafo = criarGrafo(num_vertices);

    adicionarAresta(grafo, 6, 7, 10);

    int *r = dijkstra(grafo, 0, num_vertices);



/*

	// aqui vc pode incluir codigo de teste

	// exemplo de teste trivial

	int N=3; // grafo de 3 v�rtices numerados de 1..3
	int aberto[] = {1,1,1}; // todos abertos
	int inicio=1;
	int fim=3;
	int chave=2;
    int A = 3;
	int ijpeso[]={1,2,10, 2,3,20, 3,1,10};

	// o EP sera testado com uma serie de chamadas como esta
	NO* teste = null;
	teste = caminho(N, A, ijpeso, aberto, inicio, fim, chave);
	return teste;
*/

}