#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dons_hop_prim.h"
int elemtab1supp (TAB1 a,int pos)
{
    int i;
    int succee=0;
    if (estvidetab1(a))
    {
        printf("listevide\n");
    }
    else{
        if ((pos<1)||(pos>a->lg))
        {
            printf("pos invalide\n");
        }
        else
        {succee=1;
            needdetruire(a->tab1[pos]);
            for (i=pos;i<=a->lg;i++)
                needaffecter(&a->tab1[i],a->tab1[i+1]);
            (a->lg)--;
        }
    }
      return succee;
}
STRUCT structurecreer(void)
{
    STRUCT e;
    e=(STRUCT)malloc (sizeof (thestruct));
    return e;
}

void structuredetruire (STRUCT e)
{
    free(e);
}

void structureaffecterb (STRUCT *e1, STRUCT e2)
{
    *e1=e2;
}


void structurelire (STRUCT* e)
{
    int x,i;
    needs n;
    TAB1 a=tab1creer();
    TAB2 b=tab2creer();
    fflush(stdin);
    do
    {printf("le nom de l'hopital\n");
    fgets(&(*e)->hopital->nom,20,stdin);}
     while(!verif((*e)->hopital->nom));
    printf("le numero de l'hopital\n");
    scanf("%i",&(*e)->hopital->num);
    fflush(stdin);
    do
    {printf("l'adresse de cet hopital\n");
    fgets(&(*e)->hopital->adresse,20,stdin);}
     while(!verif((*e)->hopital->adresse));
    printf("le numero de telephone generale de l'hopital\n");
    scanf("%ld",&(*e)->hopital->numtel);
    printf("combient de besoins avez vous\n");
    scanf("%i",&x);
    for (i=1;i<=x;i++)
    {
        //ajout_besoin(n);
        inserertab1(a,n,i);
    }


}

void structureafficher(elemnt e)
{
    printf("khalil");
    printf("hopital :     %s\n",e->nom);
    printf("son adresse :   %s\n",e->adresse);
    printf("numero de telephone generale     %ld\n",e->numtel);
}

int structurecomparer (STRUCT e1,STRUCT e2)
{
    return (e1->hopital->numtel == e2->hopital->numtel);
}

// gestion des besoins
needs needcreer (void)
{
    needs n;
    n=malloc (sizeof (needd));
    return n;
}

void ajout_besoin (needs *n)
{

        printf("donner votre besoin \n");
        fflush(stdin);
        gets(&(*n)->besoin);
        printf("la quantitee desiree en cet besoin \n");
        scanf("%i",&(*n)->quantite);
}

void needdetruire (needs n)
{
    free(n);
}

void needaffecter (needs *n1,needs n2)
{
    *n1=n2;
}

void needafficher (needs n)
{
    printf("Nous avons besoins de   %s\n   en quantite de   %i\n",n->besoin,n->quantite);
}


TAB1 tab1creer (void )
{
    TAB1 a=(TAB1)malloc (sizeof (tab1struct));
    if (!a)
    {
        printf("probleme de memoire \n");
        exit (EXIT_FAILURE);
    }
    else
        (a->lg)=0;
    return a;

}

void tab1detruire (TAB1 a)
{
     int i;
     for (i=1;i<a->lg;i++)
     {
         needdetruire (a->tab1[i]);
     }
}

int estvidetab1 (TAB1 a)
{
 return ((a->lg)== 0);
}


int estsatureetab1(TAB1 a)
{
    return ((a->lg)== lg_max);
}

int tab1taille (TAB1 a)
{
 return (a->lg);
}

needs recupererneed (TAB1 a,int i)
{
    needs n=needcreer();

    if (estvidetab1(a))
        printf("vide\n");
    else
    {int j;
        if ((i<1)||(i>a->lg))
            printf("position invalide \n");
        else
            needaffecter(&n,a->tab1[j]);
    }
    return n;
}

int inserertab1 (TAB1 a,needs n,int i)
{
    int succee=0,j;
    if (estsatureetab1(a))
    {
        printf("saturee\n");
        exit (EXIT_FAILURE);
    }
    else
    {
        succee=1 ;
        if ((i<1)||(i>1+(a->lg)))
            printf("position invalide\n");
        else
        {
            for (j=a->lg;j>=i;j--)
                needaffecter (&a->tab1[j+1],a->tab1[j]);
            needaffecter (&a->tab1[j],n);
            (a->lg)++;
        }
    }
    return succee;
}

void tab1afficher (TAB1 a)
{
    int i;
    printf("\nLes besoins de cet hopital sont: \n");
    for (i=1;i<a->lg;i++)
       needafficher(a->tab1[i]);

}


//gestion des dons

void dondetruire (donnations e)
{
    free(e);
}

void donaffecter (donnations *d1,donnations d2)
{
    *d1=d2;
}

donnations doncreer (void)
{
    donnations d=malloc (sizeof (donn));
    return d;
}

void donafficher (donnations d)
{

    printf("les dons materielles  %s\ndons monetaires  %i\n",d->don,d->argent);
    if (d->inventions != NULL )
        printf("les inventions des jeunes %s\n",d->inventions);
}


void ajout_don (donn *d)
{
    int a;

            printf("donner le montant donne\n");
            scanf("%i",&(*d).argent);

}



TAB2 tab2creer (void )
{
    TAB2 a=(TAB2)malloc (sizeof (tab2struct));
    if (!a)
    {
        printf("probleme de memoire \n");
                 exit(EXIT_FAILURE);

    }
    else
        (a->lg)=0;
    return a;

}

void tab2detruire (TAB2 a)
{
     int i;
     for (i=1;i<a->lg;i++)
     {
         dondetruire (a->tab2[i]);
     }
}

int estvidetab2 (TAB2 a)
{
 return ((a->lg)== 0);
}


int estsatureetab2(TAB2 a)
{
    return ((a->lg)== lg_max);
}

int tab2taille (TAB2 a)
{
 return (a->lg);
}

donnations recupererdon (TAB2 a,int i)
{
    donnations n=doncreer();

    if (estvidetab2(a))
        printf("vide\n");
    else
    {int j;
        if ((i<1)||(i>a->lg))
            printf("position invalide \n");
        else
            donaffecter(&n,a->tab2[j]);
    }
    return n;
}

int inserertab2 (TAB2 a,donnations n,int i)
{
    int succee=0,j;
    if (estsatureetab2(a))
    {
        printf("saturee\n");
       exit(EXIT_FAILURE);

    }
    else
    {
        succee=1 ;
        if ((i<1)||(i>1+(a->lg)))
            printf("position invalide\n");
        else
        {
            for (j=a->lg;j>=i;j--)
                donaffecter (&a->tab2[j+1],a->tab2[j]);
            donaffecter (&a->tab2[j],n);
            (a->lg)++;
        }
    }
    return succee;
}

void tab2afficher (TAB2 a)
{
    int i;
    printf("\nLes dons sont: \n");
    for (i=1;i<a->lg;i++)
       donafficher(a->tab2[i]);
}
