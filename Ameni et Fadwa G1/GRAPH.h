#ifndef _GRAPH_h
#define _GRAPH_h
#include "patient.h"
#include "LSTTAB.h"

typedef enum
{
    false,
    true
}bool;

//definition du noeud
typedef struct Noeudlistelement
{
    int valeur;
    struct Noeudlistelement *suivant;
}Noeudlistelement, *NOEUDLISTE;

//liste
typedef struct listeadjacence
{
    NOEUDLISTE tete;
}listeadjacence,*ADLISTE;

//definition du graphe
typedef struct graphelement
{
    ADLISTE tab;
    int sommet;
    bool orientee;
    FILE *graph_file;
}graphelement,*GRAPH;

GRAPH new_graph(LISTE);
bool estvide_graph (GRAPH);
NOEUDLISTE node_creer (int);
void supprime_graph (GRAPH,LISTE);
void ajout_lien (GRAPH,int,int,LISTE);
void affiche_graphe(GRAPH,LISTE);
void supprime_node(GRAPH,LISTE,int);
void print_console(GRAPH);


#endif // _GRAPH_h
