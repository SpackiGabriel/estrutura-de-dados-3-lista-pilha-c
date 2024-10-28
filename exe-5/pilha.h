typedef struct Elemento {
    double valor;
    struct Elemento* proximo;
} Elemento;

typedef struct Pilha {
    Elemento* topo;
} Pilha;

Pilha* criar_pilha();
int empilhar(Pilha* pilha, double valor);
double desempilhar(Pilha* pilha);
int pilha_vazia(Pilha* pilha);
void liberar_pilha(Pilha* pilha);
double calcular(Pilha* pilha, char operador);
