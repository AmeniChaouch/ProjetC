#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "LSTPRIM.h"
#include <string.h>
void ajout (LISTE l)
{
    elementpt e=elementcreer();
    elementlire(&e);
    inserer(l,e,(l->lg+1));

}

//
listem listemcreer(void)
{
    listem L;
    L=(listem) malloc (long_max*sizeof(mstruct));
    if(!L)
    {
           printf("\nProbleme de memoire") ;
    }
(L->lg)=0;
}
void listemafficher(listem l)
{int i;
    printf("les maladies chroniques sont :\n");
    for(i = 1;i <= l->lg;i++)
        elementmafficher(l->maladies[i]);

}
void listemdetruire (listem L)
{
  int i;
for(i = 1;i <= L->lg;i++)
elementmdetruire ( L->maladies [i] );
free(L);
}

int insererm (listem l, elementm e, int pos)
{
    int succee=0,i;
    if (estsaturee(l))
        printf("liste saturee\n");
    else
    {
        if ((pos<1)||(pos>l->lg+1))
            printf("position invalide \n");
        else
        {
            succee=1;
           for(i=l->lg;i>=pos;i--)
                elementaffecter(&(l->maladies[i+1]),l->maladies[i]);
           elementaffecter(&(l->maladies[pos]),e);
           (l->lg)++;
        }
    }
    return succee;
}
//personnes
listep listepcreer(void)
{
    listep l;
    l=(listep)malloc(sizeof(pstruct));
    if (!l)
    {
        printf("probleme de memoire \n");
        exit(0);
    }
    (l->lg)=0;
}
int listeptaille(listep l)
{
    return (l->lg);
}

int insererp(listep l, elementm e, int pos)
{
    int succee=0,i;
    if (estsaturee(l))
        printf("liste saturee\n");
    else
    {
        if ((pos<1)||(pos>l->lg+1))
            printf("position invalide \n");
        else
        {
            succee=1;
           for(i=l->lg;i>=pos;i--)
                elementaffecter(&(l->personnes[i+1]),l->personnes[i]);
           elementaffecter(&(l->personnes[pos]),e);
           (l->lg)++;
        }
    }
    return succee;
}
void listepafficher(listep l)
{int i;
        printf("les personnes en contact sont:\n");
        for(i = 1;i <= l->lg;i++)
        elementmafficher(l->personnes[i]);
        printf("\n");

}
void listepDetruire (listep L)
{
  int i;
for(i = 1;i <= L->lg;i++)
elementmdetruire ( L-> personnes[i] );
free(L);
}
//liste generale
LISTE listecreer(void)
{
    LISTE L;
    L=(LISTE) malloc (long_max*sizeof(ptlist));
    if(!L)
    {
           printf("\nProblème de mémoire") ;
    }
(L->lg)=0;

    return (L);
}
void listeDetruire (LISTE L)
{
  int i;
for(i = 1;i <= L->lg;i++)
elementdetruire ( L-> patients[i] );
free(L);
}
int estsaturee(LISTE l)
{
    return((l->lg)==long_max);
}

int listetaille(LISTE l)
{
    return (l->lg);
}
int estvide (LISTE l)
{
return ((l->lg)==0);
}

elementpt recuperer (LISTE l,int pos)
{
    elementpt elt;
    elt = elementcreer();
    if (l->lg==0)
    printf ("\nListe vide");
    else
    {
if ((pos < 1) || (pos > l->lg))
    {printf ("\nPosition invalide");}
    else
    elt = (l->patients[pos]);
    }
return(elt);
}

void supprimer (LISTE L)
{
    int i,j;
    for(j=1;j<=listetaille(L);j++)
    {
        if ((recuperer(L,j)->etat[0])=='G')
    {elementdetruire(L ->patients[j]);
    for(i=j;i<=(L->lg);i++)
    elementaffecter(&L ->patients[i],L ->patients[i+1]);
    (L->lg)--;
    }}
listeafficher (L);
}

void listeafficher (LISTE l)
{
    int i;
    for(i=1;i<=(l->lg);i++)
        elementafficher(l->patients[i]);
}

LISTE listecopier(LISTE l)
{
    int i;
    LISTE lr;
    lr=listecreer();
    for (i=1;i<=(l->lg);i++)
        elementcopier (&(lr->patients),(l->patients));
return lr;
}

int inserer(LISTE l, elementpt e, int pos)
{
    int succee=0,i;
    if (estsaturee(l))
        printf("liste saturee\n");
    else
    {
        if ((pos<1)||(pos>l->lg+1))
            printf("position invalide \n");
        else
        {
            succee=1;
           for(i=l->lg;i>=pos;i--)
                elementaffecter(&(l->patients[i+1]),l->patients[i]);
           elementaffecter(&(l->patients[pos]),e);
           (l->lg)++;
        }
    }
    return succee;
}

int listecomparer(LISTE l1,LISTE l2)
{
    return (listetaille(l1)==(listetaille(l2)));
}

void listechercher_age (LISTE l)
{int ag,i,test=0;

    printf("Qui sont les patients que vous cherchez?\n");
    printf("Leurs ages\n");
    scanf("%i",&ag);

    for (i=1;i<=listetaille(l);i++)
    {
        if (ag==l->patients[i]->age)
        {test=1;

            elementafficher(recuperer(l,i));

        }

    }
    if (test==0)
    printf("cet age n'existe pas");
}

void listecherche_ad (LISTE l)
{
    int i;
    char ad[10];
    printf("donner l'adresse cherchee\n");
    fflush(stdin);
    fgets(ad,15,stdin);

    for (i=1;i<=listetaille(l);i++)
    {
         if (((l->patients[i]->adresse[1])==ad[1])&&((l->patients[i]->adresse[2])==ad[2])&&((l->patients[i]->adresse[3])==ad[3]))

            elementafficher(l->patients[i]);


    }
}

void listechercherpatient (LISTE l)
{
     int test=0,  i=1,ag,numero;
char n[50],p[50],a[50];
    printf("le numero du patient\n");
    scanf("%i",&numero);

    while ((i<=listetaille(l))&&(!test))
    {
        if ((recuperer(l,i)->num)==numero)
        {
            test=1;
            elementafficher(recuperer(l,i));
        }
        else i++;
    }
}

void listecherche_g(LISTE l)
{
    char a;
    int i;
    printf("le genre des patients cherchees\n");
    scanf("%c",&a);
    scanf("%c",&a);
    for (i=1;i<=listetaille(l);i++)
    {
         if (recuperer(l,i)->genre==a)
            elementafficher(recuperer(l,i));
    }

}

void listecherche_et(LISTE l)
{
    char ch[10];
    int i;
    printf("donner l'etat cherchee\n");
    fflush(stdin);
    fgets(ch,10,stdin);
    for (i=1;i<=listetaille(l);i++)
    {
        if ((recuperer(l,i)->etat[0])==ch[0])

            elementafficher(recuperer(l,i));

    }
}
//
//
//
void initialisationm(elementm e,elemm m,listem l)
{
    e= elementmcreer();
    *e = m;
    insererm(l,e,1);
}
void initialisationp (elementm e,elemm m,listep l)
{
    e= elementmcreer();
    *e = m;
    insererp(l,e,1);
}
LISTE initia (void)
{
    LISTE l =listecreer();
    elementpt e=elementcreer();
    //
    //
//patient_1
listem malad = listemcreer();
    elemm maladies_1={""};
    elementm mld1;
    initialisationm (mld1,maladies_1,malad);
    //
listep persons =listepcreer();
    elemm personnes_1={"frere"};
    elementm per1;
    initialisationp(per1 , personnes_1,persons);
   //
    elemm personnes_2={"pere"};
    elementm per2;
    initialisationp(per2 , personnes_2,persons);
    //
    elemm personnes_3={"mere"};
    elementm per3;
    initialisationp(per3 , personnes_3,persons);
    ptstruct patient_1 = {"fendi","fadwa","Tunis",410,19,malad,persons,0,'f',"Normale"};
    *e=patient_1;
    inserer(l,e,1);
    //
    //
//patient2
elementpt e2=elementcreer();

    listem malad2=listemcreer();
    elemm maladies_2_1={"diabete"};
    elementm mld_2_1;
    initialisationm (mld_2_1,maladies_2_1,malad2);
    //
    elementm mld_2_2;
    elemm maladies_2_2={"hypertension"};
    initialisationm (mld_2_2,maladies_2_2,malad2);
    //personnes
listep persons2 =listepcreer();
    elemm personnes_2_1={"voisin"};
    elementm per_2_1;
    initialisationp(per_2_1 , personnes_2_1,persons2);
   //
    elemm personnes_2_2={"fils"};
    elementm per_2_2;
    initialisationp(per_2_2 , personnes_2_2,persons2);
    //
    elemm personnes_2_3={"fille"};
    elementm per_2_3;
    initialisationp(per_2_3 , personnes_2_3,persons2);
    //elemnt liste
    ptstruct patient_2 = {"ali","mohamed","Sfax",411,40,malad2,persons2,1,'m',"Guerie"};
    *e2=patient_2;
    inserer(l,e2,2);

//patient3
elementpt e3=elementcreer();
    //maladies2
    listem malad3=listemcreer();
    elemm maladies_3_1={""};
    elementm mld_3_1;
    initialisationm (mld_3_1,maladies_3_1,malad3);
    //personnes2
listep persons3 =listepcreer();
    elemm personnes_3_1={"soeur2"};
    elementm per_3_1;
    initialisationp(per_3_1 , personnes_3_1,persons3);
   //
    elemm personnes_3_2={"soeur1"};
    elementm per_3_2;
    initialisationp(per_3_2 , personnes_3_2,persons3);
    //
    elemm personnes_3_3={"frere"};
    elementm per_3_3;
    initialisationp(per_3_3, personnes_3_3,persons3);
    //
    elemm personnes_3_4={"mere"};
    elementm per_3_4;
    initialisationp(per_3_4, personnes_3_4,persons3);
    //
    elemm personnes_3_5={"pere"};
    elementm per_3_5;
    initialisationp(per_3_5 , personnes_3_5,persons3);
    //elemnet liste
    ptstruct patient_3 = {"chaouch","ameni","Nabeul",412,19,malad3,persons3,0,'f',"Normale"};
    *e3=patient_3;
    inserer(l,e3,3);

    //patient4
    elementpt e4=elementcreer();
    //maladies2
    listem malad4=listemcreer();
    elemm maladies_4_1={"hypotension"};
    elementm mld_4_1;
    initialisationm (mld_4_1,maladies_4_1,malad4);
    //
    elemm maladies_4_2={"hepatite"};
    elementm mld_4_2;
    initialisationm (mld_4_2,maladies_4_2,malad4);
    //personnes2
listep persons4 =listepcreer();
    elemm personnes_4_1={"docteur"};
    elementm per_4_1;
    initialisationp(per_4_1 , personnes_4_1,persons4);
   //
    elemm personnes_4_2={"policier1"};
    elementm per_4_2;
    initialisationp(per_4_2 , personnes_4_2,persons4);
    //
    elemm personnes_4_3={"policier2"};
    elementm per_4_3;
    initialisationp(per_4_3, personnes_4_3,persons4);
    //
    elemm personnes_4_4={"frere"};
    elementm per_4_4;
    initialisationp(per_4_4, personnes_4_4,persons4);
    //
    elemm personnes_4_5={"pere"};
    elementm per_4_5;
    initialisationp(per_4_5 , personnes_4_5,persons4);
    //element liste
    ptstruct patient_4 = {"wesleti","mehdi","Mahdia",413,27,malad4,persons4,1,'m',"critique"};
    *e4=patient_4;
    inserer(l,e4,4);

    //patient5
     elementpt e5=elementcreer();
    //maladies2
    listem malad5=listemcreer();
    elemm maladies_5_1={"triglicerides"};
    elementm mld_5_1;
    initialisationm (mld_5_1,maladies_5_1,malad5);
    //
    elemm maladies_5_2={"acide urique"};
    elementm mld_5_2;
    initialisationm (mld_5_2,maladies_5_2,malad5);
    //personnes2
listep persons5 =listepcreer();
    elemm personnes_5_1={"voisine"};
    elementm per_5_1;
    initialisationp(per_5_1 , personnes_5_1,persons5);
   //
    elemm personnes_5_2={"infirmiere"};
    elementm per_5_2;
    initialisationp(per_5_2 , personnes_5_2,persons5);
    //
    elemm personnes_5_3={"ami"};
    elementm per_5_3;
    initialisationp(per_5_3, personnes_5_3,persons5);
    //
    elemm personnes_5_4={"fille"};
    elementm per_5_4;
    initialisationp(per_5_4, personnes_5_4,persons5);
    //
    elemm personnes_5_5={"epoux"};
    elementm per_5_5;
    initialisationp(per_5_5 , personnes_5_5,persons5);
    //elemnet liste
    ptstruct patient_5 = {"slama","fatma","Kasserine",414,50,malad5,persons5,0,'f',"critique"};
    *e5=patient_5;
    inserer(l,e5,5);

//patient6
elementpt e6=elementcreer();

    listem malad6=listemcreer();
    elemm maladies_6_1={"diabete"};
    elementm mld_6_1;
    initialisationm (mld_6_1,maladies_6_1,malad6);
    //
    elementm mld_6_2;
    elemm maladies_6_2={"insuffisance_renale"};
    initialisationm (mld_6_2,maladies_6_2,malad6);
    //
    elementm mld_6_3;
    elemm maladies_6_3={"depression"};
    initialisationm(mld_6_3,maladies_6_3,malad6);
    //personnes
listep persons6 =listepcreer();
    elemm personnes_6_1={"frere"};
    elementm per_6_1;
    initialisationp(per_6_1 , personnes_6_1,persons6);
   //
    elemm personnes_6_2={"soeur"};
    elementm per_6_2;
    initialisationp(per_6_2 , personnes_6_2,persons6);
    //elemnt liste
    ptstruct patient_6 = {"gafsi","ridha","Gafsa",415,26,malad6,persons6,0,'m',"Guerie"};
    *e6=patient_6;
    inserer(l,e6,6);
    //
    return l;

}


