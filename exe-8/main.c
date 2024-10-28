#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elemento {
    char caractere;
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

void empilhar(Pilha* pilha, char caractere) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->caractere = caractere;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

char desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        return '\0';
    }
    Elemento* tmp = pilha->topo;
    char caractere = tmp->caractere;
    pilha->topo = tmp->proximo;
    free(tmp);
    return caractere;
}

int validar(Pilha *pilhaX, Pilha *pilhaY) {
    if (pilhaVazia(pilhaX) || pilhaVazia(pilhaY)) {
        return 0;
    }
    
    while (!pilhaVazia(pilhaX) && !pilhaVazia(pilhaY)) {
        char caractereX = desempilhar(pilhaX);
        char caractereY = desempilhar(pilhaY);

        if ((caractereX == 'A' && caractereY != 'B') || (caractereX == 'B' && caractereY != 'A')) {
            return 0;
        }
    }

    return pilhaVazia(pilhaX) && pilhaVazia(pilhaY); // Se inicialmente as cadeias tinham o mesmo comprimento, significa que as duas devem estar vazias agora. Caso não estejam, vai retornar 0 confirmando que não são inversas.
}

void liberarPilha(Pilha* pilha) {
    while(!pilhaVazia(pilha)) {
        desempilhar(pilha);
    }

    free(pilha);
}

int main() {
    Pilha* pilhaX = criarPilha();
    Pilha* pilhaY = criarPilha();

    empilhar(pilhaX, 'A');
    empilhar(pilhaX, 'B');
    empilhar(pilhaX, 'A');
    empilhar(pilhaX, 'B');
    empilhar(pilhaX, 'B');
    empilhar(pilhaX, 'A');

    empilhar(pilhaY, 'B');
    empilhar(pilhaY, 'A');
    empilhar(pilhaY, 'B');
    empilhar(pilhaY, 'A');
    empilhar(pilhaY, 'A');
    empilhar(pilhaY, 'B');

    if (validar(pilhaX, pilhaY)) {
        printf("A cadeia Y é o inverso da pilha X.\n");
    } else {
        printf("A cadeia Y não é o inverso da pilha X.\n");
    }

    return 0;
}