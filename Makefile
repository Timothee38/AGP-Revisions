CC= gcc

fifo: lifo.c
	$(CC) lifo.c -o lifo

clean: 
	rm -rf *.o lifo
