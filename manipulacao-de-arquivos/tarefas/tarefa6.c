#include <stdio.h>

/* == TAREFA ==
#### Fazer a escrita em um arquivo com registro de nome\nidade:
*/

int main() {    
    int maxNome = 100;
    char nome[maxNome];
    int idade;
    int quantRegistros;
    
    FILE* arquivo = fopen("registroNomeIdades", "w");

    // entrada de nome e idade
    fgets(nome, sizeof(nome), stdin);
    scanf("%i", &idade);

    // escrever nome e idade
    fprintf(arquivo, "%s", nome);
    fprintf(arquivo, "%i", idade);
    
    // fechar arquivos
    fclose(arquivo);
    return 0;
}
