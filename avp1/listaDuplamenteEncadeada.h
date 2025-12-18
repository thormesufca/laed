typedef struct no Lista;
typedef struct elemento Elemento;

Lista* criar();

int exibir(Lista *ld, int sentido);

int estatisticas(Lista *ld);

int inserirOrdenadoSemRepetir(Lista *ld, char *nome, int idade);

int eliminaIdade(Lista *ld, int idade);

