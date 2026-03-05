#include <stdio.h>
#include <stdlib.h>
#include <pila.h>
#include <iostring.h>
#include "Laberinto.h"




int main(void)
{
    Laberinto lab = crear_laberinto();
	Coordenada *punto;
	//Movimientos mov;
	Coordenada origen = {1,1}; 
	Coordenada destino = {25,24};
	unsigned int nuevasCoor = 0;	
	inputEnteroSinSigno("\n Nuevas coordenadas? (1:SI 0:NO) : ",&nuevasCoor);
	if(nuevasCoor)
	{
		inputEntero("\n Captura Origen X: ",&origen.x);
		inputEntero(" Captura Origen Y: ",&origen.y);
		inputEntero("\n Captura Destino X: ",&destino.x);
		inputEntero(" Captura Destino Y: ",&destino.y);
	}
	setOrigen(lab,origen);
	setDestino(lab,destino);
	imprimirLab(lab);
	Pila pila = {NULL,0,-1,imprimirCoordenada,free};
	//PUSH INICIAL DEL ORIGEN
	punto = crearCoordenada(origen.x,origen.y);
	pushDato(&pila,punto);
	
	//CICLO
	/*
	while( !pilaVacia(pila))
	{
		punto = peekPila(pila);
		mov = movimientosPosibles(lab,*punto);		
		//REGRESAR
		
		if(bloqueado(mov))
		{
			free( popDato(&pila) );
		}
		
		//MOVERTE
	}
	*/	
	

	imprimirLab(lab);
	liberarLaberinto(lab);
    printf("\n\n FIN DE PROGRAMA\n\n");
    return 0;
}


