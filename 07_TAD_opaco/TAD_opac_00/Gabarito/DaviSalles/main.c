#include <stdlib.h>
#include <stdio.h>
#include "circulo.h"
#include "ponto.h"

int main(int argc, char const *argv[])
{
    float x_centro, y_centro, raio, x_teste, y_teste;

    if(scanf("%f %f %f %f %f", &x_centro, &y_centro, &raio, &x_teste, &y_teste))
    {
        tCirculo c = Circulo_Cria(x_centro, y_centro, raio);

        tPonto p = Pto_Cria(x_teste, y_teste);

        int resultado = Circulo_Interior(c, p);
        printf("%d", resultado);

        Pto_Apaga(p);

        Circulo_Apaga(c);
    }

    return 0;
}
