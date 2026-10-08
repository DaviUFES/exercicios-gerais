#ifndef _GAME_ENGINE_H
#define _GAME_ENGINE_H

typedef struct GameEngine tGameEngine;
typedef void (*ProcessaElementosCallbackFunction)(tGameEngine * eng);

struct GameEngine{
	char tecla; //Tecla pressionada
	int * estados; //Variaveis de estado para comunicacao entre chamadas da callback
	int estadosTam;
	int ciclosSemProcessamento;
};

//Cria uma Game Engine
tGameEngine * CriaGameEngine(int numeroEstados, int ciclosSemProcessamento);

//Finaliza uma Game Engine
void FinalizaGameEngine(tGameEngine * eng);

//Retorna a ultima tecla pressionada no teclado
char ObtemTeclaPressianadaGameEngine(tGameEngine * eng);

//Reseta tecla pressionada no teclado
char ResetaTeclaPressianadaGameEngine(tGameEngine * eng);

//Altera uma variavel de estado de uma Game Engine
void AlteraEstadoGameEngine(tGameEngine * eng, int indiceEstadoAlterado, int valor);

//Ontem uma variavel de estado de uma Game Engine
int ObtemEstadoGameEngine(tGameEngine * eng, int indiceEstadoAlterado);

//Função que faz o loop principal
void RealizaJogoGameEngine(tGameEngine * eng, ProcessaElementosCallbackFunction processaElementosCallbackFunction);

#endif
