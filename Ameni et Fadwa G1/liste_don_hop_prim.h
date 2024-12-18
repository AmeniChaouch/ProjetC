#ifndef _liste_don_hop_prim_h
#define _liste_don_hop_prim_h
#include "liste_don_hop.h"
#include "dons_hop.h"

LISTEBESOIN listebcreer(void);
void listebdetruire (LISTEBESOIN);
int estvideb (LISTEBESOIN);
int estsatureeb(LISTEBESOIN);
int listebtaille (LISTEBESOIN);
STRUCT recupererSTRUCT (LISTEBESOIN,int);
int insererb (LISTEBESOIN,STRUCT,int);
int supprimeb (LISTEBESOIN,int);
void listebafficher (LISTEBESOIN);
void liste_ajout_don (LISTEBESOIN);



#endif // _liste_don_hop_prim_h
