#include "expresion.h"





void evaluar(Arbol arbol)
{
	NodoA **arrOrigin = calloc(arbol.cantidad,sizeof(NodoA*));
	if(!arrOrigin)
	{
		printf("\n NO SE PUDO ASIGNAR EL ARREGLO DE NODOS");
		exit(1);
	}
	int cantidad = 0;
	extraerNodos(arbol.raiz,arrOrigin,&cantidad);
	asignarMemoria(arrOrigin,cantidad,arbol.comparar);
	
	
	exit(1);
	/*
	for(int j = 0;j<i;j++)
	{		
		if((*(char*)arrOrigin[j]->dato)=='^')
			continue;
		if(  *(double**)arrOrigin[j]->dato == NULL )
		{
			*(double**)arrOrigin[j]->dato = calloc(1,sizeof(double));
			printf("\n Captura variable %c: ", (*(char*)arrOrigin[j]->dato)) ;
			inputDouble("",*(double**)arrClon[j]->dato);
		}	
	}
	*/
}

void extraerNodos(NodoA *raiz,NodoA **nodos,int *i)
{	
	if(!raiz)
		return;
	extraerNodos(raiz->izq,nodos,i);
	//imprimir(raiz->dato);
	nodos[*i] = raiz;
	(*i)++;
	extraerNodos(raiz->dch,nodos,i);	
}

void asignarMemoria(NodoA **original,int cantidad,int (*comparar)(void*,void*))
{
	
	printf("\n INICIALIZANDO INDICES %d",cantidad);
	int *indices = calloc(cantidad,sizeof(int));	
	if(!indices)
	{
		printf("\n NO SE PUDO ASIGNAR EL ARREGLO DE INDICES");
		exit(1);
	}	
	for(int i = 0;i<cantidad;i++)
	{	
		if(indices[i] !=-1)
			continue;			
		if(   ((Variable*)(original[i]->dato))->c=='^')
		{
			((Variable*)(original[i]->dato))->v = NULL;
			continue;		
		}			
		for(int j = i;j<cantidad;j++)
		{
			if( comparar(original[i]->dato,original[j]->dato)==0)				
				indices[j] = i;
		}
		double **ptr = calloc(1,sizeof(double*));		
		for(int j = 0;j<cantidad;j++)
		{
			if(indices[j] ==i)
				((Variable*)(original[j]->dato))->v  = ptr;
		}		
	}
}
