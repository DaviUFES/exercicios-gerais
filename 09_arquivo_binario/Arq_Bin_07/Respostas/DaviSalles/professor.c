#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct Professor
{
    char nome[100];
    char dataNasc[100];
    char departamento[100];
};

/**
 * @brief Cria um novo professor.
 * @param nome Nome do professor.
 * @param dataNascimento Data de nascimento do professor.
 * @param departamento Departamento do professor.
 * @return Um ponteiro para a estrutura do professor criada. Caso a alocação falhe, a função termina o programa.
 */
tProfessor *CriaProfessor(char *nome, char *dataNascimento, char *departamento)
{
    tProfessor *p = (tProfessor*)malloc(sizeof(tProfessor));

    if(p==NULL)
        exit(1);

    strcpy(p->nome, nome);
    strcpy(p->dataNasc, dataNascimento);
    strcpy(p->departamento, departamento);

    return p;
}

/**
 * @brief Destroi um professor.
 * @param prof Ponteiro para a estrutura do professor a ser destruída.
 */
void DestroiProfessor(tProfessor *prof)
{
    if(prof!=NULL)
    {
        free(prof);
    }
}

/**
 * @brief Lê um professor da entrada padrão.
 * @return Um ponteiro para a estrutura do professor lida.
 */
tProfessor *LeProfessor()
{
    char nome[100], dataNasc[100], departamento[100];
    scanf(" %[^\n]", nome);
    scanf(" %[^\n]", dataNasc);
    scanf(" %[^\n]", departamento);

    tProfessor *p = CriaProfessor(nome, dataNasc, departamento);

    return p;
}

/**
 * @brief Compara o nome de dois professores.
 * @param prof1 Ponteiro para a estrutura do primeiro professor.
 * @param prof2 Ponteiro para a estrutura do segundo professor.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeProfessor(tProfessor *prof1, tProfessor *prof2)
{
    return(strcmp(prof1->nome, prof2->nome));
}

/**
 * @brief Salva um professor em um arquivo binário.
 * @param prof Ponteiro para a estrutura do professor a ser salva.
 * @param file Ponteiro para o arquivo onde o professor será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste professor.
 */
int SalvaProfessor(tProfessor *prof, FILE *file)
{
    int qtdBytes = 0;
    int tam = 0;

    tam = strlen(prof->nome);
    qtdBytes += (fwrite(&tam, sizeof(int), 1, file)*sizeof(int));
    qtdBytes += fwrite(prof->nome, sizeof(char), tam, file);

    tam = strlen(prof->dataNasc);
    qtdBytes += (fwrite(&tam, sizeof(int), 1, file)*sizeof(int));
    qtdBytes += fwrite(prof->dataNasc, sizeof(char), tam, file);

    tam = strlen(prof->departamento);
    qtdBytes += (fwrite(&tam, sizeof(int), 1, file)*sizeof(int));
    qtdBytes += fwrite(prof->departamento, sizeof(char), tam, file);

    return qtdBytes;
}

/**
 * @brief Carrega um professor de um arquivo binário.
 * @param prof Ponteiro para a estrutura do professor a ser carregada.
 * @param file Ponteiro para o arquivo de onde o professor será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste professor.
 */
int CarregaProfessor(tProfessor *prof, FILE *file)
{
    int qtdBytes = 0;
    int tam;

    memset(prof->nome, 0, 100);
    memset(prof->dataNasc, 0, 100);
    memset(prof->departamento, 0, 100);

    qtdBytes += (fread(&tam, sizeof(int), 1, file)*sizeof(int));
    qtdBytes += fread(prof->nome, sizeof(char), tam, file);

    qtdBytes += (fread(&tam, sizeof(int), 1, file)*sizeof(int));
    qtdBytes += fread(prof->dataNasc, sizeof(char), tam, file);

    qtdBytes += (fread(&tam, sizeof(int), 1, file)*sizeof(int));
    qtdBytes += fread(prof->departamento, sizeof(char), tam, file);

    return qtdBytes;
}

/**
 * @brief Imprime o nome de um professor.
 * @param prof Ponteiro para a estrutura do professor cujo nome será impresso.
 */
void ImprimeNomeProfessor(tProfessor *prof)
{
    printf("%s\n", prof->nome);
}
