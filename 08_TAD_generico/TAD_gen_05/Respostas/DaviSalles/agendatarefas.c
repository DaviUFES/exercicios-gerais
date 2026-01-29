#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*Fptr_executa_tarefa)(void*);
typedef void (*Fptr_destroi_tarefa)(void*);

struct agendatarefas{
    int numTarefas;
    void **tarefas;
    int *prioridades;
    Fptr_destroi_tarefa *destroi;
    Fptr_executa_tarefa *executa;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem)
{
    tAgendaTarefas *agenda = malloc(sizeof(tAgendaTarefas));
    agenda->numTarefas = numElem;
    agenda->tarefas = calloc(sizeof(void*), numElem);
    agenda->prioridades = calloc(sizeof(int), numElem);
    agenda->destroi = calloc(sizeof(Fptr_destroi_tarefa), numElem);
    agenda->executa = calloc(sizeof(Fptr_executa_tarefa), numElem);
    return agenda;
}


void DestroiAgendaDeTarefas(tAgendaTarefas* tar)
{
    free(tar->executa);
    free(tar->destroi);
    free(tar->prioridades);
    free(tar->tarefas);
    free(tar);
}


void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) )
{
    tar->prioridades[tar->numTarefasCadastradas] = prioridade;
    tar->tarefas[tar->numTarefasCadastradas] = tarefa;
    tar->executa[tar->numTarefasCadastradas] = executa;
    tar->destroi[tar->numTarefasCadastradas] = destroi;
    numTarefasCadastradas++;
}   


void ExecutarTarefasDaAgenda(tAgendaTarefas* tar)
{
    int int_min = -100000;
    int maiorPrioridade = 0;
    int indiceMaiorPrioridade;
    while (maiorPrioridade != int_min){
        maiorPrioridade = int_min;
        indiceMaiorPrioridade = int_min;
        for(int i=0; i<tar->numTarefasCadastradas; i++){
            if(tar->prioridades[i] > maiorPrioridade){
                indiceMaiorPrioridade = i;
                maiorPrioridade = tar->prioridades[i];
            }
        }
        if(maiorPrioridade > -1){
            //Poderia ser feito assim
            //Fptr_executa_tarefa executa_tarefa = tar->executa[indiceMaiorPrioridade];
            //executa_tarefa(tar->tarefas[indiceMaiorPrioridade]);
            tar->executa[indiceMaiorPrioridade](tar->tarefas[indiceMaiorPrioridade]);
            tar->destroi[indiceMaiorPrioridade](tar->tarefas[indiceMaiorPrioridade]);
            tar->prioridades[indiceMaiorPrioridade] = int_min;
        }
    }
}