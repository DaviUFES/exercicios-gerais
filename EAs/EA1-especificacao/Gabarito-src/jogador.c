#include "jogador.h"
#include <stdio.h>
#include <string.h>

void tJogador_copiaNome(tJogador j, char dst[]) {
    strcpy(dst, j.nome);
}

int tJogador_getIdEquipe(tJogador j) {
    return j.idEquipe;
}

int tJogador_getIdUnico(tJogador j) {
    return j.idUnico;
}

tJogador lerJogador() {
    tJogador jogador;
    scanf("%d %d %[^\n]\n", &jogador.idUnico, &jogador.idEquipe, jogador.nome);
    return jogador;
}
