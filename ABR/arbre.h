typedef struct cell { 
  int val;
  struct cell *fDroit;
  struct cell *fGauche;
} CELL;

typedef CELL* ARBRE;
