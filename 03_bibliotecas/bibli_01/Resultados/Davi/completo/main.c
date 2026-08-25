#include <stdio.h>
#include <stdlib.h>
#include "esfera_utils.h"

int main(int argc, char const *argv[])
{
    float raio = 0, volume = 0, area = 0;
    scanf("%f",&raio);

    volume = calcula_volume(raio);
    area = calcula_area(raio);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f", volume);

    return 0;
}
