#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};
    Pilha* pi = cria_Pilha();


    for(int i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    imprime_Pilha(pi);

    pop2(pi);

    printf("\n- - - - - - - - - - - -\n\n");

    imprime_Pilha(pi);

    printf("\n- - - - - - - - - - - -\n\n");

    struct aluno al1 = {1,"Bianca",9.7,6.7,8.4};
    struct aluno al2 = {3,"Ana",5.7,6.1,7.4};

    push2(pi, al1, al2);

    imprime_Pilha(pi);

    printf("\n- - - - - - - - - - - -\n\n");

    return 0;
}

