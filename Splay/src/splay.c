#include "splay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SplayTree* novo_nodo(char* palavra, SplayTree* esq, SplayTree* dir){
	SplayTree* x = (SplayTree*) malloc(sizeof(SplayTree));
	x->palavra = palavra; x->esq = esq; x->dir = dir;
	x->ocorrencias = 1;
	return x;
}

SplayTree* insere_nodo(char* palavra, SplayTree* t){	
  	return splay(t,palavra);
}

SplayTree* consulta_arvore(SplayTree* nodo, char* palavra){
	if (nodo == NULL) return NULL;
	nodo = consulta_splay(nodo, palavra);
	return nodo;
}

SplayTree* remove_nodo(SplayTree* nodo, char* palavra){
	SplayTree* x;
	if (nodo==NULL) return NULL;
	nodo = consulta_arvore(nodo,palavra);
	if (strcmp(palavra, nodo->palavra) == 0) {               /* achou */
		if (nodo->esq == NULL) {
			x = nodo->dir;
		} else {
		x = consulta_arvore(nodo->esq,palavra);
		x->dir = nodo->dir;
		}
		free(nodo);
		return x;
	}
	return nodo;                         /* It wasn't there */
}

void destroi_arvore(SplayTree* nodo){
	if(nodo->esq != NULL) destroi_arvore(nodo->esq);
	if(nodo->dir != NULL) destroi_arvore(nodo->dir);
	free(nodo);
}

SplayTree* splay(SplayTree* nodo, char* palavra){
	if (nodo == NULL) {
		comparacoes++;
		return novo_nodo(palavra, NULL, NULL);}
	if(strcmp(palavra, nodo->palavra) == 0){
		comparacoes++;
		nodo->ocorrencias++;
		return nodo;
	}if (strcmp(palavra, nodo->palavra) < 0){
		comparacoes++;
		if (nodo->esq == NULL) return novo_nodo(palavra, NULL, nodo);
		if(strcmp(palavra, nodo->esq->palavra) == 0){
			comparacoes++;
			nodo->esq->ocorrencias++;
			return nodo;
		}if (strcmp(palavra, nodo->esq->palavra) < 0){
			comparacoes++;
			nodo->esq->esq = splay(nodo->esq->esq, palavra);
			nodo = rot_direita(nodo);
		}else{
			comparacoes++;
			nodo->esq->dir = splay(nodo->esq->dir, palavra);
			nodo->esq = rot_esquerda(nodo->esq);
		}
		return rot_direita(nodo); 
	}else{ 
		if (nodo->dir == NULL) {
			comparacoes++;
			return novo_nodo(palavra, nodo, NULL);}
		if(strcmp(palavra, nodo->dir->palavra) == 0){
			comparacoes++;
			nodo->dir->ocorrencias++;
			return nodo;
		}if (strcmp(palavra, nodo->dir->palavra) > 0){
			comparacoes++;
			nodo->dir->dir = splay(nodo->dir->dir, palavra);
			nodo = rot_esquerda(nodo);
		}else{ 
			nodo->dir->esq = splay(nodo->dir->esq, palavra);
			nodo->dir = rot_direita(nodo->dir);
		}
		return rot_esquerda(nodo);
	}
}

SplayTree* consulta_splay(SplayTree* nodo, char* palavra){
	if (nodo == NULL) return NULL;
	if (strcmp(palavra, nodo->palavra) < 0) {
		if (nodo->esq == NULL) return nodo;
		if (strcmp(palavra, nodo->esq->palavra) < 0){
			nodo->esq->esq = consulta_splay(nodo->esq->esq, palavra);
			nodo = rot_direita(nodo);
			if (nodo->esq == NULL) return nodo;
			else return rot_direita(nodo);
	} else if (strcmp(palavra, nodo->esq->palavra) > 0) {
			nodo->esq->dir = consulta_splay(nodo->esq->dir, palavra);
			if (nodo->esq->dir != NULL) nodo->esq = rot_esquerda(nodo->esq);
			return rot_direita(nodo);
		} else return rot_direita(nodo);
	} else if(strcmp(palavra, nodo->palavra) > 0) {
			if (nodo->dir == NULL) return nodo;
			if (strcmp(palavra, nodo->dir->palavra) > 0) {
			nodo->dir->dir = consulta_splay(nodo->dir->dir, palavra);
			nodo = rot_esquerda(nodo);
			if (nodo->dir == NULL) return nodo;
			else return rot_esquerda(nodo);
		} else if (strcmp(palavra, nodo->dir->palavra) < 0) {
			nodo->dir->esq = consulta_splay(nodo->dir->esq, palavra);
			if (nodo->dir->esq != NULL) nodo->dir = rot_direita(nodo->dir);
			return rot_esquerda(nodo);
			} else return rot_esquerda(nodo);
		} else return nodo;
}

SplayTree* rot_direita(SplayTree* nodo){ 
	SplayTree* aux = nodo->esq;
	nodo->esq = aux->dir;
	aux->dir = nodo;
	return aux; 
}

SplayTree* rot_esquerda(SplayTree* nodo){ 
	SplayTree* aux = nodo->dir;
	nodo->dir = aux->esq;
	aux->esq = nodo;
	return aux;
}

void Desenha(SplayTree* nodo, int nivel){
	printf("\n");
	int x;
	if (nodo !=NULL){
		for (x=1; x<=nivel; x++)
			printf("=");
		printf("%s \n", nodo->palavra);
		printf("%d \n", nodo->ocorrencias);
		printf("\nesq:");
		if (nodo->esq != NULL) Desenha(nodo->esq, (nivel+1));
		printf("\ndir:");
		if (nodo->dir != NULL) Desenha(nodo->dir, (nivel+1));
	}else printf("Arvore Vazia");
}

void caminha_ECD(SplayTree* nodo){
	if(nodo != NULL){
		caminha_ECD(nodo->esq);
		printf("\n%s", nodo->palavra);
		printf(" %d", nodo->ocorrencias);
		caminha_ECD(nodo->dir);
	}
}

int frequencia(char* palavra){
	SplayTree* resultado_pesquisa = consulta_arvore(splay_tree, palavra);
	if(strcmp(resultado_pesquisa->palavra, palavra) == 0){
		return resultado_pesquisa->ocorrencias;
	}
	return -1;
}

int soma_frequencias(SplayTree* nodo){
	if(nodo != NULL){
		return nodo->ocorrencias + soma_frequencias(nodo->esq) + soma_frequencias(nodo->dir);
	}
	return 0;
}

int conta_nodos(SplayTree* nodo){
	return (nodo != NULL)? 1 + conta_nodos(nodo->esq) + conta_nodos(nodo->dir) : 0;
}

int altura(SplayTree* nodo){
	if(nodo != NULL){
		int altura_esq = altura(nodo->esq);
		int altura_dir = altura(nodo->dir);
		return 1 + (altura_dir > altura_esq)? altura_dir : altura_esq;
	}
	return 0;
}

int fator(SplayTree* nodo){
	return (nodo != NULL)? altura(nodo->esq) - altura(nodo->dir) : 0;
}