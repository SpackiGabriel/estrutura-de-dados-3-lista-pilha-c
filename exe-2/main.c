#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Pilha* pi = cria_Pilha();

    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    imprime_Pilha(pi);
    printf("Tamanho: %d\n\n",tamanho_Pilha(pi));

    int n = 3;
    int desempilhados = popN(pi, n);
    
    if (desempilhados > 0) {
        printf("Desempilhados %d elementos da pilha.\n\n", desempilhados);

        imprime_Pilha(pi);
        printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    } 

    else {
        printf("BUG!!!\n");
    }

    return 0;
}

