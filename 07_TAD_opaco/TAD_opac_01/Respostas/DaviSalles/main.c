#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"


int main(int argc, char const *argv[])
{
    
    tJogo *jogo;
    do
    {
        jogo = CriaJogo();
        ComecaJogo(jogo);

        DestroiJogo(jogo);
    }while(ContinuaJogo(jogo));
    return 0;
}
