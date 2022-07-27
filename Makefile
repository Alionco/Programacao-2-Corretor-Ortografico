all: ortografia

ortografia: ortografia.c dicionario.c dicionario.h
	gcc -Wall ortografia.c -o ortografia dicionario.c

clean: 
	-rm -f *~ *.o

purge: clean
	-rm -f ortografia
	