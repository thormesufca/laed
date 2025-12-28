#include <stdio.h>
#include "matriz.h"
#include "pilha.h"
#include "colors.h"

void print_tabuleiro(Tabuleiro *matriz)
{
    if (matriz == NULL)
    {
        return;
    }
    if (linhas(matriz) < 1 || colunas(matriz) < 1)
    {
        return;
    }
    char fg[12];
    set_foreground_color(2, 0, 1, fg);
    char bg[12];
    set_background_color(3, bg);
    char reset[12];
    set_background_color(8, reset);
    printf("\n\t   ");
    for (int i = 0; i < colunas(matriz); i++)
    {
        printf("%s%s %02d %s", fg, bg, i, reset);
    }
    printf("\n");
    for (int i = 0; i < linhas(matriz); i++)
    {
        set_foreground_color(2, 1, 0, fg);
        set_background_color(3, bg);
        printf("%s%s\t%02d ", fg, bg, i);
        for (int j = 0; j < colunas(matriz); j++)
        {
            Pilha *pd;
            if (!acessar(matriz, i, j, &pd))
            {
                printf("Não foi possível acessar a pilha nessa posição");
                continue;
            };
            if ((i + j) % 2 == 0)
            { // Se soma é par (diagonais principais) (branco)
                set_foreground_color(1, 0, 0, fg);
                set_background_color(2, bg);
            }
            else
            { //(preto)
                set_foreground_color(2, 0, 0, fg);
                set_background_color(1, bg);
            }
            if (tamanho(pd) == 0)
            {
                printf("%s%s    %s", fg, bg, reset);
            }
            else
            {
                printf("%s%s %02d %s", fg, bg, tamanho(pd), reset);
            }
        }
        printf("\n%s", reset);
    }
}

void imprime_repeated_char(char letra, int vezes)
{
    for (int i = 0; i < vezes; i++)
    {
        printf("%c", letra);
    }
}

void imprime_erro(char *message)
{
    char bg[12];
    set_background_color(4, bg);
    char fg[12];
    set_foreground_color(5, 0, 0, fg);
    printf("%s%s", bg, fg);
    imprime_repeated_char(' ', strlen(message) + 2);
    printf("\n");
    printf(" %s \n", message);
    imprime_repeated_char(' ', strlen(message) + 2);
    set_background_color(9, bg);
    printf("\n%s", bg);
}