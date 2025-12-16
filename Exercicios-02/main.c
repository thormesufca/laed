#include "listaSimplesmenteEncadeada.h"
#include <stdio.h>


void eliminarDistancia(Lista *ldse){
    float dist;
    int i, eliminar;
    printf("Digite uma distancia para eliminar os proximos\n");
    scanf("%f", &dist);
    while(getchar() != '\n');
    printf("Digite um indice para calcular distancia\n");
    scanf("%d", &i);
    while(getchar() != '\n');
    eliminar = eliminePerto(ldse, i, dist);
    if(!eliminar){
        printf("Nao foi possivel eliminar pontos\n");
    } else{
        printf("Pontos eliminados com sucesso!\n");
    }

}

void calcularDistancia(Lista *ldse){
    int i, j;
    printf("Digite o indice do primeiro ponto\n");
    if(!lerInteiro(&i)){
        printf("Entrada invalida!\n");
        return;
    }

    printf("Digite o indice do segundo ponto\n");
    if(!lerInteiro(&j)){
        printf("Entrada invalida!\n");
        return;
    }
    float dist = distancia(ldse, i, j);
    if(dist == -1.0){
        printf("Nao foi possivel calcular distancia\n");
    } else{
        printf("Distancia entre os pontos eh de %.2f\n", dist);
    }
}

Lista* criarLista(){
    float x, y;
    printf("Digite coordenada x:\n");
    scanf("%f", &x);
    while(getchar() != '\n');
    printf("Digite coordenada y:\n");
    scanf("%f", &y);
    while(getchar() != '\n');
    Lista* ls = criar(x, y);
    if(ls == NULL){
        printf("Nao foi possivel criar lista\n");
    }
    return ls;
}

void inserirElementos(Lista *ldse){
    int continuar = 1;
    int inserir;
    float x, y;
    while(continuar == 1){
        printf("Digite coordenada x:\n");
        if(!lerFloat(&x)){
            printf("Entrada invalida!\n");
            continue;
        }
        
        printf("Digite coordenada y:\n");
        if(!lerFloat(&y)){
            printf("Entrada invalida!\n");
            continue;
        }
        inserir = inserirSemRepetir(ldse, x, y);
        if(inserir){
            printf("ponto inserido com sucesso: \n");
        } else{
            printf("Nao foi possivel adicionar o ponto\n");
        }
        printf("Deseja continuar inserindo elementos?\n1 - SIM\n2 - NAO\n");
        if(!lerInteiro(&continuar)){
            printf("Entrada Invalida! Encerrando insercao. \n");
            continuar = 2;
        }
    }
}

int lerInteiro(int *valor){
    int resultado = scanf("%d", valor);
    while(getchar() != '\n');
    return resultado == 1;
}

int lerFloat(float *valor){
    int resultado = scanf("%f", valor);
    while(getchar() != '\n');
    return resultado == 1;
}

int main(){
    Lista *ls = NULL;
    int funcao = 99;
    while(funcao != 0){
        printf("O que quer fazer?\n");
        printf("1 - Criar lista\n");
        printf("2 - Inserir Pontos\n");
        printf("3 - Exibir lista\n");
        printf("4 - Calcular distancia entre pontos\n");
        printf("5 - Eliminar pontos com base em distancia\n");
        printf("0 - Sair do programa\n");
        if(!lerInteiro(&funcao)){
            printf("Entrada invalida. Tente novamente\n");
            funcao = 99;
            continue;
        }
        switch(funcao){
            case 0:
                if(ls != NULL) destruir(ls);
                return 0;
            case 1:
                ls = criarLista();
                break;
            case 2:
                inserirElementos(ls);
                break;
            case 3:
                exibir(ls);
                break;
            case 4:
                calcularDistancia(ls);
                break;
            case 5:
                eliminarDistancia(ls);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
}
