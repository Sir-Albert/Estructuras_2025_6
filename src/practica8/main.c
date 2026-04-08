
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <iostring.h>
#include <heap.h>

int* crearEntero(int);
int compararEntero(void*,void*);
void imprimirEntero(void*);


int main(void)
{
	Heap heap = crearHeap(HEAP_MIN,compararEntero,imprimirEntero);
	printf("\n INICIO");
	insertarHeap(&heap, crearEntero(11));
	insertarHeap(&heap, crearEntero(10));
	insertarHeap(&heap, crearEntero(9));
	insertarHeap(&heap, crearEntero(8));
	insertarHeap(&heap, crearEntero(7));
	insertarHeap(&heap, crearEntero(6));
	insertarHeap(&heap, crearEntero(3));
	
	imprimirHeap(heap);
	heapify(&heap);
	imprimirHeap(heap);
	heap.tipo = HEAP_MAX;
	heapify(&heap);
	imprimirHeap(heap);


	printf("\n\n FIN DE PROGRAMA\n");
	
	
	return 0;
}



int* crearEntero(int dato)
{
	int *nuevo = malloc(sizeof(int));
	*nuevo = dato;
	return nuevo;
}

int compararEntero(void*a,void*b)
{
	int *aa = a,*bb=b;
	if(*aa==*bb)return 0;
	else if(*aa<*bb)return -1;
	else return 1;
}

void imprimirEntero(void *a)
{
	int *aa=a;
	printf("%d",*aa);
}