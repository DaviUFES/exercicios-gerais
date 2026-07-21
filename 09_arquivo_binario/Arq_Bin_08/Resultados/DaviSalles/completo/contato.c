#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h" 

struct Contato
{
    char nome[100];
    unsigned long int telefone;
};

tContato *CriarContato(char *nome, unsigned long int telefone)
{
    tContato *c = (tContato*)malloc(sizeof(tContato));

    if(c!=NULL)
    {
        memset(c->nome, 0, 100);
        strcpy(c->nome, nome);
        c->telefone = telefone;
    }

    return c;
}

/**
 * @brief Libera a memória alocada para um contato.
 * 
 * @param contato Ponteiro para o contato a ser liberado.
*/
void DestruirContato(tContato *contato)
{
    if(contato != NULL)
        free(contato);
}

/**
 * @brief Imprime as informações de um contato.
 * Formato de impressão:
 * Nome: <nome>
 * Telefone: <telefone>
 * 
 * @param contato Ponteiro para o contato a ser impresso.
*/
void ImprimirContato(tContato *contato)
{
    printf("Nome: %s\n", contato->nome);
    printf("Telefone: %lu\n", contato->telefone);
    printf("\n");
}

/**
 * @brief Salva as informações de um contato em um arquivo binario.
 * 
 * @param contato Ponteiro para o contato a ser salvo.
 * @param arquivo Ponteiro para o arquivo binario onde o contato será salvo.
*/
void SalvarContato(tContato *contato, FILE *arquivo)
{

    fwrite(contato->nome, sizeof(char), 100, arquivo);

    fwrite(&(contato->telefone), sizeof(unsigned long int), 1, arquivo);

}

/**
 * @brief Le as informações de um contato da entrada padrão, primeiro lendo o nome e depois o telefone.
 * 
 * @return tContato* Retorna um ponteiro para o contato lido.
*/
tContato *LeContato()
{
    unsigned long int tel;
    char nome[100];
    tContato *c;

    scanf(" %[^\n]", nome);
    scanf("%lu", &tel);

    c = CriarContato(nome, tel);

    return c;
}

/**
 * @brief Carrega as informações de um contato de um arquivo binario, primeiro lendo o nome e depois o telefone.
 * 
 * @param arquivo Ponteiro para o arquivo binario de onde o contato será carregado.
 * @return tContato* Retorna um ponteiro para o contato carregado.
*/
tContato *CarregarContato(FILE *arquivo)
{
    char nome[100];
    tContato *c;
    unsigned long int tel;

    memset(nome, 0, 100);

    fread(nome, sizeof(char), 100, arquivo);

    fread(&tel, sizeof(unsigned long int), 1, arquivo);

    c = CriarContato(nome, tel);

    return c;

}

/**
 * @brief Compara dois contatos pelo número de telefone.
 * 
 * @param c1 Ponteiro para o primeiro contato a ser comparado.
 * @param c2 Ponteiro para o segundo contato a ser comparado.
 * @return int Retorna 1 se os números de telefone dos contatos são iguais e 0 caso contrário.
*/
int ComparaTelefoneContato(tContato *c1, tContato *c2)
{
    if(c1->telefone == c2->telefone)
        return 1;
    return 0;
}

/**
 * @brief Compara dois contatos pelo nome.
 * 
 * @param c1 Ponteiro para o primeiro contato a ser comparado.
 * @param c2 Ponteiro para o segundo contato a ser comparado.
 * @return int Retorna 1 se os nomes dos contatos são iguais e 0 caso contrário.
*/
int ComparaNomeContato(tContato *c1, tContato *c2)
{
    if (strcmp(c1->nome, c2->nome) == 0)
        return 1;
    return 0;
}

/**
 * @brief Retorna o número de telefone de um contato.
 * 
 * @param contato Ponteiro para o contato.
 * @return unsigned long int Retorna o número de telefone do contato.
*/
unsigned long int GetTelefoneContato(tContato *contato)
{
    return contato->telefone;
}

/**
 * @brief Retorna o nome de um contato.
 * 
 * @param contato Ponteiro para o contato.
 * @return char* Retorna o nome do contato.
*/
char *GetNomeContato(tContato *contato)
{
    return contato->nome;
}

