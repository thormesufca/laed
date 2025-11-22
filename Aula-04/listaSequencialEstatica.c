#include <stdio.h>
#include <stdlib.h>
#include "listaSequencialEstatica.h"

struct lista {
    int quantidade;
    struct aluno dados[MAX];
};

Lista* criar(){
    Lista* ls;
    ls = (Lista*) malloc(sizeof(Lista));
    if(ls != NULL){
        ls->quantidade = 0;
    }
    return ls;
}

void destruir(Lista* ls){
    free(ls);
}

int tamanho(Lista *lse){
    if(lse == NULL){
        return -1;
    } else{
        return lse->quantidade;
    }
}

int cheia(Lista *lse){
    if(lse == NULL){
        return -1;
    } else if(lse->quantidade == MAX){
        return 1;
    } else{
        return 0;
    }
}

int vazia(Lista *lse){
    if(lse == NULL){
        return -1;
    } else if(lse->quantidade == 0){
        return 1;
    } else{
        return 0;
    }
}

int inserirFim(Lista *lse, struct aluno novo){
    if(lse == NULL){
        return 0;
    } else if(cheia(lse)){
        return 0;
    } else{
        lse->dados[lse->quantidade] = novo;
        lse->quantidade++;
        return 1;
    }
}

int inserirInicio(Lista *lse, struct aluno novo){
    if(lse == NULL){
        return 0;
    } else if(cheia(lse)){
        return 0;
    } else{
        int i;
        for (i = (lse->quantidade) -1; i >=0; i--){
            lse->dados[i+1] = lse->dados[i];
        }
        lse->dados[0] = novo;
        lse->quantidade++;
        return 1;
    }
}

int inserirOrdenado(Lista* lse, struct aluno novo){
    if(lse == NULL){
        return 0;
    } else if(cheia(lse)){
        return 0;
    } else{
        int i, pos = 0;
        while(lse->dados[pos].matricula < novo.matricula && pos < lse->quantidade){
            pos++;
        }

        for (i = (lse->quantidade) -1; i >= pos; i--){
            lse->dados[i+1] = lse->dados[i];
        }
        lse->dados[pos] = novo;
        lse->quantidade++;
        return 1;
    }
}

int removerFim(Lista *lse){
    if(lse == NULL){
        return 0;
    } else if(cheia(lse)){
        return 0;
    } else{
        lse->quantidade--;
        return 1;
    }
}

int removerInicio(Lista *lse){
    if(lse == NULL){
        return 0;
    } else if(cheia(lse)){
        return 0;
    } else{
        for(int i = 0; i < lse->quantidade -1; i++){
            lse->dados[i] = lse->dados[i+1];
        }
        lse->quantidade--;
        return 1;
    }
}

int removerValor(Lista *lse, int matricula){
    if(lse == NULL){
        return 0;
    } else if(cheia(lse)){
        return 0;
    } else{
        int i; int pos = 0;
        while(lse->dados[pos].matricula != matricula && pos < lse->quantidade){
            pos++;
        }
        if(pos == lse->quantidade){
            return 0;
        }
        for(int i = pos; i < (lse->quantidade) - 1; i++){
            lse->dados[i] = lse->dados[i+1];
        }
        lse->quantidade--;
        return 1;
    }
}

int acessarIndice(Lista *lse, int indice, struct aluno *a){
    if(lse == NULL){
        return 0;
    } else if(indice >= lse->quantidade || indice < 0){
        return 0;
    } else{
        *a = lse->dados[indice];
        return 1;
    }
}

int acessarValor(Lista *lse, int matricula, struct aluno *a){
    if(lse == NULL){
        return 0;
    } else{
        int i, pos = 0;
        while(lse->dados[pos].matricula != matricula && pos < lse->quantidade){
            pos++;
        }
        if(pos == lse->quantidade){
            return 0;
        }
        *a = lse->dados[pos];
        return 1;


    }
}

