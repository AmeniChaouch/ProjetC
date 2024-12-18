#ifndef _LSTPRIM_h
#define _LSTPRIM_h
#include "patientprim.h"
#include "patientsdd.h"

LISTE listecreer (void);
void listeDetruire (LISTE);
int estvide (LISTE);
int estsaturee(LISTE);
int listetaille(LISTE);
elementpt recuperer (LISTE,int);
void supprimer (LISTE);
int inserer(LISTE, elementpt, int);
void listeafficher(LISTE);
LISTE listecopier(LISTE);
int listecomparer(LISTE,LISTE);
void listechercherpatient (LISTE l);
void listechercherage(LISTE);

//primitives de la liste "personnes"
listep listepcreer(void);
void listepafficher(listep);
void listepdetruire(listep);

//lprimitives de la liste "maladies"
listem listemcreer(void);
void listemafficher(listem);
void listemdetruire(listem);

#endif // _LSTPRIM_h

