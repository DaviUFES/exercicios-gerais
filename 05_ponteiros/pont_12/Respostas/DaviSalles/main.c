#include <stdio.h>
#include "vetor.h"

int soma(int a, int b) {
    return a + b;
}

int produto(int a, int b) {
    return a * b;
}

int main(int argc, char const *argv[])
{
    Vetor v;
    LeVetor(&v);
    printf("Soma: %d\n", AplicarOperacaoVetor(&v, soma));
    printf("Produto: %d\n", AplicarOperacaoVetor(&v, produto));
    return 0;
}
