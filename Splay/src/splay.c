#include "splay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PtNodo* Novo(char* palavra, PtNodo* esq, PtNodo* dir){ 
  PtNodo* x = (PtNodo*) malloc(sizeof(PtNodo));
  x->palavra = palavra;
  x->esq = esq; x->dir = dir;
  return x;
};

PtNodo* Insere(char* palavra, PtNodo* t){ 
  return Splay(t,palavra);
};

int Altura(PtNodo* t){
  if(t != NULL){
      int altura_esq = Altura(t->esq);
      int altura_dir = Altura(t->dir);
      return 1 + ((altura_dir > altura_esq)? altura_dir : altura_esq);
  }
  return 0;
}

int Fator(PtNodo* t){
  if(t != NULL){
    return Altura(t->esq) - Altura(t->dir);
  }
}

int ContaNodos(PtNodo* t){
  return (t != NULL)? 1 + ContaNodos(t->esq) + ContaNodos(t->dir) : 0;
}

PtNodo* Consulta(PtNodo* t, char* palavra){
  if (t == NULL) return NULL;
  t = ConsultaSplay(t, palavra);
  return t;
};

PtNodo* Remove(PtNodo* t, char* palavra){
       PtNodo* x;
       if (t==NULL) return NULL;
       t = Consulta(t,palavra);
       if (strcmp(palavra, t->palavra) == 0) {               /* achou */
          if (t->esq == NULL) {
	           x = t->dir;
          } else {
	        x = Consulta(t->esq, palavra);
	        x->dir = t->dir;
	        }
	        free(t);
	        return x;
       }
       return t;                         /* It wasn't there */
};

void Destroi(PtNodo* t){
 if(t->esq != NULL) Destroi(t->esq);
 if(t->dir != NULL) Destroi(t->dir);
 free(t);
};

PtNodo* Splay(PtNodo* t, char* palavra){ 
  if (t == NULL) return Novo(palavra, NULL, NULL);  
  if (strcmp(palavra, t->palavra) < 0){ 
    if (t->esq == NULL) return Novo(palavra, NULL, t);
    if (strcmp(palavra, t->esq->palavra) < 0) 
    { 
      t->esq->esq = Splay(t->esq->esq, palavra);
      t = RotDir(t);
    }
    else 
    { 
    t->esq->dir = Splay(t->esq->dir, palavra);
    t->esq = RotEsq(t->esq);
    }
    return RotDir(t); 
  }
  else
  { 
    if (t->dir == NULL) return Novo(palavra, t, NULL);
    if (strcmp(t->dir->palavra, palavra) < 0) 
    { 
      t->dir->dir = Splay(t->dir->dir, palavra);
      t = RotEsq(t);
    }
    else 
    { 
    t->dir->esq = Splay(t->dir->esq, palavra);
    t->dir = RotDir(t->dir);
    }
    return RotEsq(t);
  }
};

PtNodo* ConsultaSplay(PtNodo* t, char* palavra){
 if (t == NULL) return NULL;
 if (strcmp(palavra, t->palavra) < 0) {
    if (t->esq == NULL) return t;
	  if (strcmp(palavra, t->esq->palavra) < 0) {
       t->esq->esq = ConsultaSplay(t->esq->esq, palavra);
	     t = RotDir(t);
	     if (t->esq == NULL) return t;
	     else return RotDir(t);
    } else if (t->esq->palavra , palavra) {
              t->esq->dir = ConsultaSplay(t->esq->dir, palavra);
	            if (t->esq->dir != NULL) t->esq = RotEsq(t->esq);
	            return RotDir(t);
           } else return RotDir(t);
 } else if(strcmp(palavra, t->palavra) > 0) {
	         if (t->dir == NULL) return t;
	         if (strcmp(t->dir->palavra, palavra) < 0) {
	            t->dir->dir = ConsultaSplay(t->dir->dir, palavra);
	            t = RotEsq(t);
	            if (t->dir == NULL) return t;
	            else return RotEsq(t);
           } else if (strcmp(palavra, t->dir->palavra) < 0) {
	                   t->dir->esq = ConsultaSplay(t->dir->esq, palavra);
                     if (t->dir->esq != NULL) t->dir = RotDir(t->dir);
	                   return RotEsq(t);
                     } else return RotEsq(t);
        } else{
            return t;
            }
};

PtNodo* RotDir(PtNodo* t){ 
  PtNodo* x = t->esq;
  t->esq = x->dir;
  x->dir = t;
  return x; 
};

PtNodo* RotEsq(PtNodo* t){ 
  PtNodo* x = t->dir;
  t->dir = x->esq;
  x->esq = t;
  return x;
};

void Desenha(PtNodo* t, int nivel){
int x;
 if (t !=NULL)
 {
   for (x=1; x<=nivel; x++)
      printf("=");
   printf("%d \n", t->key);
   if (t->esq != NULL) Desenha(t->esq, (nivel+1));
   if (t->dir != NULL) Desenha(t->dir, (nivel+1));
 }
 else printf("Arvore Vazia");
};