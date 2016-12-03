#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

ARBRE creerABR(int val, ARBRE gauche, ARBRE droit) {

  ARBRE tree = (ARBRE)malloc(sizeof(CELL));

  tree->val = val;
  tree->fGauche = gauche;
  tree->fDroit = droit;

  return tree;

}

void detruitABR(ARBRE root) {
  if(root->fGauche) detruitABR(root->fGauche);
  if(root->fDroit) detruitABR(root->fDroit);
  free(root);
}

void displayABR(ARBRE root, int profondeur) {

  int i;
    for (i = 0; i < profondeur; i++) {
      fputs("|---- ", stdout);
    }
  printf("%d \n", root->val);
  if (root->fGauche) displayABR(root->fGauche, profondeur+1);
  if (root->fDroit) displayABR(root->fDroit, profondeur+1);

}

void insererABR(ARBRE* root, int val) {
  if(val > (*root)->val) {
    if((*root)->fDroit)
      insererABR(&((*root)->fDroit), val);
    else { 
      ARBRE newTree = creerABR(val, NULL, NULL);
      (*root)->fDroit = newTree;
    } 
  }
  else {
    if((*root)->fGauche) insererABR(&((*root)->fGauche), val);
    else {
      ARBRE newTree = creerABR(val, NULL, NULL);
      (*root)->fGauche = newTree;
    }
  }
}

void main() {

  ARBRE arbreFG = creerABR(2, NULL, NULL);
  ARBRE arbreFD = creerABR(15, NULL, NULL);
  ARBRE root = creerABR(8, arbreFG, arbreFD);
  insererABR(&root, 18);
  insererABR(&root,13);
  insererABR(&root, 1);
  displayABR(root, 0);
  detruitABR(root);
}
