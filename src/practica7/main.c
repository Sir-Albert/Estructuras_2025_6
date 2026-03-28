
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <iostring.h>
#include <arbol.h>
#include "variable.h"
#include "expresion.h"


void abortar(void);
void ordenIterativo(NodoA *raiz,void (*imprimir)(void*));
void imprimirDoubleDouble(void *);

int main(void)
{
	Arbol arbol;
	arbol.raiz = NULL;
	arbol.cantidad = 3;
	arbol.imprimir = &imprimirVariable;
	arbol.comparar = &compararVariable;
	arbol.liberar = &free;
	
	
	/*
	arbol.raiz = crearNodoA(crearChar('^'));	
	arbol.raiz->izq = crearNodoA(crearChar('X'));	
	arbol.raiz->dch = crearNodoA(crearChar('X'));
	*/
	
	arbol.raiz = crearNodoA(crearVariable('^'));	
	arbol.raiz->izq = crearNodoA(crearVariable('X'));	
	arbol.raiz->dch = crearNodoA(crearVariable('^'));	
	arbol.raiz->dch->izq = crearNodoA(crearVariable('X'));	
	arbol.raiz->dch->dch = crearNodoA(crearVariable('X'));	
	
	printf("\n ARBOL\n");
	imprimirArbol(arbol);
	evaluar(arbol);

	
	
	eliminarArbol(&arbol);

	printf("\n\n FIN DE PROGRAMA\n");
	
	
	return 0;
}


void imprimirDoubleDouble(void *ptr)
{
	double **ptrdouble= ptr;	
	if(!ptrdouble)	
	{		
		printf("null ") ;
		return;
	}
	printf("%lf ",**ptrdouble); 
}

void ordenIterativo(NodoA *raiz,void (*imprimir)(void*))
{
	Pila pila = {NULL,0,-1,imprimir,NULL};
	if(!raiz)
		return;
	NodoA* aux = raiz;
	while( aux || !pilaVacia(pila))
	{			
		while(aux)
		{
			pushDato(&pila,aux);	
			aux = aux->izq;
		}		
		aux = popDato(&pila);
		imprimir(aux);		
		printf(" ");		
		aux= aux->dch;
	}	
	vaciarPila(&pila);
}

void abortar(void)
{
	char c = 'e';
	if( (c=getchar()) == 'e')
		exit(0);
}
