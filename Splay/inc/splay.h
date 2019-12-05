typedef struct SplayNode SplayTree;

struct SplayNode { 
    char* palavra;
    int ocorrencias;
    SplayTree* esq;
    SplayTree* dir;
};

SplayTree* splay_tree;
long rotacoes, comparacoes;

SplayTree* novo_nodo(char* palavra, SplayTree* esq, SplayTree* dir);
SplayTree* insere_nodo(char* palavra, SplayTree* nodo);
SplayTree* splay(SplayTree* nodo, char* palavra);
SplayTree* consulta_arvore(SplayTree* nodo, char* palavra);
SplayTree* remove_nodo(SplayTree* nodo, char* palavra);
void destroi_arvore(SplayTree* nodo);
char** contador(int lower_bound, int higher_bound);

int conta_nodos(SplayTree* nodo);
int altura(SplayTree* nodo);
int fator(SplayTree* nodo);
int frequencia(char* palavra);
int soma_frequencias(SplayTree* nodo);
int maior_fator(SplayTree* nodo);
long get_rotacoes();
long get_comparacoes();
void caminha_ECD(SplayTree* nodo);
int get_maior(int a, int , int c);

SplayTree* rot_esquerda(SplayTree* nodo);
SplayTree* rot_direita(SplayTree* nodo);
void Desenha(SplayTree* nodo , int nivel);
SplayTree* consulta_splay(SplayTree* nodo, char* palavra);
