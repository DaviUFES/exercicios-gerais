#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"


/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos)
{
    int alunosAprovados = 0;
    int alunosM = 0;
    int alunosF = 0;
    int alunosO = 0;
    float somaNotas = 0.0;

    int total_alunos = VectorSize(alunos);

    for(int i = 0; i<total_alunos;i++)
    {
        tAluno *a = (tAluno*)VectorGet(alunos, i);

        somaNotas += GetNotaAluno(a);
        if(GetNotaAluno(a)>=6)
            alunosAprovados++;

        if(GetGeneroAluno(a) == 'M')
            alunosM++;
        else if(GetGeneroAluno(a) == 'F')
            alunosF++;
        else if(GetGeneroAluno(a) == 'O')
            alunosO++;

    }

    float mediaNotas = somaNotas/(float)total_alunos;
    float prctAprovados = ((alunosAprovados/(float)total_alunos)*100);
    float prctMasc = ((alunosM/(float)total_alunos)*100);
    float prctFem = ((alunosF/(float)total_alunos)*100);
    float prctOut = ((alunosO/(float)total_alunos)*100);


    printf("Media das notas: %.2f\n", mediaNotas);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", prctAprovados);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", prctMasc);
    printf("Feminino: %.2f%%\n", prctFem);
    printf("Outro: %.2f%%\n", prctOut);


    
}
