#include <stdlib.h>
#include <stdio.h>
#include "listaSimplesmenteEncadeada.h"


struct elemento {
    Aluno dados;
    struct elemento *proximo;
};

typedef struct elemento Elemento;

Lista* criar(){
    Lista *ldse;
    ldse = (Lista*) malloc(sizeof(Lista));
    if(ldse != NULL){
        *ldse = NULL;
    }
    return ldse;
}

void inserirInicio(Lista *ldse, Aluno novosdados){
    if( ldse == NULL){
        return 0;
    }
    else{
        Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
        if(novo == NULL) return 0;
        novo->dados = novosdados;
        novo->prox = *ldse;
        *ldse = novo;
        return 1;
    }
}

void inserirFim(Lista *ldse, Aluno novosdados){
    if(ldse == NULL){
        return 0;
    }
    else{
        Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
        if(novo == NULL) return 0;
        novo->proximo = NULL;
        novo->dados = novosdados;
        if(vazia(ldse)){
            *ldse = novo;
        }
        Elemento *next = *ldse;
        while(next->proximo != NULL){
            next = next->proximo;
        }
        next->proximo = novo;
    }
    return 1;
}

int vazia(Lista *ldse){
    if(ldse == NULL){
        return 1;
    }
    else if(*ldse == NULL){
        return 1;
    }
    else{
        return 0;
    }

}

int inserirOrdenado(Lista *ldse, Aluno novosdados){
    if(ldse == NULL){
        return -1;
    } else{
        Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
        if(novo == NULL) return 0;
        novo->dados = novosdados;
        if(vazia(ldse) || (*ldse)->dados.matricula < novo->dados.matricula){
            novo->proximo = *ldse;
            *ldse = novo;
        } else{
            Elemento *prox = (*ldse)->proximo;
            Elemento *atual = *ldse;
            while(prox != NULL && prox->dados.matricula > novo->dados.matricula){
                atual = prox;
                prox = prox->proximo;
            }
            atual->proximo = novo;
            novo->proximo = prox;
        }
        return 1;
    }
}

int tamanho(Lista *ldse){
    if(vazia(ldse)){
        return 0;
    }
    int cont = 0;
    Elemento *aux = *ldse;
    while(aux != NULL){
        cont++;
        aux = aux->proximo;
    }
    return cont;
}
int cheia(Lista *ldse){
    return 0;
}

void destruir(Lista *ldse){
    if(ldse != NULL){
        Elemento *aux;
        while (*ldse != NULL){
            aux = *ldse;
            *ldse = (*ldse)-> prox;
            free(aux);
        }
    }
    //free(ldse);
}

int removerInicio(Lista *ldse){
    if(vazia(ldse)){
        return 0;
    }
    else{
        Elemento *aux = *ldse;
        *ldse = aux->proximo;
        free(aux);
        return 1;
    }
}
int removerFim(Lista *ldse){
    if(vazia(ldse)){
        return 0;
    }
    else if((*ldse)->proximo == NULL){
        Elemento *aux = *ldse;
        *ldse = aux->proximo;
        free(aux);
        return 1;
    } else{
        Elemento *ant = *ldse;
        Elemento *aux = ant->proximo;
        while(aux-prox != NULL){
            ant = aux;
            aux = aux->proximo;
        }
        ant->proximo = aux->proximo;
        free(aux);
        return 1;
    }
}

int removerValor(Lista *ldse, int matricula){
        if(vazia(ldse)){
        return 0;
    }
    else if((*ldse)->dados.matricula == matricula){
        Elemento *aux = *ldse;
        *ldse aux->proximo;
        free(aux);
        return 1
    } else{
            Elemento *prox = (*ldse)->proximo;
            Elemento *atual = *ldse;
            while(prox != NULL && prox->dados.matricula != matricula){
                atual = prox;
                prox = prox->proximo;
            }
            if(prox == NULL) return 0;
            atual->proximo = prox->proximo;
            free(prox);
            return 1;
        }
}

int acessarIndice(Lista *ldse, int pos, Aluno *a){
    if(vazia(ldse)){
        return 0;
    }
    else if(pos <0){
        return 0;
    } else{
        int cont = 0;
        Elemento *aux = *ldse;
        while(aux != NULL && pos != cont){
            aux = aux->proximo;
            cont++;
        }
        if(aux == NULL) return 0;
        *a = aux->dados;
        return 1;
    }
}

int acessarValor(Lista *ldse, int matricula, Aluno *a){
    if(vazia(ldse)){
        return 0;
    }
    else{
        Elemento *aux = *ldse;
        while(aux != NULL && matricula != aux->dados.matricula){
            aux = aux->proximo;
        }
        if(aux == NULL) return 0;
        *a = aux->dados;
        return 1;
    }
}
