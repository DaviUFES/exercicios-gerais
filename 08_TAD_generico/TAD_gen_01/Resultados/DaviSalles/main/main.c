#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"


int main(int argc, char const *argv[])
{
    int tipo;
    int qtdElementos;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:");
    scanf("%d %d", &tipo, &qtdElementos);
    tGeneric *g = CriaGenerico(tipo, qtdElementos);
    LeGenerico(g);
    ImprimeGenerico(g);
    DestroiGenerico(g);
    
    return 0;
}
