#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct soma{
    float n1, n2;
}

tSoma* CriaTarefaSoma(float n1, float n2)
{
    tSoma *tar = malloc(sizeof(tSoma));
    tar->n1 = n1;
    tar->n2 = n2;
    return tar;
}

/**
 * @brief Função que executa uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaSoma(void *sum)
{
    tSoma *tar = (tSoma*) sum;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", tar->n1, tar->n2, tar->n1+tar->n2);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaSoma(void *sum)
{
    free(sum);
}
