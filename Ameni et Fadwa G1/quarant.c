#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quarantprim.h"
#include "QTRPRIM.h"
//
//
void elemqtrlire (elemqtr *e)
{
    int x,i;
    fflush(stdin);
    do
    {printf("donner le nom \n");
    fgets((*e)->nom,15,stdin);}
    while(!verif((*e)->nom));
    do
    {printf("le prenom du patient\n");
    fflush(stdin);
    fgets((*e)->prenom,15,stdin);}
     while(!verif((*e)->prenom));
     do
    {printf("l'adresse du patient\n");
    gets((*e)->adr);}
     while(!verif((*e)->adr));
    printf("l'age\n");
    scanf("%i",&((*e)->age));
    printf("le numero du patient\n");
    scanf("%i",&((*e)->num));
    //
    listemaladies l=listemaladiescreer();
 listepersonnes p=listepersonnescreer();
 listelieux ll=listelieuxcreer();
    printf("combient de maladies chroniques souffre cet patient\n");
    scanf("%i",&x);
    if (x>0)
    {

    for (i=0;i<x;i++)
    {

        elemch elt=elemchcreer();
        char *ch;
        do
        {printf("donner les maladies chroniques du patient\n");
        scanf("%s",&elt->ch);}
         while(!verif((*e)->nom));
        inserermaladies(l,elt,i+1);
    }
    (*e)->maladies=l;
    }
printf("combient de personnes en contact avec ce patient\n");
    scanf("%i",&x);
    if (x>0)
    {

    for (i=0;i<x;i++)
    {

        elemch elt=elemchcreer();
        char *ch;
        do
        {printf("donner les personnes en contact avec ce  patient\n");
        scanf("%s",&elt->ch);}
         while(!verif((*e)->nom));
        insererpersonnes(p,elt,i+1);

    }
(*e)->personnes=p;
    }
    printf("combient de lieux avez vous visite \n");
    scanf("%i",&x);
    if (x>0)
    {

    for (i=0;i<x;i++)
    {

        elemch elt=elemchcreer();
        char *ch;
        do
        {printf("donner les lieux visites \n");
        scanf("%s",&elt->ch);}
         while(!verif((*e)->nom));
        insererlieux(ll,elt,i+1);

    }
(*e)->lieuxvisites=ll;
    }
    printf("la contamination est-t-elle introduite? 1 si oui 0 sinon \n");
    scanf("%i",&((*e)->contamination));
//
printf("la provenance : 1 si vous venez d'ailleurs 0 sinon \n");
    scanf("%i",&((*e)->provenance));
    //
    time_t now;
int jours,mois,an;
   //
    time(&now);
  // Convertir au format heure locale
  struct tm *local = localtime(&now);
  jours = local->tm_mday;
  mois = local->tm_mon + 1;
  an = local->tm_year + 1900;
  (*e)->jour=jours;
 (*e)->mois=mois;
 Color (12,15);
   printf("La date : %02d/%02d\n", jours, mois);
   Color (0,15);

}
//

elemqtr elemqtrcreer(void)
{
    elemqtr m;
    m=(elemqtr)malloc(sizeof(structqtr));
    return (m);
}

void elemqtrdetruire(elemqtr e)
{
    free(e);
}

void elemqtraffecter (elemqtr *e1,elemqtr e2)
{
    *e1=e2;
}
int elemqtrcomparer(elemqtr elt1,elemqtr elt2)
{
    return (elt1-elt2);
}

void elemqtrafficher(elemqtr e )
{

    printf("nom                           :%s\n", e->nom);
    printf("prenom                        :%s\n", e->prenom);
    printf("adresse                       :%s\n", e->adr);
    printf("age                           :%i\n", e->age);
    printf("contamination                 :%i\n", e->contamination);
    printf("provenance                    :%i\n",e->provenance);
    printf("date du debut du confinement  :%i/%i\n",e->jour,e->mois);
listepersonnesafficher(e->personnes);
listemaladiesafficher(e->maladies);
listelieuxafficher(e->lieuxvisites);


}

//
//
//
elemch elemchcreer(void)
{
    elemch l;
    l=(elemch)malloc(sizeof (structch));
    return (l);
}

void elemchaffecter (elemch*elt1,elemch elt2)
{
    *elt1=elt2;
}
void elemchafficher(elemch k)
{
    printf ("%s \n ", k->ch);

}
int elemchcomparer(elemch elt1,elemch elt2)
{
    return (elt1-elt2);
}

//
//
//
