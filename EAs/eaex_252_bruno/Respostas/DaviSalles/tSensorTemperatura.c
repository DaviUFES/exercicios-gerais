#include <stdlib.h>
#include <stdio.h>
#include "tSensorTemperatura.h"

struct _tSensorTemperatura{
    int id;
    int tMin;
    int tMax;
    int estadoAtual;
};

tSensorTemperatura *leSensorTemperatura(int id)
{
    tSensorTemperatura *s = (tSensorTemperatura*)malloc(sizeof(tSensorTemperatura));

    if(s==NULL)
        return NULL;

    scanf("%d %d", &s->tMin, &s->tMax);
    s->id = id;
    s->estadoAtual = 0;

    return s;
}

void liberaSensorTemperatura(void *s)
{
    if(s!=NULL)
        free(s);
}

void processaSensorTemperatura(void *s)
{
    tSensorTemperatura *sensor = (tSensorTemperatura*)s;

    int tAtual;
    scanf("%d", &tAtual);


    switch(sensor->estadoAtual){
        case 0:
            if(tAtual>sensor->tMax){
                printf("SENSOR(%d)[%d-%d] processando TEMP:%d(LIGANDO AR)\n", sensor->id, sensor->tMin, sensor->tMax, tAtual);
                sensor->estadoAtual = 1;
                break;
            }else if(tAtual>=sensor->tMin){
                printf("SENSOR(%d)[%d-%d] processando TEMP:%d(MANTEM AR)\n", sensor->id, sensor->tMin, sensor->tMax, tAtual);
                break;
            }else{
                printf("SENSOR(%d)[%d-%d] processando TEMP:%d(MANTEM AR)\n", sensor->id, sensor->tMin, sensor->tMax, tAtual);
                break;
            }
        case 1:
            if(tAtual>sensor->tMax){
                printf("SENSOR(%d)[%d-%d] processando TEMP:%d(MANTEM AR)\n", sensor->id, sensor->tMin, sensor->tMax, tAtual);
                break;
            }else if(tAtual>=sensor->tMin){
                printf("SENSOR(%d)[%d-%d] processando TEMP:%d(MANTEM AR)\n", sensor->id, sensor->tMin, sensor->tMax, tAtual);
                break;
            }else{
                printf("SENSOR(%d)[%d-%d] processando TEMP:%d(DESLIGANDO AR)\n", sensor->id, sensor->tMin, sensor->tMax, tAtual);
                sensor->estadoAtual = 0;
                break;
            }

    }

}
