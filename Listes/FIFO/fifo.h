struct model_elem {
	int val;
	struct model_elem *suivant;
};
typedef struct model_elem ELEMLIST;

struct model_fifo {
	int nbElem;
	ELEMLIST *premier;
};
typedef struct model_fifo FIFO;

FIFO* init_fifo();

void display_fifo(FIFO*);

void add_element(FIFO*, int);

int remove_element(FIFO*);
