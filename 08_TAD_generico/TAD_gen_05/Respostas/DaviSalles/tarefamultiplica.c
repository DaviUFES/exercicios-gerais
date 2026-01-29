#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct mult{
    float n1, n2;
};

tMult* CriaTarefaMultiplicar(float n1, float n2)
{
    tMult *tar = malloc (sizeof(tMult));
    tar -> n1 = n1;
    tar -> n2 = n2;
    return tar;
}

/**
 * @brief Função que executa uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaMultiplicar(void *mult)
{
    tMult *tar = (tMult*) mult;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", tar->n1, tar->n2, tar->n1*tar->n2);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaMultiplicar(void *mult)
{
    free(mult);
}
