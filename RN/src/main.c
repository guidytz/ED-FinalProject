#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "aux.h"
#include "RN.h"
#include "globals.h"

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "");  // para imprimir corretamente na tela os caracteres acentuados
    FILE *texto;
    FILE *cmd;
    FILE *saida;

    char *palavra, linha[1000];
    char separador[] = {" ,.&*\\%%\?!—;/-−'@\"$#=><()][}{:_^~+|\n\t\r"};

    if (argc != 4) {
        printf("Número incorreto de parâmetros.\n Para chamar o programa digite: exemplo <arq_texto> <arq_ops> <arq_saida>\n");

        return 1;
    } else {
        texto = fopen(argv[1], "r");
        if (texto == NULL) {
            printf("Erro ao abrir o arquivo %s\n", argv[1]);

            return 1;
        } else {
            cmd = fopen(argv[2], "r");
            if (cmd == NULL) {
                printf("Erro ao abrir o arquivo %s\n", argv[2]);
                fclose(texto);

                return 1;
            } else {
                saida             = fopen(argv[3], "w");
                clock_t time = clock();

                // Carregamento dos dados na arvore
                while (fgets(linha, 1000, texto)) {
                    palavra = strtok(linha, separador);

                    while (palavra != NULL) {
                        t       = Insere(t, stralloc(strlwr(palavra)));
                        palavra = strtok(NULL, separador);
                    }
                }
                time = clock() - time;
                long comps = 0;

                fprintf(saida, "******************** ESTATÍSTICAS DA GERAÇÃO DA ÁRVORE R-N ********************\n");
                fprintf(saida, "Número de nodos: %d\n", contaNodos(t));
                fprintf(saida, "Altura: %d\n", altura(t));
                fprintf(saida, "Fator de Balanceamento: %d\n", fator(t));
                fprintf(saida, "Tempo: %lf ms\n", ((double)time) / CLOCKS_PER_SEC * 1000.0);
                fprintf(saida, "Rotações: %ld\n", numRotacoes());
                fprintf(saida, "Comparações: %ld\n", comps = numComparacoes());
                fprintf(saida, "*******************************************************************************\n");

                time = clock();
                while (fgets(linha, 1000, cmd)) {
                    fprintf(saida, "%s", linha);
                    
                    char *str = strtok(linha, separador);
                    
                    if ( strcmp("F", str) == 0 ) {
                        str = strtok(NULL, separador);
                        if (str == NULL) continue;
                        int freq = frequencia(str);
                        fprintf(saida, "%s: %d ocorrência", str, freq);
                        if (freq != 1) fprintf(saida, "s");
                        fprintf(saida, "\n******************************\n");
                    } else {
                        char *str1, *str2;
                        str1 = strtok(NULL, separador);
                        str2 = strtok(NULL, separador);
                        if (str1 == NULL || str2 == NULL) continue;
                        contador(atoi(str1), atoi(str2), saida);
                        fprintf(saida, "******************************\n");
                    }
                }

                time = clock() - time;

                fprintf(saida, "\nTempo: %lf ms\n", ((double)time) / CLOCKS_PER_SEC * 1000.0);
                fprintf(saida, "Comparações: %ld\n", numComparacoes() - comps + cmpContador);

                Destroi(t);
                printf("Arquivo %s gerado com sucesso.\n", argv[3]);
            }
        }

        fclose(texto);
        fclose(cmd);
        fclose(saida);

        return 0;
    }
}