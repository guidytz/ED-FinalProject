#ifndef __RN_H__
#define __RN_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct  RNnodo RNtree;

struct RNnodo {
  char *key;
  int red; /* se red=0 ent�o o nodo � preto */
  struct RNnodo* esq;
  struct RNnodo* dir;
  struct RNnodo* pai;
};

// Defini��es das Fun��es
RNtree* Insere(RNtree* t, char *key);
int Consulta(char *key, RNtree* t );
RNtree* Remove(RNtree* t, char *key);
void Destroi(RNtree* t);

#endif // __RN_H__