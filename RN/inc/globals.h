#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include "RN.h"
#include <stdio.h>

extern RNtree *t;
extern long cmpContador;

/**
 * @brief Conta as frequências de uma palavra aramzanada na estrutura que guarda o texto
 * 
 * @param palavra palavra a ser buscada
 * @return int número de vezes que a palavra informada foi vista no texto
 */
int frequencia(char *palavra);

/**
 * @brief Retorna todas as strings cujas frequências estão entre os limites superior e inferior
 *        informados
 * 
 * @param k1 limite inferior
 * @param k2 limite superior
 * @param f arquivo no qual deseja imprimir as strings e suas frequências
 */
void contador(int k1, int k2, FILE *f);

#endif  // __GLOBALS_H__