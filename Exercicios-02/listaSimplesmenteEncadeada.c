
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "listaSimplesmenteEncadeada.h"


struct elemento {
    float x;
    float y;
    struct elemento *proximo;
};

typedef struct elemento Elemento;

Lista* criar(float x, float y){
    Lista *ldse;
    ldse = (Lista*) malloc(sizeof(Lista));
    Elemento *inicial = (Elemento*) malloc(sizeof(Elemento));
    inicial->x = x;
    inicial->y = y;
    inicial->proximo = NULL;
    if(ldse == NULL || inicial == NULL){
        return NULL;
    } else {
        *ldse = inicial;
    }
    return ldse;
}

int exibir(Lista *ldse){
     if(vazia(ldse)){
        return 0;
    }
    Elemento *aux = *ldse;
    while(aux != NULL){
        printf("(%.2f,%.2f)\n", aux->x, aux->y);
        aux = aux->proximo;
    }
    printf("\n");
    return 1;
}

int inserirSemRepetir(Lista *ldse, float x, float y){
    if(ldse == NULL){
        return 0;
    } else{
        Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
        novo->x = x;
        novo->y = y;
        novo->proximo = NULL;
        if(vazia(ldse)){
            //lista est� vazia, insere o elemento
            *ldse = novo;
        } else{
            Elemento *aux = *ldse;

            //Compara com o primeiro elemento
            if(aux->x == x && aux->y == y) return 0;
            //Compara os pr�ximos dos demais
            while(aux->proximo != NULL){
                if(aux->proximo->x == novo->x && aux->proximo->y == novo->y){
                    return 0;
                }
                aux = aux->proximo;
            }
            //Se n�o retornou, comparou todos os elementos e n�o encontrou igual, adiciona
            aux->proximo = novo;
        }
        return 1;
    }
}

float distanciaEntrePontos(Elemento *a, Elemento *b){
    return sqrt(pow(b->x - a->x, 2.0) + pow(b->y - a->y, 2.0));
}

float distancia(Lista *ldse, int i, int j){
    if( ldse == NULL){
        return -1.0;
    } else{
        if(i<0 || j < 0){
            return -1.0;
        } else{
            int limite = tamanho(ldse) - 1;
            if(limite < i || limite < j){
                return -1.0;
            } else{
                if(i == j){
                    return 0.0;
                }
                //Colocar o i sempre como primeiro
                if (i > j){
                    int aux = j;
                    j = i;
                    i = aux;
                }
                int cont = 0;
                Elemento *aux = *ldse;
                Elemento *a, *b;
                while(cont < i){
                    aux = aux->proximo;
                    cont++;
                }
                a = aux;
                while (cont < j){
                    aux = aux->proximo;
                    cont++;
                }
                b = aux;
                return distanciaEntrePontos(a, b);
            }
        }
    }
}

int eliminePerto(Lista *ldse, int i, float d){
    if( ldse == NULL){
        return 0;
    } else{
        int limite = tamanho(ldse) - 1;
        if(limite < i){
            return 0;
        } else{
            int cont = 0;
            Elemento *aux = *ldse;
            Elemento *a;
            while(cont < i){
                aux = aux->proximo;
                cont++;
            }
            a = aux;

            //Retorna ao comeco da lista
            Elemento *ant = *ldse;
            aux = ant->proximo;

            while(aux != NULL){
                //Se esta na distancia, remove o elemento
                if(distanciaEntrePontos(a, aux) <= d){
                    ant->proximo = aux->proximo;
                    free(aux);
                    aux = ant->proximo;
                } else{
                    ant = aux;
                    aux = aux->proximo;
                }
            }
            return 1;
        }
    }
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
            *ldse = (*ldse)-> proximo;
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
        while(aux->proximo != NULL){
            ant = aux;
            aux = aux->proximo;
        }
        ant->proximo = aux->proximo;
        free(aux);
        return 1;
    }
}
