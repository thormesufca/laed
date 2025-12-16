typedef struct elemento* Lista;

Lista* criar(float x, float y);

void destruir(Lista *);

int tamanho(Lista *);

int cheia(Lista *);

int vazia(Lista *);

int exibir(Lista *);

int inserirSemRepetir(Lista *ls, float x, float y);

int eliminePerto(Lista *ldse, int i, float d);

float distancia(Lista *ls, int i, int j);

void destruir(Lista*);
