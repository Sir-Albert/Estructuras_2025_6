#ifndef EXPRESION_H
#define EXPRESION_H

#include <stdlib.h>
#include <stdio.h>
#include <arbol.h>

#include "variable.h"


void evaluar(Arbol arbol);
void extraerNodos(NodoA *raiz,NodoA **nodos,int *i);
void asignarMemoria(NodoA **original,int cantidad,int (*comparar)(void*,void*));

#endif