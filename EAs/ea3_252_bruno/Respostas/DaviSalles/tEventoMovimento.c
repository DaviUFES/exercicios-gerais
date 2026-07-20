#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tEventoMovimento.h"

struct eventomovimento
{
    char movimentos[5];
};

/// @brief Função que cria um evento do tipo movimento
/// @param caracteresAceitos - Vetor de QUATRO caracteres que irá representar movimento
///                             na ordem: CIMA, ESQUERDA, BAIXO, DIREITA
/// @return O ponteiro para a variável do tipo evento movimento
tEventoMovimento* criaEventoMovimento(char *caracteresAceitos)
{
    tEventoMovimento *e = (tEventoMovimento*)malloc(sizeof(tEventoMovimento));
    e->movimentos[0] = caracteresAceitos[0];
    e->movimentos[1] = caracteresAceitos[1];
    e->movimentos[2] = caracteresAceitos[2];
    e->movimentos[3] = caracteresAceitos[3];
    
    // Coloca o terminador de string manualmente no último espaço disponível
    e->movimentos[4] = '\0';
    return e;
}

/// @brief Função que libera o evento...
/// @param eve - Ponteiro para o evento
void liberaEventoMovimento(void* eve)
{
    if(eve!=NULL)
    {
        free(eve);
    }
}

/// @brief Função que executará o comportamento de um evento movimento
///         No caso, deve alterar o ambiente de acordo com a tecla apertada, se for possível
/// @param amb - Ponteiro para o ambiente a ser manipulado
/// @param eve - Ponteiro para o evento de movimento 
/// @param c - Caractere que foi digitado no teclado
void processaEventoMovimento(tAmbiente *amb, void *eve, char c)
{
    tEventoMovimento *evento = (tEventoMovimento*)eve;

    int linha, coluna;
    retornaPosicaoAtual(amb, &linha, &coluna);

    int novaLinha = linha;
    int novaColuna = coluna;

    if(c == evento->movimentos[0])
    {
        novaLinha--;
    }else if(c == evento->movimentos[1])
    {
        novaColuna--;
    }else if(c == evento->movimentos[2])
    {
        novaLinha++;
    }else if(c == evento->movimentos[3])
    {
        novaColuna++;
    }

    if(novaLinha >= 0 && novaLinha<10 && novaColuna>=0 && novaColuna<10)
    {
        char situacao = retornaSituacaoPosicao(amb, novaLinha, novaColuna);
        if(situacao == '0' || situacao == '\0')
        {
            alteraPosicaoJogador(amb, novaLinha, novaColuna);
            printf("MOVIMENTO PARA POSICAO (%d,%d)\n", novaLinha, novaColuna);
            return;
        }
        printf("MOVIMENTO INVALIDO POIS EXISTE OBSTACULO!\n");
        return;
    }
    printf("MOVIMENTO INVALIDO POIS SAI DO MAPA!\n");
    

}

/// @brief Função que indica se um caractere apertado está registrado nos caracteres válidos de um movimento
/// @param eve - ponteiro para a variável evento
/// @param c - Caractere que foi digitado no teclado
/// @return 1 se o caractere digitado está registrado como um caractere do evento
int identificaEventoMovimento(void *eve, char c)
{
    tEventoMovimento *evento = (tEventoMovimento*)eve;
    for(int i = 0; i<4; i++)
    {
        if(evento->movimentos[i] == c)
        {
            return 1;
        }
    }
    return 0;
}
