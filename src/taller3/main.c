
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <time.h>
#include <iostring.h>
#include <arbol.h>

int* crearEntero(int);
int compararEntero(void*,void*);
void imprimirEntero(void*);
void imprimirResultado(Resultado resultado);

void imprimirMitades(int *arreglo,int longitud);
void myprintf(char *msg,char *formato,...);

int main(void)
{
	Arbol arbol;
	arbol.raiz = NULL;
	arbol.cantidad = 0;
	arbol.imprimir = &imprimirEntero;
	arbol.comparar = &compararEntero;
	arbol.liberar = &free;
	
	insertarArbol(&arbol, crearEntero(9));
	insertarArbol(&arbol, crearEntero(8));
	insertarArbol(&arbol, crearEntero(11));
	insertarArbol(&arbol, crearEntero(7));
	insertarArbol(&arbol, crearEntero(6));
	
	printf("\n");
	imprimirArbol(arbol);		
	
	int valor =11;
	void *dato = buscarEnArbol(arbol,&valor);
	if(dato)
		printf("\n ENCONTRADO");
	else
		printf("\n NO ENCONTRADO");
	
	imprimirResultado(buscarNodoEnArbol(arbol,&valor));
	
	eliminarArbol(&arbol);
	printf("\n\n FIN DE PROGRAMA\n");
	
	
	int arreglo[9] = {1,4,5,6,7,8,9,10,11};
	imprimirMitades(arreglo,9);
	
	
	return 0;
}


void imprimirMitades(int *arreglo,int longitud)
{
	if(longitud <= 0)
		return;
	int mitad = longitud/2;
	printf(" %d", arreglo[mitad]);
	//IZQUIERDA
	imprimirMitades(arreglo,mitad);
	//DERECHA
	imprimirMitades(arreglo+mitad+1,longitud-1-mitad);	
}


void imprimirResultado(Resultado resultado)
{
	if(resultado.nodo)
	{
		if(resultado.padre)
		{
			printf("\n PADRE: ");
			imprimirEntero(resultado.padre->dato);
			printf("\n RAMA: %s",
			(resultado.rama) ? "DERECHA":"IZQUIERDA");
		}
		printf("\n Nodo: ");
		imprimirEntero(resultado.nodo->dato);
	}
	else
		printf("\n NODO NO ENCONTRADO");
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


void myprintf(char* msg,char *formato,...)
{
	va_list args;
    va_start(args, formato);
	printf("\n %s ",msg);
	char *ptr = formato;
	while(*ptr!='\0')
	{
		switch(*ptr)
		{
			case 'd':
				printf("%d ",va_arg(args, int));
				break;
			case 'c':
				printf("%c ",va_arg(args, int));				
				break;
			case 'f':
				printf("%f ",va_arg(args, double));				
				break;
			case 'x':
				printf("%x ",va_arg(args, Arbol*));				
				break;
		}
		ptr++;
	}
	va_end(args);
}
