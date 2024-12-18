#ifndef QTRPRIM_H_INCLUDED
#define QTRPRIM_H_INCLUDED
#include "QTRSDD.h"
//
listeqtr listeqtrcreer(void);
int insererqtr (listeqtr l, elemqtr e, int pos);
void listeqtrafficher (listeqtr l);
elemqtr recupererqtr (listeqtr l,int pos);
void testcorona(listeqtr);
//
listemaladies listemaladiescreer(void);
int inserermaladies (listemaladies l, elemch e, int pos);
void listemaladiesafficher(listemaladies l);
//
listepersonnes listepersonnescreer(void);
void listepersonnesafficher(listepersonnes l);
int insererpersonnes (listepersonnes l, elemch e, int pos);


#endif // QTRPRIM_H_INCLUDED
