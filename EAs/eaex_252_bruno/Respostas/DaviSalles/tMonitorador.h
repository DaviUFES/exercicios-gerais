#ifndef _TMONITORADOR
#define _TMONITORADOR

/* Typedefs dos callbacks */
typedef void (*FptrProcessaElemento)(void * e);
typedef void (*FptrLiberaElemento)(void * e);

/***
O monitorador eh um TAD generico uniforme que tem o objetivo de 
varrer os sensores registrados processando cada um deles continuamente.
*/
typedef struct _tMonitorador tMonitorador;

/// @brief Cria um monitorador valido definindo, de acordo com o tipo de elemento,
/// @param funcPE Callback para a função de Processar Elemento
/// @param funcLE Callback para a função de Liberar Elemento
/// @return O monitorador do tipo definido via callbacks
tMonitorador * criaMonitorador(FptrProcessaElemento funcPE, FptrLiberaElemento funcLE);

/// @brief Função que libera toda a memória de um monitorador
/// @param m - um monitorador valido
void liberaMonitorador(tMonitorador* m);

/// @brief Função que "cadastra" um sensor no monitorador.
/// @param m - Um monitorador Válido
/// @param e - Um ponteiro genérico para o monitorador, que DEVE SER do tipo especificado pelas funções PE e LE
void adicionaElementoMonitorador(tMonitorador * m, void * e);

/// @brief Função que inicia o processo de monitoramento dos sensores cadastrados em um monitorador
/// @param m - Um monitorador válido
/// @param numeroDeCiclos - Número de ciclos de leitura de cada sensor.
void iniciaMonitoramentotMonitorador(tMonitorador* m, int numeroDeCiclos);

#endif
