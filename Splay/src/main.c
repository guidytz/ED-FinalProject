#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "aux.h"
#include "splay.h"

int main( int argc, char *argv[] ) {
    setlocale(LC_ALL,"");
    FILE * texto;
    FILE * commands_file;
    FILE * saida;

    splay_tree = NULL;
    rotacoes = 0;
    comparacoes = 0;

    char *palavra, linha[1000]; 
    char separador[]= {" ,.&*\\%%\?!—;/-−'@\"$#=><()][}{:\n\t"};

    if ( argc != 4 ) {
        printf ("\nNúmero incorreto de parâmetros.\n Para chamar o programa digite: contador <arq_texto> <arq_ops> <arq_saida>\n");
        return 1;
    } else {
        texto = fopen (argv[1], "r"); 
        if (texto == NULL) { 
            printf ("\nErro ao abrir o arquivo %s", argv[1]);

            return 1;
        } else {
            commands_file = fopen(argv[2], "r"); 
            if (commands_file == NULL){
                printf ("\nErro ao abrir o arquivo %s", argv[2]);
                fclose(texto);

                return 1;
            } else {
                clock_t start_timestamp, end_timestamp;
                int insert_counter = 0;
                saida = fopen (argv[3], "w"); 
                while ( fgets(linha, 1000, texto) ) {
                    palavra = strtok(linha, separador);
                    
                    //Inserção das palavras na arvore
                    start_timestamp = clock();
                    while ( palavra != NULL ) {
                        splay_tree = insere_nodo(stralloc(strlwr(palavra)), splay_tree);
                        palavra = strtok(NULL, separador);
                    }
                    end_timestamp = clock();
                }
                printf("\n| ->[DEBUG] Foram carregadas %d palavras em %fs", soma_frequencias(splay_tree), ((double) (end_timestamp - start_timestamp)) / CLOCKS_PER_SEC);
                printf("\n| ->[DEBUG] Quantidade de palavras distintas: %d", conta_nodos(splay_tree));
                printf("\n| ->[DEBUG] Comparações realizadas: %d", comparacoes);
                printf("\n| ->[DEBUG] Rotações realizadas: %d", rotacoes);
                printf("\n| ->[DEBUG] Arquivo [%s] gerado com sucesso.\n",argv[2]);
                destroi_arvore(splay_tree);
            } 
        } 
        // tratar  (travessao bizarro "caso, dizia")
        // tratar caso "d'agua"
        fclose (texto); 
        fclose (commands_file); 
        fclose (saida);
        return 0;
    }
}
