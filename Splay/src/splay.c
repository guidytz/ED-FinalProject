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
			if (nodo->esq->dir != NULL) 
				nodo->esq = rot_esquerda(nodo->esq);
			return rot_direita(nodo);
		} 
		else return rot_direita(nodo);
	} else if(strcmp(palavra, nodo->palavra) > 0) {
			if (nodo->dir == NULL) return nodo;
			if (strcmp(palavra, nodo->dir->palavra) > 0) {
				nodo->dir->dir = consulta_splay(nodo->dir->dir, palavra);
				nodo = rot_esquerda(nodo);
				if (nodo->dir == NULL) return nodo;
				else return rot_esquerda(nodo);
			} else if (strcmp(palavra, nodo->dir->palavra) < 0) {
				nodo->dir->esq = consulta_splay(nodo->dir->esq, palavra);
				if (nodo->dir->esq != NULL) 
					nodo->dir = rot_direita(nodo->dir);
				return rot_esquerda(nodo);
			}
			else return rot_esquerda(nodo);
		}
	else return nodo;
}

SplayTree* rot_direita(SplayTree* nodo){ 
	SplayTree* aux = nodo->esq;
	nodo->esq = aux->dir;
	aux->dir = nodo;
	rotacoes++;
	return aux; 
}

SplayTree* rot_esquerda(SplayTree* nodo){ 
	SplayTree* aux = nodo->dir;
	nodo->dir = aux->esq;
	aux->esq = nodo;
	rotacoes++;
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
	splay_tree = consulta_arvore(splay_tree, palavra);
	if(strcmp(splay_tree->palavra, palavra) == 0){
		return splay_tree->ocorrencias;
	}
	return 0;
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
		return (altura_dir > altura_esq)? 1 + altura_dir : 1 + altura_esq;
	}
	return 0;
}

int fator(SplayTree* nodo){
	return (nodo != NULL)? altura(nodo->esq) - altura(nodo->dir) : 0;
}


int maior_fator(SplayTree* nodo){
	if(nodo != NULL){
		return get_maior(altura(nodo->esq) - altura(nodo->dir), maior_fator(nodo->esq), maior_fator(nodo->dir));
	}
	return 0;
}

int get_rotacoes(){
	return rotacoes;
}

int get_comparacoes(){
	return comparacoes;
}

int get_maior(int a, int b, int c){
	if(a >= b){
		if(a > c)
			return a;
		else
			return c;
	}if(c >= b){
		if(c > a)
			return c;
		else
			return a;
	}if(b >= a){
		if(b > c)
			return b;
		else
			return c;
	}
}

void coleta_palavras(SplayTree* nodo, int l_b, int h_b, char** lista){
	if(nodo != NULL){
		coleta_palavras(nodo->esq, l_b, h_b, lista);
		if(nodo->ocorrencias >= l_b && nodo->ocorrencias <= h_b){
			if(lista[nodo->ocorrencias - l_b] != NULL){
				char* nova_tupla = (char*) malloc(sizeof(char) * (strlen(nodo->palavra) + strlen(lista[nodo->ocorrencias - l_b]) + 2));
				strcpy(nova_tupla, lista[nodo->ocorrencias - l_b]);
				strcat(nova_tupla, " ");
				strcat(nova_tupla, nodo->palavra);
				free(lista[nodo->ocorrencias - l_b]);
				lista[nodo->ocorrencias - l_b] = nova_tupla;
			}else{
				char* nova_tupla = (char*) malloc(sizeof(char) * strlen(nodo->palavra) + 2);
				strcpy(nova_tupla, nodo->palavra);
				lista[nodo->ocorrencias - l_b] = nova_tupla;
			}
		}
		coleta_palavras(nodo->dir, l_b, h_b, lista);
	}
}

 char** contador(int lower_bound, int higher_bound){
	char **lista = (char **) malloc(sizeof(char*) * abs(higher_bound - lower_bound) + 1);
	for(int i = 0 ; i <= (higher_bound - lower_bound); i++) lista[i] = NULL;
	coleta_palavras(splay_tree, lower_bound, higher_bound, lista);
	return lista;
}