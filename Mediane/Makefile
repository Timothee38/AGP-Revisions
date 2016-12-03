CC = gcc

all: main.o mediane.o
	$(CC) main.o mediane.o -o Mediane

main.o: main.c mediane.h
	$(CC) -c main.c -o main.o

mediane.o: mediane.c mediane.h
	$(CC) -c mediane.c -o mediane.o

clean:
	rm -rf Mediane *.o
