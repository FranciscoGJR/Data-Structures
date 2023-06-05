# Data_Structures
 

## Grafos
Para tratar tal tema, foi implementado uma estrutura de grafos, coma representação de lista de adjacência, e algumas funções para manipular tal estrutura.

### Descrição das funções
#### Função buscaAresta
- Parâmetros: ponteiro para AdjList, retorna o elemento anterior, inteiro que representa um NODE A, inteiro que representa um NODE B.
- Principal função: identificar se o NODE A está ligado com o NODE B.
- Funcionalidade: entra no NODE A e passa por todos os elementos, guiando-se pelo atributo de ponteiro next. Quando acha o NODE B, ele é retornado. Ademais, por questões práticas, também é retornado o elemento anterior ao NODE B.

## Lista Ligada
### Modelagem

A figura abaixo representa a modelagem de um elemento presente em uma lista ligada. Tal estrutra foi implementada com alocação dinâmica, de modo que cada elemento apresenta 2 campos: "registro", onde pode-se armazenar todas os dados úteis, nesse caso, "idade" e "saldo"; "prox", que trata-se de um ponteiro para um próximo elemento, assim constituindo a estrutura de dados referida.

![modelagemListaSequencial](
https://github.com/FranciscoGJR/Data_Structures/blob/main/Imagens/ModelagemListaLigada.png)


Com isso, podemos montar uma lista sequêncial. Abaixo pode-se observar um exemplo de tal estrutura, esta que contêm 3 elementos com todos os seus campos preenchidos. Ademais, é importante notar que, com a ausência de um nó cabeça, o ultimo elemento aponta para um endereço _NULL_.

![ListaSequecial](
https://github.com/FranciscoGJR/Data_Structures/blob/main/Imagens/ListaSequencial.png)



## Estruturas a serem implementadas
- Lista sequêncial
  - Sem nó cabeça
  - Implementação dinâmica
- Lista ligada com nó cabeça
  - Nó cabeça
  - Implementação dinâmica
- Lista duplamente ligada
  - Nó cabeça
  - Implementação dinâmica
- Pilha
- Deque
- Fila
- Matrizes
- Árvores binárias
- Árvores binárias de buscas


## Manipulação de arquivos

### Tarefas 
1. Leitura de um arquivo de texto;
2. Escrita de um inteiro em um arquivo arquivo de texto;
3. Escrita de um texto em um arquivo arquivo de texto;
4. Faça a cópia de um arquivo de texto;
5. Fazer a leitura de um arquivo com registro de `nome\nidade`