#include <stdio.h>

/* == TAREFA ==
### Escrita de um inteiro em um arquivo arquivo de texto:
    -   Crie um novo arquivo de texto ou abra um existente em modo de escrita.
    -   Permita que o usuário insira um inteiro e escreva-o no arquivo.
    -   Feche o arquivo e verifique se os dados foram gravados corretamente.  
*/
int main() {    
    int max = 1000;
    
    int idade;

    // criando arquivo
    FILE* arquivo = fopen("dados", "w");

    // entrada do usuario
    scanf("%d", &idade);

    // escrever int no arquivo
    fprintf(arquivo, "%i", idade);

    // fechar arquivo
    fclose(arquivo);

    return 0;
}
