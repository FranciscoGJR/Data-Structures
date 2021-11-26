#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef int bool;

typedef struct{
    int chave;
    int idade;
    int saldo;
} REGISTRO_LISTA_LIGADA;


typedef struct aux{
    REGISTRO_LISTA_LIGADA* reg;
    struct aux* prox;
} ELEMENTO_LISTA_LIGADA;


typedef struct{
    ELEMENTO_LISTA_LIGADA* inicio;
} LISTA_LIGADA;


// INICIALIZA UMA LISTA LIGADA JA CRIADA, PASSADA COMO PARAMETRO
bool inicializarListaLigada(LISTA_LIGADA* f){
    f->inicio = NULL;
    return true;
}

//
ELEMENTO_LISTA_LIGADA* buscaLiistaLigada(LISTA_LIGADA* f, int chave, ELEMENTO_LISTA_LIGADA* anterior){
  ELEMENTO_LISTA_LIGADA* atual = f->inicio;

  while (atual != NULL && atual->reg->chave < chave){
    anterior = atual;
    atual = atual->prox;
  }
  if (atual != NULL && atual->reg->chave == chave) return atual;
  return NULL;
}


bool InserirElementoOrdenadoListaLigada(LISTA_LIGADA* f){
    int chave, idade, saldo;

    // ENTRADA DOS DADOS QUE SERAO INSERIDOS EM REGISTRO
    printf("Chave: ");
    scanf("%i",&chave);
    printf("Idade: ");
    scanf("%i",&idade);
    printf("Saldo: ");
    scanf("%i",&saldo);

    // ALOCANDO ESPACO PARA O NOVO ELEMENTO E REGISTRO
    ELEMENTO_LISTA_LIGADA* elemento = (ELEMENTO_LISTA_LIGADA*) malloc (sizeof(ELEMENTO_LISTA_LIGADA));
    REGISTRO_LISTA_LIGADA* reg = (REGISTRO_LISTA_LIGADA*) malloc (sizeof(REGISTRO_LISTA_LIGADA));

    // ALIMENTANDO REGISTRO COM OS DADOS COLETADOS DA ENTRADA
    reg->chave = chave;
    reg->idade = idade;
    reg->saldo = saldo;
    elemento->reg = reg;

    // INSERINDO ELEMENTO EM UMA LISTA VAZIA
    if(f->inicio == NULL){
    f->inicio = elemento;
    return true;
    }

    // INSERINDO DE FORMA ORDENADA
    ELEMENTO_LISTA_LIGADA* anterior;
    buscaLiistaLigada(f, chave, &anterior);

    printf("CHAVE ANTEIROE: %i", anterior->reg->chave);

    elemento->prox = anterior->prox;
    anterior->prox = elemento;

    return true;
}




/*
tamanhoListaLigada
imprimirListaLigada
BuscarElementoListaLigada
alterarRegistroListaLigada
deletarElementoListaLigada
*/
