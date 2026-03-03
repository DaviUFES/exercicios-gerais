#ifndef _cidade
#define _cidade

#include "defesa.h"
#include "missil.h"

/**
 * @brief Estrutura que representa uma cidade.
 * 
 * A estrutura tCidade contém as coordenadas da cidade, a quantidade de mísseis cadastrados no sistema, 
 * quantidade de defesas, e as listas de mísseis e defesas.
 * 
 */
typedef struct cidade tCidade;

/**
 * @brief Cria uma nova cidade.
 * 
 * @return tCidade Ponteiro para a cidade criada.
 */
tCidade* criaLeCidade();

/**
 * @brief Adiciona uma defesa à lista de defesas cidade possui.
 * 
 * @param c Ponteiro para a cidade que armazenará o míssil
 * @param d Ponteiro para a defesa a ser armazenado
 */
void adicionaDefesa(tCidade* c, tDefesa* d);

/**
 * @brief Adiciona um míssil à lista de mísseis de ataque cadastrados no sistema da cidade
 * 
 * @param c Ponteiro para a cidade que armazenará o míssil
 * @param m Ponteiro para o míssil a ser armazenado
 */
void adicionaMissilAtaque(tCidade* c, tMissilAtaque* m);

/**
 * @brief Processa o ataque do míssil da posição i. Ou seja, percorre o vetor de defesas, 
 * verificando quais irão atuar no míssil. Para cada defesa que atuar no míssil, o processamento
 * descrito no pdf deve ser feito (o poder do míssil deve ser alterado e o número de mísseis 
 * armazenados na defesa deve ser subtraido)
 * 
 * @param c Ponteiro para a cidade que armazenará o míssil
 * @param i Índice do míssil que terá ataque processado.
 */
void processaAtaqueDeUmMissil(tCidade *c, unsigned int i);

/**
 * @brief Libera a memória alocada para a cidade.
 * 
 * @param cidade Ponteiro para a cidade que terá a memória liberada.
 */
void liberaCidade(tCidade* cidade);

/**
 * @brief Retorna a quantidade de mísseis cadastrados no sistema da cidade
 * 
 * @param cidade Ponteiro para a cidade;
 */
int getQuantidadeMisseisCadastrados(tCidade *cidade);

/**
 * @brief Retorna a quantidade de defesas cadastrados no sistema da cidade
 * 
 * @param cidade Ponteiro para a cidade;
 */
int getQuantidadeDefesasCadastrados(tCidade *cidade);

/**
 * @brief Imprime informações do i-ésimo míssil cadastrado no sistema da cidade
 *        (olhar cidade.h)
 * 
 * @param cidade Ponteiro para a cidade;
 * @param i índice do vetor de defesas cadastradas 
 */
void imprimeInformacaoDefesa(tCidade *cidade, unsigned int i);

/**
 * @brief Imprime informações do i-ésimo míssil cadastrado no sistema da cidade
 *        (olhar missil.h)
 * 
 * @param cidade Ponteiro para a cidade;
 * @param i índice do vetor de mísseis cadastradas
 */
void imprimeInformacaoMissil(tCidade *cidade, unsigned int i);

/**
 * @brief Libera a memória alocada para a cidade.
 * 
 * @param cidade Ponteiro para a cidade;
 */
float calculaEfetividadeAtaque(tCidade *c);

#endif