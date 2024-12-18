#ifndef HOPITAUXPRIM_H_INCLUDED
#define HOPITAUXPRIM_H_INCLUDED
#include"hopitauxsdd.h"

void elemhopafficher (elemhop e);
int elemhopcomparer(elemhop elt1,elemhop elt2);
void elemhopcopier (elemhop* e1,elemhop e2);
void elemhopaffecter (elemhop * elt1,elemhop elt2);
void elemspecaffecter(elemspec*elt1,elemspec elt2);
elemspec elemspeccreer(void);
void elemspecafficher (elemspec e);
elemhop elemhopcreer(void);
void elemhopdetruire(elemhop l);


#endif // HOPITAUXPRIM_H_INCLUDED

