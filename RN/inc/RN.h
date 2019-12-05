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
 * @brief Insere um no na arvore
 * 
 * @param t arvore R-N
 * @param key chave do no a ser inserido
 * @return RNtree* arvore com o novo no inserido
 */
RNtree *Insere(RNtree *t, char *key);

/**
 * @brief Consulta um no na arvore
 * 
 * @param key chave a ser consultada
 * @param t arvore a ser consultada 
 * @return RNtree* estrutura com o no encontrado (caso nao encontrado retorna NULL)
 */
RNtree *Consulta(char *key, RNtree *t);

/**
 * @brief Remove um no da arvore
 * 
 * @param t arvore que será removido o no
 * @param key chave do no a ser removido
 * @return RNtree* arvore sem o no passado (caso nao tenha, retorna  mesma)
 */
RNtree *Remove(RNtree *t, char *key);

/**
 * @brief Desaloca toda estrutura de uma arvore alocada
 * 
 * @param t arvore a ser desalocada
 */
void Destroi(RNtree *t);

/**
 * @brief Conta a quantidade de nos presentes em uma arvore
 * 
 * @param t arvore que deseja contar os nos
 * @return int numero de nos encontrados
 */
int contaNodos(RNtree *t);

/**
 * @brief Retorna a altura maxima de uma arvore
 * 
 * @param t arvore que se deseja saber a altura
 * @return int altura maxima da arvore inserida
 */
int altura(RNtree *t);

/**
 * @brief Retorna o fator maximo da arvore
 * 
 * @param t arvore que se deseja saber o fator
 * @return int fator maximo da arvore inserida
 */
int fator(RNtree *t);

/**
 * @brief Retorna o numero de rotacoes operadas ate o momento
 * 
 * @return long numero de rotacoes operadas
 */
long numRotacoes(void);

/**
 * @brief Retorna o numero de comparacoes operadas ate o momento
 * 
 * @return long numero de comparacoes feitas
 */
long numComparacoes(void);

/**
 * @brief Dado um vetor de frequencia strings, preenche ele com as strings nas posições 
 *        de acordo com a sua frequencia
 * 
 * @param freqs vetor de frequencias de strings
 * @param k1 limite inferior de frequencias
 * @param k2 limite superior de frequencias
 * @param t arvore da qual se deseja obter as strings
 */
void fillCountVec(char **freqs, int k1, int k2, RNtree *t);

#endif  // __RN_H__