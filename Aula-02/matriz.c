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
        printf("Não foi possível criar a matriz. Memória insuficiente.\n");
        exit(1);
    }
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->dados = malloc(linhas * sizeof(float *));
    if (matriz->dados == NULL)
    {
        free(matriz);
        printf("Não foi possível criar espaços para matriz. Memória insuficiente.\n");
        exit(1);
    }
    for (int i = 0; i < linhas; i++)
    {
        matriz->dados[i] = malloc(colunas * sizeof(float));
        if (matriz->dados[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(matriz->dados[j]);
            }
            free(matriz->dados);
            free(matriz);
            printf("Não foi possível criar linha %d da matriz. Memória insuficiente.\n", i + 1);
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

void preenche(Matriz* matriz, float valor){
    for (int i = 0; i < matriz->linhas; i++){
        for (int j = 0; j < matriz->colunas; j++){
            matriz->dados[i][j] = valor;
        }
    }
}

void print_matriz(Matriz* matriz){
    for (int i = 0; i < matriz->linhas; i++){
        for (int j = 0; j < matriz->colunas; j++){
            printf("%d\t[%.2f]\t",i, matriz->dados[i][j]);
        }
        printf("\n");
    }
}

float acessa(Matriz* matriz, int linha, int coluna){
    return matriz->dados[linha][coluna];
}

void atribui(Matriz* matriz, int linha, int coluna, float valor){
    matriz->dados[linha][coluna] = valor;
}

int linhas(Matriz* matriz){
    return matriz->linhas;
}

int colunas(Matriz* matriz){
    return matriz->colunas;
}