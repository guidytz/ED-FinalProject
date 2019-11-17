
// Defini��o da Estrutura
typedef struct SplayNode SplayTree;

struct SplayNode { 
    char* palavra;
    int ocorrencias;
    SplayTree* esq;
    SplayTree* dir;
};

SplayTree* splay_tree;
int rotacoes, comparacoes;

SplayTree* novo_nodo(char* palavra, SplayTree* esq, SplayTree* dir);
SplayTree* insere_nodo(char* palavra, SplayTree* nodo);
SplayTree* splay(SplayTree* nodo, char* palavra);
SplayTree* consulta_arvore(SplayTree* nodo, char* palavra);
SplayTree* remove_nodo(SplayTree* nodo, char* palavra);
void destroi_arvore(SplayTree* nodo);

int conta_nodos(SplayTree* nodo);
int altura(SplayTree* nodo);
int fator(SplayTree* nodo);
int frequencia(char* palavra);
int soma_frequencias(SplayTree* nodo);
void caminha_ECD(SplayTree* nodo);

SplayTree* rot_esquerda(SplayTree* nodo);
SplayTree* rot_direita(SplayTree* nodo);
void Desenha(SplayTree* nodo , int nivel);
SplayTree* consulta_splay(SplayTree* nodo, char* palavra); // Auxiliar do Inserem, al�m de fazer o Splay Insere o elemento.
