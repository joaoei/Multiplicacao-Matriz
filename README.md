# Multiplicacao-Matriz
Trabalho prático da matéria de Programação Concorrente, onde é necessário criar dois programas que multipliquem matrizes, sendo um implementado de forma sequencial e outro de modo concorrente.

## Compilando
`g++ src/mult_matriz.cpp src/aux.cpp -o bin/multimat -I include/ -lpthread`

## Rodando

`./multimat [tamanho_matriz] [tipo_multiplicação]`

`tamanho_matriz` deve ser um inteiro positivo maior que 4 (possuindo matriz com esse tamanho) e `tipo_multiplicação` deve ser S (sequencial) ou C (concorrente).