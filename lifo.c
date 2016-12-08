#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

/* AKA LA PILE */

LIFO init_lifo() {
	LIFO lifo = (LIFO)malloc(sizeof(ELEMLIFO));
	
	lifo->val=0;
	lifo->suivant=NULL;
	
	return lifo;
}

void add_element(LIFO lifo, int val) { 
	LIFO newElem = (LIFO)malloc(sizeof(ELEMLIFO));
	
	newElem->val = val;
	newElem->suivant = lifo->suivant;
	
	lifo->suivant = newElem;
}

int remove_element(LIFO lifo) {
	ELEMLIFO* tmp = lifo->suivant;
	lifo->suivant=tmp->suivant;
	int ret = tmp->val;
	free(tmp);
	return ret;
}

void display_lifo(LIFO lifo) {
	
	ELEMLIFO *visitor = lifo->suivant;
	
	while(visitor!=NULL) {
			printf("|%d", visitor->val);
			visitor=visitor->suivant;
	}
	printf("|\n");
}

void main() {
	LIFO lifo = init_lifo();
	add_element(lifo, 5);
	add_element(lifo, 8);
	add_element(lifo, 6);
	add_element(lifo, 48);
	display_lifo(lifo);
	printf("Removing element: %d\n",remove_element(lifo));
	display_lifo(lifo);
}
