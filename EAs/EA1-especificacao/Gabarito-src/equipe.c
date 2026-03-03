#include "equipe.h"
#include <stdio.h>
#include <string.h>

void tEquipe_copiaNome(tEquipe e, char dst[]) {
    strcpy(dst, e.nome);
}

int tEquipe_getNumPontos(tEquipe e) {
    return 3 * e.nVitorias + e.nEmpates;
}

int tEquipe_getNumJogos(tEquipe e) {
    return e.nDerrotas + e.nEmpates + e.nVitorias;
}

int tEquipe_getSaldogols(tEquipe e) {
    return e.nGolsPro - e.nGolsContra;
}

int tEquipe_getQtdeGolsJogador(tEquipe e, int idJogador) {
    int contador = 0;
    for (int i = 0; i < e.nGolsPro; i++) {
        if (e.idGols[i] == idJogador) {
            contador++;
        }
    }
    return contador;
}

tEquipe tEquipe_incrementaVitorias(tEquipe e) {
    e.nVitorias++;
    return e;
}

tEquipe tEquipe_incrementaDerrotas(tEquipe e) {
    e.nDerrotas++;
    return e;
}

tEquipe tEquipe_incrementaEmpates(tEquipe e) {
    e.nEmpates++;
    return e;
}

tEquipe tEquipe_adicionaGolPro(tEquipe e, int idJogador) {
    e.idGols[e.nGolsPro] = idJogador;
    e.nGolsPro++;
    return e;
}

tEquipe tEquipe_adicionaGolsContra(tEquipe e, int nGols) {
    for(int i =0; i<nGols; i++){
        e.nGolsContra++;
    }
    return e;
}

tEquipe tEquipe_incrementaNumeroJogadores(tEquipe e) {
    e.nJogadores++;
    return e;
}

int tEquipe_getNumeroJogadores(tEquipe e) {
    return e.nJogadores;
}

int tEquipe_getNumeroVitorias(tEquipe e) {
    return e.nVitorias;
}

int tEquipe_getNumeroDerrotas(tEquipe e) {
    return e.nDerrotas;
}

int tEquipe_getNumeroEmpates(tEquipe e) {
    return e.nEmpates;
}

int tEquipe_getIdUnico(tEquipe e) {
    return e.idUnico;
}

int tEquipe_getNumeroGolsPro(tEquipe e) {
    return e.nGolsPro;
}

int tEquipe_getNumeroGolsContra(tEquipe e) {
    return e.nGolsContra;
}

tEquipe leEquipe() {
    tEquipe e;
    scanf("%d %[^\n]\n", &e.idUnico, e.nome);
    e.nDerrotas = 0;
    e.nEmpates = 0;
    e.nJogadores = 0;
    e.nGolsContra = 0;
    e.nGolsPro = 0;
    e.nVitorias = 0;
    return e;
}
