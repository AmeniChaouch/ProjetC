#ifndef _RESEAU_h
#define _RESEAU_h
#include "QUARANT.h"
#include "quarantaine.h"
#include "GRAPH.h"


//definition du noeud
typedef struct noeudreseauelement
{
    int valeur;
    struct noeudreseauelement *suivant;
}noeudreseauelement,*NOEUDRESEAU;

//definition de la liste d'adjacence
typedef struct listeadj
{
  NOEUDRESEAU tete;
}listeadj,*ADJSLISTE;


//definition du graphe
typedef struct graphreseau
{
    ADJSLISTE tab;
    int sommet;
    bool orientee;
    FILE *RESEAUFILE;
}graphreseau,*GRAPHRES;


//les primitives
GRAPHRES new_graph_res(int);
bool estvide_graph_res (GRAPHRES);
NOEUDRESEAU node_creer_res (int);
void supprime_graph_res (GRAPHRES,int);
void ajout_lien_res (GRAPHRES,int,int,int);
void affiche_graphe_res(GRAPHRES,int);
void supprime_node_res(GRAPHRES,int,int);
void print_console_res(GRAPHRES);

#endif // _RESEAU_h
