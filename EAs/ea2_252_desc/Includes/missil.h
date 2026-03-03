#ifndef _missil
#define _missil

#define MAX_TAM 100 /**< Tamanho máximo do nome do míssil. */

/**
 * @brief Estrutura que representa um míssil.
 * 
 * A estrutura tMissil contém o nome do míssil, as coordenadas x e y, e o poder de ataque.
 * 
 */
typedef struct missil_ataque tMissilAtaque;

/**
 * @brief Lê a entrada do usuário, cria e retorna um novo míssil.
 * 
 * @return tMissil Ponteiro para o míssil criado.
 */
tMissilAtaque* criaLeMissilAtaque();

/**
 * @brief Imprime as informações do míssil.
 * Exemplo: M-1: 0.00
 * Nome e Dano Causado pelo míssil de ataque na cidade
 * 
 * @param missil Ponteiro para o míssil que será impresso.
 */
void imprimeMissilAtaqueDentroCidade(tMissilAtaque* missil);

/**
 * @brief Imprime as informações do míssil.
 * Exemplo: M-1: 0.00
 * Nome. Como o míssil foi fora da cidade, o dano dele é zero.
 * 
 * @param missil Ponteiro para o míssil que será impresso.
 */
void imprimeMissilAtaqueForaCidade(tMissilAtaque* missil);

/**
 * @brief Libera a memória alocada para o míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a memória liberada.
 */
void liberaMissilAtaque(tMissilAtaque* missil);

/**
 * @brief Obtém a coordenada y do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada y obtida.
 * @return float Coordenada y do míssil.
 */
float getYMissilAtaque(tMissilAtaque* missil);

/**
 * @brief Obtém a coordenada x do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada x obtida.
 * @return float Coordenada x do míssil.
 */
float getXMissilAtaque(tMissilAtaque* missil);

/**
 * @brief Obtém o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque obtido.
 * @return float Poder de ataque do míssil.
 */
float getPoderMissilAtaque(tMissilAtaque* missil);

/**
 * @brief Reduz o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque reduzido.
 * @param valor Valor a ser subtraído do poder de ataque do míssil.
 */
void reduzPoderMissilAtaque(tMissilAtaque* missil, float valor);

#endif