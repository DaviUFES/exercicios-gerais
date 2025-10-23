#include "jogo.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>

/**
typedef struct{
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;
    
} tJogo;


 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo()
{
    tJogo j;
    tJogador jogador1, jogador2;
    tTabuleiro tabuleiro;

    jogador1 = CriaJogador(ID_JOGADOR_1);
    jogador2 = CriaJogador(ID_JOGADOR_2);
    
    tabuleiro = CriaTabuleiro();

    return j;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo);


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo);


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo();
