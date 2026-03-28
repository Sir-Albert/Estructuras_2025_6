#include "variable.h"




Variable* crearVariable(char c)
{
	Variable* nuevo=calloc(1,sizeof(Variable));
	nuevo->c=c;
	return nuevo;
}




int compararVariable(void *a,void *b)
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





void imprimirVariable(void *a)
{
	printf("%c",((Variable*)a)->c);
}