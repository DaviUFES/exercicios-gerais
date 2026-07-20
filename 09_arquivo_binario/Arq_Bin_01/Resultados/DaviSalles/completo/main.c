#include <stdio.h>
#include "aluno.h"

int main()
{
    Aluno **a;
    int qtdAlunos = 0;
    printf("Digite o numero de alunos: ");
    scanf("%d", &qtdAlunos);
    a = CriaVetorAlunos(qtdAlunos);
    LeAlunos(a,qtdAlunos);
    SalvaAlunosBinario(a, "alunos.bin", qtdAlunos);
    LiberaAlunos(a, qtdAlunos);

    a = CriaVetorAlunos(qtdAlunos);
    CarregaAlunosBinario(a,"alunos.bin");
    ImprimeAlunos(a, qtdAlunos);
    LiberaAlunos(a, qtdAlunos);

    return 0;
}