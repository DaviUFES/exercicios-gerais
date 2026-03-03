#ifndef _TSENSORTEMPERATURA
#define _TSENSORTEMPERATURA

/***
O sensor servira para controlar um ar condicionado (que inicialmente esta desligado)
baseado em uma temperatura ambiente.
*/
typedef struct _tSensorTemperatura tSensorTemperatura;

/// @brief Le as configuracoes de um sensor de presenca da entrada padrao e retorna um sensor valido
/// O sensor servira para controlar um ar que inicialmente esta desligado.
/// Configuracoes serao dadas em uma linha seguindo "#MIN #MAX"
/// #MIN sendo a temperatura limite minima para desligar o AR ao ficar abaixo dela
/// #MAX sendo a temperatura limite maxima para ligar o AR ao ficar acima dela
/// @param id - id do sensor
/// @return Um ponteiro para o sensor de presença lido. Ver especificação do EA para mais detalhes
tSensorTemperatura *leSensorTemperatura(int id);

/// @brief Dado um sensor de temperatura valido, libera sua memoria
/// @param s - ponteiro para o sensor a ser liberado
void liberaSensorTemperatura(void *s);




/// @brief Dado um sensor de temperatura valido, faz a leitura da temperatura ambiente do sensor fisico e
/// controla o estado do ar condicionado (ver comentários abaixo e/ou especificação)
/// @param s - ponteiro genérico para o sensor.
void processaSensorTemperatura(void *s);


/***
A leitura do sensor de temperatura sera simulada aqui por uma leitura de um inteiro da entrada padrao
O controle do estado do ar condicionado sera simulado aqui com uma impressao em uma linha da saida padrao sendo
    "SENSOR(#ID)[#MIN-#MAX] processando TEMP:#T\n" em que #ID eh o id do sensor,
    #MIN e #MAX sao conforme definidos acima e #T eh a temperatura lida do sensor fisico, seguida de
    "(DESLIGANDO AR)" para representar que o ar deve desligar ao ficar abaixo da temperatura minima e estava ligado
    "(LIGANDO AR)" para representar que o ar deve ligar ao ficar acima da temperatura maxima e estiver desligado
    "(MANTEM AR)" caso contrario
*/


#endif
