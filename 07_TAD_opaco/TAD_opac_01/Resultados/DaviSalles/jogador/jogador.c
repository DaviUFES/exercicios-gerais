#include "jogador.h"
#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Jogador
{
    int id;
};


/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 * 
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador* CriaJogador(int idJogador)
{
    tJogador *j = (tJogador*)malloc(sizeof(struct Jogador));
    j->id = idJogador;
}


/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador)
{
    if(jogador!=NULL)
        free(jogador);
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro)
{
    int x = 0, y=0;
    tJogada *jogada = CriaJogada();

    while(1)
    {
        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);

        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);

        if(EhPosicaoValidaTabuleiro(x, y))
        {
            if(EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
            {
                MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);
                printf("Jogada [%d,%d]!\n",x,y);
                break;
            } else
            {
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n",x,y);
            }
        } else
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n",x,y);
        }
    }
    DestroiJogada(jogada);
}


/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro)
{
    int peca_jogador;
    if(jogador->id == ID_JOGADOR_1)
    {
        peca_jogador = PECA_1;
    } else
    {
        peca_jogador = PECA_2;
    }

    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca_jogador))
        return 1;
    else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, peca_jogador))
        return 1;
    else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca_jogador))
        return 1;

    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca_jogador))
        return 1;
    else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, peca_jogador))
        return 1;
    else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca_jogador))
        return 1;

    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca_jogador))
        return 1;
    else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca_jogador) && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca_jogador))
        return 1;

    return 0;
}
