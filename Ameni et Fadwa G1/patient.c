#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patientsdd.h"
#include "HOPPRIM.h"
#include "LSTHOP.h"
#include "hopitauxprim.h"

//primitives de l element patient

elementpt elementcreer(void)
{
    elementpt l;
    l=(elementpt)malloc(sizeof (ptstruct));
    return (l);
}

void elementdetruire(elementpt l)
{
    free(l);
}

void elementaffecter (elementpt*elt1,elementpt elt2)
{
    *elt1=elt2;
}

int elementcomparer(elementpt elt1,elementpt elt2)
{
    return (elt1-elt2);
}

void elementafficher(elementpt e )
{
    int i;
    printf("le patient %s %s,son adresse %s, d'age %i,son numero %i,son genre %c\n", e->nom,e->prenom,e->adresse,e->age,e->num,e->genre);
    printf("la contamination est-t-elle introduite? %i \n son etat est %s\n ",e->conta_introd,e->etat);
    listemafficher(e->maladie_chro);
    listepafficher(e->personnes_contact);
}

void elementcopier (elementpt* e1,elementpt e2)
{
 strcpy((*e1)->nom,e2->nom);
 strcpy((*e1)->prenom,e2->prenom);
 strcpy((*e1)->adresse,e2->adresse);
 (*e1)->age = e2->age;

}

void elementlire (elementpt *e)
{
    lsthop b=lsthopcreer();
    b=inithop();
    int x,i;
    do
    {fflush(stdin);
    printf("donner le nom \n");
    fgets((*e)->nom,15,stdin);}
     while(!verif((*e)->nom));
     do
    {printf("le prenom du patient\n");
    fflush(stdin);
    fgets((*e)->prenom,15,stdin);}
     while(!verif((*e)->prenom));
     do
    {printf("l'adresse du patient\n");
    gets((*e)->adresse);}
     while(!verif((*e)->adresse));
    printf("l'age\n");
    scanf("%i",&((*e)->age));
    printf("le numero du patient\n");
    scanf("%i",&((*e)->num));
    //
    listem l=listemcreer();
 listep p=listepcreer();
    printf("combient de maladies chroniques souffre cet patient\n");
    scanf("%i",&x);
    if (x>0)
    {

    for (i=0;i<x;i++)
    {

        elementm elt=elementmcreer();
        char *ch;
        printf("donner les maladies chroniques du patient\n");
        scanf("%s",&elt->m);
        insererm(l,elt,i+1);

    }
    (*e)->maladie_chro=l;
    }
printf("combient de personnes en contact avec ce patient\n");
    scanf("%i",&x);
    if (x>0)
    {

    for (i=0;i<x;i++)
    {

        elementm elt=elementmcreer();
        char *ch;
        printf("donner les personnes en contact avec ce  patient\n");
        scanf("%s",&elt->m);
        insererm(p,elt,i+1);

    }
(*e)->personnes_contact=p;
    }


    printf("la contamination est-t-elle introduite? 1 si oui 0 sinon \n");
    scanf("%i",&((*e)->conta_introd));
    printf("le genre de cet patient: m si masculin f sinon\n");
     fflush(stdin);
    scanf("%c",&((*e)->genre));
    fflush(stdin);
    printf("l'etat du patient: Normale ,Critique ou Guerie\n");
    fgets((*e)->etat,10,stdin);

    printf("Avez-vous des besoins en salles specifiques ou un lit de reanimation ou bien un lit normale ?\n");
    printf("5:lit normale 6:lit de reanimation 7:salles specifiques ");
    scanf("%i",&x);
    if (x == 7)
    {
        printf("verifions les disponibilites des salles, veuillez-vous choisir:\n 1:salle de chirurgie  2:salle de cardiologie  3:salle de radiologie  4:salle de dialyse");
        scanf("%i",&x);
    }
    printf("\n\n\n");
recherche(b,(*e)->adresse,x);


}

//les fonctions de elementm:
elementm elementmcreer(void)
{
    elementm m;
    m=(elementm)malloc(sizeof(elemm));
    return (m);
}

void elementmafficher(elementm k)
{
    printf ("%s \n ",k );
}

void elementmdetruire(elementm e)
{
    free(e);
}

void elementmaffecter (elementm *e1,elementm e2)
{
    *e1=e2;
}

