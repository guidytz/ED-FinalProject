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
 * Função que cria um novo nodo na árvore, retornando a referência para este novo nodo logo após a execução.
 * @param palavra 
 * @param esq 
 * @param dir 
 * @return SplayTree* 
 */
SplayTree* novo_nodo(char* palavra, SplayTree* esq, SplayTree* dir);

/**
 * @brief 
 * Função que insere um novo nodo na árvore, retornando uma referência à árvore já atualizada após a execução.
 * @param palavra 
 * @param nodo 
 * @return SplayTree* 
 */
SplayTree* insere_nodo(char* palavra, SplayTree* nodo);

/**
 * @brief 
 * Função que realiza a rotação de nodos o "splay"
 * @param nodo 
 * @param palavra 
 * @return SplayTree* 
 */
SplayTree* splay(SplayTree* nodo, char* palavra);

/**
 * @brief 
 * Função auxiliar que realiza a consulta de um nodo na árvore, retornando uma referência à instância já atualizada.
 * @param nodo 
 * @param palavra 
 * @return SplayTree* 
 */
SplayTree* consulta_arvore(SplayTree* nodo, char* palavra);

/**
 * @brief 
 * Função que remove um nodo da árvore, retornando uma referência à instância já atualizada.
 * @param nodo 
 * @param palavra 
 * @return SplayTree* 
 */
SplayTree* remove_nodo(SplayTree* nodo, char* palavra);

/**
 * @brief 
 * Função sem retorno que destroi a arvore, liberando a memória ocupada pela mesma
 * @param nodo 
 */
void destroi_arvore(SplayTree* nodo);

/**
 * @brief 
 * Função que realiza a coleta 
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
 * Função que calcula a altura de um nodo dentro da árvore
 * @param nodo 
 * @return int 
 */
int altura(SplayTree* nodo);

/**
 * @brief 
 * Função que encontra o maior fator de uma dada árvore
 * @param nodo 
 * @return int 
 */
int fator(SplayTree* nodo);

/**
 * @brief 
 * Função que retorna a frequência de uma dada palavra dentro da árvore
 * @param palavra 
 * @return int 
 */
int frequencia(char* palavra);

/**
 * @brief 
 * Função que realiza a soma das frequencias de todas as palavras inseridas na árvore até o momento
 * @param nodo 
 * @return int 
 */
int soma_frequencias(SplayTree* nodo);

/**
 * @brief 
 * Encontra o maior fator à partir de um dado nodo
 * @param nodo 
 * @return int 
 */
int maior_fator(SplayTree* nodo);

/**
 * @brief Get the 'rotacoes' object
 * Retorna a quantidade de rotações executadas até o momento
 * @return long 
 */
long get_rotacoes();

/**
 * @brief Get the 'comparacoes' object
 * Retorna a quantidade de comparações realizadas até o momento
 * @return long 
 */
long get_comparacoes();

/**
 * @brief 
 * Função de debug, realiza um caminhamento Central-Esquerdo imprimindo as informações de cada nodo
 * @param nodo 
 */
void caminha_ECD(SplayTree* nodo);

/**
 * @brief Get the 'maior' object
 * Retorna o maior dos três parâmetros recebidos
 * @param a 
 * @param c 
 * @return int 
 */
int get_maior(int a, int , int c);

/**
 * @brief 
 * Realiza uma rotação à esquerda de um dado nodo
 * @param nodo 
 * @return SplayTree* 
 */
SplayTree* rot_esquerda(SplayTree* nodo);

/**
 * @brief 
 * Realiza uma rotação à direita de um dado nodo
 * @param nodo 
 * @return SplayTree* 
 */
SplayTree* rot_direita(SplayTree* nodo);

/**
 * @brief 
 * Imprime uma representação de uma dada árvore à partir de um certo nodo (Créditos: Renata Galante)
 * @param nodo 
 * @param nivel 
 */
void Desenha(SplayTree* nodo , int nivel);

/**
 * @brief 
 * Função que de fato realiza a consulta de um nodod dentro de uma dada árvore
 * @param nodo 
 * @param palavra 
 * @return SplayTree* 
 */
SplayTree* consulta_splay(SplayTree* nodo, char* palavra);
