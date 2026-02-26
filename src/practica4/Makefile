cflags = -Wall -Werror -std=c99 -O2
dflags = -Wall -Werror -std=c99 -g
includes = -I ../iostring -I ../structures/nodos -I ../structures/pila
libs = ../../lib -liostring -lLista -lListaDoble -lPila 
source = $(wildcard *.c) 
output = ../../bin/practica4

build :
	gcc $(cflags) $(source) -o $(output) $(includes) -L $(libs)
	@echo "Compilo Exitosamente!!!"
rebuild:
	make -C ..\iostring
	make -C ..\structures\nodos
	make -C ..\structures\cola
	gcc $(cflags) $(source) -o $(output) $(includes) -L $(libs)
	@echo "Compilo Exitosamente!!!"