#include "pila.h"

//VERIFICIACION
int pilaVacia(Pila pila)
{
	return pila.cima == NULL && pila.cantidad==0;
}

int pilaLlena(Pila pila)
{
	return pila.cantidad == pila.capacidad;
}

//DATOS
void pushDato(Pila *pila,void *dato)
{
	if(pilaLlena(*pila))
	{
		printf("OVERFLOW");
		return;
	}
	Nodo *nuevaCima = crearNodo(dato);
	nuevaCima->sig = pila->cima;	
	pila->cima = nuevaCima; 
	pila->cantidad++;
}


void* popDato(Pila *pila)
{
	void *dato = NULL;
	if(!pilaVacia(*pila))
	{
		printf("UNDERFLOW");
		return dato;	
	}
	Nodo *cimaVieja = pila->cima;
	pila->cima = pila->cima->sig;	
	dato = cimaVieja->dato;
	free(cimaVieja);
	pila->cantidad--;	
	return dato;
}

//NODOS
void pushNodo(Pila *pila,Nodo *nodo)
{
	if(pilaLlena(*pila))
	{
		printf("OVERFLOW");
		return;
	}
	nodo->sig = pila->cima;	
	pila->cima = nodo; 
	pila->cantidad++;
}

Nodo* popNodo(Pila *pila)
{
	Nodo *cimaVieja = NULL;
	if(!pilaVacia(*pila))
	{
		printf("UNDERFLOW");
		return cimaVieja;	
	}
	cimaVieja = pila->cima;
	pila->cima = pila->cima->sig;	
	pila->cantidad--;	
	cimaVieja->sig = NULL;
	return cimaVieja;
}


//VACIAR/ELIMINAR PILA
void vaciarPila(Pila *pila)
{
	
}
void eliminarPila(Pila *pila)
{
	
}
//IMPRIMIR
void imprimirPila(Pila pila)
{
	
}