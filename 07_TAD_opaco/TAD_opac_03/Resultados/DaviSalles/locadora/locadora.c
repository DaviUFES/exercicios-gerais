#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

#define MAX_FILMES 100

typedef struct Locadora{
    tFilme **filmes;
    int numFilmes;
    int lucro;
}tLocadora;

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora ()
{
    tLocadora *l = (tLocadora*)malloc(sizeof(tLocadora));
    l->filmes = NULL;
    l->numFilmes = 0;
    l->lucro = 0;

    return l;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora)
{
    if(locadora!=NULL)
    {
        if(locadora->filmes)
        {
            for(int i = 0; i<locadora->numFilmes; i++)
            {
                DestruirFilme(locadora->filmes[i]);
            }
            free(locadora->filmes);
        }
        free(locadora);
    }
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo)
{
    for(int i = 0; i<locadora->numFilmes; i++)
    {
        if(EhMesmoCodigoFilme(locadora->filmes[i], codigo))
            return 1;
    }
    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme)
{
    if(!locadora->filmes)
        locadora->filmes = (tFilme**)malloc(MAX_FILMES*sizeof(tFilme*));

    if(!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme)))
    {
        locadora->filmes[locadora->numFilmes] = filme;
        printf("Filme cadastrado %d - ", ObterCodigoFilme(locadora->filmes[locadora->numFilmes]));
        ImprimirNomeFilme(locadora->filmes[locadora->numFilmes]);
        printf("\n");
        locadora->numFilmes++;
    } 
    else 
    {
        printf("Filme ja cadastrado no estoque\n");
        DestruirFilme(filme);
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora)
{
    int codigo;
    while(scanf("%d", &codigo) == 1)
    {
        tFilme *filme = CriarFilme();
        scanf("%*[^a-zA-Z]");
        LeFilme(filme, codigo);
        CadastrarFilmeLocadora(Locadora, filme);
    }
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {
    int i, j;
    int qtdAlugados = 0, valorTotal = 0;
    for(i = 0; i < quantidadeCodigos; i++) {
        if(VerificarFilmeCadastrado(locadora, codigos[i])) {
            for(j = 0; j < locadora->numFilmes; j++) {
                if(EhMesmoCodigoFilme(locadora->filmes[j], codigos[i])) {
                    if(ObterQtdEstoqueFilme(locadora->filmes[j]) > 0) {
                        AlugarFilme(locadora->filmes[j]);
                        qtdAlugados++;
                        valorTotal += ObterValorFilme(locadora->filmes[j]);
                        break;
                    } else {
                        printf("Filme %d - ", ObterCodigoFilme(locadora->filmes[j]));
                        ImprimirNomeFilme(locadora->filmes[j]);
                        printf(" nao disponivel no estoque. Volte mais tarde.\n");
                        break;
                    }
                }
            }
        } else { // Caso nao exista o codigo do filme
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    if(qtdAlugados > 0) {
        printf("Total de filmes alugados: %d com custo de R$%d\n", qtdAlugados, valorTotal);
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora)
{
    int qtdCodigos = 0;
    scanf("%d", &qtdCodigos); 

    int *codigos = (int*)malloc(qtdCodigos * sizeof(int));
    for(int i = 0; i < qtdCodigos; i++)
    {
        scanf("%d", &codigos[i]); 
    }
    

    AlugarFilmesLocadora(locadora, codigos, qtdCodigos);

    free(codigos);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{
    for(int i = 0; i<quantidadeCodigos; i++)
    {
        if(VerificarFilmeCadastrado(locadora, codigos[i]))
        {
            for(int j = 0; j<locadora->numFilmes; j++)
            {
                if(EhMesmoCodigoFilme(locadora->filmes[j], codigos[i]))
                {
                    if(ObterQtdAlugadaFilme(locadora->filmes[j])>0)
                    {
                        DevolverFilme(locadora->filmes[j]);

                        printf("Filme %d - ", ObterCodigoFilme(locadora->filmes[j]));
                        ImprimirNomeFilme(locadora->filmes[j]);
                        printf(" Devolvido!\n");

                        locadora->lucro += ObterValorFilme(locadora->filmes[j]);
                        break;
                    } else 
                    {
                        printf("Nao e possivel devolver o filme %d - ", codigos[i]);
                        ImprimirNomeFilme(locadora->filmes[j]);
                        printf(". \n");
                        break;
                    }
                }
            }
        }else{
                printf("Filme %d nao cadastrado. \n", codigos[i]);
                break;
            }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora)
{
    int qtdCodigos = 0;
    scanf("%d", &qtdCodigos);

    int *codigos = (int*)malloc(qtdCodigos * sizeof(int));
    for(int i = 0; i < qtdCodigos; i++)
    {
        scanf("%d", &codigos[i]);
    }
    

    DevolverFilmesLocadora(locadora, codigos, qtdCodigos);

    free(codigos);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora)
{
    for(int i = 0; i<locadora->numFilmes-1; i++)
    {
        for(int j = i+1; j<locadora->numFilmes; j++)
        {
            if(CompararNomesFilmes(locadora->filmes[i], locadora->filmes[j]) > 0)
            {
                tFilme *temp = locadora->filmes[i];
                locadora->filmes[i] = locadora->filmes[j];
                locadora->filmes[j] = temp;
            }
        }
    }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora)
{

    printf("~ESTOQUE~\n");
    for(int i = 0; i<locadora->numFilmes; i++)
    {
        printf("%d - ", ObterCodigoFilme(locadora->filmes[i]));
        ImprimirNomeFilme(locadora->filmes[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filmes[i]));
    }
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora)
{
    if(locadora->lucro > 0)
    {
        printf("\nLucro total R$%d\n", locadora->lucro);
    }
}
