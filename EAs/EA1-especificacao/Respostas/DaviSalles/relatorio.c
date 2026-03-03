#include "relatorio.h"

#include <stdio.h>

#include "busca.h"

void geraRelatorio(tEquipe equipes[], int nEquipes, tJogador jogadores[], int nJogadores) {
    int idCampea = 0;
    int pontosCampea = tEquipe_getNumPontos(equipes[0]);
    for (int i = 1; i < nEquipes; i++) {
        if (tEquipe_getNumPontos(equipes[i]) > pontosCampea) {
            idCampea = i;
            pontosCampea = tEquipe_getNumPontos(equipes[i]);
        }
    }
    char nomeCampea[TAM_MAX_NOME];
    tEquipe_copiaNome(equipes[idCampea], nomeCampea);
    printf("EQUIPE CAMPEA: %s (%d) P:%d J:%d V:%d E:%d D:%d GP:%d GC:%d SG:%d AP:%.2f%%\n",
           nomeCampea,
           tEquipe_getIdUnico(equipes[idCampea]),
           pontosCampea,
           tEquipe_getNumJogos(equipes[idCampea]),
           tEquipe_getNumeroVitorias(equipes[idCampea]),
           tEquipe_getNumeroEmpates(equipes[idCampea]),
           tEquipe_getNumeroDerrotas(equipes[idCampea]),
           tEquipe_getNumeroGolsPro(equipes[idCampea]),
           tEquipe_getNumeroGolsContra(equipes[idCampea]),
           tEquipe_getSaldogols(equipes[idCampea]),
           ((float)100.0 * pontosCampea / ((6.0) * (nEquipes - 1))));

    // for (int i=0; i<nEquipes; i++) {
    //     char nomeEqp[TAM_MAX_NOME];
    //     tEquipe_copiaNome(equipes[i],nomeEqp);
    //     int pontos = tEquipe_getNumPontos(equipes[i]);
    //     printf("EQUIPE %s (%d) P:%d J:%d V:%d E:%d D:%d GP:%d GC:%d SG:%d AP:%.2f%%\n",
    //         nomeEqp,
    //         tEquipe_getIdUnico(equipes[i]),
    //         pontos,
    //         tEquipe_getNumJogos(equipes[i]),
    //         tEquipe_getNumeroVitorias(equipes[i]),
    //         tEquipe_getNumeroEmpates(equipes[i]),
    //         tEquipe_getNumeroDerrotas(equipes[i]),
    //         tEquipe_getNumeroGolsPro(equipes[i]),
    //         tEquipe_getNumeroGolsContra(equipes[i]),
    //         tEquipe_getSaldogols(equipes[i]),
    //         ((float) 100.0*pontos/((6.0)*(nEquipes-1)))
    //     );
    // }

    int maxGols = 0;
    int indiceArtilheiro = -1;
    // int indiceEquipeVetor = 0;
    for (int i = 0; i < nJogadores; i++) {
        int idEquipe = tJogador_getIdEquipe(jogadores[i]);

        int indiceEquipeVetor = tEquipe_encontraIndiceVetorComIdUnico(equipes, nEquipes, idEquipe);
        if (tEquipe_getQtdeGolsJogador(equipes[indiceEquipeVetor], tJogador_getIdUnico(jogadores[i])) > maxGols) {
            maxGols = tEquipe_getQtdeGolsJogador(equipes[indiceEquipeVetor], tJogador_getIdUnico(jogadores[i]));
            indiceArtilheiro = i;
        }
    }
    char nomeArtilheiro[TAM_MAX_NOME];
    char nomeTimeArtilheiro[TAM_MAX_NOME];
    tJogador_copiaNome(jogadores[indiceArtilheiro], nomeArtilheiro);
    int indiceEquipeArtilheiro = tEquipe_encontraIndiceVetorComIdUnico(equipes, nEquipes, tJogador_getIdEquipe(jogadores[indiceArtilheiro]));
    tEquipe_copiaNome(equipes[indiceEquipeArtilheiro], nomeTimeArtilheiro);
    printf("ARTILHEIRO: %s (%s) - %d GOLS\n",
           nomeArtilheiro,
           nomeTimeArtilheiro,
           maxGols);
}