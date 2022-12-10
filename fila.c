#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

#define MAX 20

struct fila{
    int inicio, final, qtd;
    struct numero dados[MAX];
};

Fila* cria_Fila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->inicio = 0;
    f->final= 0;
    f->qtd = 0;
    return f;
}

void libera_Fila(Fila *f) {
    free(f);
}

int tamanho_Fila(Fila *f) {
    if(f == NULL)
        return -1;
    return f->qtd;
}

int fila_cheia(Fila *f) {
    if(f == NULL)
        return -1;
    if (f->qtd == MAX)
        return 1;
    else
        return 0;
}

int fila_vazia(Fila *f) {
    if(f == NULL)
        return -1;
    if (f->qtd == 0)
        return 1;
    else
        return 0;
}

int enqueue(Fila *f, int valor) {
    if (f == NULL)
        return 0;
    if (fila_cheia(f)) {
        printf("Fila cheia");
        return 0;
    }
    f->dados[f->final].num = valor;
    f->final = (f->final + 1) %MAX;
    f->qtd++;
    return 1;
}

int dequeue(Fila *f) {
    if (f == NULL)
        return 0;
    if (fila_vazia(f)) {
        printf("Fila vazia");
        return 0;
    }
    else {
        f->inicio = (f->inicio + 1) %MAX;
        f->qtd--;
        return 1;
    }
}

void imprimir_Fila(Fila *f) {
    int i = f->inicio;
    int temp;
    for (temp = 0;  temp < f->qtd; temp++) {
        printf("%d ", f->dados[i].num);
        i = (i + 1) %MAX;
    }
    printf("\n");
}

int combina_Filas(Fila * nova_Fila, Fila *f1, Fila *f2) {
    int menor = tamanho_menor_Fila(f1, f2);
    int i;
    for(i = 0; i < menor; i++) {
        enqueue(nova_Fila, f1->dados[i].num);
        enqueue(nova_Fila, f2->dados[i].num);
    }
    if (tamanho_Fila(f1) > tamanho_Fila(f2)) {
        int maior = tamanho_maior_Fila(f1,  f2);
        for(i = menor; i < maior; i++) {
            enqueue(nova_Fila, f1->dados[i].num);
        }
    }
    else if (tamanho_Fila(f2) > tamanho_Fila(f1)) {
        int maior = tamanho_maior_Fila(f1,  f2);
        for(i = menor; i < maior; i++) {
            enqueue(nova_Fila, f2->dados[i].num);
        }
    }
    return 1;

}

int tamanho_menor_Fila(Fila *f1, Fila *f2) {
    if(tamanho_Fila(f1) == tamanho_Fila(f2))
        return tamanho_Fila(f1);
    else if (tamanho_Fila(f1) < tamanho_Fila(f2))
        return tamanho_Fila(f1);
    else
        return tamanho_Fila(f2);
}
int tamanho_maior_Fila(Fila *f1, Fila *f2) {
    if(tamanho_Fila(f1) == tamanho_Fila(f2))
        return tamanho_Fila(f1);
    else if (tamanho_Fila(f1) > tamanho_Fila(f2))
        return tamanho_Fila(f1);
    else
        return tamanho_Fila(f2);
}
