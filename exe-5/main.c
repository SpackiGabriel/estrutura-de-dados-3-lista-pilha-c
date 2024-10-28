#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* pilha = criar_pilha();

    double num;
    printf("Digite um número: ");
    scanf("%lf", &num);
    empilhar(pilha, num);

    printf("Digite o operador (+, -, *, /): ");
    char operador;
    scanf(" %c", &operador);

    printf("Digite o segundo número: ");
    scanf("%lf", &num);
    empilhar(pilha, num);

    double resultado = calcular(pilha, operador);
    printf("Resultado: %.2lf\n", resultado);
    empilhar(pilha, resultado);

    printf("Deseja continuar? (s/n): ");
    scanf(" %c", &continuar);

    liberar_pilha(pilha);
    return 0;
}
