#include <stdlib.h>
#include <stdio.h>
#include "gouvernerat.h"

int q[100];

GRAPHELT nouveau_graph(int x)
{

    int i;
    GRAPHELT g= malloc(sizeof (graphelt));
    if (g==NULL)
    {
        fprintf(stderr, "probleme de creation de graph !\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        g->sommet = x;
        g->tab=malloc (x * sizeof (listeadj));
    if (g->tab == NULL )
    {
        fprintf(stderr, "probleme de creation!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (i=0;i<(g->sommet);i++)
        {
            g->tab[i].tete = NULL;
        }
    }
    }


    return g;
}

int vide_graph (GRAPHELT g)
{
    if (g == NULL)
        return 1;
    else
        return 0;
}

NOEUDLST noeud_creer (int x)
{
    NOEUDLST n= malloc (sizeof (Noeudlistelt));

    if (n == NULL)
    {
        fprintf(stderr, "probleme de creation de noeud!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        n->valeur = x;
        n->suivant = NULL;
    }
    return n;

}

void supprim_graph (GRAPHELT g)
{
    int i;
    if (estvide_graph(g))
    {
        printf("le graphe n'existe pas\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        if (g->tab)
        {
            int i;
            for (i=0; i<g->sommet ;i++)
            {
                NOEUDLST n= g->tab[i].tete,s;
                while (n!= NULL)
                {
                   s=n;
                   n=n->suivant;
                   free(s);
                }
            }
            free(g->tab);

        }
free(g);
    }
    }

    void ajouter_lien (GRAPHELT g,int e1,int e2)
{
    // notre graphe est non orientee

    NOEUDLST n = node_creer(e2);
	n->suivant = g->tab[e1].tete;
    g->tab[e1].tete = n ;

		n = node_creer(e1);
        n->suivant= g->tab[e2].tete;
        g->tab[e2].tete = n;
}


void affich_graphe(GRAPHELT g)
{
    int i;
    if (estvide_graph(g))
    {
        printf("le graphe n'existe pas\n");
        return;
    }
    else
    {
      for (i=0;i<(g->sommet);i++)
      {
          NOEUDLST n=g->tab[i].tete;
          printf("\n%i : ",i);

          while (n!= NULL)
          {
              printf("%i ,",n->valeur);
              n=n->suivant;

          }

      }
    }
}
