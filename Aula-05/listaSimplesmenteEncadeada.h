
#define MAX 50

struct aluno{
    int matricula;
    char nome[50];
    float av1;
    float av2;
    float pr;
};

typedef struct aluno Aluno;

typedef struct elemento* Lista;

Lista* criar();

void destruir(Lista *);

int tamanho(Lista *);

int cheia(Lista *);

int vazia(Lista *);

int inserirFim(Lista *, struct aluno);

int inserirInicio(Lista *ls, struct aluno);

int inserirOrdenado(Lista *ls, struct aluno);

int removerFim(Lista *);

int removerInicio(Lista *);

int removerValor(Lista*, int);

int acessarIndice( Lista*, int indice, struct aluno*);

int acessarValor(Lista*, int matricula, struct aluno*);

void destruir(Lista*);

