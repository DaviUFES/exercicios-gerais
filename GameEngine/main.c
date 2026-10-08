#include "game_engine.h"
#include <stdio.h>
#include <stdlib.h>
#define MAPA_TAM_VERT 10
#define MAPA_TAM_HORI 100
#define TECLA_DE_PULO ' '


void InicializaMapa(int linhas, int colunas, char mapa[linhas][colunas]){
	for(int i = 0; i < MAPA_TAM_VERT; i++){
		for(int j = 0; j < MAPA_TAM_HORI; j++){
			mapa[i][j] = ' ';
		}
	}
}

void ImprimeMapa(int linhas, int colunas, char mapa[linhas][colunas]){
	for(int i = MAPA_TAM_VERT-1; i >= 0; i--){
		for(int j = 0; j < MAPA_TAM_HORI; j++){
			printf("%c", mapa[i][j]); 
		}
		printf("\n");
	}
	printf("\n");	
}

void ProcessaElementos(tGameEngine * eng){
	int posJogador = MAPA_TAM_HORI/2;
	char mapa[MAPA_TAM_VERT][MAPA_TAM_HORI];
	InicializaMapa(MAPA_TAM_VERT, MAPA_TAM_HORI, mapa);
	
	char tecla = ObtemTeclaPressianadaGameEngine(eng);
	int pulando = ObtemEstadoGameEngine(eng, 0);
	int alturaPulo = ObtemEstadoGameEngine(eng, 1);
	int posObstaculo = ObtemEstadoGameEngine(eng, 2);
	printf("Pressione uma tecla (Pressione 'q' para sair):\n");
	printf("tecla:%c pulando:%d alturaPulo:%d posObstaculo:%d\n", tecla, pulando, alturaPulo, posObstaculo);

	//detecta colisao se a altura do jogador for zero e o obstaculo estiver na mesma posicao
	if ( alturaPulo == 0 &&  posObstaculo == posJogador ){
		printf("Game Over - You Lost!\n");
		return;
	}
	
	//Verifica se o jogador esta no chao e se a tecla de pulo foi pressionada
	if ( !pulando && tecla == TECLA_DE_PULO ){
		//Comeca a pular
		pulando = 1;
		//Guarda se esta pulando para o proximo frame
		AlteraEstadoGameEngine(eng, 0, pulando);
		//Limpa a tecla pressionada da engine
		ResetaTeclaPressianadaGameEngine(eng);
	}
    //Trata qunado ele esta pulando
	if (pulando){
		//incrementa ou decrementa alturaPulo dependendo do estado do pulo 1 (subindo) e 2 (descendo)
		alturaPulo += pulando;
		
		//Se chegou no topo, comeca a descer
		if ( alturaPulo >= MAPA_TAM_VERT-1 ) AlteraEstadoGameEngine(eng, 0, -1);
		
		//Se chegou no chao, desliga o pulo
		if ( alturaPulo == 0 ){
			//Para de pular, pois chegou no chao
			pulando = 0;
			//Guarda se esta pulando para o proximo frame
			AlteraEstadoGameEngine(eng, 0, pulando);
		}
			
		//Guarda da altura do pulo para o proximo frame
		AlteraEstadoGameEngine(eng, 1, alturaPulo);
	}
	
	//coloca jogador no mapa
	mapa[alturaPulo][posJogador] = 'X';

	//Anda com obstaculo ate o final e reinicia
	posObstaculo--;
	if (posObstaculo < 0) posObstaculo = MAPA_TAM_HORI-1;
	//Guarda estado do obstaculo para o proximo frame
	AlteraEstadoGameEngine(eng, 2, posObstaculo); 
	
	//coloca obstaculo no mapa
	mapa[0][posObstaculo] = 'I';
	
    //Imprime Instrucoes
    printf("Pressione espaco para pular\n");
    printf("Nao seja atingido pelo obstaculo\n");
    
	//Imprime mapa
	ImprimeMapa(MAPA_TAM_VERT, MAPA_TAM_HORI, mapa);
}

int init(tGameEngine * eng) {
	//Inicializa o estado pulando para 0
	AlteraEstadoGameEngine(eng, 0, 0);
	//Inicializa o altura do pulo para 0
	AlteraEstadoGameEngine(eng, 1, 0);
	//Inicializa a posicao do obstaculo para o final do mapa
	AlteraEstadoGameEngine(eng, 2, MAPA_TAM_HORI-1);
}

int main() {
	
	//Cria uma game engine com 3 estado e com 100000 ciclos sem processamento
	tGameEngine * gameEngine = CriaGameEngine(3, 100000);
	init(gameEngine);
	
	//Loop principal que realiza jogo e chama a dispara a callback
	RealizaJogoGameEngine(gameEngine, ProcessaElementos);
    
    FinalizaGameEngine(gameEngine);

    return 0;
}