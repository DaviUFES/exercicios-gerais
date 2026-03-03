#include <stdio.h>
#include <stdlib.h>
#include "tSensorPresenca.h"


struct _tSensorPresenca
{
    int tMinimo;
    int id;
    int ultimaNot;
};

tSensorPresenca *leSensorPresenca(int id)
{
    tSensorPresenca *s = (tSensorPresenca*)malloc(sizeof(tSensorPresenca));

    if(s == NULL)
        return NULL;
    
    s->id = id;
    s->ultimaNot = -999;

    scanf("%d\n", &s->tMinimo);
    return s;
}

void liberaSensorPresenca(void *s)
{
    if(s!=NULL){
        free(s);
    }
}

void processaSensorPresenca(void *s)
{
    tSensorPresenca *sensor = (tSensorPresenca*)s;

    int tempoAtual, presenca;

    scanf("%d %d", &presenca, &tempoAtual);

    if(presenca == 1 && tempoAtual - sensor->ultimaNot > sensor->tMinimo){
        printf("SENSOR(%d)[%d] processando PRESENCA:%d e %d(NOTIFICA)\n", sensor->id, sensor->tMinimo, presenca, tempoAtual);
        sensor->ultimaNot = tempoAtual;
    }else{
        printf("SENSOR(%d)[%d] processando PRESENCA:%d e %d(AGUARDA)\n", sensor->id, sensor->tMinimo, presenca, tempoAtual);
    }
}