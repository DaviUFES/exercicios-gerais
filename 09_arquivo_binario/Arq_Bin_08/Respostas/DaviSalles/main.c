#include <stdio.h>
#include <stdlib.h>
#include "lista_contato.h"
#include "contato.h"

int main()
{
    char caminhoEntrada[100], caminhoSaida[100];
    int opcao, subOpcao;

    scanf(" %s", caminhoEntrada);

    tListaContato *lista = CriarListaContato();
    CarregarListaContato(lista, caminhoEntrada);

    do
    {

        printf("1 - Cadastrar contato\n");
        printf("2 - Remover contato\n");
        printf("3 - Realizar busca\n");
        printf("4 - Exibir todos os contatos\n");
        printf("0 - Sair da lista de contatos\n");
        printf("Opcao escolhida:\n");

        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
            {
                tContato *novoContato = LeContato();
                AdicionarContatoListaContato(lista, novoContato);
                break;
            }
            case 2:
            {
                RemoverContatoListaContato(lista);
                break;
            }
            case 3:
            {

                printf("1 - Buscar pelo nome\n");
                printf("2 - Buscar pelo numero de telefone\n");
                printf("Opcao escolhida:\n");
                
                scanf("%d", &subOpcao);
                if(subOpcao==1)
                    BuscarPorNomeListaContato(lista);
                if(subOpcao==2)
                    BuscarPorNumeroTelefoneListaContato(lista);
                break;
            }
            case 4:
            {
                ImprimirListaContato(lista);
                break;
            }
            case 0:
            {
                scanf(" %s", caminhoSaida);

                SalvarListaContato(lista, caminhoSaida);
                DestruirListaContato(lista);
                break;
            }
            default:
                break;
        }
    }while(opcao!=0);
    return 0;
}