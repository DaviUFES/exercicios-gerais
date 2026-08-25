#include <stdio.h>
#include <stdlib.h>
#include "impressao.h"

void ImprimeInvertido(char* string)
{
    if(*string == '\0')
        return;

    ImprimeInvertido(string+1);

    printf("%c", *string);
}