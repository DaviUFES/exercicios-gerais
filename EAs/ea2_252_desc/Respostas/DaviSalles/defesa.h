#ifndef _defesa
#define _defesa

#define QUADRADO 'Q' /**< Caractere que indica uma defesa do tipo quadrado. */
#define CIRCULO 'C' /**< Caractere que indica uma defesa do tipo círculo. */
#define MAX_TAM 100 /**< Tamanho máximo do nome da defesa. */

/**
 * @brief Estrutura que representa uma defesa.
 * 
 * A estrutura tDefesa contém o tipo da defesa, as coordenadas do centro, o tamanho
 * a quantidade de mísseis disponíveis e o poder de cada míssil de defesa.
 * 
 */
typedef struct defesa tDefesa;

/**
 * @brief Lê a entrada do usuário, cria e retorna uma nova defesa.
 * 
 * @return tDefesa Ponteiro para a defesa criada.
 */
tDefesa* criaLeDefesa();

/**
 * @brief Imprime as informações da defesa.
 * Exemplo: D-2: 6 
 * Nome e quantidade final de mísseis de defesa
 * 
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void imprimeDefesa(tDefesa *defesa);

/**
 * @brief Libera a memória alocada para a defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void liberaDefesa(tDefesa *defesa);

/**
 * @brief Verifica se um ponto está dentro da área de defesa. 
 * Lembre: o comportamento muda de acordo com o tipo da defesa
 * Olhe a seção de "fórmulas e informações úteis" do pdf.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */
int verificaSeDentroArea(tDefesa *defesa, float x, float y);

/**
 * @brief Usa um míssil da defesa 
 * (diminui a quantidade de mísseis restantes, se houver algum disponível).
 * 
 * @param defesa Ponteiro para a defesa que será usada.
 */
void usaDefesa(tDefesa *defesa);

/**
 * @brief Obtém o poder de defesa dos mísseis de uma defesa.
 * 
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float getPoderDefesa(tDefesa *defesa);

/**
 * @brief Verifica se a defesa pode defender. Ou seja, se há mísseis disponíveis.
 * 
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int podeDefender(tDefesa *defesa);

#endif