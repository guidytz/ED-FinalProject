#ifndef __RN_H__
#define __RN_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct RNnodo RNtree;

struct RNnodo {
    char *key;
    int red; /* se red=0 entao o nodo e preto */
    int freq;
    struct RNnodo *esq;
    struct RNnodo *dir;
    struct RNnodo *pai;
};

// no NULL global que facilita a execucao dos algoritmos da RN
extern RNtree *NodoNULL;

// Definicoes das Funcoes

/**
 * @brief Insere um nó na árvore
 * 
 * @param t árvore R-N
 * @param key chave do nó a ser inserido
 * @return RNtree* árvore com o novo nó inserido
 */
RNtree *Insere(RNtree *t, char *key);

/**
 * @brief Consulta um nó na árvore
 * 
 * @param key chave a ser consultada
 * @param t árvore a ser consultada 
 * @return RNtree* estrutura com o nó encontrado (caso não encontrado retorna NULL)
 */
RNtree *Consulta(char *key, RNtree *t);

/**
 * @brief Remove um nó da árvore
 * 
 * @param t árvore que será removido o nó
 * @param key chave do nó a ser removido
 * @return RNtree* árvore sem o nó passado (caso não tenha, retorna  mesma)
 */
RNtree *Remove(RNtree *t, char *key);

/**
 * @brief Desaloca toda estrutura de uma árvore alocada
 * 
 * @param t árvora a ser desalocada
 */
void Destroi(RNtree *t);

/**
 * @brief Conta a quantidade de nós presentes em uma árvore
 * 
 * @param t árvore que deseja contar os nós
 * @return int número de nós encontrados
 */
int contaNodos(RNtree *t);

/**
 * @brief Retorna a altura máxima de uma árvore
 * 
 * @param t árvore que se deseja saber a altura
 * @return int altura máxima da árvore inserida
 */
int altura(RNtree *t);

/**
 * @brief Retorna o fator máximo da árvore
 * 
 * @param t árvora que se deseja saber o fator
 * @return int fator máximo da árvore inserida
 */
int fator(RNtree *t);

/**
 * @brief Retorna o número de rotações operadas até o momento
 * 
 * @return long número de rotações operadas
 */
long numRotacoes(void);

/**
 * @brief Retorna o número de comparações operadas até o momento
 * 
 * @return long número de operações operadas
 */
long numComparacoes(void);

/**
 * @brief Dado um vetor de frequência strings, preenche ele com as strings nas posições 
 *        de acordo com a sua frequência
 * 
 * @param freqs vetor de frequências de strings
 * @param k1 limite inferior de frequências
 * @param k2 limite superior de frequências
 * @param t árvore da qual se deseja obter as strings
 */
void fillCountVec(char **freqs, int k1, int k2, RNtree *t);

#endif  // __RN_H__