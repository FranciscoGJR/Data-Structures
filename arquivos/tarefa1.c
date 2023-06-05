#include <stdio.h>

/* == TAREFA ==
### Leitura de um arquivo de texto:
    - Abra um arquivo de texto existente em modo de leitura.
    - Leia e exiba o conteúdo do arquivo na tela.
*/
int main() {    
    
    char c[4];
    
    FILE* arq = fopen("dados", "r");

    // imprimir um char por ver
    while(fscanf(arq, "%c", c) != EOF) {
        printf("%s", c);
    }

    fclose(arq);

    return 0;
}
