#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno
{
    char nome[100];
    char dataNasc[100];
    char curso[100];
    float prctConclusao;
    float cfRendimento;
};

/**
 * @brief Cria um novo aluno.
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso do aluno.
 * @param prctConclusao Percentual de conclusão do curso.
 * @param cfRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para a estrutura do aluno criada. Caso a alocação falhe, a função termina o programa.
 */
tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento)
{
    tAluno *a = (tAluno*)malloc(sizeof(tAluno));

    if(a == NULL) {
        exit(1);
    }

    strcpy(a->nome, nome);
    strcpy(a->dataNasc, dataNascimento);
    strcpy(a->curso, curso);
    a->prctConclusao = prctConclusao;
    a->cfRendimento = cfRendimento;

    return a;
}

/**
 * @brief Destroi um aluno.
 * @param aluno Ponteiro para a estrutura do aluno a ser destruída.
 */
void DestroiAluno(tAluno *aluno)
{
    if(aluno != NULL)
        free(aluno);
}

/**
 * @brief Lê um aluno da entrada padrão.
 * @return Um ponteiro para a estrutura do aluno lida.
 */
tAluno *LeAluno()
{
    char nome[100], curso[100], nasc[100];
    float percentual, cr;

    scanf("%*[^a-zA-Z]");
    scanf(" %[^\n]", nome);
    scanf(" %[^\n]", nasc);
    scanf(" %[^\n]", curso);
    scanf("%f", &percentual);
    scanf("%f", &cr);

    tAluno *a = CriaAluno(nome, nasc, curso, percentual, cr);

    return a;

}

/**
 * @brief Compara o nome de dois alunos.
 * @param aluno1 Ponteiro para a estrutura do primeiro aluno.
 * @param aluno2 Ponteiro para a estrutura do segundo aluno.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2)
{
    return(strcmp(aluno1->nome, aluno2->nome));
}

/**
 * @brief Salva um aluno em um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser salva.
 * @param file Ponteiro para o arquivo onde o aluno será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste aluno.
 */
int SalvaAluno(tAluno *aluno, FILE *file)
{
    
    int qtdBytes = 0;
    int auxTam;

    auxTam = strlen(aluno->nome);
    qtdBytes += (fwrite(&auxTam, sizeof(int),1,file)*sizeof(int));
    qtdBytes += fwrite(aluno->nome, sizeof(char), auxTam, file);

    auxTam = strlen(aluno->dataNasc);
    qtdBytes += (fwrite(&auxTam, sizeof(int),1,file)*sizeof(int));
    qtdBytes += fwrite(aluno->dataNasc, sizeof(char), auxTam, file);

    auxTam = strlen(aluno->curso);
    qtdBytes += (fwrite(&auxTam, sizeof(int),1,file)*sizeof(int));
    qtdBytes += fwrite(aluno->curso, sizeof(char), auxTam, file);

    qtdBytes += (fwrite(&aluno->prctConclusao, sizeof(float), 1, file)*sizeof(int));

    qtdBytes += (fwrite(&aluno->cfRendimento, sizeof(float), 1, file)*sizeof(int));

    return qtdBytes;
}

/**
 * @brief Carrega um aluno de um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser carregada.
 * @param file Ponteiro para o arquivo de onde o aluno será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste aluno.
 */
int CarregaAluno(tAluno *aluno, FILE *file)
{
    int qtdBytes = 0;
    int auxTam = 0;

    qtdBytes += (fread(&auxTam, sizeof(int),1,file)*sizeof(int));
    qtdBytes += fread(aluno->nome, sizeof(char), auxTam, file);
    aluno->nome[auxTam] = '\0';

    qtdBytes += (fread(&auxTam, sizeof(int),1,file)*sizeof(int));
    qtdBytes += fread(aluno->dataNasc, sizeof(char), auxTam, file);
    aluno->dataNasc[auxTam] = '\0';

    qtdBytes += (fread(&auxTam, sizeof(int),1,file)*sizeof(int));
    qtdBytes += fread(aluno->curso, sizeof(char), auxTam, file);
    aluno->curso[auxTam] = '\0';

    qtdBytes += (fread(&aluno->prctConclusao, sizeof(float), 1, file)*sizeof(int));

    qtdBytes += (fread(&aluno->cfRendimento, sizeof(float), 1, file)*sizeof(int));

    return qtdBytes;
}

/**
 * @brief Imprime o nome de um aluno na saída padrão.
 * @param aluno Ponteiro para a estrutura do aluno cujo nome será impresso.
 */
void ImprimeNomeAluno(tAluno *aluno)
{
    printf("%s\n", aluno->nome);
}
