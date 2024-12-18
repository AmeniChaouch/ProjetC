#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PTRPRIM.h"
#include "eltprim.h"
#include "hopiteaux.h"
#include "LSTHOP.h"

NOEUD noeudcreer(element e)
{
    NOEUD n;
    n=(NOEUD)malloc(sizeof(structnoeud));
    if (!n)
        printf("pas d'espace\n");
    else
        {
        elementaffecter1(&n->info,e);
        n->suivant= NULL;
        }
        return n;
}

void noeuddetruire(NOEUD n)
{
    elementdetruire1(n->info);
    free(n);
}

int estvide1 (liste l)
{
    return (l->lg==0);
}

int estsaturee1(liste l)
{
    int succee;
    NOEUD n;
    n=(NOEUD)malloc(sizeof(structnoeud));
    if (n==NULL)
        succee=1;
        else
            {succee=0;
        free(n);}
        return  succee;
}

int listetaille1(liste l)
{
    return (l->lg);
}


element recuperer1(liste l,int pos)
{
    element e;
    if(estvide(l))
        printf("liste vide \n");
    else
    {
        if((pos<1)||(pos>l->lg))
            printf("position invalide \n");

    else
    { int i;
      e=elementcreer1();
      NOEUD q;
      q=l->tete;
      for (i=1;i<pos;i++)
        q=q->suivant;
        elementaffecter1(&e,q->info);
    }}
    return e;
}

liste listecreer1(void)
{
    liste l;
    l=(liste)malloc(sizeof(lastruct));
    if(!l)
        printf("pas d'espace\n");
    else
    {
        l->lg=0;
        l->tete=NULL;
        l->queue=NULL;
    }
    return l;
}

void listedetruire1(liste l)
{
    NOEUD q,p;
    int i;
    for (i=1;i<=l->lg;i++)
    {
        p=q;
        q=q->suivant;
        noeuddetruire(p);
    }
    free(l);
}

void listeafficher1(liste l)
{
    NOEUD q=l->tete;
    int i;
    for(i=1;i<=l->lg;i++)
    {
        elementafficher1(q->info);
        q=q->suivant;
    }
}


int inserer1(liste l,element e,int pos)
{
    NOEUD p,q,n;
    int succee,i;

    if (estsaturee(l))
        {
            printf("liste saturee\n");
            succee=0;
        }
        else
        {
            if ((pos<1)||(pos>l->lg+1))
                {printf("position invalide\n");
                succee=0;}

        else
        {
            succee=1;
            n=noeudcreer(e);
            if (estvide(l))
            {
                l->tete=n;
                l->queue=n;
            }
            else {
                if (pos==1)
                {
                    n->suivant=l->tete;
                    l->tete->precedent=n;
                    l->tete=n;
                }
                else
                {
                    if(pos == listetaille(l)+1)
                    {
                      l->queue->suivant=n;
                      n->precedent=l->queue;
                      l->queue=n;
                    }
                    else
                    {
                        if (pos < (listetaille(l)/2))
                        {
                            q=l->tete;
                            for (i=1;i<l->lg;i++)
                            {
                                p=q;
                                q=q->suivant;
                            }
                            p->suivant=n;
                            n->precedent=p;
                            q->precedent=n;
                            n->suivant=q;
                        }
                        else
                        {
                            q=l->queue;
                            for(i=l->lg;i>pos;i--)
                            {
                                p=q;
                                q=q->precedent;
                            }
                            p->precedent=n;
                            n->suivant=p;
                            q->suivant=n;
                            n->precedent=q;
                        }
                    }
                }
            }
            (l->lg)++;
            }
            }
        return succee;
}


