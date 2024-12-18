#ifndef _patientprim_h
#define _patientprim_h
#include "patientsdd.h"

//les primitives de elementpt (le la grande liste contigue)
elementpt elementcreer(void);
void elementdetruire(elementpt l);
void elementaffecter (elementpt*elt1,elementpt elt2);
int elementcomparer(elementpt elt1,elementpt elt2);
void elementafficher(elementpt);
void elementcopier (elementpt* e1,elementpt e2);
void elementlire (elementpt*);

//les primitives de elementm (elements qui compose les sous listes)
elementm elementmcreer(void);
void elementmafficher(elementm);
void elementmdetruire(elementm);
void elementmaffecter (elementm*,elementm);

#endif // _patientprim_h

