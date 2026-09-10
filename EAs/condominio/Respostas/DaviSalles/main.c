#include <stdio.h>
#include <stdlib.h>
#include "area.h"
#include "morador.h"
#include "reserva.h"
#include "data.h"

int main(int argc, char const *argv[])
{
    int qtdAreas, qtdMoradores, qtdSolicitacoes;
    int qtdReservasAprovadas;
    Area areas[10];
    Morador moradores[100];
    Reserva reservas[100];

    scanf("%d", &qtdAreas);
    for(int i = 0; i<qtdAreas; i++)
    {
        areas[i] = lerArea();
    }

    scanf("%d", &qtdMoradores);
    for(int i = 0; i<qtdMoradores; i++)
    {
        moradores[i] = lerMorador();
    }

    char idArea[MAX_TAM_ID];
    char cpfMoradorReserva[MAX_TAM_CPF];
    Morador moradorReserva;
    Area areaReserva;
    Data dReserva;
    int nConvidados;

    scanf("%d", &qtdSolicitacoes);
    for(int i = 0; i<qtdSolicitacoes; i++)
    {
        scanf(" %[^\n]", idArea);
        for(int j = 0; j<qtdAreas; j++)
        {
            if(verificaIdArea(areas[j], idArea)==1)
                areaReserva = areas[j];
        }

        scanf(" %[^\n]", cpfMoradorReserva);
        for(int j = 0; j<qtdMoradores; j++)
        {
            if(verificaCPFMorador(moradores[j], cpfMoradorReserva) == 1)
                moradorReserva = moradores[j];
        }
        dReserva = lerData();
        scanf(" %d", &nConvidados);

        if(verificaSolicitacaoReserva(reservas, qtdReservasAprovadas, moradorReserva, areaReserva, dReserva, nConvidados) == 1)
        {
            reservas[qtdReservasAprovadas] = criaReserva(moradorReserva, areaReserva, dReserva, nConvidados);
            qtdReservasAprovadas++;
        }
            
    }

    for(int i = 0; i<qtdReservasAprovadas; i++)
    {
        imprimeReserva(reservas[i]);
    }

    

    return 0;
}
