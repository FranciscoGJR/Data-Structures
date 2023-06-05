#include <stdio.h>

/* == TAREFA ==
#### Fazer a leitura de um arquivo com registro de nome e idade:
*/

void printarRegistros(int idades, char nomes, int tamanho){

    
    return;
}

int main() {    
    int max = 100;

    char nomes[max][16];
    int idades[max];
    int posicao = 0;

    // abrindo arquivos
    FILE* arquivo = fopen("registroNomeIdades", "r");

    while(feof(arquivo) == 0){
        fscanf(arquivo, "%s", nomes[posicao]);
        fscanf(arquivo, "%i", &idades[posicao]);
        posicao++;
    }

    // fechar arquivos
    fclose(arquivo);

    // mostrar registros
    int i;
    for(i = 0; i < posicao; i++){
        printf("%i REGISTRO\n", i);
        printf("nome: %s\n", nomes[i]);
        printf("idades: %i\n", idades[i]);
    }

    return 0;
}
