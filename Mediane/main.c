#include <stdio.h>
#include <stdlib.h>
#include "mediane.h"

void main() {

  int tab[] = {1,2,3,4,5,6};
  int tableau[] = {1, -2, 6, 19, 3 };
  printf("La valeur de médiane du tableau est %f \n", mediane(tableau, 5));
  printf("La valeur de médiane du tableau est %f \n", mediane(tab, 6));

}
