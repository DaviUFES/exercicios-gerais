#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "circulo.h"

int main()
{
    float x_ponto, y_ponto, x_circulo, y_circulo, raio;
    if(scanf("%f %f %f %f %f\n", &x_circulo, &y_circulo, &raio, &x_ponto, &y_ponto))
    {
        tCirculo *c = Circulo_Cria(x_circulo, y_circulo, raio);
        tPonto p = Pto_Cria(x_ponto, y_ponto);

        int resultado = Circulo_Interior(c,p);

        printf("%d", resultado);

        Circulo_Apaga(c);
        Pto_Apaga(p);
    }
    

    
    return 0;
}