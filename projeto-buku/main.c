#include "matriz.h"
#include <stdio.h>

int main(){
    Tabuleiro *matriz;
    matriz = cria(8);
    esvazia_espaco(matriz, 5, 5);
    print_tabuleiro(matriz);
    libera(matriz);
}
