#include <stdio.h>

/* == TAREFA ==
#### Cópia de arquivo:
    - Crie uma função que receba o nome de dois arquivos (origem e destino).
    - Abra o arquivo de origem em modo de leitura e o arquivo de destino em modo de escrita.
    - Leia o conteúdo do arquivo de origem e escreva-o no arquivo de destino.
    - Verifique se a cópia foi realizada com sucesso.
*/
int main() {    
    int max = 100;
    char c[max];
    
    // abrindo arquivos
    FILE* arquivoOrigem = fopen("dados", "r");
    FILE* arquivoDestino = fopen("dados1", "w");

    while(fscanf(arquivoOrigem, "%c", c) != EOF)   // leitura
        fprintf(arquivoDestino, "%s", c);  // escrita

    // fechar arquivos
    fclose(arquivoDestino);
    fclose(arquivoOrigem);

    return 0;
}
