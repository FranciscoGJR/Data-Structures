#include "Lista_ligada/listaLigada.c"
#include <stdio.h>

void main(){

    LISTA_LIGADA listaLigada;
    inicializarListaLigada(&listaLigada);

    InserirElementoOrdenadoListaLigada(&listaLigada);
    InserirElementoOrdenadoListaLigada(&listaLigada);
}


