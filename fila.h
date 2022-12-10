struct numero{
    int num;
};
typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila *f);

int tamanho_Fila(Fila *f);
int fila_cheia(Fila *f);
int fila_vazia(Fila *f);

int enqueue(Fila *f, int valor);
int dequeue(Fila *f);

void imprimir_Fila(Fila *f);

int combina_Filas(Fila * nova_Fila, Fila *f1, Fila *f2);


int tamanho_menor_Fila(Fila *f1, Fila *f2);
int tamanho_maior_Fila(Fila *f1, Fila *f2);