#include <stdio.h>
#include <stdlib.h>
#include "hopitauxprim.h"
//

//primitives de l'element salles specifique
elemspecaffecter(elemspec*elt1,elemspec elt2)
{
    *elt1 = elt2;
}

elemspec elemspeccreer(void)
{
    elemspec l;
    l=(elemspec)malloc(sizeof (structspec));
    return (l);
}

void elemspecafficher (elemspec e)
{
    printf("  %s   ", e->specialite);
    if (e->disponibilite == 0)
    printf("   non disponible \n                          ");
    else printf("\n                          ");
    printf("\n");
}

//
//
//primitives de l element hopital

elemhop elemhopcreer(void)
{
    elemhop l;
    l=(elemhop)malloc(sizeof (structhop));
    return (l);
}

void elemhopdetruire(elemhop l)
{
    free(l);
}

void elemhopaffecter (elemhop * elt1,elemhop elt2)
{
    *elt1=elt2;
}

int elemhopcomparer(elemhop elt1,elemhop elt2)
{
    return (elt1-elt2);
}

void elemhopafficher(elemhop e )
{
    printf("L'hopital                :  %s\n",e->nom);
    printf("adresse                  :  %s\n",e->adr);
    printf("numero d'urgence         :  %d \n",e->numtel);
    printf("lit normaux              :  %i \nlit de reanimation       :  %i \n",e->litnormal,e->litrea);
    printf("nb medecins              :  %i \nagents paramedicaux      :  %i\n",e->medecins,e->paramedicaux);
    listespecafficher(e->salles);
    //
}

void elemhopcopier (elemhop* e1,elemhop e2)
{
 strcpy((*e1)->nom,e2->nom);
 strcpy((*e1)->adr,e2->adr);
 (*e1)->litnormal = e2->litnormal;
 (*e1)->litrea = e2->litrea;

}

void elemhoplire (elemhop* e,structspec s)
{
lstspec q=lstspeccreer();
do
{printf("entrez le nom de l'hopital\n");
fflush(stdin);
fgets((*e)->nom,15,stdin);}
 while(!verif((*e)->nom));

printf("son numero\n");
scanf("%i",&(*e)->num);
do
{printf("son adresse\n");
fflush(stdin);
fgets((*e)->adr,10,stdin);}
 while(!verif((*e)->adr));
printf("combient de lits de reanimation comprend cet hopital\n");
scanf("%i",&(*e)->litrea);
printf("combient de lits normale comprend cet hopital\n");
scanf("%i",&(*e)->litnormal);
printf("le nombre de medecins\n");
scanf("%i",&(*e)->medecins);
printf("l'equipe paramedicale\n");
scanf("%i",&(*e)->paramedicaux);
printf("le numero de telephone\n");
scanf("%i",&(*e)->numtel);
q=listespeclire(s);
(*e)->salles=q;
//listespecafficher((*e)->salles);
}

