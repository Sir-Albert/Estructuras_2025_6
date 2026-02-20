#include <stdio.h>
#include <iostring.h>
#include <pila.h>


#define MAX 100

int palindromo(char *cadena);
int verificarParentesis(char *cadena);

int main(void)
{
	char *cadena = NULL;
	
	inputCadenaDinamica("\n Captura cadena: ",&cadena,MAX);
	printf(" Es palindromo: %s", palindromo(cadena) ? "SI" : "NO");
	
	inputCadenaDinamica("\n\n Captura expresion: ",&cadena,MAX);
	printf(" Parentesis correctos : %s", verificarParentesis(cadena) ? "SI" : "NO");
	
	free(cadena);
	printf("\n\n FIN DE PROGRAMA");
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