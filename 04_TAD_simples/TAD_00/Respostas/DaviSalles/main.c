#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main(int argc, char const *argv[])
{
    Ponto p1, p2;

    float x1, y1, x2, y2, dist;

    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    p1 = pto_cria(x1, y1);
    p2 = pto_cria(x2, y2);

    dist = pto_distancia(p1, p2);
    printf("%f\n", dist);

    return 0;
}
