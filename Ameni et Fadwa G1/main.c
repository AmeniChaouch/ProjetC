#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "patientprim.h"
#include "LSTPRIM.h"
#include "hopitauxprim.h"
#include "HOPPRIM.h"
#include "GRAPH.h"
#include "LSTPTR.h"
#include "quarantprim.h"
#include "QTRPRIM.h"
#include "liste_don_hop_prim.h"
#include "dons_hop_prim.h"
#include"lieu.h"
#include "RESEAU.h"
#define max 100
//
//
void menu (LISTE,lsthop,listeqtr,LISTEBESOIN,lieux );
void continuation (LISTE,lsthop,listeqtr,LISTEBESOIN,lieux );


//
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
//
int main()
{

LISTE a=initia();
lsthop h=inithop();
listeqtr q=initqtr();
LISTEBESOIN hb=initialisation();
lieux ll=initlieux();

menu(a,h,q,hb,ll);
continuation(a,h,q,hb,ll);

return 0;
}

//
//
//
//
void menu (LISTE m ,lsthop h,listeqtr q,LISTEBESOIN hb,lieux l)
{char* ch;

     int x,y,a,b,c,d,z,choix,rr;
    system("cls");
    printf("             ===                \n");
    printf("\n");
    printf("   veuillez choisir une operation   ");
    printf("\n");
    printf("\n");
    printf("1- Gestion des patients - Gestion de l'hopital  \n");
    printf("2- Gestion des dons \n");
    printf("3- Gestion des patients en quarantaine \n");
    printf("             ===                 \n");
    printf("4_ Informations utiles pour notre utilisateur\n");
    scanf("%i",&a);
    switch (a)
    {

    case 1:
        system("cls");

        {
            printf("                ===========================\n");
            printf("                ===========================\n");
            printf("                  1-Gestion des patients \n\n");
            printf("                  2-gestion des hopitaux\n");
            printf("                ===========================\n");
            printf("                ===========================\n");
            scanf("%i",&c);
            switch(c)
        {
        case 1:
            {
                system("cls");
                printf("       La Gestion des Patients - Gestion de l'hopital     \n");
                printf("                          ====                            \n");
                printf("\n");
                printf("              Veuillez choisir une operation              \n");
                printf("       1- afficher tous les patients dans l'hopital\n");
                printf("          2- Chercher un ou plusieurs patients \n");
                printf("             3- Modifier l'etat d'un patient \n");
                printf("                4- Supprimer les patients gueries \n");
                printf("                     5-Ajouter un patient\n");
                printf("    6- Afficher le graphe de la localisation graphique des patients\n");

                scanf("%i",&b);
                switch(b)
                {
                case 1:
                system("cls");
                printf("les patients sont :\n \n");
                listeafficher(m);
                continuation(m,h,q,hb,l);
                break;
                case 2:
                {
                    system("cls");
                    printf ("voulez vous chercher un seul patient(1) ou plusieurs(0)?\n");
                    scanf("%i",&x);
                    switch(x)
                    {
                    case 1:
                        {system("cls");
                        listechercherpatient(m);
                        continuation(m,h,q,hb,l);
                    break;}
                    case 0:
                    {
                        system("cls");
                        printf("Par quel parametre?\nchoisissez 1:age 2:adresse 3:genre 4:etat \n");
                        scanf("%i",&y);
                        switch (y)
                        {
                        case 1:
                            system("cls");
                            listechercher_age(m);
                            continuation(m,h,q,hb,l);
                        break;

                        case 2:
                            system("cls");
                            listecherche_ad(m);
                            continuation(m,h,q,hb,l);
                            break;
                        case 3:
                            system("cls");
                            listecherche_g(m);
                            continuation(m,h,q,hb,l);
                        break;
                        case 4:
                            system("cls");
                            listecherche_et(m);
                            continuation(m,h,q,hb,l);
                        break;
                          default :
                            {printf("erreur de choix\n");
                            continuation(m,h,q,hb,l);}
                    }
                    break;}

                break;
                 default:
                            {
                                printf("erreur de choix\n");
                                continuation(m,h,q,hb,l);
                            }}

            case 3:
            {
            int n,i=1,test=0;
            char ch[10];
            system("cls");
            do
            {
            printf("Quel est le numero du patient que vous voulez lui changer l'etat?\n");
            scanf("%i",&n);
            }
            while ((n<410)||(n>420));
            while ((i<=listetaille(m))&&(!test))
            {
                if ((recuperer(m,i)->num)==n)
                {
                    test=1;
                    do
                    {
                        fflush(stdin);
                    printf("donner le nouvel etat du patient \n");
                    fgets(ch,10,stdin);
                    }
                    while ((ch[0]!='N')&&(ch[0]!='G')&&(ch[0]!='C'));
                    strcpy((recuperer(m,i)->etat),ch);
                    elementafficher(recuperer(m,i));
                }
                else
                    i++;
            }
            continuation(m,h,q,hb,l);
            break;
            }

        case 4:
            {
                system("cls");
               printf("la liste avant la suppression\n");
               listeafficher(m);
               printf("\n\n\n la liste apres suppression\n\n");
               supprimer(m);
               continuation(m,h,q,hb,l);
               break;
            }
        case 5:
            {
                system("cls");
                    ajout(m);
                    continuation(m,h,q,hb,l);
            }
            case 6:
            {
               GRAPH g1=new_graph(m);

ajout_lien(g1,m->patients[1]->num,m->patients[3]->num,m);
ajout_lien(g1,m->patients[1]->num,m->patients[2]->num,m);
ajout_lien(g1,m->patients[3]->num,m->patients[4]->num,m);
ajout_lien(g1,m->patients[5]->num,m->patients[6]->num,m);
ajout_lien(g1,m->patients[6]->num,m->patients[2]->num,m);

print_console(g1);
supprime_graph(g1,m);
continuation(m,h,q,hb,l);
break;
            }
             default:
            {
                printf("erreur de choix\n");
                continuation(m,h,q,hb,l);
            }

                }

            }

        }

        case 2:

            system("cls");
            printf("      1- afficher les hopitaux \n");
             printf("      2- Ajouter un hopital    \n");
            printf("      3- Modifier les informations d'un hopital \n");
            printf("\n     =======================    \n");
            //
            //
            scanf("%i",&d);
            switch (d)
            {
            case 1:

                system("cls");
                lsthopafficher(h);
                continuation(m,h,q,hb,l);
            break;

            case 2:

                system("cls");
                h=inithop2();
                continuation(m,h,q,hb,l);
                break;

            case 3:
                {
                    int n;
                    system("cls");

                do
                {printf("donner le numero de l'hopital a modifier\n");
                scanf("%i",&n);}
                while ((n<0)||(n>7));
                modification(h,n);
                continuation(m,h,q,hb,l);
                break;
                }
                   default :
                            {printf("erreur de choix\n");
                            continuation(m,h,q,hb,l);}
            }break;

            //
            //

               default:{printf("erreur de choix\n");
                            continuation(m,h,q,hb,l);} }}
            case 3:
               {

                   system("cls");
                   printf("   1-Mise a jour des lieux :)  \n");
                   printf("   2-ajouter un quarantaine\n ======================================\n");
                    printf("  3-Afficher la liste des lieux de confinement   \n");
                    printf("  4-afficher le reseau des quarantaines ");
                    scanf("%i",&choix);
                    switch (choix)
                    {
                    case 1:
                        system("cls");
                        q=initqtr();
                        continuation(m,h,q,hb,l);
                        break;
                    case 3:
                        system("cls");
                        l=initlieux();
                        continuation(m,h,q,hb,l);
                        break;
                    case 4:
                        {system("cls");
                        GRAPHRES g= new_graph_res(20);

ajout_lien_res (g,1,6,20);
ajout_lien_res (g,1,2,20);
ajout_lien_res (g,2,7,20);
ajout_lien_res (g,2,8,20);
ajout_lien_res (g,2,9,20);
ajout_lien_res (g,3,10,20);
ajout_lien_res (g,3,11,20);
ajout_lien_res (g,3,12,20);
ajout_lien_res (g,3,13,20);
ajout_lien_res (g,4,14,20);
ajout_lien_res (g,4,15,20);
ajout_lien_res (g,4,16,20);
ajout_lien_res (g,4,17,20);
ajout_lien_res (g,5,18,20);
ajout_lien_res (g,5,19,20);
ajout_lien_res (g,5,20,20);
ajout_lien_res (g,5,21,20);
ajout_lien_res (g,5,10,20);
ajout_lien_res (g,2,9,20);
print_console_res(g);
affiche_graphe_res(g,20);
supprime_graph_res(g,20);

break;}
                    case 2:
                         system("cls");
                        q=initqtr3();

                        continuation(m,h,q,hb,l);
                        break;
                    }
                     default :
                            {printf("erreur de choix\n");
                            continuation(m,h,q,hb,l);}

break;
            }
            case 2:
    {system("cls");
        printf("\n                     =========================    \n");
                    printf("   1- Afficher la listes des hopitaux avec ces besoins et les dons donnees\n");
                    printf("   2- Ajouter un besoin a un hopital   \n");
                    printf("   3- Modifier le besoin d'un hopital  \n");
                    printf("   4- Supprimer un besoin d'un hopital \n");
                    printf("   5- Ajouter un don \n");
                    int j;
                    scanf("%i",&j);
                    switch (j)
                    {
                    case 1:
                        {system("cls");
                         hb=initialisation();
                        continuation(m,h,q,hb,l);
                        break;}

                    case 2:
                        {system("cls");
                        initialisation3();
                        continuation(m,h,q,hb,l);
                        break;}


                    case 3:
                        {
                            system("cls");
                       hb=initialisation2();
                       continuation(m,h,q,hb,l);
                        break;
                        }

                    case 4:
                        {int i;
                            system("cls");
                            printf("est-ce que vous voulez vraiment supprimer quelques besoins \n 1:oui  2:non\n");
                        scanf("%i",&i);
                        if (i == 1)
                            {hb = initialisation4();
                            continuation(m,h,q,hb,l);}
                            else
                                continuation(m,h,q,hb,l);
                        break;
                        }

                    case 5:
                        {
                            int v,n;
                            system("cls");
                            hb = initialisation5();
                            continuation(m,h,q,hb,l);

                        break;
                        }

                        default :
                            {printf("erreur de choix\n");
                            continuation(m,h,q,hb,l);}
                    }
                    }

case 4:
    system("cls");
    printf("1-savoir si j'ai la possibilite d'etre atteint par le corona.\n");
    printf("2-avoir l'hopital le plus proche\n");

    scanf("%i",&rr);
    switch(rr)
    {
case 1:
    system("cls");
    q=initqtr2();
    continuation(m,h,q,hb,l);
    break;
case 2:
    system("cls");

    printf("quelle est votre adresse:");
    scanf("%s",&ch);
    printf("donnez la specialite 1:chirurgie 2:cardiologie 4:dialyse 3:radiologie");

    scanf("%i",&c);
    recherche(h,&ch,c);
    continuation(m,h,q,hb,l);
    break;
default :
    printf("erreur de choix");
    continuation(m,h,q,hb,l);
    }

break;
}
}

void continuation (LISTE m,lsthop h,listeqtr q,LISTEBESOIN hb,lieux l)
{
    int v;
    printf("voulez-vous vraiment continuer ?\n 1:continuer 0:sinon \n");
       scanf("%i",&v);
       if (v==1)
        menu(m,h,q,hb,l);
       else
        exit (0);
}

//
