#include "globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

RNtree *t = NULL;
int cmpContador = 0; 

int frequencia(char *palavra) {
    if (t == NULL) return -1;

    RNtree *n = Consulta(palavra, t);
    if (n != NodoNULL) return n->freq;
    return 0;
}

void contador(int k1, int k2, FILE *f) {
    char **freqs = (char **) malloc(sizeof(char*) * k2 + 1);
    for (int i = 0; i <= k2; i++) freqs[i] = NULL;
    fillCountVec(freqs, k1, k2, t);
    for (int i = k2; i >= k1; i--) {
        if (freqs[i] != NULL) {
            cmpContador++;
            char *str = strtok(freqs[i], " ");
            while (str != NULL) {
                fprintf(f, "%s %d\n", str, i);
                str = strtok(NULL, " ");
            }
        }
    }

    for (int i = 0; i <= k2; i++) {
        if (freqs[i] != NULL) {
            cmpContador++;
            free(freqs[i]);
            freqs[i] = NULL;
        }
    }
    free(freqs);
}