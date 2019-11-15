
// Defini��o da Estrutura
typedef struct SplayTree PtNodo;
struct SplayTree {
    int key;
    int ocorrencias;
    char* palavra;
    PtNodo* esq;
    PtNodo* dir;
};

// Defini��o das Fun��es
PtNodo* Novo(char* palavra, PtNodo* esq, PtNodo* dir);
PtNodo* Insere(char* palavra, PtNodo* t);
PtNodo* Splay(PtNodo* t, char* palavra);
PtNodo* Consulta(PtNodo* t, char* palavra);
PtNodo* Remove(PtNodo* t, char* palavra);
void Destroi(PtNodo* t);

//TODO
int Altura(PtNodo* t);      //DONE
int Fator(PtNodo* t);       //DONE
int ContaNodos(PtNodo* t);  //DONE

// Fun��es Auxiliares
PtNodo* RotEsq(PtNodo* t);
PtNodo* RotDir(PtNodo* t);
void Desenha(PtNodo* t , int nivel);
PtNodo* ConsultaSplay(PtNodo* t, char* palavra); // Auxiliar do Inserem, al�m de fazer o Splay Insere o elemento