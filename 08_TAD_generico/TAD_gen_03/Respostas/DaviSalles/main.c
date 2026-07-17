#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

int main()
{
    int qtdAlunos;
    Vector *v = VectorConstruct();
    scanf("%d",&qtdAlunos);

    for(int i=0; i<qtdAlunos;i++)
    {
        tAluno *a = CriaAluno();
        LeAluno(a);
        VectorPushBack(v,a);
    }

    ImprimeRelatorio(v);

    VectorDestroy(v,DestroiAluno);

    return 0;
}