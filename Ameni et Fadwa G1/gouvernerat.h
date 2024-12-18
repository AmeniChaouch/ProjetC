#ifndef _gouvernerat_h
#define _gouvernerat_h



//definition du noeud
typedef struct Noeudlistelt
{
    int valeur;
    struct Noeudlistelt *suivant;
}Noeudlistelt, *NOEUDLST;

//liste
typedef struct listeadj
{
    NOEUDLST tete;
}listeadj,*ADJLISTE;

//definition du graphe
typedef struct graphelt
{
    ADJLISTE tab;
    int sommet;
}graphelt,*GRAPHELT;


GRAPHELT nouveau_graph(int);
int vide_graph (GRAPHELT);
NOEUDLST noeud_creer (int);
void ajouter_lien (GRAPHELT,int,int);
void supprim_node(GRAPHELT,int);
void affich_graphe(GRAPHELT);



#endif // _gouvernerat_h
