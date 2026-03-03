#include <stdio.h>
#include <stdlib.h>
#include "tMonitorador.h"

/* typedef void (*FptrProcessaElemento)(void * e);
typedef void (*FptrLiberaElemento)(void * e); */

struct _tMonitorador{
    int qtdSensores;
    void **sensores;
    FptrProcessaElemento funcPE;
    FptrLiberaElemento funcLE;
};

tMonitorador * criaMonitorador(FptrProcessaElemento funcPE, FptrLiberaElemento funcLE)
{
    tMonitorador *m = (tMonitorador*)malloc(sizeof(tMonitorador));

    if(m == NULL)
        return NULL;
    
    m->qtdSensores = 0;
    m->sensores = NULL;

    m->funcPE = funcPE;
    m->funcLE = funcLE;

    return m;
}

void liberaMonitorador(tMonitorador* m)
{
    if(m){
        if(m->sensores){
            for(int i = 0; i<m->qtdSensores; i++){
                m->funcLE(m->sensores[i]);
            }
            free(m->sensores);
        }free(m);
    }
}

void adicionaElementoMonitorador(tMonitorador * m, void * e)
{
    int qtdAtual = m->qtdSensores;

    m->sensores = (void**)realloc(m->sensores,(qtdAtual+1)*sizeof(void*));

    m->sensores[qtdAtual] = e;
    m->qtdSensores = qtdAtual+1;

}
void iniciaMonitoramentotMonitorador(tMonitorador* m, int numeroDeCiclos)
{
    for(int ciclo = 0; ciclo<numeroDeCiclos; ciclo++){
        for(int i = 0; i<m->qtdSensores; i++){
            m->funcPE(m->sensores[i]);
        }
    }
}
