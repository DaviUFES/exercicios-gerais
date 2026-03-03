#ifndef CONTATO_H_
#define CONTATO_H_

typedef struct Contato tContato;

/**
 * @brief Cria um novo contato.
 * 
 * @param nome Nome do contato.
 * @param tipo Tipo do contato.
 * @param telefone Telefone do contato.
 * @param fax Ponteiro para uma variável que armazena o fax do contato, ou NULL (se não for do tipo 'J')
 * @return tContato* Retorna um ponteiro para o contato criado. 
*/
tContato *CriarContato(char *nome, char tipo, unsigned long int telefone, unsigned long int *fax);

/**
 * @brief Libera a memória alocada para um contato.
 * 
 * @param contato Ponteiro para o contato a ser liberado.
*/
void DestruirContato(tContato *contato);

/**
 * @brief Imprime as informações de um contato.
 * Formato de impressão:
 * Nome: <nome>
 * Telefone: <telefone>
 * 
 * @param contato Ponteiro para o contato a ser impresso.
*/
void ImprimirContato(tContato *contato);

/**
 * @brief Salva as informações de um contato em um arquivo binario.
 * 
 * @param contato Ponteiro para o contato a ser salvo.
 * @param arquivo Ponteiro para o arquivo binario onde o contato será salvo.
*/
void SalvarContato(tContato *contato, FILE *arquivo);

/**
 * @brief Le as informações de um contato da entrada padrão, primeiro lendo o nome e depois o telefone.
 * 
 * @return tContato* Retorna um ponteiro para o contato lido.
*/
tContato *LeContato();

/**
 * @brief Carrega as informações de um contato de um arquivo binario, primeiro lendo o nome e depois o telefone.
 * 
 * @param arquivo Ponteiro para o arquivo binario de onde o contato será carregado.
 * @return tContato* Retorna um ponteiro para o contato carregado.
*/
tContato *CarregarContato(FILE *arquivo);

/**
 * @brief Compara dois contatos pelo número de telefone, caso eles sejam do mesmo tipo.
 * 
 * @param c1 Ponteiro para o primeiro contato a ser comparado.
 * @param c2 Ponteiro para o segundo contato a ser comparado.
 * @return int Retorna 1 se os números de telefone dos contatos são iguais (e do mesmo tipo) e 0 caso contrário.
*/
int ComparaTelefoneContato(tContato *c1, tContato *c2);

/**
 * @brief Compara dois contatos pelo nome, caso eles sejam do mesmo tipo.
 * 
 * @param c1 Ponteiro para o primeiro contato a ser comparado.
 * @param c2 Ponteiro para o segundo contato a ser comparado.
 * @return int Retorna 1 se os nomes dos contatos são iguais (e do mesmo tipo) e 0 caso contrário.
*/
int ComparaNomeContato(tContato *c1, tContato *c2);


/// @brief Compara se dois contatos são do mesmo tipo
/// @param c1 
/// @param c2 
/// @return 1 se são do mesmo tipo, 0 c.c.
int ComparaTipoContato(tContato *c1, tContato *c2);


/// @brief Checa se o nome de um contato é igual à string fornecida
/// @param c - Contato
/// @param nome - Nome a ser comparado
/// @return 1 se são iguais, 0 c.c.
int ChecaNomeContato(tContato *c, char *nome);

/// @brief Checa se o telefone de um contato é igual ao telefone fornecido.
/// @param c - Contato 
/// @param telefone a ser comparado
/// @return 1 se são iguais, 0 c.c.
int ChecaTelefoneContato(tContato *c, unsigned long int telefone);

/// @brief Checa se o tipo de um contato é igual ao tipo fornecido
/// @param c - Contato
/// @param tp - tipo a ser comparado
/// @return 1 se são iguais, 0 c.c.
int ChecaTipoContato(tContato *c, char tp);

#endif // CONTATO_H_
