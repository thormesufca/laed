#include "listaDuplamenteEncadeada.h"
#include <stdio.h>

int main(){
    Lista *ld = criar();
    inserirOrdenadoSemRepetir(ld,"Enzo", 15);
    inserirOrdenadoSemRepetir(ld,"Thormes", 46);
    inserirOrdenadoSemRepetir(ld, "Matusalem", 97);
    inserirOrdenadoSemRepetir(ld, "Roberto", 32);
    exibir(ld, 0);
    exibir(ld, 1);
    inserirOrdenadoSemRepetir(ld, "Enzo", 17);
    inserirOrdenadoSemRepetir(ld, "Marcos", 23);
    inserirOrdenadoSemRepetir(ld, "Antonio", 18);
    inserirOrdenadoSemRepetir(ld, "Hermenegildo", 60);
    inserirOrdenadoSemRepetir(ld, "Francisco", 12);
    inserirOrdenadoSemRepetir(ld, "Bento", 16);
    inserirOrdenadoSemRepetir(ld, "Zacarias", 56);
    inserirOrdenadoSemRepetir(ld, "Antonia", 23);
    estatisticas(ld);
    eliminaIdade(ld, 97);
    estatisticas(ld);
    eliminaIdade(ld, 23);
    estatisticas(ld);
    exibir(ld, 0);
}