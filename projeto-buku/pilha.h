typedef struct pilha Pilha;
typedef struct elemento Elemento;

Pilha *criar();
int inserir(Pilha *pd);
int remover(Pilha *pd);
int tamanho(Pilha *pd);
void destruir(Pilha *pd);
