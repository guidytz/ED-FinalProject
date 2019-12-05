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
 * Função que cria um novo nodo na árvore, associando as dúas árvores recebidas como seus filhos.
 * @param palavra Palavra que se deseja inserir no nodod que sera criado
 * @param esq Árvore que será inserida na referência à esquerda do novo nodo
 * @param dir Árvore que será inserida na referência à direita do novo nodo
 * @return SplayTree* 
 */
SplayTree* novo_nodo(char* palavra, SplayTree* esq, SplayTree* dir);

/**
 * @brief 
 * Função que insere um novo nodo na árvore, retornando uma referência à árvore já atualizada após a execução.
 * @param palavra Palavra que se deseja inserir na árvore 
 * @param nodo Nodo à partir do qual será realizado o procedimento de busca do local apropriado, dentro da árvore, no qual a nova palavra será inserida
 * @return SplayTree* 
 */
SplayTree* insere_nodo(char* palavra, SplayTree* nodo);

/**
 * @brief 
 * Função que realiza a rotação de nodos o "splay"
 * @param nodo Nodo à partir do qual será realizado o "splay"
 * @param palavra Palavra sobre a qual será realizado o splay
 * @return SplayTree* 
 */
SplayTree* splay(SplayTree* nodo, char* palavra);

/**
 * @brief 
 * Função auxiliar que realiza a consulta de um nodo na árvore, retornando uma referência à instância já atualizada.
 * @param nodo Nodo à partir do qual será realizada a busca
 * @param palavra Palavra que está sendo buscada dentro da árvore
 * @return SplayTree* 
 */
SplayTree* consulta_arvore(SplayTree* nodo, char* palavra);

/**
 * @brief 
 * Função que remove um nodo da árvore, retornando uma referência à instância já atualizada.
 * @param nodo Nodo à partir do qual será realizado o processo de pesquisa e de remoção da palavra em questão
 * @param palavra Palavra que se deseja remover da árvore
 * @return SplayTree* 
 */
SplayTree* remove_nodo(SplayTree* nodo, char* palavra);

/**
 * @brief 
 * Função sem retorno que destroi a arvore, liberando a memória ocupada pela mesma
 * @param nodo Nodo à partir do qual será realizado a liberação de memória (destruição dos dados)
 */
void destroi_arvore(SplayTree* nodo);

/**
 * @brief 
 * Função que realiza a coleta de palavras contidas pela arvore que possuem frequencia incçuída no intervalo em questão
 * @param lower_bound Valor de teto utilizado na busca de palavras
 * @param higher_bound Valor de piso utilizado na busca de palavras
 * @return char** 
 */
char** contador(int lower_bound, int higher_bound);

/**
 * @brief 
 *  Função que realiza a contagem da quantidade de nodos contidos pela árvore no momento da chamada
 * @param nodo Nodo à partir do qual será realizada a contagem
 * @return int Quantidade de nodos da árvore 
 */
int conta_nodos(SplayTree* nodo);

/**
 * @brief 
 * Função que calcula a altura de um nodo dentro da árvore
 * @param nodo Nodo à partir do qual será realizado o cálculo de altura
 * @return int Altura do nodo
 */
int altura(SplayTree* nodo);

/**
 * @brief 
 * Função que calcula o fator de um nodo
 * @param nodo Nodo com relação ao qual se busca obter o fator
 * @return int Fator do nodo
 */
int fator(SplayTree* nodo);

/**
 * @brief 
 * Função que retorna a frequência de uma dada palavra dentro da árvore
 * @param palavra A palavra cuja frequência deseja-se descobrir
 * @return int A frequência da palavra em questão
 */
int frequencia(char* palavra);

/**
 * @brief 
 * Função que realiza a soma das frequencias de todas as palavras inseridas na árvore até o momento
 * @param nodo Nodo à partir do qual será realizada a soma de frequências das palavras
 * @return int Soma das frequências das palavras contidas pela árvore em questão
 */
int soma_frequencias(SplayTree* nodo);

/**
 * @brief 
 * Encontra o maior fator à partir de um dado nodo
 * @param nodo Nodo à partir do qual será realizado o procedimento de obtenção do maior fator contido pela árvore
 * @return int O maior fator contido pela árvore recebida
 */
int maior_fator(SplayTree* nodo);

/**
 * @brief Get the 'rotacoes' object
 * Retorna a quantidade de rotações executadas até o momento
 * @return long Quantidade de rotações realizadas pela árvore até o momento
 */
long get_rotacoes();

/**
 * @brief Get the 'comparacoes' object
 * Retorna a quantidade de comparações realizadas até o momento
 * @return long Quantidade de comparações realizadas pela árvore até o momento
 */
long get_comparacoes();

/**
 * @brief 
 * Função de debug, realiza um caminhamento Central-Esquerdo imprimindo as informações de cada nodo
 * @param nodo Nodo à partir do qual será realizado o caminhamento
 */
void caminha_ECD(SplayTree* nodo);

/**
 * @brief Get the 'maior' object
 * Retorna o maior dos três parâmetros recebidos
 * @param a Valor inteiro 
 * @param b Valor inteiro
 * @param c Valor inteiro
 * @return int Maior valor dentre aqueles recebidos
 */
int get_maior(int a, int b, int c);

/**
 * @brief 
 * Realiza uma rotação à esquerda de um dado nodo
 * @param nodo Nodo sobre o qual se deseja realizar a rotação
 * @return SplayTree* Referência para a árvore resultante do processo de rotação
 */
SplayTree* rot_esquerda(SplayTree* nodo);

/**
 * @brief 
 * Realiza uma rotação à direita de um dado nodo
 * @param nodo Nodo sobre o qual se deseja realizar a rotação
 * @return SplayTree* Referência para a árvore resultante do processo de rotação
 */
SplayTree* rot_direita(SplayTree* nodo);

/**
 * @brief 
 * Imprime uma representação de uma dada árvore à partir de um certo nodo (Créditos: Renata Galante)
 * @param nodo Nodo à partir do qual deseja-se "desenhar" 
 * @param nivel Nível do nodo de partida (usado apenas para fins de impressão)
 */
void Desenha(SplayTree* nodo , int nivel);

/**
 * @brief 
 * Função que de fato realiza a consulta de um nodo dentro de uma dada árvore
 * @param nodo Nodo à partir do qual será realizada a consulta
 * @param palavra Palavra que está sendo buscada
 * @return SplayTree* Referência da árvore após a realização da pesquisa
 */
SplayTree* consulta_splay(SplayTree* nodo, char* palavra);
