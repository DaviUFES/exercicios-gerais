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
    //Aqui fazemos a alocação para um ponteiro de ponteiros.
    //Nesse caso, não estamos alocando o aluno em si, mas uma lista dos alunos
    Aluno **alunos = (Aluno **) malloc(sizeof(Aluno *)*numeroAlunos);
    return alunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA) 
{
    Aluno *a = (Aluno *) malloc(sizeof(Aluno));

    strcpy(a->nome, nome);
    strcpy(a->dataNasc, dtNasc);
    strcpy(a->curso, cursoUfes);
    strcpy(a->periodo, periodoIngresso);
    a->percentualConcluido = percConclusao;
    a->CRA = CRA;

    return a;
}


void LeAlunos(Aluno** vetorAlunos, int numeroAlunos) {
    int i;
    char nome[100], dataNasc[100], curso[100], periodo[100];
    int percentualConcluido;
    float CRA;
    for(i = 0; i < numeroAlunos; i++) {
        // Limpando buffer
        scanf("%*[^a-zA-Z]");
        // Lendo nome
        scanf("%[^\n]\n", nome);
        // Lendo data
        scanf("%[^\n]\n", dataNasc);
        // Lendo curso
        scanf("%[^\n]\n", curso);
        // Lendo periodo
        scanf("%[^\n]\n", periodo);
        // Lendo percent conclusao
        scanf("%d\n", &percentualConcluido);
        // Lendo CRA
        scanf("%f\n", &CRA);

        vetorAlunos[i] = CriaAluno(nome, dataNasc, curso, periodo, percentualConcluido, CRA);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos) {
    int i;
    if(alunos) {
        for(i = 0; i < numeroAlunos; i++) {
            free(alunos[i]);
        }
        free(alunos);
    }
}


void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos)
{
    int i, tamanhoString;
    int qtdBytes = 0;
    //Criando uma referência para o arquivo
    FILE *fp;
    //Aqui estamos abrindo o arquivo. O modo "wb" funciona para escrever em binário
    fp = fopen(fileName,"wb");
    //O 'fwrite' é a função para escrever em formato binário. Estamos gravando 1 elemento e direcionando para o ponteiro aberto 'fp'
    //Fazendo 'sizeof(int) * fwrite(...)' nós convertemos os elementos para a quantidade de bytes gravados
    //Por fim, acumulamos a quantidade de Bytes gravados em 'qtdBytes'
    qtdBytes += sizeof(int) * fwrite(&numeroAlunos, sizeof(int),1,fp);

    for(i=0;i<numeroAlunos;i++)
    {
        //Gravando o tamanho da String do nome do aluno (até o \0) e salvando em 'tamanhoString'
        tamanhoString = strlen(alunos[i]->nome);
        //acumulando o inteiro que representa o tamanho do nome convertido para bytes
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        //Gravando o conteúdo real da String (não precisamos converter para Bytes pois sizeof(char) é 1)
        qtdBytes += fwrite(alunos[i]->nome, sizeof(char), tamanhoString, fp);

        tamanhoString = strlen(alunos[i]->dataNasc);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->dataNasc, sizeof(char), tamanhoString, fp);

        tamanhoString = strlen(alunos[i]->curso);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->curso, sizeof(char), tamanhoString, fp);

        tamanhoString = strlen(alunos[i]->periodo);
        qtdBytes += (fwrite(&tamanhoString, sizeof(int), 1, fp)) * (sizeof(int));
        qtdBytes += fwrite(alunos[i]->periodo, sizeof(char), tamanhoString, fp);

        qtdBytes += (fwrite(&(alunos[i]->percentualConcluido), sizeof(int),1,fp)) * sizeof(int);

        qtdBytes += (fwrite(&(alunos[i]->CRA), sizeof(int),1,fp)) * sizeof(int);
    }

    printf("Numero de bytes salvos: %d\n", qtdBytes);
    fclose(fp);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName)
{
    //abrindo o arquivo para leitura binária
    FILE *fp = fopen(fileName, "rb");
    int numAlunos, auxTamanho, i;
    char nome[100], dataNasc[100], curso[100], periodo[100];
    int percentualConcluido;
    float CRA;

    percentualConcluido = 0;
    CRA = 0;

    //lendo o número de alunos
    fread(&numAlunos, sizeof(int),1,fp);

    for(i=0; i<numAlunos; i++)
    {
        //preenchendo blocos de memória
        memset(nome,0,100);
        memset(dataNasc,0,100);
        memset(curso,0,100);
        memset(periodo,0,100);

        fread(&auxTamanho, sizeof(int),1,fp);
        fread(nome, sizeof(char), auxTamanho,fp);

        fread(&auxTamanho, sizeof(int),1,fp);
        fread(dataNasc, sizeof(char), auxTamanho,fp);

        fread(&auxTamanho, sizeof(int),1,fp);
        fread(curso, sizeof(char), auxTamanho,fp);

        fread(&auxTamanho, sizeof(int),1,fp);
        fread(periodo, sizeof(char), auxTamanho,fp);

        fread(&percentualConcluido, sizeof(int), 1, fp);
        
        fread(&CRA, sizeof(int), 1, fp);

        alunos[i] = CriaAluno(nome,dataNasc,curso,periodo,percentualConcluido,CRA);
    }
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos)
{
    int i;
    for(i=0; i<numeroAlunos; i++)
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
