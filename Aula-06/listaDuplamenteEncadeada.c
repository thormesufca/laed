#include <stdlib.h>
#include <stdio.h>
#include "listas.h"

struct elemento
{
    struct elemento *anterior;
    Aluno dados;
    struct elemento *proximo;
};

typedef struct elemento Elemento;
typedef struct elemento *Lista;

Lista *criar()
{
    Lista *ldde;
    ldde = (Lista *)malloc(sizeof(Lista));
    if (ldde != NULL)
    {
        *ldde = NULL;
    }
    return ldde;
}

int inserirInicio(Lista *ldde, Aluno novosdados)
{
    if (ldde == NULL)
    {
        return 0;
    }
    else
    {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL)
            return 0;
        novo->dados = novosdados;
        novo->anterior = NULL;
        novo->proximo = *ldde;
        if (*ldde != NULL)
        {
            (*ldde)->anterior = novo;
        }
        *ldde = novo;
        return 1;
    }
}

int inserirFim(Lista *ldde, Aluno novosdados)
{
    if (ldde == NULL)
    {
        return 0;
    }
    else
    {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL)
            return 0;
        novo->proximo = NULL;
        novo->dados = novosdados;
        if (vazia(ldde))
        {
            novo->anterior = NULL;
            *ldde = novo;
        }
        else
        {
            Elemento *next = *ldde;
            while (next->proximo != NULL)
            {
                next = next->proximo;
            }
            next->proximo = novo;
            novo->anterior = next;
        }
    }
    return 1;
}

int vazia(Lista *ldde)
{
    if (ldde == NULL)
    {
        return 1;
    }
    else if (*ldde == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserirOrdenado(Lista *ldde, Aluno novosdados)
{
    if (ldde == NULL)
    {
        return 0;
    }
    else
    {
        Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
        if (novo == NULL)
            return 0;
        novo->dados = novosdados;
        // Se vazio ou matrícula do inserido é menor que a do primeiro, o novo passa a ser o primeiro
        if (vazia(ldde) || (*ldde)->dados.matricula > novo->dados.matricula)
        {
            novo->proximo = *ldde;
            novo->anterior = NULL;
            if (*ldde != NULL)
            {
                (*ldde)->anterior = novo;
            }
            *ldde = novo;
        }
        else
        {
            Elemento *prox = (*ldde)->proximo;
            Elemento *atual = *ldde;
            while (prox != NULL && prox->dados.matricula < novo->dados.matricula)
            {
                atual = prox;
                prox = prox->proximo;
            }
            atual->proximo = novo;
            if (prox != NULL)
            {
                prox->anterior = novo;
            }
            novo->proximo = prox;
            novo->anterior = atual;
        }
        return 1;
    }
}

int tamanho(Lista *ldde)
{
    if (vazia(ldde))
    {
        return 0;
    }
    int cont = 0;
    Elemento *aux = *ldde;
    while (aux != NULL)
    {
        cont++;
        aux = aux->proximo;
    }
    return cont;
}
int cheia(Lista *ldde)
{
    return 0;
}

void destruir(Lista *ldde)
{
    if (ldde != NULL)
    {
        Elemento *aux;
        while (*ldde != NULL)
        {
            aux = *ldde;
            *ldde = (*ldde)->proximo;
            free(aux);
        }
    }
    // free(ldde);
}

int removerInicio(Lista *ldde)
{
    if (vazia(ldde))
    {
        return 0;
    }
    else
    {
        Elemento *aux = *ldde;
        *ldde = aux->proximo;
        if (aux->proximo != NULL)
        {
            aux->proximo->anterior = NULL;
        }
        free(aux);
        return 1;
    }
}
int removerFim(Lista *ldde)
{
    if (vazia(ldde))
    {
        return 0;
    }
    else if ((*ldde)->proximo == NULL)
    {
        Elemento *aux = *ldde;
        *ldde = NULL;
        free(aux);
        return 1;
    }
    else
    {
        Elemento *aux = *ldde;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->anterior->proximo = NULL;
        free(aux);
        return 1;
    }
}

int removerValor(Lista *ldde, int matricula)
{
    if (vazia(ldde))
    {
        return 0;
    }
    //Se o elemento for o primeiro
    else if ((*ldde)->dados.matricula == matricula)
    {
        Elemento *aux = *ldde;
        *ldde = aux->proximo;
        free(aux);
        return 1;
    }
    //Se não, busca o elemento
    else
    {
        Elemento *atual = *ldde;
        while (atual != NULL && atual->dados.matricula != matricula)
        {
            atual = atual->proximo;
        }

        if (atual == NULL) return 0; // Se passou do último elemento
        
        atual->anterior->proximo = atual->proximo; //Move o ponteiro do elemento anterior para o próximo (retira do atual)
        
        //Se não é o último elemento
        if(atual->proximo != NULL){ 
            atual->proximo->anterior = atual->anterior; //Move o ponteiro anterior do próximo elemento para o elemento anterior (retira do atual)
        }
        free(atual);
        return 1;
    }
}

int acessarIndice(Lista *ldde, int pos, Aluno *a)
{
    if (vazia(ldde))
    {
        return 0;
    }
    else if (pos < 0)
    {
        return 0;
    }
    else
    {
        int cont = 0;
        Elemento *aux = *ldde;
        while (aux != NULL && pos != cont)
        {
            aux = aux->proximo;
            cont++;
        }
        if (aux == NULL)
            return 0;
        *a = aux->dados;
        return 1;
    }
}

int acessarValor(Lista *ldde, int matricula, Aluno *a)
{
    if (vazia(ldde))
    {
        return 0;
    }
    else
    {
        Elemento *aux = *ldde;
        while (aux != NULL && matricula != aux->dados.matricula)
        {
            aux = aux->proximo;
        }
        if (aux == NULL)
            return 0;
        *a = aux->dados;
        return 1;
    }
}
