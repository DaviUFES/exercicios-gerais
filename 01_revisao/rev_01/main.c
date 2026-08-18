#include <stdio.h>
#include <stdlib.h>
#include "calculo.h"

int main(){

    float x1, y1, x2, y2, r1, r2;
    scanf("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);

    float result = calculo(x1, y1, r1, x2, y2, r2);

    if (result < (r1 + r2)) {
        printf("ACERTOU\n");
    } else {
        printf("ERROU\n");
    }

    return 0;
}

