#include <stdio.h>
#include <stdlib.h>
#include "mediane.h"

void fusion(int tab[], int* G , int sizeGauche, int* D, int sizeDroite) {

  int i, j, k;
  // i pour l'index du tableau de gauche G
  // j pour l'index du tableau de droite D
  // k pour l'index du tableau fusionné
  i = 0; j = 0; k = 0;

  while (i < sizeGauche && j < sizeDroite) {
    if(G[i] < D[j]) tab[k++] = G[i++];
    else tab[k++] = D[j++];
  }
  while (i < sizeGauche) tab[k++] = G[i++];
  while (j < sizeDroite) tab[k++] = D[j++];


}

void fusionSort(int tab[], int size) {

  int mid, i, *G, *D;
  if (size < 2) return;
  mid = size/2;

  G = (int*)malloc(mid*sizeof(int));
  D = (int*)malloc((size-mid)*sizeof(int));

  // Creation du tableau de gauche;
  for (i = 0; i<mid; i++)
    G[i] = tab[i];
  // Creation du tableau de droite;
  for (i = mid; i < size; i++)
    D[i-mid] = tab[i];

  fusionSort(G, mid);
  fusionSort(D, size-mid);
  fusion(tab, G, mid, D, size-mid);
  free(G);
  free(D);

}

double mediane(int tab[], int size) {

  /*
   * Tri un tableau et renvoie la médiane de ce tableau
   */
  fusionSort(tab, size);

  double mediane = 0;
  
  if(size%2 == 0) { //Si size est pair
      mediane = (((double)tab[size/2])+((double)tab[(size/2)-1]))/2.0;
  }
  else {
    mediane = tab[size/2];
  }
  return mediane;
}
