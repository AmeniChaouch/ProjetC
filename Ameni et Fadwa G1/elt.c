#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "eltprim.h"


element elementcreer1(void)
{
    element e;
    e=malloc (sizeof(mastruct));
    return(e);
}

void elementafficher1(element e)
{
    printf("%s\n",e->gouvernerat);
}

int elementcomparer1(element e1,element e2)
{
    return (strcmp(e1->gouvernerat,e2->gouvernerat));
}

void elementdetruire1(element e)
{
    free(e);
}

void elementaffecter1(element* e1,element e2)
{
    *e1=e2;
}

