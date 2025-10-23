#include "jogador.h"
#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct{
    int id;
} tJogador;

 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador j;
    j.id = idJogador;
    return j;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada j;
    int peca;

    if(jogador.id == ID_JOGADOR_1)
        peca = PECA_1;
    else
        peca = PECA_2;

    while(1)
    {
        printf("Jogador %d\n", &jogador.id);
        j = LeJogada();
        if(FoiJogadaBemSucedida(j))
        {
            if(EhPosicaoValidaTabuleiro(ObtemJogadaX(j), ObtemJogadaY(j)))
            {
                tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, peca, ObtemJogadaX(j), ObtemJogadaY(j));
                printf("Jogada [%d,%d]!\n", ObtemJogadaX(j), ObtemJogadaY(j));
                break;
            }
            else
            {
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(j), ObtemJogadaY(j));
            }
        }
        else
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(j), ObtemJogadaY(j));
        }
    }
    
    return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    char peca;

    if(jogador.id == ID_JOGADOR_1)
    {
        peca = tabuleiro.peca1;
    }
    else
    {
        peca = tabuleiro.peca2;
    }

    if(tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[0][1] == peca && tabuleiro.posicoes[0][2] == peca)
        return 1;
    else if (tabuleiro.posicoes[1][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[1][2] == peca)
        return 1;
    else if (tabuleiro.posicoes[2][0] == peca && tabuleiro.posicoes[2][1] == peca && tabuleiro.posicoes[2][2] == peca)
        return 1;
    else if (tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][0] == peca && tabuleiro.posicoes[2][0] == peca)
        return 1;
    else if (tabuleiro.posicoes[0][1] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][1] == peca)
        return 1;
    else if (tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][2] == peca && tabuleiro.posicoes[2][2] == peca)
        return 1;
    else if (tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][2] == peca)
        return 1;
    else if (tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][0] == peca)
        return 1;

    return 0;
}
