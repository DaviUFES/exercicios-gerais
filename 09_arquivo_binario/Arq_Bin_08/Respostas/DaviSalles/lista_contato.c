#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_contato.h"

struct ListaContato
{
    tContato **contatos;
    int qtdContatos;
};

/**
 * @brief Cria uma lista de contatos.
 * 
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
*/
tListaContato *CriarListaContato()
{
    tListaContato *lc = (tListaContato*)malloc(sizeof(tListaContato));

        lc->contatos = NULL;
        lc->qtdContatos = 0;

    return lc;
}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 * 
 * @param l Ponteiro para a lista de contatos a ser liberada.
*/
void DestruirListaContato(tListaContato *l)
{
    if(l!=NULL)
    {
        for(int i =0; i<l->qtdContatos; i++)
        {
            DestruirContato(l->contatos[i]);
        }
        free(l->contatos);
        free(l);
    }
}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista 
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
*/
void AdicionarContatoListaContato(tListaContato *l, tContato *contato)
{
    for(int i = 0; i<l->qtdContatos; i++)
    {
        if(ComparaNomeContato(contato, l->contatos[i]) == 1 || ComparaTelefoneContato(contato, l->contatos[i]))
        {
            printf("Ja existe um contato com esse nome e/ou numero de telefone\n");
            DestruirContato(contato);
            return;
        }
    }

    int novaQtd = l->qtdContatos+1;

    l->contatos = realloc(l->contatos, novaQtd*sizeof(tContato*));

    l->contatos[l->qtdContatos] = contato;
    l->qtdContatos++;
}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 * 
 * Formato do arquivo binário (caso exista):
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
*/
void CarregarListaContato(tListaContato *l, char* nomeArquivo)
{
    FILE *fp;
    fp = fopen(nomeArquivo, "rb");

    if (fp == NULL) {
        return; 
    }

    int qtdContatos = 0;

    fread(&qtdContatos,sizeof(int),1,fp);

    for(int i = 0; i<qtdContatos; i++)
    {
        tContato *c = CarregarContato(fp);

        AdicionarContatoListaContato(l,c);
    }
    fclose(fp);

}

/**
 * @brief Salva uma lista de contatos em um arquivo binário.
 * 
 * Formato do arquivo binário:
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário onde a lista de contatos será salva.
*/
void SalvarListaContato(tListaContato *l, char* nomeArquivo)
{
    FILE *fp;
    fp = fopen(nomeArquivo,"wb");

    fwrite(&l->qtdContatos,sizeof(int),1,fp);

    for(int i = 0; i<l->qtdContatos; i++)
    {
        SalvarContato(l->contatos[i], fp);
    }
    fclose(fp);
}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNumeroTelefoneListaContato(tListaContato *l)
{
    unsigned long int tel, telLista;
    scanf("%lu", &tel);
    
    for(int i = 0; i<l->qtdContatos; i++)
    {
        telLista = GetTelefoneContato(l->contatos[i]);
        if(tel == telLista)
        {
            ImprimirContato(l->contatos[i]);
            return;
        }
    }
    printf("Contato nao encontrado\n");
}

/**
 * @brief Busca um contato na lista de contatos pelo nome e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNomeListaContato(tListaContato *l)
{
    char nome[100], *nomeLista;
    scanf(" %[^\n]", nome);
    
    for(int i = 0; i<l->qtdContatos; i++)
    {
        nomeLista = GetNomeContato(l->contatos[i]);
        if(strcmp(nome, nomeLista)==0)
        {
            ImprimirContato(l->contatos[i]);
            return;
        }
    }
    printf("Contato nao encontrado\n");
}


/**
 * @brief Imprime a lista de contatos na tela.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void ImprimirListaContato(tListaContato *l)
{
    printf("\n");
    printf("Lista de contatos cadastrados\n");
    for(int i = 0; i<l->qtdContatos; i++)
    {
        ImprimirContato(l->contatos[i]);
    }
}

/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void RemoverContatoListaContato(tListaContato *l)
{
    unsigned long int tel, telLista;
    scanf("%lu", &tel);

    for(int i = 0; i<l->qtdContatos; i++)
    {
        telLista = GetTelefoneContato(l->contatos[i]);
        if(tel == telLista)
        {
            DestruirContato(l->contatos[i]);

            for(int j = i; j<l->qtdContatos-1; j++)
            {
                l->contatos[j] = l->contatos[j+1];
            }

            l->qtdContatos--;
            printf("\n");
            printf("Contato removido com sucesso\n");
            return;
        }
    }
    printf("Nao existe um contato cadastrado com esse numero de telefone\n");
}
