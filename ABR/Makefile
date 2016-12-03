CC = gcc

all: arbre.o
	$(CC) arbre.o -o Arbre

arbre.o: arbre.c arbre.h
	$(CC) -c arbre.c -o arbre.o

clean:
	rm -rf Arbre *.o
