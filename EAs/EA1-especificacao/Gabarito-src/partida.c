#include "partida.h"

#include <stdio.h>

// tPartida_getTERS
int tPartida_getIdPartida(tPartida partida) {
    return partida.idPartida;
}

int tPartida_getIdEquipe1(tPartida partida) {
    return partida.idEquipe1;
}

int tPartida_getIdEquipe2(tPartida partida) {
    return partida.idEquipe2;
}

int tPartida_getNumGolsEquipe1(tPartida partida) {
    return partida.numGolsEquipe1;
}

int tPartida_getNumGolsEquipe2(tPartida partida) {
    return partida.numGolsEquipe2;
}

// tPartida_setTERS (retornam uma nova estrutura atualizada)
tPartida tPartida_setIdPartida(tPartida partida, int id) {
    partida.idPartida = id;
    return partida;
}

tPartida tPartida_setIdEquipe1(tPartida partida, int id) {
    partida.idEquipe1 = id;
    return partida;
}

tPartida tPartida_setIdEquipe2(tPartida partida, int id) {
    partida.idEquipe2 = id;
    return partida;
}

tPartida tPartida_setNumGolsEquipe1(tPartida partida, int gols) {
    partida.numGolsEquipe1 = gols;
    return partida;
}

tPartida tPartida_setNumGolsEquipe2(tPartida partida, int gols) {
    partida.numGolsEquipe2 = gols;
    return partida;
}

tPartida tPartida_lerPartida() {
    tPartida novaPartida;
    scanf("%d %d %d %d %d\n",
          &novaPartida.idPartida,
          &novaPartida.idEquipe1,
          &novaPartida.idEquipe2,
          &novaPartida.numGolsEquipe1,
          &novaPartida.numGolsEquipe2);
    return novaPartida;
}
