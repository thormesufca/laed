#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

struct matriz
{
    int linhas;
    int colunas;
    float **dados;
};

Matriz *cria(int linhas, int colunas)
{
    Matriz* matriz;
    matriz = (Matriz*) malloc(sizeof(Matriz));
    if (matriz == NULL)
    {
        printf("Nao foi possível criar a matriz. Memoria insuficiente.\n");
        exit(1);
    }
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->dados = (float **) malloc(linhas * sizeof(float *));
    if (matriz->dados == NULL)
    {
        free(matriz);
        printf("Nao foi possível criar espaços para matriz. Memoria insuficiente.\n");
        exit(1);
    }
    for (int i = 0; i < linhas; i++)
    {
        matriz->dados[i] = (float *) malloc(colunas * sizeof(float));
        if (matriz->dados[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(matriz->dados[j]);
            }
            free(matriz->dados);
            free(matriz);
            printf("Nao foi possível criar linha %d da matriz. Memoria insuficiente.\n", i + 1);
            exit(1);
        }
    }
    return matriz;
}

void libera(Matriz* matriz){
    for (int i = 0; i < matriz->linhas; i++){
        free(matriz->dados[i]);
    }
    free(matriz->dados);
    free(matriz);
}

void preenche_total(Matriz* matriz, float valor){
    for (int i = 0; i < matriz->linhas; i++){
        for (int j = 0; j < matriz->colunas; j++){
            matriz->dados[i][j] = valor;
        }
    }
}

void preenche(Matriz* matriz){
    float valor;
    for (int i = 0; i < matriz->linhas; i++){
        for (int j = 0; j < matriz->colunas; j++){
            printf("Digite o valor para linha %d e coluna %d:\n", i, j);
            scanf("%f", &valor);
            matriz->dados[i][j] = valor;
        }
    }
}

void print_matriz(Matriz* matriz){
    printf("\t");
    for (int i =0; i<matriz->colunas; i++){
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 0; i < matriz->linhas; i++){
        printf("%d\t", i);
        for (int j = 0; j < matriz->colunas; j++){
            printf("[%.2f]\t", matriz->dados[i][j]);
        }
        printf("\n");
    }
}

float acessa(Matriz* matriz, int linha, int coluna){
    if(linha + 1 > matriz->linhas){
        printf("Nao eh possivel acessar o valor. Matriz possui %d linhas, iniciando por 0. Ultima linha eh %d\n", matriz->linhas, matriz->linhas - 1);
        return -1;
    } else if(coluna + 1 > matriz->colunas){
        printf("Nao eh possivel acessar o valor. Matriz possui %d colunas, iniciando por 0. Ultima coluna eh %d\n", matriz->colunas, matriz->colunas - 1);
        return -1;
    } else{
        return matriz->dados[linha][coluna];
    }
}

void atribui(Matriz* matriz, int linha, int coluna, float valor){
    if(linha + 1 > matriz->linhas){
        printf("Nao eh possivel atribuir o valor. Matriz possui %d linhas, iniciando por 0. Ultima linha eh %d\n", matriz->linhas, matriz->linhas - 1);
    } else if(coluna + 1 > matriz->colunas){
        printf("Nao eh possivel atribuir o valor. Matriz possui %d colunas, iniciando por 0. Ultima coluna eh %d\n", matriz->colunas, matriz->colunas - 1);
    }
    else{
        matriz->dados[linha][coluna] = valor;
    }
}

int linhas(Matriz* matriz){
    return matriz->linhas;
}

int colunas(Matriz* matriz){
    return matriz->colunas;
}
