#include <stdio.h>
#include <stdlib.h>
#include "tMonitorador.h"

struct _tMonitorador
{
    void **eventos;
    FptrProcessaEvento *funcProcessa;
    FptrLiberaEvento *funcLibera;
    FptrIdentificaEvento *funcIdent;
    int qtdEventos;
}



/// @brief Função que cria uma variável do tipo monitorador de eventos
/// @return Um ponteiro para a variável do tipo monitorador de eventos
tMonitorador* criaMonitorador()
{
    tMonitorador *m = (tMonitorador*)malloc(sizeof(tMonitorador));
    m->qtdEventos = 0;
    return m;
}

/// @brief Função que libera o monitorador e seus eventos cadastrados.
/// @param m - O monitorador a ser liberado
void liberaMonitorador(tMonitorador* m)
{
    if(m!=NULL)
    {
        for(int i = 0; i<m->qtdEventos; i++)
        {
            m->funcLibera[i](m->eventos[i]);
        }
        free(m->funcLibera);
        free(m->funcProcessa);
        free(m->funcIdent);
        free(m);
    }
}

/// @brief Função que adiciona um evento a um monitorador de eventos
/// @param m - Ponteiro para o monitorador de eventos
/// @param e - Ponteiro para o evento a ser cadastrado no monitorados
/// @param funcPE Callback para a função a ser executada quando o evento for identificado ("evento será processado")
/// @param funcId Callback para a função responsável por indicar se a tecla apertada se refere a um dos eventos
///                 cadastrados no monitorador
/// @param funcLE Callback para a função a ser executada quando o evento cadastrado tiver que ser liberado
void adicionaElementoMonitorador(tMonitorador* m, void* e, FptrProcessaEvento funcPE, FptrIdentificaEvento funcId, FptrLiberaEvento funcLE)
{
    int novaQtd = m->qtdEventos + 1;

    m->eventos = realloc(m->eventos, novaQtd * sizeof(void*));
    m->funcIdent = realloc(m->funcIdent, novaQtd * sizeof(FptrIdentificaEvento));
    m->funcLibera = realloc(m->funcProcessa, novaQtd * sizeof(FptrLiberaEvento));
    m->funcProcessa = realloc(m->funcProcessa, novaQtd * sizeof(FptrProcessaEvento));

    m->eventos[m->qtdEventos] = e;
    m->funcIdent[m->qtdEventos] = funcId;
    m->funcLibera[m->qtdEventos] = funcLE;
    m->funcProcessa[m->qtdEventos] = funcPE;

    m->qtdEventos++;
}

/// @brief Função que inicia o "loop de escuta" do monitorador. Ver especificação do EA para mais detalhes
/// @param amb - Ponteiro para o ambiente
/// @param m - Ponteiro para o monitorador de eventos
void iniciaMonitoramentotMonitorador(tAmbiente* amb, tMonitorador* m);
