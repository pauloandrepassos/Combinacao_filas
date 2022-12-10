#include "stdio.h"
#include "fila.h"

int main() {
    Fila *f1;
    Fila *f2;
    Fila *fila_combinada;
    f1 = cria_Fila();
    f2 = cria_Fila();
    fila_combinada = cria_Fila();
    enqueue(f1, 1);
    enqueue(f1, 2);
    enqueue(f1, 3);
    enqueue(f1, 4);
    enqueue(f2, 10);
    enqueue(f2, 11);
    enqueue(f2, 12);
    enqueue(f2, 13);
    enqueue(f2, 14);
    printf("\nFila 1:\n");
    imprimir_Fila(f1);
    printf("\nFila 2:\n");
    imprimir_Fila(f2);

    combina_Filas(fila_combinada, f1, f2);

    printf("\nFila combinada:\n");
    imprimir_Fila(fila_combinada);

    return 1;
}