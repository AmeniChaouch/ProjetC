#ifndef LIEU_H_INCLUDED
#define LIEU_H_INCLUDED
#include "quarantsdd.h"
#include"QTRSDD.h"
#define lg_max 50
typedef struct
{
    char*lieu;
    int qtr;
    char*adr;
    int num;
    int disponibilite;
}structl,*lieu;
//
//
//
typedef struct{
lieu tab[lg_max];
int lg;
}structlistel,*lieux;
//
//
void rotation (lieux l,listeqtr q);
//
elemlieucreer(void);
void elemlieudetruire(lieu e);
void elemlieuaffecter (lieu *e1,lieu e2);
int elemlieucomparer(lieu elt1,lieu elt2);
void elemlieuafficher(lieu e );
//
lieux lieuxcreer(void);
int lieuxinserer (lieux l, lieu e, int pos);
lieu recupererlieu (lieux l,int pos);
lieux initlieux(void);

#endif // LIEU_H_INCLUDED
