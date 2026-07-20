#ifndef _EVENTOCLIQUE_H_
#define _EVENTOCLIQUE_H_

#include "tAmbiente.h"

struct tEventoClique
{
    char teclas[5];
};

tEventoClique* criaEventoClique(char *caracteresAceitos)
{
    tEventoClique *e = (tEventoClique*)malloc(sizeof(tEventoClique));
    e->movimentos[0] = caracteresAceitos[0];
    e->movimentos[1] = caracteresAceitos[1];
    e->movimentos[2] = caracteresAceitos[2];
    
    // Coloca o terminador de string manualmente no último espaço disponível
    e->movimentos[3] = '\0';
    return e;
}

void liberaEventoClique(void* eve)
{
    if(eve!= NULL)
        free(eve);
}

void processaEventoClique(tAmbiente *amb, void *eve, char c)
{
    EventoClique *evento = (tEventoClique*)eve;

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

    

}

int identificaEventoClique(void *eve, char c);

#endif