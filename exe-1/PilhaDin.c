#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h" //inclui os Prot�tipos

//Defini��o do tipo Pilha
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

int pop2(Pilha* pi) {
    if (pi == NULL || *pi == NULL) {
        return 0;
    }

    // Desempilhar o primeiro elemento
    Elem *no1 = *pi;
    *pi = no1->prox;
    free(no1);

    // Verifica se tem outro elemento
    if (*pi == NULL) {
        return 0;
    }

    // Desempilhar o segundo elemento
    Elem *no2 = *pi;
    *pi = no2->prox;
    free(no2);

    return 1;
}

int push2(Pilha* pi, struct aluno al1, struct aluno al2) {
    if (pi == NULL) {
        return 0;
    }

    // Inserir o primeiro elemento
    Elem* no1 = (Elem*)malloc(sizeof(Elem));
    if (no1 == NULL) {
        return 0;
    }
    no1->dados = al1;
    no1->prox = *pi;  // Define o elemento atual como próximo (coloca o novo dado no topo)
    *pi = no1;

    // Insere o segundo elmemento
    Elem* no2 = (Elem*)malloc(sizeof(Elem));
    if (no2 == NULL) {
        free(no1);
        return 0;
    }
    no2->dados = al2;
    no2->prox = *pi;
    *pi = no2;

    return 1;
}
