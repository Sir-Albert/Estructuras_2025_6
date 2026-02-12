#include "listadoble.h"



void insertarFinalD(ListaD *lista,void *dato)
{
	NodoD *nuevo = crearNodoD(dato);
	//LISTA VACIA
	if(!lista->inicio)
	{
		lista->inicio = lista->fin = nuevo;
	}
	//LISTA NO VACIA
	else
	{
		lista->fin->sig = nuevo;
		nuevo->ant = lista->fin;
		lista->fin = nuevo;
	}
	lista->cant++;
}

void imprimirListaDIF(ListaD lista)
{
	printf("\n [%d] LISTA:",lista.cant);
	if(!lista.inicio)
	{
		printf("VACIA");
		return;
	}
	for(NodoD *aux = lista.inicio; aux!=NULL;  aux=aux->sig )
	{
		printf("\n");
		lista.imprimir( aux->dato);
	}	
}

void imprimirListaDFI(ListaD lista)
{
	printf("\n [%d] LISTA:",lista.cant);
	if(!lista.inicio)
	{
		printf("VACIA");
		return;
	}
	for(NodoD *aux = lista.fin; aux!=NULL;  aux=aux->ant )
	{
		printf("\n");
		lista.imprimir( aux->dato);
	}
	
}


