
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <time.h>
#include <iostring.h>
#include <arbol.h>

typedef struct
{
	char c;
	double **v;
}Variable;


Variable* crearVariable(char c);



void abortar(void);
int* crearEntero(int);
int compararEntero(void*,void*);
void imprimirEntero(void*);
void imprimirNodo(void*);
void imprimirResultado(Resultado resultado);

void asignarMemoria(NodoA **original,NodoA **valores,int cantidad,int (*comparar)(void*,void*));

char* crearChar(char);
int compararChar(void*,void*);
void imprimirChar(void*);

void ordenIterativo(NodoA *raiz,void (*imprimir)(void*));

void equilibrar(Arbol *arbol);
void extraerDatos(NodoA *raiz,void **datos,int *i);
void generarArbol(Arbol *arbol,void **datos,int longitud);

void clonarNodos(NodoA *raizO,NodoA** raizC);
Arbol clonar(Arbol arbol);

void extraerNodos(NodoA *raiz,NodoA **nodos,int *i);
void evaluar(Arbol arbol);
void imprimirDoubleDouble(void *);
int main(void)
{
	Arbol arbol;
	arbol.raiz = NULL;
	arbol.cantidad = 3;
	arbol.imprimir = &imprimirChar;
	arbol.comparar = &compararChar;
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

Variable* crearVariable(char c)
{
	Variable* nuevo=calloc(1,sizeof(Variable));
	nuevo->c=c;
	return nuevo;
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


void asignarMemoria(NodoA **original,NodoA **valores,int cantidad,int (*comparar)(void*,void*))
{
	
	printf("\n INICIALIZANDO INDICES %d",cantidad);
	char *indices = NULL,*aux=NULL;	
	while(!aux)
	{
		aux = realloc(indices,cantidad*sizeof(char));
		printf("No se pudo asignar memoria");
	}
	indices = aux;
	printf("\n INDICES INICIALIZADOS");
	for(int k = 0;k<cantidad;k++)
		indices[k] =-1;
	for(int j = 0;j<cantidad;j++)
	{	
		if(indices[j] !=-1)
			continue;			
		if((*(char*)original[j]->dato)=='^')
		{
			valores[j]->dato = NULL;
			continue;		
		}	
		
		for(int k = j;k<cantidad;k++)
		{
			if( comparar(original[j]->dato,original[k]->dato)==0)				
				indices[k] = j;
		}
		double **ptr = calloc(1,sizeof(double*));		
		for(int k = 0;k<cantidad;k++)
		{
			if(indices[k] ==j)
			{
				valores[k]->dato = ptr;
				printf("\n ASIGNADO");
			}
		}		
	}
}

void evaluar(Arbol arbol)
{
	NodoA **arrOrigin = calloc(arbol.cantidad,sizeof(NodoA*));
	int cantidad = 0;
	extraerNodos(arbol.raiz,arrOrigin,&cantidad);
	
	int *indices = malloc( cantidad * sizeof(double));
	printf("adASD");
	for(int k = 0;k<cantidad;k++)
		indices[k] =-1;
	printf("\n MEMORIA ASIGNADA");
	abort();
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


void clonarNodos(NodoA *raizO,NodoA** raizC)
{
	if(!raizO)
		return;
	*raizC = crearNodoA( raizO->dato );
	clonarNodos(raizO->izq, &((*raizC)->izq) );
	clonarNodos(raizO->dch, &((*raizC)->dch) );	
}



Arbol clonar(Arbol arbol)
{
	Arbol clon = {NULL,arbol.cantidad,arbol.imprimir,arbol.comparar,arbol.liberar};
	if(!arbol.raiz)
		return clon;
	clonarNodos(arbol.raiz,&clon.raiz);
	return clon;
	
}


char* crearChar(char c)
{
	char *nuevo = calloc(1,sizeof(char));
	*nuevo = c;
	return nuevo;
	
}
int compararChar(void *a,void *b)
{
	char aa = ((Variable*)a)->c;
	char bb = ((Variable*)b)->c;
	if( aa ==  bb )
		return 0;
	else if( aa <  bb )
		return -1;
	else 
		return 1;
	
}





void imprimirChar(void *a)
{
	printf("%c",((Variable*)a)->c);
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


void equilibrar(Arbol *arbol)
{
	if(!arbol->raiz)
		return;
	void **datos = (void**) calloc(arbol->cantidad,sizeof(void*));
	int i = 0;
	extraerDatos(arbol->raiz,datos,&i);
	vaciarArbol(arbol);
	generarArbol(arbol,datos,i);
	free(datos);
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


void extraerDatos(NodoA *raiz,void **datos,int *i)
{	
	if(!raiz)
		return;
	extraerDatos(raiz->izq,datos,i);
	//imprimir(raiz->dato);
	datos[*i] = raiz->dato;
	(*i)++;
	extraerDatos(raiz->dch,datos,i);	
}

void generarArbol(Arbol *arbol,void **datos,int longitud)
{
	if(longitud <= 0)
		return;
	int mitad = longitud/2;
	//INSERTAR MITAD
	insertarArbol(arbol,datos[mitad]);
	//IZQUIERDA
	generarArbol(arbol,datos,mitad);
	//DERECHA
	generarArbol(arbol,datos+mitad+1,longitud-1-mitad);
	
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

void imprimirNodo(void *a)
{
	NodoA *aa=a;
	imprimirEntero(aa->dato);
}

