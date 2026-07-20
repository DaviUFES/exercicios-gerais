#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno
{
    char nome[100];
    char dataNasc[100];
    char curso[100];
    char periodo[100];
    int percentualConcluido;
    float CRA;
};

Aluno** CriaVetorAlunos(int numeroAlunos)
{
    Aluno **a = (Aluno**)malloc(sizeof(Aluno));
    return a;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA)
{
    Aluno *a = (Aluno*)malloc(sizeof(Aluno));

    strcpy(a->nome, nome);
    strcpy(a->dataNasc, dtNasc);
    strcpy(a->curso, cursoUfes);
    strcpy(a->periodo, periodoIngresso);
    a->percentualConcluido = percConclusao;
    a->CRA = CRA;

}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos)
{
    char nome[100], curso[100], dataNasc[100], periodo[100];
    int percConclusao;
    float CRA;
    for(int i = 0; i<numeroAlunos; i++)
    {
        scanf("%*[^a-zA-Z]");
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", dataNasc);
        scanf("%[^\n]\n", curso);
        scanf("%[^\n]", periodo);
        scanf("%d\n", &percConclusao);
        scanf("%f\n", &CRA);

        vetorAlunos[i] = CriaAluno(nome, dataNasc, curso, periodo, percConclusao, CRA);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos)
{
    if(alunos != NULL)
    {
        for(int i = 0; i<numeroAlunos; i++)
            free(alunos[i]);
        free(alunos);
    }
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos)
{
    int tamanhoString;
    int qtdBytes = 0;

    FILE *fp;

    fp = fopen(fileName, "wb");

    qtdBytes += sizeof(int)*fwrite(&numeroAlunos, sizeof(int), 1, fp);

    for(int i = 0; i<numeroAlunos; i++)
    {
        tamanhoString = strlen(alunos[i]->nome);
        qtdBytes += (fwrite(&tamanhoString,sizeof(int),1,fp)*sizeof(int));
        qtdBytes += fwrite(alunos[i]->nome, sizeof(char), tamanhoString, fp);

        tamanhoString = strlen(alunos[i]->dataNasc);
        qtdBytes += (fwrite(&tamanhoString,sizeof(int),1,fp)*sizeof(int));
        qtdBytes += fwrite(alunos[i]->dataNasc, sizeof(char), tamanhoString, fp);

        tamanhoString = strlen(alunos[i]->curso);
        qtdBytes += (fwrite(&tamanhoString,sizeof(int),1,fp)*sizeof(int));
        qtdBytes += fwrite(alunos[i]->curso, sizeof(char), tamanhoString, fp);

        tamanhoString = strlen(alunos[i]->periodo);
        qtdBytes += (fwrite(&tamanhoString,sizeof(int),1,fp)*sizeof(int));
        qtdBytes += fwrite(alunos[i]->periodo, sizeof(char), tamanhoString, fp);

        qtdBytes += (fwrite(&(alunos[i]->percentualConcluido),sizeof(int),1,fp)*sizeof(int));

        qtdBytes += (fwrite(&(alunos[i]->CRA), sizeof(float),1,fp)*sizeof(int));
    }

    printf("Numero de bytes salvos: %d\n", qtdBytes);
    fclose(fp);

}

void CarregaAlunosBinario(Aluno **alunos, char *fileName)
{
    FILE *fp = fopen(fileName,"rb");

    char nome[100], dataNasc[100], curso[100], periodo[100];
    int numAlunos, tam;
    int percConclusao;
    float CRA;

    fread(&numAlunos,sizeof(int),1,fp);

    for(int i = 0; i<numAlunos; i++)
    {
        memset(nome, 0, 100);
        memset(dataNasc, 0, 100);
        memset(curso, 0, 100);
        memset(periodo, 0, 100);

        fread(&tam, sizeof(int), 1, fp);
        fread(nome,sizeof(char),tam,fp);

        fread(&tam, sizeof(int), 1, fp);
        fread(dataNasc,sizeof(char),tam,fp);

        fread(&tam, sizeof(int), 1, fp);
        fread(curso,sizeof(char),tam,fp);

        fread(&tam, sizeof(int), 1, fp);
        fread(periodo,sizeof(char),tam,fp);

        fread(&percConclusao, sizeof(int),1,fp);

        fread(&CRA, sizeof(float), 1, fp);

        alunos[i] = CriaAluno(nome, dataNasc, curso, periodo, percConclusao, CRA);
    }

    fclose(fp);

}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos)
{
    for(int i=0; i<numeroAlunos; i++)
    {
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dataNasc);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->percentualConcluido);
        printf("CRA: %.2f\n", alunos[i]->CRA);
    }
}
