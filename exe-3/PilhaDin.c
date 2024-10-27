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

/*

Ideia:

- Criar uma pilha auxiliar (tem a função cria_pilha já pronta)
- Para preservar os elementos da pilha principal, vamos percorrer a pilha e guardar os elementos em um vetor temporário
- Então podemos inserir os elementos na pilha auxiliar    

*/

Pilha* pilha_copia(Pilha* p) {

    if (p == NULL) {
        return 0;
    }

    Pilha *nova_pilha = cria_Pilha(); // Criar a pilha auxiliar

    if (nova_pilha == NULL) {
        return 0;
    }

    int tamanho = tamanho_Pilha(p);

    Elem *vetor_aux[tamanho]; // Criar um vetor temporário
    Elem *no = *p;

    int tmp = 0;

    // Preencher o vetor
    while (no != NULL) {
        vetor_aux[tmp] = no;
        no = no->prox;
        tmp++;
    }

    // A partir do último elemento do vetor, vamos inserir na pilha auxiliar para manter a mesma ordem de elementos
    for (int j = tmp - 1; j >= 0; j--) {
        insere_Pilha(nova_pilha, vetor_aux[j]->dados);
    }

    return nova_pilha;
}
