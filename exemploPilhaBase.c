#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elementos[MAX];
    int topo;
} PILHA;

PILHA *cria() {
    PILHA *p;
    p = malloc(sizeof(PILHA));

    if (!p) {
        perror(NULL);
        exit(1);
    }

    p->topo = 0;
}

void empilha(PILHA *p, int elem) {
    if (p->topo == MAX - 1) {
        printf("Pilha cheia.");
    } else {
        p->elementos[p->topo] = elem;
        p->topo++;
    }
}

int desempilha(PILHA *p) {
    if (p->topo == 0) {
        printf("Pilha vazia");
        exit(1);
    } else {
        p->topo--;
        return p->elementos[p->topo];
    }
}

int tamanho(PILHA *p) {
    return p->topo;
}

void destroi(PILHA *p) {
    free(p);
}

int main() {

    return 0;
}