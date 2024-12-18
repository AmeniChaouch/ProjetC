#ifndef QUARANTPRIM_H_INCLUDED
#define QUARANTPRIM_H_INCLUDED
#include "quarantsdd.h"
//
void dateafficher (date d);
//primitives de lelement ch

elemch elemchcreer(void);
void elemchaffecter (elemch*elt1,elemch elt2);
void elemchafficher(elemch k);

//primitives de l'element  quarantaine
elemqtr elemqtrcreer(void);
void elemqtrdetruire(elemqtr e);
void elemqtraffecter (elemqtr *e1,elemqtr e2);
int elemqtrcomparer(elemqtr elt1,elemqtr elt2);
void elemqtrafficher(elemqtr e );
void elemqtrlire (elemqtr *e);

#endif // QUARANTPRIM_H_INCLUDED
