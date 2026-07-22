#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "aluno.h"
#include "professor.h"

struct Database
{
    tAluno **alunos;
    int qtdAlunos;

    tProfessor **professores;
    int qtdProfessores;
};

/**
 * @brief Cria um nova database.
 * @return Um ponteiro para a estrutura database criada. Caso a alocação falhe, a função termina o programa.
 */
tDatabase *CriaDatabase()
{
    tDatabase *db = (tDatabase*)malloc(sizeof(tDatabase));

    if(db ==NULL)
        exit(1);

    db->alunos = NULL;
    db->professores = NULL;
    db->qtdAlunos = 0;
    db->qtdProfessores = 0;

    return db;
}

/**
 * @brief Destroi uma database.
 * @param db Ponteiro para a estrutura da database a ser destruída.
 */
void DestroiDatabase(tDatabase *db)
{
    if(db != NULL)
    {
        for(int i = 0; i<db->qtdAlunos; i++)
            DestroiAluno(db->alunos[i]);
        for(int i = 0; i<db->qtdProfessores; i++)
            DestroiProfessor(db->professores[i]);
        if(db->alunos != NULL) free(db->alunos);
        if(db->professores != NULL) free(db->professores);
        free(db);
    }
}

/**
 * @brief Lê uma database da entrada padrão.
 * @param db Ponteiro para a estrutura da database a ser lida.
 */
void LeDatabase(tDatabase *db)
{
    int qtdAlunos;
    scanf("%d", &qtdAlunos);

    db->alunos = (tAluno**)malloc(sizeof(tAluno*)*qtdAlunos);

    for(int i = 0; i<qtdAlunos; i++)
    {
        db->alunos[i] = LeAluno();
        db->qtdAlunos++;
    }

    int qtdProf;
    scanf("%d", &qtdProf);

    db->professores = (tProfessor**)malloc(sizeof(tProfessor*)*qtdProf);

    for(int i = 0; i<qtdProf; i++)
    {
        db->professores[i] = LeProfessor();
        db->qtdProfessores++;
    }
}

/**
 * @brief Ordena uma database, primeiro os alunos e depois os professores, de acordo com o nome.
 * @param db Ponteiro para a estrutura da database a ser ordenada.
 */
void OrdenaDatabase(tDatabase *db)
{
    for(int i = 0; i<db->qtdAlunos-1; i++)
    {
        for(int j = 0; j<db->qtdAlunos-i-1;j++)
        {
            if(ComparaNomeAluno(db->alunos[j], db->alunos[j+1])>0)
            {
                tAluno *aux = db->alunos[j];
                db->alunos[j] = db->alunos[j+1];
                db->alunos[j+1] = aux;
            }
        }
    }
    for(int i = 0; i<db->qtdProfessores-1; i++)
    {
        for(int j = 0; j<db->qtdProfessores-i-1;j++)
        {
            if(ComparaNomeProfessor(db->professores[j], db->professores[j+1])>0)
            {
                tProfessor *aux = db->professores[j];
                db->professores[j] = db->professores[j+1];
                db->professores[j+1] = aux;
            }
        }
    }
}

/**
 * @brief Salva uma database em um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser salva.
 * @param file Ponteiro para o arquivo onde a database será salva.
 * @return Um inteiro indicando o total de bytes salvos.
 */
int SalvarDatabase(tDatabase *db, FILE *file)
{
    int qtdBytes = 0;

    qtdBytes += (fwrite(&db->qtdAlunos, sizeof(int), 1, file));

    for(int i = 0; i<db->qtdAlunos; i++)
    {
        qtdBytes += SalvaAluno(db->alunos[i],file);
    }

    qtdBytes += (fwrite(&db->qtdProfessores, sizeof(int), 1, file));

    for(int j = 0; j<db->qtdProfessores; j++)
    {
        qtdBytes += SalvaProfessor(db->professores[j],file);
    }

    return qtdBytes;
}

/**
 * @brief Carrega uma database de um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser carregada.
 * @param file Ponteiro para o arquivo de onde a database será carregada.
 * @return Um inteiro indicando o total de bytes lidos.
 */
int CarregaDatabase(tDatabase *db, FILE *file)
{
    int qtdBytes = 0;
    int qtdAlunos = 0;

    qtdBytes += (fread(&qtdAlunos, sizeof(int), 1, file));
    db->qtdAlunos = qtdAlunos;

    db->alunos = (tAluno**)malloc(sizeof(tAluno*)*db->qtdAlunos);

    for(int i = 0; i<db->qtdAlunos; i++)
    {
        db->alunos[i] = CriaAluno("","","",0,0.0);
        qtdBytes += CarregaAluno(db->alunos[i], file);
    }

    int qtdProfessores = 0;

    qtdBytes += (fread(&qtdProfessores, sizeof(int), 1, file));
    db->qtdProfessores = qtdProfessores;

    db->professores = (tProfessor**)malloc(sizeof(tProfessor*)*db->qtdProfessores);

    for(int j = 0; j<db->qtdProfessores; j++)
    {
        db->professores[j] = CriaProfessor("","","");
        qtdBytes += CarregaProfessor(db->professores[j], file);
    }

    return qtdBytes;

}

/**
 * @brief Imprime uma database, primeiro os alunos e depois os professores. Apenas os nomes são impressos.
 * @param db Ponteiro para a estrutura da database a ser impressa.
 */
void ImprimeDatabase(tDatabase *db)
{
    printf("Alunos:\n");
    for(int i = 0; i<db->qtdAlunos; i++)
        ImprimeNomeAluno(db->alunos[i]);
    printf("\n");
    printf("Professores:\n");
    for(int i = 0; i<db->qtdProfessores; i++)
        ImprimeNomeProfessor(db->professores[i]);
}
