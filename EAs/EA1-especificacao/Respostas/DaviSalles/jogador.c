#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"

/* #define TAM_MAX_NOME 30

/*  Definição da estrutura 
    NÃO ALTERAR


typedef struct
{
    int idUnico;
    int idEquipe;
    char nome[TAM_MAX_NOME];
} tJogador; */


/// @brief Função que copia o conteúdo de um nome de um jogador para uma nova variável
/// @param j - o jogador que terá seu nome copiado
/// @param dst - o vetor "externo" que receberá o valor copiado
void tJogador_copiaNome(tJogador j, char dst[])
{
    strcpy(dst, j.nome);
}

/// @brief Função getter - retorna um campo da estrutura
/// @param j - um jogador
/// @return O id da equipe do jogador
int tJogador_getIdEquipe(tJogador j)
{
    return j.idEquipe;
}

/// @brief Função getter - retorna um campo da estrutura
/// @param j - um jogador
/// @return O id único do jogador
int tJogador_getIdUnico(tJogador j)
{
    return j.idUnico;
}

/// @brief Função que lê os dados de um jogador (scanf)
///         E retorna a variável inicializada e preenchida.
/// @return 
tJogador lerJogador()
{
    tJogador j;
    scanf("%d %d %[^\n]\n", &j.idUnico, &j.idEquipe, j.nome);
    return j;
}
