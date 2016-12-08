struct model_lifo {
	int val;
	struct model_lifo *suivant;
};
typedef struct model_lifo ELEMLIFO; 

typedef ELEMLIFO *LIFO;
