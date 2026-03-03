#ifndef _processamento_h_
#define _processamento_h_

#define ENCERRAR 'F' /**< Caractere que indica o fim da entrada. */
#define MISSIL 'M' /**< Caractere que indica um míssil. */
#define DEFESA 'D' /**< Caractere que indica uma defesa. */

#include "cidade.h"

/**
 * @brief Lê a entrada do usuário e preenche a cidade com as informações lidas.
 * 
 * @param cidade Ponteiro para a cidade que será preenchida.
 * @return tCidade Ponteiro para a cidade preenchida.
 */
void leEntrada(tCidade* cidade);

/**
 * @brief Processa os ataques na cidade.
 * 
 * @param cidade Ponteiro para a cidade que será atacada.
 */
void processaAtaques(tCidade* cidade);

/**
 * @brief Imprime os dados finais da cidade.
 * Conforme especificação:
 * O relatório final deve conter as seguintes informações:
    • Quantidade final de mísseis de defesa restantes de cada defesa aérea
    • Dano causado na cidade por cada um dos mísseis de ataque detectados pelo sistema de radar
    • Porcentagem de efetividade de defesa, conforme fórmula abaixo.
 * 
 * @param cidade Ponteiro para a cidade que terá os dados impressos.
 */
void imprimeDados(tCidade* cidade);

#endif
