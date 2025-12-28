#include <stdlib.h>
#include "pilha.h"

struct elemento
{
    struct elemento *proximo;
};

struct pilha
{
    struct elemento *topo;
    int tamanho;
};

Pilha *criar()
{
    Pilha *pd;
    pe = (Pilha *)malloc(sizeof(Pilha));
    if (pe != NULL)
    {
        pe->topo = NULL;
        pe->tamanho = 0;
    }
    return pe;
}

int vazia(Pilha *pd)
{
    if (pe == NULL)
    {
        return 1;
    }
    else
    {
        return pe->tamanho == 0;
    }
}

int inserir(Pilha *pd)
{
    if (pe == NULL)
    {
        return 0;
    }
    else
    {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL)
            return 0;
        novo->proximo = pe->topo;
        pe->topo = novo;
        pe->tamanho++;
        return 1;
    }
}

int remover(Pilha *pd)
{
    if (vazia(pe))
    {
        return 0;
    }
    else
    {
        Elemento *aux = pe->topo;
        pe->topo = aux->proximo;
        pe->tamanho--;
        free(aux);
        return 1;
    }
}

void destruir(Pilha *pd)
{
    if (pe != NULL)
    {
        if (!vazia(pe))
        {
            Elemento *aux;
            while (pe->topo != NULL)
            {
                aux = pe->topo;
                pe->topo = aux->proximo;
                free(aux);
            }
        }
        free(pe);
    }
}

int tamanho(Pilha *pd)
{
    if (pe == NULL)
    {
        return -1;
    }
    else
    {
        return pe->tamanho;
    }
}