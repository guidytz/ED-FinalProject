#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "RN.h"
#include "aux.h"

// declarar o nodo NULL
RNtree* NodoNULL = NULL;
int nNodos       = 0;
int rotacoes     = 0;
int comparacoes  = 0;

// Funções Auxiliares
RNtree* VerificaRN(RNtree* t, char* key);
RNtree* RotacaoSimplesEsq(RNtree** t, RNtree* n);
RNtree* RotacaoSimplesDir(RNtree** t, RNtree* n);
RNtree* Maior(RNtree* t);
RNtree* Menor(RNtree* t);
int cmpKeys(char* k1, char* k2);

RNtree* Insere(RNtree* t, char* key) {
    RNtree* x = t;
    if (t == NULL) {
        NodoNULL = (RNtree*)malloc(sizeof(RNtree));
        x        = (RNtree*)malloc(sizeof(RNtree));

        // NULL
        NodoNULL->red = 0;  // null é preto;
        NodoNULL->esq = NodoNULL;
        NodoNULL->dir = NodoNULL;
        NodoNULL->key = "\0";
        NodoNULL->pai = NodoNULL;

        // Raiz
        x->key = key;
        x->esq = x->dir = NodoNULL;
        x->red          = 0;
        x->pai          = NodoNULL;
        x->freq         = 1;
        nNodos          = 1;
        return x;
    }

    RNtree* p = x->pai;  // pai
    RNtree* v = p->pai;  // avo

    while (x != NodoNULL) {
        v       = p;
        p       = x;
        int res = cmpKeys(key, x->key);
        if (res < 0)
            x = x->esq;
        else if (res == 0)
            break;
        else
            x = x->dir;
    }

    if (x != NodoNULL) {
        free(key);
        x->freq++;
        return t;  // Nodo ja Existe
    }

    x      = (RNtree*)malloc(sizeof(RNtree));
    x->key = key;
    x->esq = x->dir = NodoNULL;
    x->pai          = p;
    x->red          = 1;
    x->freq         = 1;

    if (cmpKeys(key, p->key) < 0)
        p->esq = x;
    else
        p->dir = x;

    nNodos++;

    return VerificaRN(t, key);
}

RNtree* Consulta(char* key, RNtree* t) {
    RNtree* x = t;
    if (x == NodoNULL) return NodoNULL;
    if (cmpKeys(x->key, key) == 0) return x;
    if (cmpKeys(key, x->key) < 0) return Consulta(key, t->esq);
    return Consulta(key, t->dir); 
}

void Destroi(RNtree* t) {
    if (t == NodoNULL) return;
    Destroi(t->esq);
    Destroi(t->dir);
    free(t->key);
    free(t);
    if (t->pai == NodoNULL) free(NodoNULL);
}

RNtree* VerificaRN(RNtree* t, char* key) {
    RNtree* x = t;
    RNtree* p = x->pai;
    RNtree* v = p->pai;
    while (cmpKeys(x->key, key) != 0) {
        v = p;
        p = x;
        if (cmpKeys(key, x->key) < 0)
            x = x->esq;
        else
            x = x->dir;
    }

    // caso 2
    if (p->red) {
        if (v != NodoNULL) {
            if (cmpKeys(p->key, v->key) < 0) {
                if (v->dir->red) {           // tio e vermelho
                    v->dir->red = 0;         // tio vira preto
                    p->red      = 0;         // troca a cor do pai
                    if (v->pai != NodoNULL)  // avo nao e raiz
                        v->red = 1;
                } else {
                    if ((cmpKeys(x->key, p->key) < 0) && (cmpKeys(p->key, v->key) < 0)) {
                        // rotacao a direita
                        RotacaoSimplesDir(&t, v);
                        p->red = 0;  // troca a cor do pai
                        v->red = 1;  // troca cor do avo
                    } else {
                        if ((cmpKeys(x->key, p->key) > 0) && (cmpKeys(p->key, v->key) > 0)) {
                            RotacaoSimplesEsq(&t, v);
                            p->red = 0;  // troca a cor do pai
                            v->red = 1;  // troca cor do avo
                        } else {
                            if (cmpKeys(p->key, v->key) < 0) {
                                RotacaoSimplesEsq(&t, p);
                                RotacaoSimplesDir(&t, v);  // rotacao Dupla a direita
                                rotacoes--;
                                x->red = 0;  // troca a cor do novo
                                v->red = 1;  // troca a cor do avo
                            } else {
                                RotacaoSimplesDir(&t, p);
                                RotacaoSimplesEsq(&t, v);  // rotacao Dupla a esquerda
                                rotacoes--;
                                x->red = 0;  // troca a cor do novo
                                v->red = 1;  // troca a cor do avo
                            }
                        }
                    }
                }
            } else {
                if (v->esq->red) {
                    v->esq->red = 0;         // tio vira preto
                    p->red      = 0;         // troca a cor do pai
                    if (v->pai != NodoNULL)  // avo não e raiz
                        v->red = 1;
                } else {
                    if ((cmpKeys(x->key, p->key) < 0) && (cmpKeys(p->key, v->key) < 0)) {
                        // rotacao a direita
                        RotacaoSimplesDir(&t, v);
                        p->red = 0;  // troca a cor do pai
                        v->red = 1;  // troca a cor do avo
                    } else {
                        if ((cmpKeys(x->key, p->key) > 0) && (cmpKeys(p->key, v->key) > 0)) {
                            RotacaoSimplesEsq(&t, v);  // --- aqui
                            p->red = 0;                // troca a cor do pai
                            v->red = 1;                // troca a cor do avo
                        } else {
                            if (cmpKeys(p->key, v->key) < 0) {
                                RotacaoSimplesEsq(&t, p);
                                RotacaoSimplesDir(&t, v);  // rotacao Dupla a direita
                                rotacoes--;
                                x->red = 0;  // troca a cor do novo
                                v->red = 1;  // troca a cor do avo
                            } else {
                                RotacaoSimplesDir(&t, p);
                                RotacaoSimplesEsq(&t, v);  // rotacao Dupla a esquerda
                                rotacoes--;
                                x->red = 0;  // troca a cor do novo
                                v->red = 1;  // troca a cor do avo
                            }
                        }
                    }
                }
            }
        }
    }
    t->red = 0;
    return t;
}

RNtree* RotacaoSimplesDir(RNtree** t, RNtree* n) {
    rotacoes++;
    RNtree* aux;

    aux           = n->esq;
    n->esq        = aux->dir;
    aux->dir->pai = n;
    aux->pai      = n->pai;
    if (aux->pai == NodoNULL) *t = aux;
    if (n == n->pai->esq)
        n->pai->esq = aux;
    else
        n->pai->dir = aux;
    aux->dir = n;
    n->pai   = aux;

    return aux; /* nova raiz */
};

RNtree* RotacaoSimplesEsq(RNtree** t, RNtree* n) {
    rotacoes++;
    RNtree* aux;

    aux         = n->dir;
    n->dir      = aux->esq;
    n->dir->pai = n;
    aux->pai    = n->pai;
    if (n->pai == NodoNULL) *t = aux;
    if (n == n->pai->esq)
        n->pai->esq = aux;
    else
        n->pai->dir = aux;
    aux->esq = n;
    n->pai   = aux;

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

int contaNodos(RNtree* t) { return nNodos; }

int altura(RNtree* t) {
    int esq, dir;
    if (t == NodoNULL)
        return 0;
    else {
        esq = altura(t->esq);
        dir = altura(t->dir);
        if (esq > dir)
            return (1 + esq);
        else
            return (1 + dir);
    }
}

int fator(RNtree* t) {
    int esq, dir;
    int fator_esq, fator_dir;
    if (t == NodoNULL)
        return 0;
    else {
        esq           = altura(t->esq);
        dir           = altura(t->dir);
        int fator_pai = abs(esq - dir);
        fator_esq     = fator(t->esq);
        fator_dir     = fator(t->dir);
        return fmax(fator_pai, fmax(fator_esq, fator_dir));
    }
}

int cmpKeys(char* k1, char* k2) {
    comparacoes++;
    return strcmp(k1, k2);
}

void fillCountVec(char **freqs, int k1, int k2, RNtree *t){
    if (t == NodoNULL) return;
    fillCountVec(freqs, k1, k2, t->esq);
    if (t->freq >= k1 && t->freq <= k2) {
        if (freqs[t->freq] != NULL){
            char *str = (char *) malloc(sizeof(char) * (strlen(freqs[t->freq]) + strlen(t->key) + 3));
            strcpy(str, freqs[t->freq]);
            strcat(str, " ");
            strcat(str, t->key);
            free(freqs[t->freq]);
            freqs[t->freq] = str;
        } else {
            freqs[t->freq] = (char *) malloc(sizeof(char) * (strlen(t->key) + 1));
            strcpy(freqs[t->freq], t->key);
        }
    }
    fillCountVec(freqs, k1, k2, t->dir);
}

int numRotacoes(void) { return rotacoes; }

int numComparacoes(void) { return comparacoes; }