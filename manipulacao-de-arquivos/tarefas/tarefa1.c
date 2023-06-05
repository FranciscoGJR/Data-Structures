#include <stdio.h>

/* == TAREFA ==
### Leitura de um arquivo de texto:
    - Abra um arquivo de texto existente em modo de leitura.
    - Leia e exiba o conteúdo do arquivo na tela.
*/
int main() {    
    int max = 1000;
    
    char c[max];
    
    FILE* arquivo = fopen("dados", "r");

    // imprimir um char por vez
    int i =0;
    while(fscanf(arquivo, "%c", c) != EOF){
        printf("%s", c);
    }

    fclose(arquivo);

    return 0;
}
