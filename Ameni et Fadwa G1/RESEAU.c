#include <stdlib.h>
#include <stdio.h>
#include "QUARANT.h"
#include "quarantaine.h"
#include "RESEAU.h"

GRAPHRES new_graph_res(int x)
{
    int i;
    GRAPHRES g = (GRAPHRES) malloc(sizeof (graphreseau));
    if (g == NULL)
    {
        fprintf(stderr, "probleme de creation de graph !\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        g->orientee = false;
        g->sommet = x;
        g->tab=malloc (x * sizeof (listeadj));
    if (g->tab == NULL )
    {
        fprintf(stderr, "probleme de creation!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (i=0;i<x;i++)
        {
            g->tab[i].tete = NULL;
        }
    }
    }

    if(g->orientee)
		g->RESEAUFILE = fopen("digraph.out", "w");
	else
		g->RESEAUFILE = fopen("graph.out", "w");


    if (g->RESEAUFILE == NULL)
    {
        fprintf(stderr, "probleme de creation!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        if(g->orientee)
		fprintf(g->RESEAUFILE, "digraph my_graph\n{\n");
	else
		fprintf(g->RESEAUFILE, "graph my_graph\n{\n");

    }

    return g;
}

bool estvide_graph_res (GRAPHRES g)
{
    if (g == NULL)
        return true;
    else
        return false;
}

NOEUDRESEAU node_creer_res (int x)
{
    NOEUDRESEAU n=malloc (sizeof (noeudreseauelement));
    if (n == NULL)
    {
        fprintf(stderr, "probleme de creation de noeud !\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        n->valeur = x;
        n->suivant = NULL;
    }
    return n;
}

void supprime_graph_res (GRAPHRES g,int x)
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
            for (i=0;i<x;i++)
            {
                NOEUDRESEAU n= g->tab[i].tete,s;
                while (n!= NULL)
                {
                   s=n;
                   n=n->suivant;
                   free(s);
                }
            }
            free(g->tab);

        }
        fprintf(g->RESEAUFILE,"}\n");
        fclose(g->RESEAUFILE);
free(g);
    }
}


void ajout_lien_res (GRAPHRES g,int e1,int e2,int x)
{
    // notre graphe est non orientee
    NOEUDRESEAU n = node_creer_res(e2-1);
	n->suivant = g->tab[e1-1].tete;
    g->tab[e1-1].tete = n ;
		n = node_creer_res(e1-1);
        n->suivant= g->tab[e2-1].tete;
        g->tab[e2-1].tete = n;


	if(g->orientee)
		fprintf(g->RESEAUFILE, "\t%i -- %i ;\n",e1,e2);
	else
		fprintf(g->RESEAUFILE, "\t%i -- %i ;\n",e1,e2);
}

void affiche_graphe_res(GRAPHRES g,int x)
{
    int i;
    if (estvide_graph(g))
    {
        printf("le graphe n'existe pas\n");
        return;
    }
    else
    {
      for (i=0;i<x;i++)
      {
          NOEUDRESEAU n=g->tab[i].tete;
          printf("\n%i : ",i);

          while (n!= NULL)
          {
              printf("%i ,",n->valeur);
              n=n->suivant;

          }

      }
    }
}


void supprime_node_res(GRAPHRES g,int l,int x)
{
    int i;
    NOEUDRESEAU n=g->tab[x].tete,s;
    while (n!= NULL)
                {
                   s=n;
                   n=n->suivant;
                   free(s);
                }
                for (i=x;i<l;i++)
                {
                    g->tab[i]=g->tab[i+1];
                }
}

void print_console_res(GRAPHRES g)
{
    system("%CD%/release/bin/dotty.exe graph.out");
}
