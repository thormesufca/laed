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
    preenche(matriz);
    print_matriz(matriz);
    printf("Digite o numero da linha e da coluna para adicionar um valor (index 0):\n");
    scanf("%d %d", &linha, &coluna);
    while(linha < 0 || coluna < 0){
        printf("Linha e coluna devem ser maior que 0. Digite novamente:\n");
        scanf("%d %d", &linha, &coluna);
    }
    printf("Digite um valor numerico para armazenar na posicao na matriz\n");
    scanf("%f", &valor);
    atribui(matriz, linha, coluna, valor);
    valor_interno = acessa(matriz, linha, coluna);
    printf("O valor armazenado na matriz na linha %d e coluna %d eh: %f\n", linha, coluna, valor_interno);
    print_matriz(matriz);
    printf("Liberando memoria\n");
    libera(matriz);
}
