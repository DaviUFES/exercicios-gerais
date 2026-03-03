#include "inconsistencias.h"
#include <stdio.h>

int verificaInconsistencias(int nPartidas, int nEquipes, tEquipe equipes[]) {
    if (nPartidas != (nEquipes * (nEquipes - 1))) {
        printf("CAMPEONATO NAO FINALIZADO\n");
        return 1;
    }
    for (int i = 0; i < nEquipes; i++) {
        if (tEquipe_getNumJogos(equipes[i]) != (2 * (nEquipes - 1))) {
            printf("ERRO DE CADASTRO\n");
            return 1;
        }
    }
    return 0;
}