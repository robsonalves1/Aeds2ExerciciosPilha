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

void imprime(PILHA *p) {
    PILHA *pAux = cria();
    int elem = 0;

    while (tamanho(p) > 0) {
        empilha(pAux, desempilha(p));
    }

    printf("Pilha: ");

    while (tamanho(pAux) > 0) {
        elem = desempilha(pAux);
        printf("%d, ", elem);
        empilha(p, elem);
    }

    destroi(pAux);
}

int main() {
    PILHA *minhaPilha = cria();
    
    empilha(minhaPilha, 10);
    empilha(minhaPilha, 20);
    empilha(minhaPilha, 30);
    
    imprime(minhaPilha);
    
    destroi(minhaPilha);


    return 0;
}