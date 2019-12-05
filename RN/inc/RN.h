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
RNtree *Insere(RNtree *t, char *key);
RNtree *Consulta(char *key, RNtree *t);
RNtree *Remove(RNtree *t, char *key);
void Destroi(RNtree *t);
int contaNodos(RNtree *t);
int altura(RNtree *t);
int fator(RNtree *t);
long numRotacoes(void);
long numComparacoes(void);
void fillCountVec(char **freqs, int k1, int k2, RNtree *t);

#endif  // __RN_H__