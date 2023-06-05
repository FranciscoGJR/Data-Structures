#include <stdio.h>

/* == TAREFA ==
### Escrita de uma string em um arquivo de texto:
    -   Crie um novo arquivo de texto ou abra um existente em modo de escrita.
    -   Permita que o usuário insira uma string e escreva-o no arquivo.
    -   Feche o arquivo e verifique se os dados foram gravados corretamente.  
*/
int main() {    
    int max = 1000;
    char nome[max];
    
    // criando arquivo
    FILE* arquivo = fopen("dados", "w");

    // entrada do usuario
    fgets(nome, sizeof(nome), stdin);

    // escrever string no arquivo
    fprintf(arquivo, "%s", nome);

    // fechar arquivo
    fclose(arquivo);

    return 0;
}
