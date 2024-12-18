#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"HOPPRIM.h"
#include "hopitauxprim.h"
//primitives de lstspec
lstspec lstspeccreer(void)
{
        lstspec l;
    l=(lstspec)malloc (sizeof(structspec));
     if(!l)
    {
           printf("\nProbleme de memoire") ;
    }
(l->lg)=0;
    return l;
}
int listespecinserer (lstspec l, elemspec e, int pos )
{
    int succee=0,i;
    if (l->lg==lg_max)
        printf("liste saturee\n");
    else
    {
        if ((pos<1)||(pos>l->lg+1))
            printf("position invalide \n");
        else
        {
            succee=1;
           for(i=l->lg;i>=pos;i--)
                elemspecaffecter(&(l->sallespec[i+1]),l->sallespec[i]);
           elemspecaffecter(&(l->sallespec[pos]),e);
           (l->lg)++;
        }
    }
    return succee;
}
void listespecafficher (lstspec l)
{
    int i;
    printf("les salles de specialite :");
    for (i=1;i<=l->lg;i++)
    {
        elemspecafficher(l->sallespec[i]);
    }
    printf("\n\n\n");
}


lstspec listespeclire (structspec s)
{int x,i,j,g;
lstspec l=lstspeccreer();
    printf("combient de salle specifiques comprend cet hopital\n");
    scanf("%i",&x);

    for (j=0;j<x;j++)
    {
        printf("choisissez les salles disponibles dans l'hopital:\nchirurgie:1 radiologie:2 dialyse:3 cardiologie:4 ");
        scanf("%i",&g);
        if (g==1)
        {
            structspec s={"chirurgie",1};
            for(i=l->lg;i>=1;i--)
                elemspecaffecter(&(l->sallespec[i+1]),l->sallespec[i]);
           elemspecaffecter(&(l->sallespec[1]),&s);
           (l->lg)++;

        }
        else
        {
            if (g==2)
            {
            structspec s={"radiologie",1};
            for(i=l->lg;i>=1;i--)
                elemspecaffecter(&(l->sallespec[i+1]),l->sallespec[i]);
           elemspecaffecter(&(l->sallespec[1]),&s);
           (l->lg)++;

            }
            else{
        if (g==3)
        {
            structspec s={"dialyse",1};
            for(i=l->lg;i>=1;i--)
                elemspecaffecter(&(l->sallespec[i+1]),l->sallespec[i]);
           elemspecaffecter(&(l->sallespec[1]),&s);
           (l->lg)++;

        }
        else {
        if (g==4)
        {
            structspec s={"cardiologie",1};
            for(i=l->lg;i>=1;i--)
                elemspecaffecter(&(l->sallespec[i+1]),l->sallespec[i]);
           elemspecaffecter(&(l->sallespec[1]),&s);
           (l->lg)++;
        }}}}
    }
    for (j=1;j<=x;j++)
    {printf("\n===========================\nles salles de specialites sont :");
    elemspecafficher(l->sallespec[j]);
    }
    return l;
}

//primitives listehop
void ajouthop(lsthop l)
{int i;
structspec s;
  elemhop e= elemhopcreer();
  elemhoplire(&e,s);
  lsthopinserer(l,e,(l->lg)+1);
  elemhopafficher(l->hopitaux[l->lg]);
}
lsthop lsthopcreer(void)
{
    lstspec l;
    l=(lsthop)malloc (sizeof(structhop));
     if(!l)
    {
           printf("\nProbleme de memoire") ;
    }
(l->lg)=0;
    return l;
}
void lsthopafficher (lsthop l)
{int i;
    for (i=1;i<=l->lg;i++)
    {
        elemhopafficher(l->hopitaux[i]);
    }
}

int lsthopinserer(lsthop l, elemhop e, int pos)
{
   int succee=0,i=l->lg;
    if (l->lg==lg_max)
        printf("liste saturee\n");
    else
    {
        if ((pos<1)||(pos>l->lg+1))
            printf("position invalide \n");
        else
        {
            succee=1;
            for(i=l->lg;i>pos;i--)
                elemhopaffecter(&(l->hopitaux[i+1]),l->hopitaux[i]);
           elemhopaffecter(&(l->hopitaux[pos]),e);
            (l->lg)++;
        }

    }
    return succee;

}

lsthop inithop (void)
{
    lsthop l =lsthopcreer();
//
 elemhop eh1=elementcreer();
lstspec s_1 = lstspeccreer();
    structspec salle1_1={"chirurgie",1};
    structspec salle1_3={"cardiologie",0};
    structspec salle1_2={"radiologie",0};
    elemspec e;
     e= elemspeccreer();
    *e = salle1_1;
    elemspec e3= elemspeccreer();
    *e3= salle1_3;
   elemspec e2= elemspeccreer();
    *e2 = salle1_2;
    listespecinserer(s_1,e,1);
    listespecinserer(s_1,e3,1);
    listespecinserer(s_1,e2,1);
    structhop hopital_1 ={"Charles Nicoll",1,"tunis",32,365,s_1,82,112,71578007};
    *eh1= hopital_1;
    lsthopinserer(l,eh1,1);
    //
    //

     elemhop eh2=elementcreer();
lstspec s_2 = lstspeccreer();
    structspec salle2_1={"chirurgie",1},salle2_2={"dialyse",0},salle2_3={"radiologie",1};
    elemspec e2_1;
     e2_1= elemspeccreer();
    *e2_1 = salle2_1;
    elemspec e2_2= elemspeccreer();
    *e2_2= salle2_2;
   elemspec e2_3= elemspeccreer();
    *e2_3 = salle2_3;
    listespecinserer(s_2,e2_1,1);
    listespecinserer(s_2,e2_3,1);
    listespecinserer(s_2,e2_2,1);
    structhop hopital_2 ={"el amen ",2,"nabeul",15,115,s_2,53,112,74241511};
    *eh2= hopital_2;
    lsthopinserer(l,eh2,2);
    //
    //
    //
  elemhop eh3=elementcreer();
lstspec s_3 = lstspeccreer();
    structspec salle3_1={"dialyse",1},salle3_2={"chirurgie",1},salle3_3={"cardiologie",1};
    elemspec e3_1;
     e3_1= elemspeccreer();
    *e3_1 = salle3_1;
    elemspec e3_2= elemspeccreer();
    *e3_2= salle3_2;
   elemspec e3_3= elemspeccreer();
    *e3_3 = salle3_3;
    listespecinserer(s_3,e3_1,1);
    listespecinserer(s_3,e3_3,1);
    listespecinserer(s_3,e3_2,1);
    structhop hopital_3 ={"Habib Bourguiba",3,"kairouen",19,208,s_3,53,112,74241511};
    *eh3= hopital_3;
    lsthopinserer(l,eh3,3);
    //
    //
    //
  elemhop eh4=elementcreer();
lstspec s_4 = lstspeccreer();
    structspec salle4_1={"dialyse",1},salle4_2={"chirurgie",1},salle4_3={"radiologie",0};
    elemspec e4_1;
     e4_1= elemspeccreer();
    *e4_1 = salle4_1;
    elemspec e4_2= elemspeccreer();
    *e4_2= salle4_2;
   elemspec e4_3= elemspeccreer();
    *e4_3 = salle4_3;
    listespecinserer(s_4,e4_1,1);
    listespecinserer(s_4,e4_3,1);
    listespecinserer(s_4,e4_2,1);
    structhop hopital_4 = {"Habib thameur",4,"sfax",15,115,s_4,53,112,74241511};
    *eh4= hopital_4;
    lsthopinserer(l,eh4,4);
    //
    //
    //
    elemhop eh5=elementcreer();
lstspec s_5 = lstspeccreer();
    structspec salle5_1={"radiologie",1},salle5_2={"dialyse",1},salle5_3={"cardiologie ",1};
    elemspec e5_1;
     e5_1= elemspeccreer();
    *e5_1 = salle5_1;
    elemspec e5_2= elemspeccreer();
    *e5_2= salle5_2;
   elemspec e5_3= elemspeccreer();
    *e5_3 = salle5_3;
    listespecinserer(s_5,e5_1,1);
    listespecinserer(s_5,e5_3,1);
    listespecinserer(s_5,e5_2,1);
    structhop hopital_5 =  {"Hopital regional",5,"tozeur",20,233,s_5,40,301,78194562};
    *eh5= hopital_5;
    lsthopinserer(l,eh5,5);
//



    return l;
}

int recherche (lsthop m,char *ch,int i)
{

    int trouv=0;
    int test=0,k=1;

    while ((k<=m->lg)&&(!test))
    {
        if ((m->hopitaux[k]->adr[0] == ch[0])&&(m->hopitaux[k]->adr[1] == ch[1]))
        {
            test=1;
            int stop=0,j=1;

             if (i == 5)
                {
                    if (m->hopitaux[k]->litnormal > 0)
                    {
                        trouv=1;
                        (m->hopitaux[k]->litnormal)--;
                        printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);
                    }
                    else
                        return 0;
                }
                    else
                    {
                        if (i==6)
                        {
                            if (m->hopitaux[k]->litrea > 0)
                            {
                                trouv = 1;
                                (m->hopitaux[k]->litrea)--;
                                printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);
                            }
                            else
                                return 0;
                        }
                          else
                          { int j=1;
                              if (i==1)
                              {

                                  while ((j<=m->hopitaux[k]->salles->lg)&&(!trouv))
                                  {
                                    if ((m->hopitaux[k]->salles->sallespec[j]->specialite[0] == 'c')&&(m->hopitaux[k]->salles->sallespec[j]->specialite[1] == 'h')&&(m->hopitaux[k]->salles->sallespec[j]->disponibilite))
                                        {trouv=1;
                                    printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);}
                               else j++;

                                  }
                              }
                              else
                              {
                                 if (i==2)
                              {

                              j=1;
                                  while ((j<=m->hopitaux[k]->salles->lg)&&(!trouv))
                                  {
                                    if ((m->hopitaux[k]->salles->sallespec[j]->specialite[0] == 'c')&&(m->hopitaux[k]->salles->sallespec[j]->specialite[1] == 'a')&&(m->hopitaux[k]->salles->sallespec[j]->disponibilite))
                                        {trouv=1;
                                    printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);}
                               else j++;

                                  }
                              }
                              else
                              {
                                 if (i==3)
                              {
                              j=1;
                                  while ((j<=m->hopitaux[k]->salles->lg)&&(!trouv))
                                  {
                                    if ((m->hopitaux[k]->salles->sallespec[j]->specialite[0] == 'r')&&(m->hopitaux[k]->salles->sallespec[j]->specialite[1] == 'a')&&(m->hopitaux[k]->salles->sallespec[j]->disponibilite))
                                        {trouv=1;
                                    printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);}
                               else  j++;

                                  }
                              }
                              else
                              {
                                  if (i==4)
                              {
                              j=1;
                                  while ((j<=m->hopitaux[k]->salles->lg)&&(!trouv))
                                  {
                                    if ((m->hopitaux[k]->salles->sallespec[j]->specialite[0] == 'd')&&(m->hopitaux[k]->salles->sallespec[j]->specialite[1] == 'i')&&(m->hopitaux[k]->salles->sallespec[j]->disponibilite))
                                        {trouv=1;
                                    printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                    elemhopafficher(m->hopitaux[k]);trouv=1;}

                                     else  j++;

                                  }
                              }

                              }

                              }



                              }
                          }



        }
        }
        k++;

        }

        if (!trouv )
        {

            while ((k<=m->lg)&&(!trouv))
            {
            int j=1;
            if (i == 5)
                {
                    if (m->hopitaux[k]->litnormal > 0)
                    {
                        trouv=1,j=1;
                        (m->hopitaux[k]->litnormal)--;
                        printf("\nvous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);
                    }
                    else
                        return 0;
                }
                    else
                    {
                        if (i==6)
                        {
                            if (m->hopitaux[k]->litrea > 0)
                            {
                                trouv = 1,j=1;
                                (m->hopitaux[k]->litrea)--;
                                printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);
                            }
                            else
                                return 0;
                        }
                        else
                        {

                           { int j=1;
                              if (i==1)
                              {
                              trouv=0,j=1;
                                  while ((j<=m->hopitaux[k]->salles->lg)&&(!trouv))
                                  {
                                    if ((m->hopitaux[k]->salles->sallespec[j]->specialite[0] == 'c')&&(m->hopitaux[k]->salles->sallespec[j]->specialite[1] == 'h')&&(m->hopitaux[k]->salles->sallespec[j]->disponibilite))
                                        {trouv=1;
                                    printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);}
                              else  j++;

                                  }
                              }
                              else
                              {
                                 if (i==2)
                              {
                              trouv=0,j=1;
                                  while ((j<=m->hopitaux[k]->salles->lg)&&(!trouv))
                                  {
                                    if ((m->hopitaux[k]->salles->sallespec[j]->specialite[0] == 'c')&&(m->hopitaux[k]->salles->sallespec[j]->specialite[1] == 'a')&&(m->hopitaux[k]->salles->sallespec[j]->disponibilite))
                                        {trouv=1;
                                    printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);}
                              else  j++;

                                  }
                              }
                              else
                              {
                                 if (i==3)
                              {
                              trouv=0,j=1;
                                  while ((j<=m->hopitaux[k]->salles->lg)&&(!trouv))
                                  {
                                    if ((m->hopitaux[k]->salles->sallespec[j]->specialite[0] == 'r')&&(m->hopitaux[k]->salles->sallespec[j]->specialite[1] == 'a')&&(m->hopitaux[k]->salles->sallespec[j]->disponibilite))
                                        {trouv=1;
                                    printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);}
                               else j++;

                                  }
                              }
                              else
                              {
                                  if (i==4)
                              {
                              trouv=0,j=1;
                                  while ((j<=m->hopitaux[k]->salles->lg)&&(!trouv))
                                  {
                                    if ((m->hopitaux[k]->salles->sallespec[j]->specialite[0] == 'd')&&(m->hopitaux[k]->salles->sallespec[j]->specialite[1] == 'i')&&(m->hopitaux[k]->salles->sallespec[j]->disponibilite))
                                        {trouv=1;
                                    printf("vous etes affecter a l'hopital le plus proche de vous qui est \n");
                                elemhopafficher(m->hopitaux[k]);}
                              else  j++;

                                  }
                              }

                              }

                              }



                              }
                          }


                        }
                    }



k++;
            }}

return trouv;
}


void modification (lsthop l,int a)
{

    int ln,x,i=1,test=1,choix;
    char *ch;
    printf("Quelles informations voulez vous modifier dans cet hopital?\n");
    printf("    1- Le nombre des lits normale \n");
    printf("    2- Le nombre des lits de reanimations \n");
    printf("    3- Le nombre de medecins \n ");
    printf("    4- Le nombre des equipes paramedicales \n");
    printf("    5- La disponibilitee d'une salle specifique \n");
    scanf("%i",&x);

    switch (x)
        {
    case 1:

        printf("donner le nouvel nombre de lits normales\n");
        scanf("%i",&ln);
        l->hopitaux[a]->litnormal = ln;
        lsthopafficher(l);
        break;

    case 2:

        printf("donner le nouvel nombre de lits de reanimations \n");
        scanf("%i",&ln);
        l->hopitaux[a]->litrea = ln;
         lsthopafficher(l);
        break;

    case 3:

        printf("donner le nouvel nombre de medecins \n");
        scanf("%i",&ln);
        l->hopitaux[a]->medecins = ln;
         lsthopafficher(l);
        break;

    case 4:

        printf("donner le nouvel nombre d'equipes paramedicales\n");
        scanf("%i",&ln);
        l->hopitaux[a]->paramedicaux = ln;
         lsthopafficher(l);
        break;

    case 5:
        {system("cls");
        elemhopafficher(l->hopitaux[a]);
        printf("donnez le numero de la salle a modifier:\nchirurgie:1 radiologie:2 dialyse:3 cardiologie:4  ");
        scanf("%i",&choix);
        printf("donner le nouvel etat de disponibilite de cette salle 1: disponible 0:sinon \n");
        scanf("%i",&ln);
        switch(choix)
        {
        case 1:

        while ((i<=l->hopitaux[a]->salles->lg)&&(test))
        {
            if ((l->hopitaux[a]->salles->sallespec[i]->specialite[0] == 'c')&&(l->hopitaux[a]->salles->sallespec[i]->specialite[1] == 'h'))
            {
                test=0;
                l->hopitaux[a]->salles->sallespec[i]->disponibilite = ln;
            }
            i++;
        }
        elemhopafficher(l->hopitaux[a]);
        break;
        case 2:
            while ((i<=l->hopitaux[a]->salles->lg)&&(test))
        {
            if (l->hopitaux[a]->salles->sallespec[i]->specialite[0] == 'r')
            {
                test=0;
                l->hopitaux[a]->salles->sallespec[i]->disponibilite = ln;
            }
            i++;
        }
         elemhopafficher(l->hopitaux[a]);
        break;
        case 3:
            while ((i<=l->hopitaux[a]->salles->lg)&&(test))
        {
            if (l->hopitaux[a]->salles->sallespec[i]->specialite[0] == 'c')
            {
                test=0;
                l->hopitaux[a]->salles->sallespec[i]->disponibilite = ln;
            }
            i++;
        }
         elemhopafficher(l->hopitaux[a]);
        break;
        case 4:
            while ((i<=l->hopitaux[a]->salles->lg)&&(test))
        {
            if (l->hopitaux[a]->salles->sallespec[i]->specialite[0] == 'd')
            {
                test=0;
                l->hopitaux[a]->salles->sallespec[i]->disponibilite = ln;
            }
            i++;
        }
         elemhopafficher(l->hopitaux[a]);
        break;
        default :
            printf("erreur de choix");
modification(l,a);
            }

        break;}

    default :
        printf("erreur de choix\n");
modification(l,a);
        }
}
lsthop inithop2(void)
{
     lsthop l =lsthopcreer();
//
 elemhop eh1=elementcreer();
lstspec s_1 = lstspeccreer();
    structspec salle1_1={"chirurgie",1};
    structspec salle1_3={"cardiologie",0};
    structspec salle1_2={"radiologie",0};
    elemspec e;
     e= elemspeccreer();
    *e = salle1_1;
    elemspec e3= elemspeccreer();
    *e3= salle1_3;
   elemspec e2= elemspeccreer();
    *e2 = salle1_2;
    listespecinserer(s_1,e,1);
    listespecinserer(s_1,e3,1);
    listespecinserer(s_1,e2,1);
    structhop hopital_1 ={"Charles Nicoll",1,"tunis",32,365,s_1,82,112,71578007};
    *eh1= hopital_1;
    lsthopinserer(l,eh1,1);
    //
    //

     elemhop eh2=elementcreer();
lstspec s_2 = lstspeccreer();
    structspec salle2_1={"chirurgie",1},salle2_2={"dialyse",0},salle2_3={"radiologie",1};
    elemspec e2_1;
     e2_1= elemspeccreer();
    *e2_1 = salle2_1;
    elemspec e2_2= elemspeccreer();
    *e2_2= salle2_2;
   elemspec e2_3= elemspeccreer();
    *e2_3 = salle2_3;
    listespecinserer(s_2,e2_1,1);
    listespecinserer(s_2,e2_3,1);
    listespecinserer(s_2,e2_2,1);
    structhop hopital_2 ={"el amen ",2,"nabeul",15,115,s_2,53,112,74241511};
    *eh2= hopital_2;
    lsthopinserer(l,eh2,2);
    //
    //
    //
  elemhop eh3=elementcreer();
lstspec s_3 = lstspeccreer();
    structspec salle3_1={"dialyse",1},salle3_2={"chirurgie",1},salle3_3={"cardiologie",1};
    elemspec e3_1;
     e3_1= elemspeccreer();
    *e3_1 = salle3_1;
    elemspec e3_2= elemspeccreer();
    *e3_2= salle3_2;
   elemspec e3_3= elemspeccreer();
    *e3_3 = salle3_3;
    listespecinserer(s_3,e3_1,1);
    listespecinserer(s_3,e3_3,1);
    listespecinserer(s_3,e3_2,1);
    structhop hopital_3 ={"Habib Bourguiba",3,"kairouen",19,208,s_3,53,112,74241511};
    *eh3= hopital_3;
    lsthopinserer(l,eh3,3);
    //
    //
    //
  elemhop eh4=elementcreer();
lstspec s_4 = lstspeccreer();
    structspec salle4_1={"dialyse",1},salle4_2={"chirurgie",1},salle4_3={"radiologie",0};
    elemspec e4_1;
     e4_1= elemspeccreer();
    *e4_1 = salle4_1;
    elemspec e4_2= elemspeccreer();
    *e4_2= salle4_2;
   elemspec e4_3= elemspeccreer();
    *e4_3 = salle4_3;
    listespecinserer(s_4,e4_1,1);
    listespecinserer(s_4,e4_3,1);
    listespecinserer(s_4,e4_2,1);
    structhop hopital_4 = {"Habib thameur",4,"sfax",15,115,s_4,53,112,74241511};
    *eh4= hopital_4;
    lsthopinserer(l,eh4,4);
    //
    //
    //
    elemhop eh5=elementcreer();
lstspec s_5 = lstspeccreer();
    structspec salle5_1={"radiologie",1},salle5_2={"dialyse",1},salle5_3={"cardiologie ",1};
    elemspec e5_1;
     e5_1= elemspeccreer();
    *e5_1 = salle5_1;
    elemspec e5_2= elemspeccreer();
    *e5_2= salle5_2;
   elemspec e5_3= elemspeccreer();
    *e5_3 = salle5_3;
    listespecinserer(s_5,e5_1,1);
    listespecinserer(s_5,e5_3,1);
    listespecinserer(s_5,e5_2,1);
    structhop hopital_5 =  {"Hopital regional",5,"tozeur",20,233,s_5,40,301,78194562};
    *eh5= hopital_5;
    lsthopinserer(l,eh5,5);
//
ajouthop(l);
lsthopafficher(l);


    return l;
}



