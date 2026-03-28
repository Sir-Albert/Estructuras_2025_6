#ifndef VARIABLE_H
#define VARIABLE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	char c;
	double **v;
}Variable;


Variable* crearVariable(char c);
void imprimirVariable(void *a);
int compararVariable(void *a,void *b);


#endif