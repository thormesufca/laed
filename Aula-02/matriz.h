/* matriz m por n */
/* Tipo exportado */
typedef struct matriz Matriz;

/* Funções exportadas */
/* Função cria
** Aloca e retorna uma matriz de dimensão m por n
*/
Matriz* cria(int, int);

/* Função libera
** Libera a memória de uma matriz previamente criada.
*/
void libera(Matriz*);

/* Função preenche
** Preenche a matriz inteira com o mesmo valor
*/
void preenche(Matriz*, float);

/* Função print
** Imprime todos os itens da matriz no console
*/
void print_matriz(Matriz *);

/* Função acessa
** Retorna o valor do elemento da linha i e coluna j da matriz
*/
float acessa(Matriz*, int, int);

/* Função atribui
** Atribui o valor dado ao elemento da linha i e coluna j da matriz
*/
void atribui(Matriz*, int, int, float);

/* Função linhas
** Retorna o número de linhas da matriz
*/
int linhas(Matriz*);

/* Função colunas
** Retorna o número de colunas da matriz
*/
int colunas(Matriz*);