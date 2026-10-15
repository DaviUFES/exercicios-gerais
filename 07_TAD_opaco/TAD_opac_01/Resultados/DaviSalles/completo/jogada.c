#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"


typedef struct Jogada
{
    int pos_x;
    int pos_y;
    int sucesso;
};



/**
 * Aloca e retorna uma estrutura do tipo tJogada.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogada alocada.
 */
tJogada* CriaJogada()
{
    tJogada *j = (tJogada*)malloc(sizeof(tJogada));

    j->pos_x = -1;
    j->pos_y = -1;
    j->sucesso = 0;

    return j;
}


/**
 * Libera a memória de uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser liberada.
 */
void DestroiJogada(tJogada* jogada)
{
    if(jogada!=NULL)
    {
        free(jogada);
    }
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser preenchida.
 */
void LeJogada(tJogada* jogada)
{
    int retorno;
    printf("Digite uma posicao (x e y):\n");
    retorno = scanf("%d %d", &jogada->pos_x, &jogada->pos_y);

    if(retorno == 2)
    {
        jogada->sucesso = 1;
    }
}


/**
 * Retorna a coordenada X da jogada.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada* jogada)
{
    return jogada->pos_x;
}


/**
 * Retorna a coordenada Y da jogada.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada* jogada)
{
    return jogada->pos_y;
}


/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada* jogada)
{
    return jogada->sucesso;
}
