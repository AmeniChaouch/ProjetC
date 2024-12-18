#ifndef _patient_h
#define _patient_h

#define longueur 20

//elements
typedef struct
{
   char m[20];
}elemm,*elementm;

//listes
typedef struct {
elementm maladies[longueur];
int lg;
}mstruct,*listem;
//

typedef struct {
elementm personnes[longueur];
int lg
}pstruct,*listep;

//structure d'elements
typedef struct {
char nom[50];
char prenom[50];
char adresse[15];
int num;
int age;
listem maladie_chro;
listep personnes_contact;
int conta_introd;
char genre;
char etat[15];
}ptstruct,*elementpt;


#endif // PATIENT_H_INCLUDED

