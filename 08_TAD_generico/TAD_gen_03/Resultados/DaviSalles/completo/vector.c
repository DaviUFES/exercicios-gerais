#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector
{
    data_type *dados;
    int capacidade_maxima;
    int tamanho_atual;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *v = (Vector*)malloc(sizeof(Vector));
    if(v==NULL)
        exit(1);

    v->capacidade_maxima = 2;
    v->tamanho_atual = 0;

    v->dados = (data_type*)malloc(sizeof(data_type)*v->capacidade_maxima);
    if(v==NULL)
    {
        free(v);
        exit(1);
    }

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val)
{
    if(v->tamanho_atual == v->capacidade_maxima)
    {
        v->capacidade_maxima *= 2;

        data_type *novo_array = (data_type*)realloc(v->dados, v->capacidade_maxima*sizeof(data_type));
        if(novo_array==NULL)
        {
            exit(1);
        }

        v->dados = novo_array;
    }

    v->dados[v->tamanho_atual] = val;
    v->tamanho_atual++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i)
{
    return v->dados[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->tamanho_atual;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    if(v!=NULL)
    {
        if(destroy!=NULL)
        {
            for(int i = 0; i<v->tamanho_atual;i++)
            {
                destroy(v->dados[i]);
            }
        }
        if(v->dados!=NULL)
            free(v->dados);
        free(v);
    }
}
