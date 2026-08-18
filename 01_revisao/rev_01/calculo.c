#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "calculo.h"

float calculo(float x1, float y1, float r1, float x2, float y2, float r2){
    float d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return d;
};

