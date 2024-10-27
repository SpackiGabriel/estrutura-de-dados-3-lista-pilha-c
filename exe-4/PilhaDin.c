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

int estatisticas_pilha(Pilha* pi, int* maior, int* menor, float* media) {
    if (Pilha_vazia(pi)) {
        *maior = 0;
        *menor = 0;
        *media = 0;
        return 0;
    }

    int soma = 0;
    int tmp = 0;

    struct aluno al;


    consulta_topo_Pilha(pi, &al); // Definir o primeiro elemento como maior e menor para ter um parâmetro inicial
    *maior = al.matricula;
    *menor = al.matricula;
    soma += al.matricula;
    tmp++;

    remove_Pilha(pi); // Remover da pilha para acessar o próximo elemento


    Pilha *aux = cria_Pilha(); // Pilha auxiliar para não perder os valores durante o processo

    insere_Pilha(aux, al);


    while (!Pilha_vazia(pi)) {
        consulta_topo_Pilha(pi, &al); // Coleta as informações do topo

        // Faz as verificações
        if (al.matricula > *maior) {
            *maior = al.matricula;
        }

        if (al.matricula < *menor) {
            *menor = al.matricula;
        }

        soma += al.matricula;
        tmp++;

        // remove da atual e insere na auxiliar
        remove_Pilha(pi);
        insere_Pilha(aux, al);
    }

    *media = 0;

    if (tmp > 0) {
        *media = (float) soma / tmp;
    }

    // Restaurar a pilha original

    while (!Pilha_vazia(aux)) {
        consulta_topo_Pilha(aux, &al);
        remove_Pilha(aux);
        insere_Pilha(pi, al);
    }

    libera_Pilha(aux);
}

