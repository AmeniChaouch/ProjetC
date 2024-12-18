#ifndef HOPITEAUX_H_INCLUDED
#define HOPITEAUX_H_INCLUDED
#define lg_max 100

typedef struct{
char specialite[50];
int disponibilite;
int num;
}structspec,*elemspec;


typedef struct{
elemspec sallespec[lg_max];
int lg;
}structlspec,*lstspec;


typedef struct {
char nom[50];
int num ;
char adr[20];
int litrea;
int litnormal;
lstspec salles;
int medecins ;
int paramedicaux;
long int numtel;
}structhop,*elemhop;

#endif // HOPITEAUX_H_INCLUDED

