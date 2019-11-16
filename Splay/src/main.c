#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "aux.h"
#include "splay.h"

//  ---DEVEM SER IMPLEMENTADOS NA MAIN
int Frequencia(char* palavra);  //...
void contador (int k1, int k2); //...

int main( int argc, char *argv[] ) {
    setlocale(LC_ALL,""); //para imprimir corretamente na tela os caracteres acentuados
    FILE * texto;
    FILE * cmd;
    FILE * saida;
    RNtree *t = NULL;

    char *palavra, linha[1000]; 
    char separador[]= {" ,.&*\\%%\?!;/-−'@\"$#=><()][}{:\n\t"};

    if ( argc != 4 ) {
        printf ("Número incorreto de parâmetros.\n Para chamar o programa digite: exemplo <arq_texto> <arq_ops> <arq_saida>\n");

        return 1;
    } else {
        texto = fopen (argv[1], "r"); 
        if (texto == NULL) { 
            printf ("Erro ao abrir o arquivo %s\n", argv[1]);

            return 1;
        } else { 
            cmd = fopen(argv[2], "r");
            if (cmd == NULL){
                printf ("Erro ao abrir o arquivo %s\n", argv[2]);
                fclose(texto);

                return 1;
            } else {
                saida = fopen (argv[3], "w"); 

                while ( fgets(linha, 1000, texto) ) {
                    palavra = strtok(linha, separador);
                    
                    while ( palavra != NULL ) {
                        t = Insere(t, stralloc(strlwr(palavra)));
                        palavra = strtok(NULL, separador);
                    }
                }

                Destroi(t);
                printf("Arquivo %s gerado com sucesso.\n",argv[2]);
            } 
        } 
        
        fclose (texto); 
        fclose (cmd); 
        fclose (saida);

        return 0;
    }

}