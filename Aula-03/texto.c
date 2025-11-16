#include <stdio.h>
#include <stdlib.h>
#include "texto.h"

struct texto{
    int tamanho;
    char *dado;
};

Texto* criar(int tamanho){
    Texto* texto;
    texto = (Texto*) malloc(sizeof(Texto));
    texto->dado = malloc(tamanho * sizeof(char));
    texto->tamanho = tamanho;
    return texto;
}


void liberar(Texto* texto){
    free(texto->dado);
    free(texto);
}

void preencher(Texto* texto, char* entrada){
    int size = 0;
    while(entrada[size] != '\0'){
        size++;
    }
    size++;

    if(size > texto->tamanho){
         char*  novo_dado;
         novo_dado = malloc(size * sizeof(char));
         free(texto->dado);
         texto->dado = novo_dado;
         texto->tamanho = size;
    } else{
        texto->tamanho = size;
    }

    for(int i = 0; i < size; i++){
        texto->dado[i] = entrada[i];
    }
}

void concatenar(Texto* texto, char* entrada){
    int size = 0;
    while(entrada[size] != '\0'){
        size++;
    }
    size++;
    char* novo_dado;
    novo_dado = malloc((texto->tamanho + size) * sizeof(char));
    int pos = 0;
    for (int i = 0; i < texto->tamanho - 1; i++){
        novo_dado[i] = texto->dado[i];
        pos++;
    }
    for(int i = 0; i < size; i++ ){
        novo_dado[i + pos] = entrada[i];
    }
    free(texto->dado);
    texto->dado = novo_dado;
    texto->tamanho = texto->tamanho + size;
}

void imprimir(Texto* texto){
    printf("Texto armazenado:\n");
    printf(texto->dado);
    printf("\n");
}
