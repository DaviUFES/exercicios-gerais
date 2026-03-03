#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"


/* typedef enum {
    INT = 1,
    CHAR = 2
} Type; */

struct pacote{
    void *data;
    int nElementos;
    int somaPacotes;
    Type tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem)
{
    tPacote *p = (tPacote*)malloc(sizeof(tPacote));

    if(p==NULL)
        return NULL;

    p->nElementos = numElem;
    p->somaPacotes = 0;
    p->tipo = type;

    switch(type){
        case CHAR:
            p->data = (char *)malloc(sizeof(char)*(numElem));
            break;
        case INT:
            p->data = (int *)malloc(sizeof(int)*(numElem));
            break;
    }
    
    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac)
{
    if(pac){
        if(pac->data){
            free(pac->data);
        }
        free(pac);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac)
{
    printf("\nDigite o conteudo do vetor/mensagem");

    for(int i = 0; i<pac->nElementos; i++){
        switch(pac->tipo){
            case CHAR:
                scanf("%c", &((char*)pac->data)[i]);
                if(((char*)pac->data)[i] == '\n'){
                    ((char*)pac->data)[i] = '\0';
                }
                break;
            case INT:
                scanf("%d", &((int *)pac->data)[i]);
                break;
        }
    }

    scanf("%*[\n]");
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac)
{
    int i;

    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->somaPacotes);

    for(i = 0; i < pac->nElementos; i++) {
        if(pac->tipo == INT) {
            printf("%d", ((int *)pac->data)[i]);
            i == (pac->nElementos-1) ? printf("") : printf(" "); 
        } else if(pac->tipo == CHAR) {
            printf("%c", ((char *)pac->data)[i]);
        }
    }
    printf("\n");

}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac)
{
    for(int i=0; i<pac->nElementos; i++){
        if(pac->tipo == INT)
            pac->somaPacotes += ((int*)pac->data)[i];
        else if(pac->tipo == CHAR)
            pac->somaPacotes += (int)((char*)pac->data)[i];
    }
}
