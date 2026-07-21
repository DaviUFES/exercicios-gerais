#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector
{
    DataType *data;
    int size;
    int capacity;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *v = (Vector*)malloc(sizeof(Vector));

    v->size = 0;
    v->capacity = 10;

    v->data = (DataType*)malloc(sizeof(DataType) * v->capacity);

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val)
{
    if(v->capacity == v->size)
    {
        v->capacity *= 2;
        DataType *novoArray = (DataType*)realloc(v->data, v->capacity*sizeof(DataType));

        v->data = novoArray;
    }

    v->data[v->size] = val;
    v->size++;
}

/**
 * @brief Remove o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
*/
void VectorRemove(Vector *v, int i)
{
    if(i<0||i>=v->size) return;

    for(int j = i; j < v->size - 1; j++)
    {
        v->data[j] = v->data[j + 1];
    }

    v->size--;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i)
{
    return v->data[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->size;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    if(v!=NULL)
    {
        if(destroy!=NULL)
        {
            for(int i = 0; i<v->size; i++)
                destroy(v->data[i]);
        }
        if(v->data!=NULL)
            free(v->data);
        free(v);
    }
}
