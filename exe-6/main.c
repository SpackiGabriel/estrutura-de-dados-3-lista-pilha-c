#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Elemento {
    char dado;
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

void empilhar(Pilha* pilha, char dado) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->dado = dado;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

char desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) {
        return '\0';
    }
    Elemento* temp = pilha->topo;
    char dado = temp->dado;
    pilha->topo = pilha->topo->proximo;
    free(temp);
    return dado;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void imprimirInverso(Pilha* pilha) {
    printf("Texto na ordem inversa: ");
    while (!pilhaVazia(pilha)) {
        printf("%c", desempilhar(pilha));
    }
    printf("\n");
}

int ehPalindromo(char* str) {
    Pilha* pilha = criarPilha();
    int tamanho = strlen(str);
    
    for (int i = 0; i < tamanho; i++) {
        if (isalnum(str[i])) { // Verifica se o char é alfanumérico (pra parte de ignorar pontos, vírgulas, etc)
            empilhar(pilha, tolower(str[i])); // Pra facilitar, empilha o char em minúsculo
        }
    }

    for (int i = 0; i < tamanho; i++) { // Compara a pilha com a cadeia
        if (isalnum(str[i])) {
            char topoChar = desempilhar(pilha);
            if (tolower(str[i]) != topoChar) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char entrada[1000];

    printf("Digite uma cadeia de chars: ");
    fgets(entrada, sizeof(entrada), stdin); // Usando fgts pra não ter que ficar limpando buffer e tal

    Pilha* pilha = criarPilha();
    
    for (int i = 0; entrada[i] != '\0' && entrada[i] != '\n'; i++) { // percorrento a cadeia até o final
        empilhar(pilha, entrada[i]);
    }
    
    imprimirInverso(pilha);

    if (ehPalindromo(entrada)) {
        printf("A sequência é um palíndromo.\n");
    } else {
        printf("A sequência não é um palíndromo.\n");
    }

    while (!pilhaVazia(pilha)) {
        desempilhar(pilha);
    }
    free(pilha);
    
    return 0;
}
