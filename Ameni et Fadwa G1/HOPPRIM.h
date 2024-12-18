#ifndef HOPPRIM_H_INCLUDED
#define HOPPRIM_H_INCLUDED
#include "HOPSDD.h"

lstspec lstspeccreer(void);
int listespecinserer (lstspec l, elemspec e, int pos );
void listespecafficher (lstspec l);
lsthop lsthopcreer(void);
void lsthopafficher (lsthop l);
int lsthopinserer(lsthop l, elemhop e, int pos);
lsthop inithop (void);
int recherche (lsthop,char *,int);


#endif // HOPPRIM_H_INCLUDED

