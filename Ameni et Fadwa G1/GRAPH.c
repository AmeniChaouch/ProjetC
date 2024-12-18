#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "GRAPH.h"
#include "patient.h"
#include "LSTPRIM.h"

GRAPH new_graph(LISTE l)
{
    int i;
    GRAPH g= malloc(sizeof (graphelement));
    if (g==NULL)
    {
        fprintf(stderr, "probleme de creation de graph !\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        g->orientee=false;
        g->sommet = l->lg;
        g->tab=malloc ((l->lg) * sizeof (listeadjacence));
    if (g->tab == NULL )
    {
        fprintf(stderr, "probleme de creation!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (i=0;i<(l->lg);i++)
        {
            g->tab[i].tete = NULL;
        }
    }
    }

    if(g->orientee)
		g->graph_file = fopen("digraph.out", "w");
	else
		g->graph_file = fopen("graph.out", "w");


    if (g->graph_file == NULL)
    {
        fprintf(stderr, "probleme de creation!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        if(g->orientee)
		fprintf(g->graph_file, "digraph mon_graph\n{\n");
	else
		fprintf(g->graph_file, "graph mon_graph\n{\n");

    }

    return g;
}

bool estvide_graph (GRAPH g)
{
    if (g == NULL)
        return true;
    else
        return false;
}

NOEUDLISTE node_creer (int x)
{
    NOEUDLISTE n= malloc (sizeof (Noeudlistelement));

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

void supprime_graph (GRAPH g,LISTE l)
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
            for (i=0;i<(l->lg);i++)
            {
                NOEUDLISTE n= g->tab[i].tete,s;
                while (n!= NULL)
                {
                   s=n;
                   n=n->suivant;
                   free(s);
                }
            }
            free(g->tab);

        }
        fprintf(g->graph_file,"}\n");
        fclose(g->graph_file);
free(g);
    }
}

void supprime_node(GRAPH g,LISTE l,int x)
{
    int i;
    NOEUDLISTE n=g->tab[x-410].tete,s;
    while (n!= NULL)
                {
                   s=n;
                   n=n->suivant;
                   free(s);
                }
                for (i=(x-410);i<(l->lg);i++)
                {
                    g->tab[i]=g->tab[i+1];
                }
}


void ajout_lien (GRAPH g,int e1,int e2,LISTE l)
{
    // notre graphe est non orientee

    NOEUDLISTE n = node_creer(e2);
	n->suivant = g->tab[e1 - 410 ].tete;
    g->tab[e1 - 410 ].tete = n ;
		n = node_creer(e1);
        n->suivant= g->tab[e2-410].tete;
        g->tab[e2 - 410].tete = n;


	if(g->orientee)
		fprintf(g->graph_file, "\t%i -- %i ;\n",e1,e2);
	else
		fprintf(g->graph_file, "\t%i -- %i ;\n",e1,e2);
}


void affiche_graphe(GRAPH g,LISTE l)
{
    int i;
    if (estvide_graph(g))
    {
        printf("le graphe n'existe pas\n");
        return;
    }
    else
    {
      for (i=0;i<(l->lg);i++)
      {
          NOEUDLISTE n=g->tab[i].tete;
          printf("\n%i : ",i+410);

          while (n!= NULL)
          {
              printf("%i ,",n->valeur);
              n=n->suivant;

          }

      }
    }
}

void print_console(GRAPH g)
{
  system("%CD%/release/bin/dotty.exe graph.out");
}
