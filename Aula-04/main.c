#include <stdlib.h>
#include <stdio.h>
#include "listaSequencialEstatica.h"

int main(){
    Lista *aed;
    aed = NULL;
    aed = criar();
    struct aluno al = {.matricula = 123, .nome = "thormes", .av1 = 10, .av2 = 8, .pr = 7};
    inserirInicio(aed, al);
    struct aluno al2;
    acessarValor(aed, 123, &al2);
    printf("Tamanho: %d\n", tamanho(aed));
    printf("Matricula aluno 2: %d\n", al2.matricula);
}
