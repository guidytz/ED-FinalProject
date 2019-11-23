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
    FILE * arquivo_operacoes;
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
            arquivo_operacoes = fopen(argv[2], "r"); 
            if (arquivo_operacoes == NULL){
                printf ("\nErro ao abrir o arquivo %s", argv[2]);
                fclose(texto);

                return 1;
            } else {
                clock_t time_stamp;
                int insert_counter = 0;
                saida = fopen (argv[3], "w"); 
                time_stamp = clock();
                while ( fgets(linha, 1000, texto) ) {
                    palavra = strtok(linha, separador);
                    //Inserção das palavras na arvore
                    while ( palavra != NULL ) {
                        splay_tree = insere_nodo(stralloc(strlwr(palavra)), splay_tree);
                        palavra = strtok(NULL, separador);
                    }                    
                }
                time_stamp = clock() - time_stamp;
                fprintf(saida, "**********ESTATÍSTICAS DA GERAÇÃO DA ÁRVORE SPLAY *************\n");
                fprintf(saida, "Número de nodos: %d\n", conta_nodos(splay_tree));
                fprintf(saida, "Altura: %d\n", altura(splay_tree));
                fprintf(saida, "Fator de Balanceamento: %d\n", maior_fator(splay_tree));
                fprintf(saida, "Tempo: %.5f\n", ((double) time_stamp) / CLOCKS_PER_SEC);
                fprintf(saida, "Rotações: %d\n", get_rotacoes());
                fprintf(saida, "Comparações: %d\n", get_comparacoes());
                fprintf(saida, "*************************************************************\n");
                time_stamp = clock();
                while ( fgets(linha, 1000, arquivo_operacoes) ) {
                    fprintf(saida, "%s", linha);
                    char * string = strtok(linha, separador);
                    if(strcmp(string, "F") == 0){
                        string = strtok(NULL, separador);
                        string[strlen(string)-1] = '\0';
                        fprintf(saida, "%s: %d ocorrencias\n", string, frequencia(string));
                    }else{
                        int  b_1 = atoi(strtok(NULL, separador));
                        int  b_2 = atoi(strtok(NULL, separador));
                        
                    }
                    fprintf(saida, "**************************\n");
                }
                time_stamp = clock() - time_stamp;
                fprintf(saida, "Tempo: %f\n", ((double) time_stamp)/CLOCKS_PER_SEC);
                fprintf(saida, "Comparacoes");
                caminha_ECD(splay_tree);
                destroi_arvore(splay_tree);
            }
        }
        fclose (texto); 
        fclose (arquivo_operacoes); 
        fclose (saida);
        return 0;
    }
}