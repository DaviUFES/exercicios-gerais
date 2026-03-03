#include "busca.h"

int tJogador_encontraIndiceVetorComIdUnico(tJogador jogadores[], int nJogadores, int idUnico) {
    for (int i = 0; i < nJogadores; i++) {
        if (tJogador_getIdUnico(jogadores[i]) == idUnico) {
            return i;
        }
    }
    return -1;
}

int tEquipe_encontraIndiceVetorComIdUnico(tEquipe equipes[], int nEquipes, int idUnico) {
    for (int i = 0; i < nEquipes; i++) {
        if (tEquipe_getIdUnico(equipes[i]) == idUnico) {
            return i;
        }
    }
    return -1;
}