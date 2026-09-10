#include <stdio.h>
#include <stdlib.h>
#include "area.h"
#include "morador.h"
#include "reserva.h"
#include "data.h"

int main(int argc, char const *argv[])
{
    int qtdAreas = 0, qtdMoradores = 0, qtdSolicitacoes = 0;
    int qtdReservasAprovadas = 0;
    
    // Inicializando os arrays com {0} para evitar lixo de memória e avisos no Valgrind
    Area areas[10] = {0};
    Morador moradores[100] = {0};
    Reserva reservas[100] = {0};

    scanf("%d", &qtdAreas);
    for(int i = 0; i < qtdAreas; i++)
    {
        areas[i] = lerArea();
    }

    scanf("%d", &qtdMoradores);
    for(int i = 0; i < qtdMoradores; i++)
    {
        moradores[i] = lerMorador();
    }

    char idArea[MAX_TAM_ID];
    char cpfMoradorReserva[MAX_TAM_CPF];
    
    // Inicializando as structs auxiliares com {0}
    Morador moradorReserva = {0};
    Area areaReserva = {0};
    Data dReserva = {0};
    int nConvidados = 0;

    scanf("%d", &qtdSolicitacoes);
    for(int i = 0; i < qtdSolicitacoes; i++)
    {
        scanf(" %[^\n]", idArea);
        
        int encontrouArea = 0;
        for(int j = 0; j < qtdAreas; j++)
        {
            if(verificaIdArea(areas[j], idArea) == 1)
            {
                areaReserva = areas[j];
                encontrouArea = 1;
            }
        }

        scanf(" %[^\n]", cpfMoradorReserva);
        
        int encontrouMorador = 0;
        for(int j = 0; j < qtdMoradores; j++)
        {
            if(verificaCPFMorador(moradores[j], cpfMoradorReserva) == 1)
            {
                moradorReserva = moradores[j];
                encontrouMorador = 1;
            }
        }
        
        dReserva = lerData();
        scanf("%d", &nConvidados);

        // Só encaminha para a validação se a Área e o Morador existirem de fato
        if(encontrouArea == 1 && encontrouMorador == 1)
        {
            if(verificaSolicitacaoReserva(reservas, qtdReservasAprovadas, moradorReserva, areaReserva, dReserva, nConvidados) == 1)
            {
                reservas[qtdReservasAprovadas] = criaReserva(moradorReserva, areaReserva, dReserva, nConvidados);
                qtdReservasAprovadas++;
            }
        }
    }

    // A especificação pede a impressão de todas as reservas que obtiveram sucesso[cite: 1]
    for(int i = 0; i < qtdReservasAprovadas; i++)
    {
        imprimeReserva(reservas[i]);
    }

    return 0;
}