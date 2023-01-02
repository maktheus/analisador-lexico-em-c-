# Análise Léxica e Sintática em C--

Este é um projeto de compilador para uma linguagem de programação de alto nível chamada C--. O objetivo do projeto é construir um analisador léxico e um analisador sintático para essa linguagem.

## Arquivos do projeto

O projeto inclui os seguintes arquivos:

- AnalisadorLexico.h: cabeçalho do analisador léxico, que define os tipos de tokens e a estrutura de dados Token.
- AnalisadorLexico.cpp: implementação do analisador léxico, que lê o código fonte em C-- e gera uma sequência de tokens.
- AnalisadorSintatico.h: cabeçalho do analisador sintático, que define a estrutura de dados para a árvore sintática abstrata.
- AnalisadorSintatico.cpp: implementação do analisador sintático, que recebe a sequência de tokens gerada pelo analisador léxico e constrói a árvore sintática abstrata do programa em C--.
- main.cpp: arquivo principal do programa, que lê o código fonte em C--, chama o analisador léxico e o analisador sintático e exibe a árvore sintática abstrata gerada.

## Executando o projeto

Para compilar o projeto, use o comando:

```
g++ AnalisadorLexico.cpp AnalisadorSintatico.cpp main.cpp -o compilador

```

Para executar o compilador, use o comando:

```
./compilador código.c--

```


Onde "código.c--" é o nome do arquivo de código fonte em C-- que você quer compilar. O compilador vai ler o código fonte, gerar a árvore sintática abstrata e exibir essa árvore na tela.

## Erros e mensagens de erro

Se o compilador encontrar um erro no código fonte, ele vai exibir uma mensagem de erro e terminar a execução. Alguns exemplos de erros possíveis são:

- Caractere inválido: o código fonte contém um caractere que não faz parte do alfabeto da linguagem C--.
- Token inválido: o código fonte contém um token que não é reconhecido pela linguagem C--.
- String incompleta: o código fonte contém uma string que não está bem formada, ou seja, não tem aspas de fechamento.
- Caractere incompleto: o código fonte contém um caractere que não está bem formado, ou seja, não tem aplas de fechamento.
- Erro de sintaxe: o código fonte contém uma construção que não está de acordo com as regras da linguagem C--.

## Extensões da linguagem C--

O projeto implementa uma versão simplificada da linguagem C--. Algumas das extensões da linguagem C-- que não estão incluídas neste projeto são:

- Arrays: o projeto não suporta arrays.
- Structs: o projeto não suporta structs.
- Pointers: o projeto não suporta pointers.

## Contribuições
Este projeto é um trabalho de exemplo e não está aceitando contribuições externas no momento.

## Licença
Este projeto está licenciado sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.

