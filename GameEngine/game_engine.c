#include "game_engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

tGameEngine * CriaGameEngine(int numeroEstados, int ciclosSemProcessamento){
	tGameEngine * gameEngine = (tGameEngine *)malloc(sizeof(tGameEngine));
	
	gameEngine->tecla = 0;
	gameEngine->estadosTam = numeroEstados;
	gameEngine->ciclosSemProcessamento = ciclosSemProcessamento;
	gameEngine->estados = (int*)malloc(numeroEstados * sizeof(int));
    for(int i = 0; i < gameEngine->estadosTam; i++){
		gameEngine->estados[i] = 0;
        
	}
	
	return gameEngine;
}

void FinalizaGameEngine(tGameEngine * eng){
    free(eng->estados);
    free(eng);
}

char ObtemTeclaPressianadaGameEngine(tGameEngine * eng){
	return eng->tecla;
}

char ResetaTeclaPressianadaGameEngine(tGameEngine * eng){
	eng->tecla = 0;
}

void AlteraEstadoGameEngine(tGameEngine * eng, int indiceEstadoAlterado, int valor){
	if (indiceEstadoAlterado < 0 || indiceEstadoAlterado >= eng->estadosTam){
		printf("Indice indiceEstadoAlterado (%d) invalido!\n", indiceEstadoAlterado);
		exit(1);
	}
	eng->estados[indiceEstadoAlterado] = valor;
}

int ObtemEstadoGameEngine(tGameEngine * eng, int indiceEstadoAlterado){
	if (indiceEstadoAlterado < 0 || indiceEstadoAlterado >= eng->estadosTam){
		printf("Indice indiceEstadoAlterado (%d) invalido!\n", indiceEstadoAlterado);
		exit(1);
	}
	return eng->estados[indiceEstadoAlterado];	
}

void RealizaJogoGameEngine(tGameEngine * eng, ProcessaElementosCallbackFunction processaElementosCallbackFunction){
    char tecla;
	int entrou = 0;
    int fd = 0; // Descritor de arquivo padrão (entrada padrão)
    struct termios old_tio, new_tio;

    // Salvar as configurações atuais do terminal
    tcgetattr(fd, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(fd, TCSANOW, &new_tio);

    // Configurar entrada não bloqueante
    fcntl(fd, F_SETFL, O_NONBLOCK);
	
	//Loop principal que chama a callback para processar o jogo
    while (1) {
		
		//Pula alguns ciclos para nao chamar printf toda hora
		if (!entrou--){
			// Limpa o terminal
			printf("\033[H\033[J");
			
			//Chama a callback de processamento dos elementos de jogo
			processaElementosCallbackFunction(eng);
		}
		if (entrou < 0) entrou = eng->ciclosSemProcessamento;	

		//Le o teclado pra ver se tem tecla pressionada
		if (read(fd, &tecla, 1) > 0) {
			//Caso tenha, armazene na gameengine
			eng->tecla = tecla;
			
			//Finaliza o loop principal se a tecla pressionada for q
			if (tecla == 'q')
				break;
		}
    }

    // Restaurar as configurações originais do terminal
    tcsetattr(fd, TCSANOW, &old_tio);
}