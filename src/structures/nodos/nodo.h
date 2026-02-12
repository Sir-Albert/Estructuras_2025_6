#ifndef NODO_H
#define NODO_H

#include <stdlib.h>

typedef struct nodo
{
	void *dato;
	void *dato2;
	struct nodo *sig;
	
}Nodo;

Nodo* crearNodo(void*);

#endif