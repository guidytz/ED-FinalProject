#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RN.h"
#include "aux.h"

// declarar o nodo NULL
static RNtree* NodoNULL = NULL;

// Fun��es Auxiliares
RNtree* VerificaRN(RNtree* t, char *key);
RNtree* RotacaoSimplesEsq(RNtree **t, RNtree *n);
RNtree* RotacaoSimplesDir(RNtree **t, RNtree *n);
RNtree* Maior(RNtree* t);
RNtree* Menor(RNtree* t);

RNtree* Insere(RNtree* t, char *key)  {
    RNtree* x = t;
    if(t == NULL)  {
        // aloca��o de espa�o
        NodoNULL = (RNtree*) malloc(sizeof(RNtree));
        x = (RNtree*) malloc(sizeof(RNtree));
        //inicializa��es
        // NULL
        NodoNULL->red = 0; // null � preto;
        NodoNULL->esq = NodoNULL;
        NodoNULL->dir = NodoNULL;
        NodoNULL->key = "\0";
        NodoNULL->pai = NodoNULL;
        // Raiz
        x->key = key;
        x->esq = x->dir = NodoNULL;
        x->red = 0;
        x->pai = NodoNULL;
        return x;
    }
    
    RNtree* p= x->pai; // pai
    RNtree* v= p->pai; // vo
    

    while( x != NodoNULL ) {
        v = p; 
        p = x;
        int res = strcmp(key, x->key);
        if( res < 0 ) x = x->esq;
        else if (res == 0) break;
        else x = x->dir;
    }
    
    if(x != NodoNULL) {
        free(key);
        return t; // Nodo Ja Existe
    }
        
    x = (RNtree*) malloc(sizeof(RNtree));
    x->key = key;
    x->esq = x->dir = NodoNULL;
    x->pai = p;
    x->red = 1;
    
    if( strcmp(key, p->key) < 0 ) p->esq = x;
    else p->dir = x;

    return VerificaRN(t, key);
}

int Consulta(char *key, RNtree* t ) {
    RNtree *x = t;
    while( strcmp(x->key, key) && x != NodoNULL ) {
        if( strcmp(key, x->key) < 0 ) x = x->esq;
        else x = x->dir;
    }
    return (x != NodoNULL);
}


void Destroi(RNtree* t) {
    if (t == NodoNULL) return;
    Destroi(t->esq);
    Destroi(t->dir);
    free(t->key);
    free(t);
    if ( t->pai == NodoNULL ) free(NodoNULL);
}

RNtree* VerificaRN(RNtree* t, char *key) {
    RNtree* x = t;
    RNtree* p = x->pai;
    RNtree* v = p->pai;
    while( strcmp(x->key, key) != 0 ) {
        v = p; 
        p = x;
        if( strcmp(key, x->key) < 0 ) x = x->esq;
        else x = x->dir;
    }

    // caso 2
    if( p->red ) {
        if( v != NodoNULL) {
            if( strcmp(p->key, v->key) < 0 ) {
                if (v->dir->red) {           // tio � vermelho
                    v->dir->red = 0;         // tio vira preto
                    p->red      = 0;         // troca a cor do pai
                    if (v->pai != NodoNULL)  // av� não � raiz
                        v->red = 1;        
                } else  {
                    if((strcmp(x->key, p->key) < 0) && (strcmp(p->key, v->key) < 0)) {
                        // rotacao a direita
                        RotacaoSimplesDir(&t, v);
                        p->red = 0;  // troca a cor do pai
                        v->red = 1;  // troca cor do vo
                    } else {
                        if((strcmp(x->key, p->key) > 0) && (strcmp(p->key, v->key) > 0) ) {
                            RotacaoSimplesEsq(&t, v);
                            p->red = 0;  // troca a cor do pai
                            v->red = 1;  // troca cor do vo
                        } else {
                            if(strcmp(p->key, v->key) < 0) {
                                RotacaoSimplesEsq(&t, p);
                                RotacaoSimplesDir(&t, v);  // rotacao Dupla a direita
                                x->red = 0;            // troca a cor do novo
                                v->red = 1;
                            } else {
                                RotacaoSimplesDir(&t, p);
                                RotacaoSimplesEsq(&t, v);  // rotacao Dupla a esquerda
                                x->red = 0;            // troca a cor do novo
                                v->red = 1;
                            }   
                        }
                    }
                }
            } else {
                if(v->esq->red) {
                    v->esq->red = 0;         // tio vira preto
                    p->red      = 0;         // troca a cor do pai
                    if (v->pai != NodoNULL)  // av� não � raiz
                        v->red = 1;        
                } else {
                    if((strcmp(x->key, p->key) < 0) && (strcmp(p->key, v->key) < 0)) {
                        // rotacao a direita
                        RotacaoSimplesDir(&t, v);
                        p->red = 0;  // troca a cor do pai
                        v->red = 1;  // troca a cor do avo
                    } else {
                        if((strcmp(x->key, p->key) > 0) && (strcmp(p->key, v->key) > 0) ) {
                            RotacaoSimplesEsq(&t, v);                      // --- aqui
                            p->red = 0;                                // troca a cor do pai
                            v->red = 1;
                        } else {
                            if(strcmp(p->key, v->key) < 0) {
                                RotacaoSimplesEsq(&t, p);
                                RotacaoSimplesDir(&t, v);  // rotacao Dupla a direita
                                x->red = 0;            // troca a cor do novo
                                v->red = 1;
                            } else {
                                RotacaoSimplesDir(&t, p);
                                RotacaoSimplesEsq(&t, v);  // rotacao Dupla a esquerda
                                x->red = 0;            // troca a cor do novo
                                v->red = 1;
                            }   
                        }
                    }
                }
            }
        }
    } 
    t->red = 0;
    // x->red = 1;
    return t;
}
        
RNtree* RotacaoSimplesDir(RNtree **t, RNtree *n) {
    RNtree* aux;

    aux           = n->esq;
    n->esq        = aux->dir;
    aux->dir->pai = n;
    aux->pai      = n->pai;
    if (aux->pai == NodoNULL) *t = aux;
    if (n == n->pai->esq) n->pai->esq = aux;
    else n->pai->dir = aux;
    aux->dir      = n;
    n->pai        = aux;

    return aux; /* nova raiz */
};

RNtree* RotacaoSimplesEsq(RNtree **t, RNtree *n) {
    RNtree* aux;

    aux         = n->dir;
    n->dir      = aux->esq;
    n->dir->pai = n;
    aux->pai    = n->pai;
    if (n->pai == NodoNULL) *t = aux;
    if (n == n->pai->esq) n->pai->esq = aux;
    else n->pai->dir = aux;
    aux->esq    = n;
    n->pai      = aux;

    return aux; /* nova raiz */
};

RNtree* Maior(RNtree* t) {
    while (t != NodoNULL) t = t->dir;
    return t->pai;
}


RNtree* Menor(RNtree* t) {
    while (t != NodoNULL) t = t->esq;
    return t->pai;
}
