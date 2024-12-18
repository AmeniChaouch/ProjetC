#ifndef _LSTTAB_h
#define _LSTTAB_h
#include "patientprim.h"
#define long_max 100

//la liste contigue

typedef struct {
elementpt patients[long_max];
int lg;
}ptlist,*LISTE;

#endif // _LSTTAB_h
