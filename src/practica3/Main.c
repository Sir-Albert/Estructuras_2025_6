#include <stdio.h>
#include <iostring.h>
#include <pila.h>


#define MAX 100

int palindromo(char *cadena);
int verificarParentesis(char *cadena);

int main(void)
{
	char *cadena = NULL;
	inputCadenaDinamica("\n Captura expresion: ",&cadena,MAX);
	printf("\n Expresion: %s",cadena);
	printf("\n Es palindromo: %s", palindromo(cadena) ? "SI" : "NO");
	printf("\n Parentesis correctos : %s", verificarParentesis(cadena) ? "SI" : "NO");
	return 0;
}



int palindromo(char *cadena)
{
	//Pila pila = {NULL,0,-1,NULL,NULL};
	return 0;
}

int verificarParentesis(char *cadena)
{
	//Pila pila = {NULL,0,-1,NULL,NULL};	
	return 0;	
}