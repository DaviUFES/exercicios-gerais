#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main()
{
    int qtdAlunos;

    scanf("%d\n", &qtdAlunos);
    tAluno **listaAlunos = (tAluno**)malloc(sizeof(tAluno*)*qtdAlunos);
    for(int i = 0; i<qtdAlunos; i++)
    {
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);
        listaAlunos[i] = aluno;
    }
    
    for(int i = 0; i<qtdAlunos; i++)
    {
        for(int j = i+1; j<qtdAlunos; j++)
        {
            if(ComparaMatricula(listaAlunos[i], listaAlunos[j])==1)
            {
                tAluno *aux = listaAlunos[i];
                listaAlunos[i] = listaAlunos[j];
                listaAlunos[j] = aux;
            }
        }
    }

    for(int i = 0; i<qtdAlunos; i++)
    {
        if(VerificaAprovacao(listaAlunos[i]))
        {
            ImprimeAluno(listaAlunos[i]);
        }
        ApagaAluno(listaAlunos[i]);
    }

    free(listaAlunos);

    return 0;
}