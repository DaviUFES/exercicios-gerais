#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"


typedef struct Jogo
{
    tJogador *jogador1;
    tJogador *jogador2;
    tTabuleiro *tabuleiro;
};

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo()
{
    tJogo *j = (tJogo*)malloc(sizeof(tJogo));

    return j;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo* jogo)
{
    jogo->jogador1 = CriaJogador(2);
    jogo->jogador2 = CriaJogador(1);
    jogo->tabuleiro = CriaTabuleiro();

    RealizaJogo(jogo);
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo* jogo)
{
    if(TemPosicaoLivreTabuleiro(jogo->tabuleiro))
        return 0;
    return 1;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    char resposta;
    printf("Jogar novamente? (s,n)\n");
    scanf("%*[^sn]");
    scanf("%c", &resposta);
    return (resposta == 's' ? 1 : 0);
}


/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo)
{
    if(jogo!=NULL)
    {
        if(jogo->jogador1)
            DestroiJogador(jogo->jogador1);
        if(jogo->jogador2)
            DestroiJogador(jogo->jogador2);
        if(jogo->tabuleiro)
            DestroiTabuleiro(jogo->tabuleiro);

        free(jogo);
    }
}


void RealizaJogo(tJogo *jogo) {
    int idJogador = 0;
    tJogador *jogadorRodada;
    
    do {

        if (idJogador == ID_JOGADOR_1) {
            idJogador = ID_JOGADOR_2;
        } else {
            idJogador = ID_JOGADOR_1;
        }

        if (idJogador == ID_JOGADOR_1) {
            jogadorRodada = jogo->jogador2;
        } else {
            jogadorRodada = jogo->jogador1;
        }
        JogaJogador(jogadorRodada, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
    } while(!AcabouJogo(jogo) && !VenceuJogador(jogadorRodada, jogo->tabuleiro));

    if(VenceuJogador(jogadorRodada, jogo->tabuleiro)) {
        printf("JOGADOR %d Venceu!\n", idJogador);
    } else {
        printf("Sem vencedor!\n");
    }
}