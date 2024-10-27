#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

int main() {
    Pilha* pi = cria_Pilha();
    struct aluno al;

    al.matricula = 101;
    insere_Pilha(pi, al);
    
    al.matricula = 102;
    insere_Pilha(pi, al);
    
    al.matricula = 99;
    insere_Pilha(pi, al);

    int maior, menor;
    float media;

    estatisticas_pilha(pi, &maior, &menor, &media);

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Média: %.2f\n", media);

    libera_Pilha(pi);
    return 0;
}


