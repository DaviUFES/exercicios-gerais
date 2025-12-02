#include <stdio.h>
#include <stdlib.h>
#include "tela.h"
#include "botao.h"


void funcao_botao_salvar()
{
    printf("- Botao de SALVAR dados ativado!\n");
}

void funcao_botao_excluir()
{
    printf("- Botao de EXCLUIR dados ativado!\n");
    
}

void funcao_botao_opcoes()
{
    printf("- Botao de OPCOES dados ativado!\n");
    
}

int main(int argc, char const *argv[])
{
    Botao b1 = CriarBotao("Salvar", 12, "FFF", CLICK, funcao_botao_salvar);
    Botao b2 = CriarBotao("Excluir", 18, "000", CLICK, funcao_botao_excluir);
    Botao b3 = CriarBotao("Opcoes", 10, "FF0000", CLICK, funcao_botao_opcoes);

    Tela t = CriarTela(200,400);

    RegistraBotaoTela(&t, b1);
    RegistraBotaoTela(&t, b2);
    RegistraBotaoTela(&t, b3);

    DesenhaTela(t);
    OuvidorEventosTela(t);
    return 0;
}
