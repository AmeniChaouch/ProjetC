#ifndef _LSTPTR_h
#define _LSTPTR_h
#include "elt.h"

typedef struct structnoeud
{
    element info;
    struct structnoeudpd *suivant;
    struct structnoeudpd *precedent;
} structnoeud, *NOEUD;

typedef struct
{
    NOEUD tete;
    NOEUD queue;
    int lg;
}lastruct,*liste;



#endif // _LSTPTR_h
