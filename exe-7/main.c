#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int valor;
    struct Elemento* proximo;
} Elemento;

typedef struct Pilha {
    Elemento* topo;
} Pilha;


Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

int empilhar(Pilha* pilha, int valor) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    return 1;
}

int desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        return -1;
    }

    Elemento* tmp = pilha->topo;
    int valor = tmp->valor;
    pilha->topo = pilha->topo->proximo;
    free(tmp);

    return valor;
}

void contarParImpar(Pilha* pilha, int* pares, int* impares) {
    *pares = 0;
    *impares = 0;

    while(!pilhaVazia(pilha)) {
        int valor = desempilhar(pilha);

        if (valor % 2 == 0) {
            (*pares)++;
        } else {
            (*impares)++;
        }
    }
}

void liberarPilha(Pilha* pilha) {
    while(!pilhaVazia(pilha)) {
        desempilhar(pilha);
    }

    free(pilha);
}

int main() {

    Pilha* pilha = criarPilha();

    empilhar(pilha, 1);
    empilhar(pilha, 2);
    empilhar(pilha, 3);
    empilhar(pilha, 4);
    empilhar(pilha, 5);

    int pares, impares;
    contarParImpar(pilha, &pares, &impares);

    printf("Pares: %d\n", pares);
    printf("Impares: %d\n", impares);

    return 0;
}