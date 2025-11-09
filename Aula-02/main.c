#include "matriz.h"
#include <stdio.h>

int main(){
    Matriz *matriz;
    int linha, coluna;
    float valor;
    float valor_interno;
    printf("Numero de Linhas da Matriz: \n");
    scanf("%d", &linha);
    printf("Numero de colunas da Matriz: \n");
    scanf("%d", &coluna);
    matriz = cria(linha, coluna);
    printf("Matriz foi criada com %d linhas e %d colunas\n", linhas(matriz), colunas(matriz));
    printf("Digite um número para preencher a matriz inteira com esse valor: \n");
    scanf("%f", &valor);
    print_matriz(matriz);
    printf("Digite o número da linha e da coluna para adicionar um valor:\n");
    scanf("%d %d", &linha, &coluna);
    printf("Digite um valor numérico para armazenar na posição na matriz\n");
    scanf("%f", &valor);
    atribui(matriz, linha, coluna, valor);
    valor_interno = acessa(matriz, linha, coluna);
    printf("O valor armazenado na matriz na linha %d e coluna %d é: %f\n", linha, coluna, valor_interno);
    print_matriz(matriz);
    libera(matriz);
}