#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include "lieu.h"
#include "QTRPRIM.h"
#include"quarantprim.h"
#define lg_max 50
void rotation (lieux l,listeqtr q)
{ //date sys
    time_t now;
int jours,mois,an;
    time(&now);
  struct tm *local = localtime(&now);
  jours = local->tm_mday;
  mois = local->tm_mon + 1;
  an = local->tm_year + 1900;
  //
    int i;
    for(i=1;i<=l->lg;i++)
    {
        if ((q->quarantaines[l->tab[i]->qtr]->jour+15>jours)&&(l->tab[i]->disponibilite==0))
            l->tab[i]->disponibilite=1;
    }
}

elemlieucreer(void)
{
    lieu m;
    m=(lieu)malloc(sizeof(structl));
    return (m);
}

void elemlieudetruire(lieu e)
{
    free(e);
}

void elemlieuaffecter (lieu *e1,lieu e2)
{
    *e1=e2;
}
int elemlieucomparer(lieu elt1,lieu elt2)
{
    return (elt1-elt2);
}

void elemlieuafficher(lieu e )
{
    int i,j;
    printf("nom                           :%s\n", e->lieu);
    printf("adresse                       :%s\n", e->adr);
    printf("disponibilite                 :%i\n", e->disponibilite);
    printf("quarantaine num %i existe dans ce lieu\n", e->qtr);

}
//
//
//
lieux lieuxcreer(void)
{
    lieux L;
    L=(lieux) malloc ( sizeof(structlistel) );
    if(!L)
    {
           printf("\nProbleme de memoire") ;
    }
(L->lg)=0;
}
int lieuxinserer (lieux l, lieu e, int pos)
{
    int succee=0,i;
    if (l->lg==lg_max)
        printf("liste saturee\n");
    else
    {
        if ((pos<1)||(pos>l->lg+1))
            printf("position invalide \n");
        else
        {
            succee=1;

           for(i=l->lg;i>=pos;i--)
                elemlieuaffecter(&(l->tab[i+1]),l->tab[i]);
           elemlieuaffecter(&(l->tab[pos]),e);
            (l->lg)++;
        }
    }
    return succee;
}
void lieuxafficher (lieux l)
{
    int i;
    for(i=1;i<=(l->lg);i++)
        {printf ("==============le lieu %i==============\n",i);
            elemlieuafficher(l->tab[i]);
        printf("\n\n");}
}
lieu recupererlieu (lieux l,int pos)
{
    lieu elt;
    elt = elemlieucreer();
    if (l->lg==0)
    printf ("\nListe vide");
    else
    {
if ((pos < 1) || (pos > l->lg))
    {printf ("\nPosition invalide");}
    else
    elt = (l->tab[pos]);
    }
return(elt);
}
lieux initlieux(void)
{
    lieux ll=lieuxcreer();
lieu e1=elemlieucreer();
structl l={"hotel",1,"tunis",1,0};
lieuxinserer(ll,&l,1);
//
lieu e2=elemlieucreer();
structl l2={"maison d'hote",2,"guebes",2,0};
lieuxinserer(ll,&l2,1);
//
lieu e3=elemlieucreer();
structl l3={"hotel",3,"nabeul",3,1};
lieuxinserer(ll,&l3,1);
//
lieu e4=elemlieucreer();
structl l4={"chez lui",4,"kairouen",4,0};
lieuxinserer(ll,&l4,1);
//
lieu e5=elemlieucreer();
structl l5={"hotel",5,"sfax",5,1};
lieuxinserer(ll,&l5,1);
lieuxafficher(ll);
return ll;
}


