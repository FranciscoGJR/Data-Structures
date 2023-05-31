//--------------------------------------------------------------
// NOMES DOS RESPONSAVEL: FRANCISCO OLIVEIRA GOMES JUNIOR
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include <stdbool.h>

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


void inicializarGrafo(VERTICE *vertice, int *d, int *p, int s){

    int v;
    for(v = 0; v < vertice->vertices; v++){

        d[v] = INT_MAX/2;
        p[v] = -1;
    }
    
    d[s] = 0;
}


void relaxa(VERTICE *vertice, int *d, int *p, int u, int v){

    NO *no = vertice[u];
    while(no && no->adj != v)
        no = no->prox;

    if(no){

        if(d[v] > d[u] + no->peso){

            d[v] = d[u] + no->peso;
            p[v] = u;
        }
    }
}


bool existeAberto(VERTICE *g, int *aberto){
	int i;
	for(i = 0; i < g->vertices; i++)
		if(aberto[i]) return(true)
	return(false);
}	


int menorDist(VERTICE *g, int *aberto, int *d){
	int i;
	for(i = 0; i < g->vertices; i++)
		if(aberto[i]) break;
	if(i == g->vertices) return (-1);
	int menor = i;
	for(i = menor+1; i < g->vertices; i++)
		if(aberto[i] && (d[menor] > d[i]))
			menor = i;
	return(menor);
}


int *dijkstra(VERTICE *vertice,, int inicio){

    int *d = (int *) malloc(vertice*sizeof(int));

    int p[g->vertices];
    bool aberto[g->vertices];
    incializaGrafo(g, d, p, inicio);

    int i;
    for(i = 0; i < g->vertices; i++)
        aberto[i] = true;

    while(exsteAberto(	g, aberto)){
        int u = menorDistancia(g, aberto, d);
        aberto[u] = false;

        ADJACENCIA *ad = g->adj[u].cab;
        while(ad){
            relaxa(g, d, p, u, ad->vertice);
            ad = ad->prox;
        }
    }
    
    return(d);
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

}