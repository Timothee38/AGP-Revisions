#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

FIFO* init_fifo() {
	
	FIFO *ret = (FIFO*)malloc(sizeof(FIFO));
	
	ret->nbElem=0;
	ret->premier=NULL;
	
	return ret;	
	
}

void display_fifo(FIFO *fifo) {
	ELEMLIST *visitor;
	
	visitor=fifo->premier;
	while(visitor!=NULL) {
			printf("|%d", visitor->val);
			visitor=visitor->suivant;
	}
	printf("|\n");
}

void add_element(FIFO *fifo, int val) {
	
	ELEMLIST *newElem = (ELEMLIST *)malloc(sizeof(ELEMLIST));
	
	if(newElem == 0) { 
			printf("Add element: plus de place dans la mémoire.\n");
			exit (-1);
	}
	newElem->val = val;
	newElem->suivant=fifo->premier;
	
	fifo->premier=newElem;
	fifo->nbElem=(fifo->nbElem)+1;
	
}

int remove_element(FIFO *fifo) {
		ELEMLIST *visitor, *precedent;
		
		int val;
		
		if(fifo->nbElem == 0) {
			printf("Remove Element: Erreur Fifo vide.\n");
			exit (-1);
		}
		visitor=fifo->premier;
		if (fifo->nbElem == 1) {
			fifo->premier=NULL;
			fifo->nbElem=0;
		}
		else {
			precedent=visitor;
			visitor=visitor->suivant;
			while(visitor->suivant!=NULL) {
				visitor=visitor->suivant;
				precedent=precedent->suivant;
			}
			precedent->suivant=NULL;
			fifo->nbElem=(fifo->nbElem)-1;
		}
		val=visitor->val;
		free(visitor);
		return val;
}


void main() { 
	
	FIFO *myFifo = init_fifo();
	add_element(myFifo, 4);
	add_element(myFifo, 5);
	add_element(myFifo, 6);
	add_element(myFifo, 7);
	add_element(myFifo, 8);
	add_element(myFifo, 9);
	display_fifo(myFifo);
	printf("remove element: %d\n",remove_element(myFifo));
	display_fifo(myFifo);
	
}


