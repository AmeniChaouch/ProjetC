#ifndef _dons_hop_prim_h
#define _dons_hop_prim_h
#include "dons_hop.h"


STRUCT structurecreer(void);
void structuredetruire (STRUCT);
void structurelire (STRUCT*);
void structureafficher(elemnt);
int structurecomparer (STRUCT,STRUCT);
void affiche_besoin(STRUCT);
void ajout_besoin(needs *);
void ajout_don (donn *d);
void structureaffecterb (STRUCT *, STRUCT);


TAB1 tab1creer (void);
void tab1detruire (TAB1);
int estvidetab1 (TAB1);
int estsatureetab1(TAB1);
int tab1taille (TAB1);
needs recupererneed (TAB1,int);
int inserertab1 (TAB1,needs,int);
void tab1afficher (TAB1);



TAB2 tab2creer (void);
void tab2detruire (TAB2);
int estvidetab2 (TAB2);
int estsatureetab2(TAB2);
int tab2taille (TAB2);
donnations recupererdon (TAB2,int);
int inserertab2 (TAB2,donnations,int);
void tab2afficher (TAB2);


#endif // _dons_hop_prim_h
