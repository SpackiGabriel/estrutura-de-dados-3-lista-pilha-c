#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int valor;
    struct Elemento* prox;
} Elemento;

typedef struct {
    Elemento* topo;
    int tamanho;
} Pilha;


Pilha* criarPilha() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

int empilhar(Pilha* pilha, int valor) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));

    if (novo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 0;
    }
    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;

    return 1;
}

int desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia! Não é possível desempilhar.\n");
        return -1;
    }
    Elemento* tmp = pilha->topo;
    
    int valor = tmp->valor;
    pilha->topo = tmp->prox;
    free(tmp);

    return valor;
}

int topo(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    }

    return pilha->topo->valor;
}

void decimalParaBinario(int n) {
    Pilha* pilha = criarPilha();

    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        empilhar(pilha, n % 2);
        n /= 2;
    }

    printf("Binario: ");

    while (!pilhaVazia(pilha)) {
        printf("%d", desempilhar(pilha));
    }

    printf("\n");
    free(pilha);
}

void menu() {
    printf("1 - Inicializa pilha.\n");
    printf("2 - Verifica se a pilha e vazia.\n");
    printf("3 - Verifica se a pilha e cheia.\n");
    printf("4 - Empilha o elemento na pilha.\n");
    printf("5 - Desempilha elemento da pilha.\n");
    printf("6 - Le topo de um pilha.\n");
    printf("7 - Converte um numero decimal em binario.\n");
    printf("8 - Sair.\n");
}


int main() {
    Pilha *pilha = NULL;
    int opcao, valor;

    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                pilha = criarPilha();
                printf("Pilha inicializada.\n");
                break;
            case 2:
                if (pilha == NULL) printf("Pilha não inicializada.\n");
                else printf(pilhaVazia(pilha) ? "Pilha está vazia.\n" : "Pilha não está vazia.\n");
                break;
            case 3:
                printf("A pilha dinâmica nunca está cheia até esgotar a memória.\n");
                break;
            case 4:
                if (pilha == NULL) {
                    printf("Pilha não inicializada.\n");
                    break;
                }
                printf("Digite o valor para empilhar: ");
                scanf("%d", &valor);
                if (empilhar(pilha, valor)) {
                    printf("Elemento %d empilhado.\n", valor);
                }
                break;
            case 5:
                if (pilha == NULL) {
                    printf("Pilha não inicializada.\n");
                    break;
                }
                if (desempilhar(pilha) != -1) {
                    printf("Elemento %d desempilhado.\n", valor);
                }
                break;
            case 6:
                if (pilha == NULL) {
                    printf("Pilha não inicializada.\n");
                    break;
                }
                printf("Topo da pilha: %d\n", topo(pilha));
                break;
            case 7:
                printf("Digite um número decimal: ");
                scanf("%d", &valor);
                decimalParaBinario(valor);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 8);

    if (pilha != NULL) {
        while (!pilhaVazia(pilha)) {
            desempilhar(pilha);
        }
        free(pilha);
    }

    return 0;
}