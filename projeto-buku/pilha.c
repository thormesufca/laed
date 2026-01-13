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
    pd = (Pilha *)malloc(sizeof(Pilha));
    if (pd != NULL)
    {
        pd->topo = NULL;
        pd->tamanho = 0;
    }
    return pd;
}

int vazia(Pilha *pd)
{
    if (pd == NULL)
    {
        return 1;
    }
    else
    {
        return pd->tamanho == 0;
    }
}

int inserir(Pilha *pd)
{
    if (pd == NULL)
    {
        return 0;
    }
    else
    {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL)
            return 0;
        novo->proximo = pd->topo;
        pd->topo = novo;
        pd->tamanho++;
        return 1;
    }
}

int remover(Pilha *pd)
{
    if (vazia(pd))
    {
        return 0;
    }
    else
    {
        Elemento *aux = pd->topo;
        pd->topo = aux->proximo;
        pd->tamanho--;
        free(aux);
        return 1;
    }
}

void destruir(Pilha *pd)
{
    if (pd != NULL)
    {
        if (!vazia(pd))
        {
            Elemento *aux;
            while (pd->topo != NULL)
            {
                aux = pd->topo;
                pd->topo = aux->proximo;
                free(aux);
            }
        }
        free(pd);
    }
}

int tamanho(Pilha *pd)
{
    if (pd == NULL)
    {
        return -1;
    }
    else
    {
        return pd->tamanho;
    }
}