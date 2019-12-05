typedef struct SplayNode SplayTree;

struct SplayNode { 
    char* palavra;
    int ocorrencias;
    SplayTree* esq;
    SplayTree* dir;
};

SplayTree* splay_tree;
long rotacoes, comparacoes;

/**
 * @brief 
 * 
 * @param palavra 
 * @param esq 
 * @param dir 
 * @return SplayTree* 
 */
SplayTree* novo_nodo(char* palavra, SplayTree* esq, SplayTree* dir);

/**
 * @brief 
 * 
 * @param palavra 
 * @param nodo 
 * @return SplayTree* 
 */
SplayTree* insere_nodo(char* palavra, SplayTree* nodo);

/**
 * @brief 
 * 
 * @param nodo 
 * @param palavra 
 * @return SplayTree* 
 */
SplayTree* splay(SplayTree* nodo, char* palavra);

/**
 * @brief 
 * 
 * @param nodo 
 * @param palavra 
 * @return SplayTree* 
 */
SplayTree* consulta_arvore(SplayTree* nodo, char* palavra);

/**
 * @brief 
 * 
 * @param nodo 
 * @param palavra 
 * @return SplayTree* 
 */
SplayTree* remove_nodo(SplayTree* nodo, char* palavra);

/**
 * @brief 
 * 
 * @param nodo 
 */
void destroi_arvore(SplayTree* nodo);

/**
 * @brief 
 * 
 * @param lower_bound 
 * @param higher_bound 
 * @return char** 
 */
char** contador(int lower_bound, int higher_bound);

/**
 * @brief 
 * 
 * @param nodo 
 * @return int 
 */
int conta_nodos(SplayTree* nodo);

/**
 * @brief 
 * 
 * @param nodo 
 * @return int 
 */
int altura(SplayTree* nodo);

/**
 * @brief 
 * 
 * @param nodo 
 * @return int 
 */
int fator(SplayTree* nodo);

/**
 * @brief 
 * 
 * @param palavra 
 * @return int 
 */
int frequencia(char* palavra);

/**
 * @brief 
 * 
 * @param nodo 
 * @return int 
 */
int soma_frequencias(SplayTree* nodo);

/**
 * @brief 
 * 
 * @param nodo 
 * @return int 
 */
int maior_fator(SplayTree* nodo);

/**
 * @brief Get the 'rotacoes' object
 * 
 * @return long 
 */
long get_rotacoes();

/**
 * @brief Get the 'comparacoes' object
 * 
 * @return long 
 */
long get_comparacoes();

/**
 * @brief 
 * 
 * @param nodo 
 */
void caminha_ECD(SplayTree* nodo);

/**
 * @brief Get the 'maior' object
 * 
 * @param a 
 * @param c 
 * @return int 
 */
int get_maior(int a, int , int c);

/**
 * @brief 
 * 
 * @param nodo 
 * @return SplayTree* 
 */
SplayTree* rot_esquerda(SplayTree* nodo);

/**
 * @brief 
 * 
 * @param nodo 
 * @return SplayTree* 
 */
SplayTree* rot_direita(SplayTree* nodo);

/**
 * @brief 
 * 
 * @param nodo 
 * @param nivel 
 */
void Desenha(SplayTree* nodo , int nivel);

/**
 * @brief 
 * 
 * @param nodo 
 * @param palavra 
 * @return SplayTree* 
 */
SplayTree* consulta_splay(SplayTree* nodo, char* palavra);
