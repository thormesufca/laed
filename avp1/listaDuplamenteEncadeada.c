#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "listaDuplamenteEncadeada.h"

struct elemento
{
    char *nome;
    int idade;
    Elemento *proximo;
    Elemento *anterior;
};

struct no
{
    int tamanho;
    int menores;
    int idosos;
    Elemento *primeiro;
    Elemento *ultimo;
};

int vazia(Lista *ld)
{
    if (ld == NULL)
    {
        return 0;
    }
    return ld->tamanho == 0;
}

void recalculaListaRemocao(Lista *ld, Elemento *removido)
{
    ld->tamanho--;
    if (removido->idade >= 60)
    {
        ld->idosos--;
    }
    else if (removido->idade < 18)
    {
        ld->menores--;
    }
}

void recalculaListaInsercao(Lista *ld, Elemento *inserido)
{
    ld->tamanho++;
    if (inserido->idade >= 60)
    {
        ld->idosos++;
    }
    else if (inserido->idade < 18)
    {
        ld->menores++;
    }
}

void removerElemento(Lista *ld, Elemento *removido)
{
    if (removido->proximo == NULL && removido->anterior == NULL)
    {
        ld->primeiro = NULL;
        ld->ultimo = NULL;
    }
    else
    {
        if (removido->proximo != NULL && removido->anterior != NULL)
        { // No meio
            removido->proximo->anterior = removido->anterior;
            removido->anterior->proximo = removido->proximo;
        }
        else if (removido->proximo == NULL)
        { // Ultimo
            removido->anterior->proximo = removido->proximo;
            ld->ultimo = removido->anterior;
        }
        else
        { // Primeiro
            removido->proximo->anterior = removido->anterior;
            ld->primeiro = removido->proximo;
        }
    }

    recalculaListaRemocao(ld, removido);
    free(removido);
}

int inserirInicio(Lista *ld, Elemento *inserido)
{
    if (ld == NULL)
    {
        return 0;
    }
    inserido->proximo = ld->primeiro;
    ld->primeiro = inserido;
    if(ld->ultimo == NULL){
        ld->ultimo = inserido;
    }
    inserido->anterior = NULL;
    recalculaListaInsercao(ld, inserido);
    return 1;
}

int inserirUnico(Lista *ld, Elemento *inserido){
    if(ld == NULL){
        return 0;
    }
    if(ld->ultimo != NULL || ld->primeiro != NULL){
        return 0;
    }
    ld->ultimo = inserido;
    ld->primeiro = inserido;
    inserido->proximo = NULL;
    inserido->anterior = NULL;
    recalculaListaInsercao(ld, inserido);
    return 1;
}

int inserirFim(Lista *ld, Elemento *inserido)
{
    if (ld == NULL)
    {
        return 0;
    }
    inserido->proximo = NULL;
    if(ld->ultimo != NULL){
        ld->ultimo->proximo = inserido;
    }
    ld->ultimo = inserido;
    if(ld->primeiro == NULL){
        ld->primeiro = inserido;
    }
    recalculaListaInsercao(ld, inserido);
    return 1;
}

int inserirMeio(Lista *ld, Elemento *inserido, Elemento *anterior, Elemento *proximo)
{
    if (ld == NULL)
    {
        return 0;
    }
    inserido->anterior = anterior;
    inserido->proximo = proximo;
    anterior->proximo = inserido;
    proximo->anterior = inserido;
    recalculaListaInsercao(ld, inserido);
    return 1;
}

Lista *criar()
{
    Lista *ld;
    ld = (Lista *)malloc(sizeof(Lista));
    if (ld == NULL)
    {
        return 0;
    }
    ld->tamanho = 0;
    ld->idosos = 0;
    ld->menores = 0;
    ld->primeiro = NULL;
    ld->ultimo = NULL;
    return ld;
}

int inserirOrdenadoSemRepetir(Lista *ld, char *nome, int idade)
{
    if (ld == NULL)
    {
        return 0;
    }
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    char *novo_nome = malloc(sizeof(char) * strlen(nome) + 1);
    novo->nome = novo_nome;
    strcpy(novo->nome, nome);
    novo->idade = idade;
    if (vazia(ld))
    {
        return inserirUnico(ld, novo);
    }
    else
    {
        int compare = strcmp(nome, ld->primeiro->nome);
        if (compare < 0)
        {
           return inserirInicio(ld, novo);
        } else if(compare == 0){ //Se o primeiro tem nome igual
            return 0;
        }
        else
        {
            Elemento *ant = ld->primeiro;
            Elemento *aux = ant->proximo;
            while (aux != NULL)
            {
                compare = strcmp(nome, aux->nome);
                if (compare == 0)
                { // Já tem mesmo nome
                    return 0;
                }
                if (compare < 0)
                {
                    break;
                }
                ant = aux;
                aux = aux->proximo;
            }
            if (aux == NULL)
            {
                return inserirFim(ld, novo);
            }
            else
            {
                return inserirMeio(ld, novo, ant, aux);
            }
        }
    }
}

int eliminaIdade(Lista *ld, int idade)
{
    if (ld == NULL)
    {
        return 0;
    }
    Elemento *aux = ld->primeiro;
    int cont = 0;
    while (aux != NULL)
    {
        if (aux->idade == idade)
        {
            removerElemento(ld, aux);
            cont++;
        }
        aux = aux->proximo;
    }
    return cont;
}

int exibir(Lista *ld, int sentido)
{
    if (ld == NULL)
    {
        return 0;
    }
    if (vazia(ld))
    {
        return 1;
    }
    if (!sentido)
    {
        Elemento *aux = ld->primeiro;
        while (aux != NULL)
        {
            printf("[%s:%d]-> ", aux->nome, aux->idade);
            aux = aux->proximo;
        }
        printf("||\n");
    }
    else
    {
        Elemento *aux = ld->ultimo;
        while (aux != NULL)
        {
            printf("[%s:%d]-> ", aux->nome, aux->idade);
            aux = aux->anterior;
        }
        printf("||\n");
    }
    return 1;
}

int estatisticas(Lista *ld)
{
    if (ld == NULL)
    {
        return 0;
    }
    printf("Idosos: %d\n", ld->idosos);
    printf("Menores: %d\n", ld->menores);
    printf("Restante: %d\n", ld->tamanho - (ld->idosos + ld->menores));
    return 1;
}
