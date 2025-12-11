#include <stdlib.h>
#include <stdio.h>
#include "listas.h"

struct elemento
{
    struct elemento *anterior;
    int valor;
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

int inserirInicio(Lista *ldde, int valor)
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
        novo->valor = valor;
        novo->anterior = NULL;
        novo->proximo = *ldde;
        //Se a lista está vazia, seta o anterior do primeiro para o novo
        if (*ldde != NULL)
        {
            (*ldde)->anterior = novo;
        }
        *ldde = novo;
        return 1;
    }
}

int inserirFim(Lista *ldde, int valor)
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
        novo->valor = valor;
        //Se lista está vazia, basta adicionar, como no início
        if (vazia(ldde))
        {
            novo->anterior = NULL;
            *ldde = novo;
        }
        else 
        {
            Elemento *next = *ldde;
            //Navega até o ultimo elemento
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

int inserirOrdenado(Lista *ldde, int valor)
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
        novo->valor = valor;
        // Se vazio ou matrícula do inserido é menor que a do primeiro, o novo passa a ser o primeiro
        if (vazia(ldde) || (*ldde)->valor > novo->valor)
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
            //Navega para localizar posição de inserção
            Elemento *prox = (*ldde)->proximo;
            Elemento *atual = *ldde;
            //Enquanto não chega no último e o valor do próximo é menor do que o que quero inserir
            while (prox != NULL && prox->valor < novo->valor)
            {
                atual = prox;
                prox = prox->proximo;
            }
            //Ajusta os ponteiros do novo
            novo->proximo = prox;
            novo->anterior = atual;

            //O próximo do atual passa a ser o novo
            atual->proximo = novo;
            
            //Se não é o último
            if (prox != NULL)
            {
                prox->anterior = novo; //O anterior do próximo passa a ser o novo
            }
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

int removerValor(Lista *ldde, int valor)
{
    if (vazia(ldde))
    {
        return 0;
    }
    //Se o elemento for o primeiro
    else if ((*ldde)->valor == valor)
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
        while (atual != NULL && atual->valor != valor)
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

int acessarIndice(Lista *ldde, int pos, int *v)
{
    if (vazia(ldde))
    {
        return 0;
    }
    else if (pos <= 0)
    {
        return 0;
    }
    else
    {
        int cont = 1;
        Elemento *aux = *ldde;
        //Enquanto não é o último e não encontrou a posição indicada (início em 1)
        while (aux != NULL && pos != cont)
        {
            aux = aux->proximo;
            cont++;
        }
        if (aux == NULL) //Não encontrou a posição
            return 0;
        
        
        *v = aux->valor; //Atribui o valor do encontrado para o ponteiro passado
        return 1;
    }
}

int acessarValor(Lista *ldde, int valor, int *v)
{
    if (vazia(ldde))
    {
        return 0;
    }
    else
    {
        Elemento *aux = *ldde;
        //Enquanto não é o último e não encontrou o valor procurado
        while (aux != NULL && valor != aux->valor)
        {
            aux = aux->proximo;
        }
        if (aux == NULL) //Se passou do último, não encontrou
            return 0;
        *v = aux->valor; //Atribui o valor do encontrado para o ponteiro passado
        return 1;
    }
}
