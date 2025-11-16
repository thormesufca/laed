#include "texto.h"
#include <stdio.h>

int tamanho(char* texto){
    int size = 0;
    while(texto[size] != '\0'){
        size++;
    }
    return size;
}

int main(){
    Texto* text;
    char recebido[50];
    printf("Digite uma palavra para armazenar: \n");
    fgets(recebido, 50, stdin);
    recebido[strcspn(recebido, "\n")] = 0;

    getchar();
    text = criar(tamanho(recebido));
    preencher(text, recebido);
    imprimir(text);
    printf("Digite um texto para concatenar: \n");
    fgets(recebido, 50, stdin);
    recebido[strcspn(recebido, "\n")] = 0;
    getchar();
    concatenar(text, recebido);
    imprimir(text);
    liberar(text);
}

