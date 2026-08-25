#include <stdio.h>
#include <stdlib.h>
#include "impressao.h"

int main()
{
    char string[100];
    int espaco = 1;

    while(scanf("%s\n", string)==1)
    {
        if(!espaco)
            printf(" ");

        ImprimeInvertido(string);

        espaco = 0;
    }


    return 0;
}