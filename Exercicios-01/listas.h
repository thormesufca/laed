typedef struct lista Lista;

Lista* criar();

void destruir(Lista *);

int tamanho(Lista *);

int cheia(Lista *);

int vazia(Lista *);

int inserirFim(Lista *, int);

int inserirInicio(Lista *ls, int);

int inserirOrdenado(Lista *ls, int);

int removerFim(Lista *);

int removerInicio(Lista *);

int removerValor(Lista*, int);

int acessarIndice( Lista*, int indice, int valor);

int acessarValor(Lista*, int valor);

void destruir(Lista*);

