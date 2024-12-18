#ifndef QUARANTAINE_H_INCLUDED
#define QUARANTAINE_H_INCLUDED
#define max 100
//
typedef struct {
int jour;
int mois;
}structdate,*date;
//
typedef struct
{
   char ch[max];
}structch,*elemch;
//
typedef struct {
elemch maladies[max];
int lg;
}structmaladies,*listemaladies;
typedef struct {
elemch personnes[max];
int lg;
}structpersonnes,*listepersonnes;
typedef struct{
    elemch lieux[max ];
    int lg;
}structlieux,*listelieux;
//
typedef struct{
int num;
char nom[max];
char prenom[max];
char adr[max];
int age;
listemaladies maladies ;
listepersonnes personnes;
int contamination ;
int provenance;
int jour;
int mois;
listelieux  lieuxvisites;
}structqtr,*elemqtr;







#endif // QUARANTAINE_H_INCLUDED
