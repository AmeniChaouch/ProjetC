#ifndef _dons_hop_h
#define _dons_hop_h
#define lg_max 50

typedef struct
{
    char *nom;
    int num;
    char *adresse;
    long int numtel;
}STRUCTURE,*elemnt;


typedef struct
{
    char *besoin;
    int quantite;
}needd,*needs;

typedef struct
{
    char *don;
    int argent;
    char *inventions;
}donn,*donnations;

typedef struct
{
    needs tab1[lg_max];
    int lg;
}tab1struct,*TAB1;

typedef struct
{
    donnations tab2[lg_max];
    int lg;
}tab2struct,*TAB2;

typedef struct
{
    TAB1 besoins ;
    TAB2 dons ;
    elemnt hopital;
}thestruct,*STRUCT;


#endif // _dons_hop_h
