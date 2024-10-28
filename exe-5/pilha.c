#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criar_pilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int empilhar(Pilha* pilha, double valor) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    
    return 1;
}

double desempilhar(Pilha* pilha) {
    if (pilha_vazia(pilha)) {
        return 0;
    }

    Elemento* tmp = pilha->topo;
    double valor = tmp->valor;
    pilha->topo = pilha->topo->proximo;
    free(tmp);
    return valor;
}

int pilha_vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void liberar_pilha(Pilha* pilha) {
    while (!pilha_vazia(pilha)) {
        desempilhar(pilha);
    }
    free(pilha);
}

double calcular(Pilha* pilha, char operador) {
    double b = desempilhar(pilha);
    double a = desempilhar(pilha);

    switch (operador) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                printf("Divisão por zero!!!\n");
                return 0;
            }
            return a / b;

        default:
            return 0;
    }
}
