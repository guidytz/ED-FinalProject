#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "RN.h"
#include <stdio.h>

extern RNtree *t;
extern long cmpContador;

int frequencia(char *palavra);

void contador(int k1, int k2, FILE *f);

#endif  // __GLOBALS_H__