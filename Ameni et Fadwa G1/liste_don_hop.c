#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dons_hop_prim.h"
#include "liste_don_hop_prim.h"


void listebafficher (LISTEBESOIN l)
{
    int i;
    for (i=1;i<=(l->lg);i++)
    {
        printf("\n\n");

     structureafficher(l->elments[i]->hopital);
    tab1afficher(l->elments[i]->besoins);
    tab2afficher(l->elments[i]->dons);

    }
}

void liste_ajout_don (LISTEBESOIN l)
{
    donn n;
    int x;
    do
                        {printf("saisir le numero de l'hopital que vous voulez lui ajouter ses dons \n");
                        scanf("%i",&x);}
                        while ((x<1) || (x > (l->lg)));
    ajout_don(&n);
    inserertab2(l->elments[x]->dons,&n,(l->elments[x]->dons->lg)+1);
    TAB1 e=tab1creer();
                        e = l->elments[x]->besoins;
                        TAB2 e2= tab2creer();
                        e2= l->elments[x]->dons;
                        STRUCT e3=structurecreer();
                        e3 = l->elments[x]->hopital;
                        thestruct modif= {e,e2,e3};
                        insererb(l,&modif,x);
    structureafficher(l->elments[x]->hopital);
tab1afficher(l->elments[x]->besoins);
tab2afficher(l->elments[x]->dons);
}


LISTEBESOIN listebcreer(void)
{
    LISTEBESOIN l=(LISTEBESOIN)malloc (sizeof (mystruct));
    if (!l)
        {
        printf("probleme de creation\n");
        exit(0);
        }
        (l->lg)=0;
        return l;
}

void listebdetruire (LISTEBESOIN l)
{
    int i;
 if (! l->lg)
 {
     printf("liste vide \n");
 }
 else
 {
     for (i=1;i<=(l->lg);i++)
     {
         structuredetruire(l->elments[i]);
     }
 }
}

int estvideb (LISTEBESOIN l)
{
    return ((l->lg) == 0);
}

int estsatureeb(LISTEBESOIN l)
{
    return ((l->lg) == lg_max);
}

int listebtaille (LISTEBESOIN l)
{
    return (l->lg);
}

STRUCT recupererSTRUCT (LISTEBESOIN l,int i)
{
    STRUCT s=structurecreer();
    if (estvideb(l))
    {
        printf("liste vide\n");
    }
    else
    {
        if (i<1 || i>l->lg)
            printf("position invalide \n");
            else
            {
             s=(l->elments[i]);
            }
    }
    return s;
}

int insererb (LISTEBESOIN l,STRUCT s,int i)
{
    int succee=0;
    if (estsatureeb(l))
        printf("liste saturee\n");
    else
    {int j;
        if ((i<1)||(i>1+(l->lg)))
            printf("position invalide \n");
        else
        {
            succee=1;
            for (j=l->lg;j>=i;j--)
            {
                structureaffecterb(&l->elments[j+1],l->elments[j]);
            }

            structureaffecterb(&l->elments[i],s);
            (l->lg)++;
        }
    }
    return succee;
}


LISTEBESOIN initialisation (void)
{
    LISTEBESOIN l=listebcreer();

    TAB1 t_1=tab1creer();
    needd t_1_1 ={};
    needd t_1_2 ={"gel_hydroalcoolique",90};
    needd t_1_3 ={"charlotte",70};
    needd t_1_4 ={"bavettes",120};
    needs d_1_1;
    d_1_1 = needcreer();
    *d_1_1 = t_1_1;
    needs d_1_2;
    d_1_2 = needcreer();
    *d_1_2 = t_1_2;
    needs d_1_3;
    d_1_3 = needcreer();
    *d_1_3 = t_1_3;
    needs d_1_4;
    d_1_4 = needcreer();
    *d_1_4 = t_1_4;
    inserertab1(t_1,d_1_1,1);
    inserertab1(t_1,d_1_2,2);
    inserertab1(t_1,d_1_3,3);
    inserertab1(t_1,d_1_4,4);
    TAB2 t_2=tab2creer();
    donn t_2_1 ={};
    donn t_2_2 ={"gel_hydroalcoolique"};
    donn t_2_3 ={"charlotte","appareil_respiratoire"};
    donn t_2_4 ={"bavettes",800};
    donnations d_2_1;
    d_2_1 = doncreer();
    *d_2_1 = t_2_1;
    donnations d_2_2;
    d_2_2 = doncreer();
    *d_2_2 = t_2_2;
    donnations d_2_3;
    d_2_3 = doncreer();
    *d_2_3 = t_2_3;
    donnations d_2_4;
    d_2_4 = doncreer();
    *d_2_4 = t_2_4;
    inserertab2(t_2,d_2_1,1);
    inserertab2(t_2,d_2_2,2);
    inserertab2(t_2,d_2_3,3);
    inserertab2(t_2,d_2_4,4);
    STRUCTURE hop_1 = {"Charles Nicoll",1,"tunis",71578007};
    thestruct s_1 = {t_1,t_2,&hop_1};
    insererb(l,&s_1,1);

      //
    TAB1 t_3=tab1creer();
    needd t_3_1 ={};
    needd t_3_2 ={"masque_ffp2",85};
    needd t_3_3 = {"blouse",80};
    needs d_3_1;
    d_3_1 = needcreer();
    *d_3_1 = t_3_1;
    needs d_3_2;
    d_3_2 = needcreer();
    *d_3_2 = t_3_2;
    needs d_3_3;
    d_3_3 = needcreer();
    *d_3_3 = t_3_3;
    inserertab1(t_3,d_3_1,1);
    inserertab1(t_3,d_3_2,2);
    inserertab1(t_3,d_3_3,3);
    TAB2 t_4=tab2creer();
    donn t_4_1 ={};
    donn t_4_2 ={"masque_ffp2",100};
    donn t_4_3 ={"charlotte",30};
    donnations d_4_1;
    d_4_1 = doncreer();
    *d_4_1 = t_4_1;
    donnations d_4_2;
    d_4_2 = doncreer();
    *d_4_2 = t_4_2;
    donnations d_4_3;
    d_4_3 = doncreer();
    *d_4_3 = t_4_3;
    inserertab2(t_4,d_4_1,1);
    inserertab2(t_4,d_4_2,2);
    inserertab2(t_4,d_4_3,3);
    STRUCTURE hop_2 ={"Habib Bourguiba",2,"nabeul",74241511};
    thestruct s_2 = {t_3,t_4,&hop_2};
    insererb(l,&s_2,2);

     //
    TAB1 t_5=tab1creer();
    needd t_5_1 ={};
    needd t_5_2 ={"sur_chaussure",405};
    needd t_5_3 = {"oxymere_au_doit",80};
    needs d_5_1;
    d_5_1 = needcreer();
    *d_5_1 = t_5_1;
    needs d_5_2;
    d_5_2 = needcreer();
    *d_5_2 = t_5_2;
    needs d_5_3;
    d_5_3 = needcreer();
    *d_5_3 = t_5_3;
    inserertab1(t_5,d_5_1,1);
    inserertab1(t_5,d_5_2,2);
    inserertab1(t_5,d_5_3,3);
    TAB2 t_6=tab2creer();
    donn t_6_1 ={};
    donn t_6_2 ={"sur_chaussure"};
    donn t_6_3 ={"oxymere_au_doit",3000};
    donnations d_6_1;
    d_6_1 = doncreer();
    *d_6_1 = t_6_1;
    donnations d_6_2;
    d_6_2 = doncreer();
    *d_6_2 = t_6_2;
    donnations d_6_3;
    d_6_3 = doncreer();
    *d_6_3 = t_6_3;
    inserertab2(t_6,d_6_1,1);
    inserertab2(t_6,d_6_2,2);
    inserertab2(t_6,d_6_3,3);
    STRUCTURE hop_3 ={"Sahloul",3,"soussa",73369411};
    thestruct s_3 = {t_5,t_6,&hop_3};
    insererb(l,&s_3,3);


    //
    TAB1 t_7=tab1creer();
    needd t_7_1 ={};
    needd t_7_2 ={"bavettes",1000};
    needd t_7_3 = {"sur_chaussures",80};
    needs d_7_1;
    d_7_1 = needcreer();
    *d_7_1 = t_7_1;
    needs d_7_2;
    d_7_2 = needcreer();
    *d_7_2 = t_7_2;
    needs d_7_3;
    d_7_3 = needcreer();
    *d_7_3 = t_7_3;
    inserertab1(t_7,d_7_1,1);
    inserertab1(t_7,d_7_2,2);
    inserertab1(t_7,d_7_3,3);
    TAB2 t_8=tab2creer();
    donn t_8_1 ={};
    donn t_8_2 ={"sur_chaussure"};
    donn t_8_3 ={"bavettes",3000,"isolant_pour_transporter_les_malades_en_COVID19"};
    donnations d_8_1;
    d_8_1 = doncreer();
    *d_8_1 = t_8_1;
    donnations d_8_2;
    d_8_2 = doncreer();
    *d_8_2 = t_8_2;
    donnations d_8_3;
    d_8_3 = doncreer();
    *d_8_3 = t_8_3;
    inserertab2(t_8,d_8_1,1);
    inserertab2(t_8,d_8_2,2);
    inserertab2(t_8,d_8_3,3);
    STRUCTURE hop_4 ={"Habib thameur",4,"sfax",774241511};
    thestruct s_4 = {t_7,t_8,&hop_4};
    insererb(l,&s_4,4);
listebafficher(l);
return l;

}
LISTEBESOIN initialisation2 (void)
{
    LISTEBESOIN l=listebcreer();

    TAB1 t_1=tab1creer();
    needd t_1_1 ={};
    needd t_1_2 ={"gel_hydroalcoolique",90};
    needd t_1_3 ={"charlotte",70};
    needd t_1_4 ={"bavettes",120};
    needs d_1_1;
    d_1_1 = needcreer();
    *d_1_1 = t_1_1;
    needs d_1_2;
    d_1_2 = needcreer();
    *d_1_2 = t_1_2;
    needs d_1_3;
    d_1_3 = needcreer();
    *d_1_3 = t_1_3;
    needs d_1_4;
    d_1_4 = needcreer();
    *d_1_4 = t_1_4;
    inserertab1(t_1,d_1_1,1);
    inserertab1(t_1,d_1_2,2);
    inserertab1(t_1,d_1_3,3);
    inserertab1(t_1,d_1_4,4);
    TAB2 t_2=tab2creer();
    donn t_2_1 ={};
    donn t_2_2 ={"gel_hydroalcoolique"};
    donn t_2_3 ={"charlotte","appareil_respiratoire"};
    donn t_2_4 ={"bavettes",800};
    donnations d_2_1;
    d_2_1 = doncreer();
    *d_2_1 = t_2_1;
    donnations d_2_2;
    d_2_2 = doncreer();
    *d_2_2 = t_2_2;
    donnations d_2_3;
    d_2_3 = doncreer();
    *d_2_3 = t_2_3;
    donnations d_2_4;
    d_2_4 = doncreer();
    *d_2_4 = t_2_4;
    inserertab2(t_2,d_2_1,1);
    inserertab2(t_2,d_2_2,2);
    inserertab2(t_2,d_2_3,3);
    inserertab2(t_2,d_2_4,4);
    STRUCTURE hop_1 = {"Charles Nicoll",1,"tunis",71578007};
    thestruct s_1 = {t_1,t_2,&hop_1};
    insererb(l,&s_1,1);

      //
    TAB1 t_3=tab1creer();
    needd t_3_1 ={};
    needd t_3_2 ={"masque_ffp2",85};
    needd t_3_3 = {"blouse",80};
    needs d_3_1;
    d_3_1 = needcreer();
    *d_3_1 = t_3_1;
    needs d_3_2;
    d_3_2 = needcreer();
    *d_3_2 = t_3_2;
    needs d_3_3;
    d_3_3 = needcreer();
    *d_3_3 = t_3_3;
    inserertab1(t_3,d_3_1,1);
    inserertab1(t_3,d_3_2,2);
    inserertab1(t_3,d_3_3,3);
    TAB2 t_4=tab2creer();
    donn t_4_1 ={};
    donn t_4_2 ={"masque_ffp2",100};
    donn t_4_3 ={"charlotte",30};
    donnations d_4_1;
    d_4_1 = doncreer();
    *d_4_1 = t_4_1;
    donnations d_4_2;
    d_4_2 = doncreer();
    *d_4_2 = t_4_2;
    donnations d_4_3;
    d_4_3 = doncreer();
    *d_4_3 = t_4_3;
    inserertab2(t_4,d_4_1,1);
    inserertab2(t_4,d_4_2,2);
    inserertab2(t_4,d_4_3,3);
    STRUCTURE hop_2 ={"Habib Bourguiba",2,"nabeul",74241511};
    thestruct s_2 = {t_3,t_4,&hop_2};
    insererb(l,&s_2,2);

     //
    TAB1 t_5=tab1creer();
    needd t_5_1 ={};
    needd t_5_2 ={"sur_chaussure",405};
    needd t_5_3 = {"oxymere_au_doit",80};
    needs d_5_1;
    d_5_1 = needcreer();
    *d_5_1 = t_5_1;
    needs d_5_2;
    d_5_2 = needcreer();
    *d_5_2 = t_5_2;
    needs d_5_3;
    d_5_3 = needcreer();
    *d_5_3 = t_5_3;
    inserertab1(t_5,d_5_1,1);
    inserertab1(t_5,d_5_2,2);
    inserertab1(t_5,d_5_3,3);
    TAB2 t_6=tab2creer();
    donn t_6_1 ={};
    donn t_6_2 ={"sur_chaussure"};
    donn t_6_3 ={"oxymere_au_doit",3000};
    donnations d_6_1;
    d_6_1 = doncreer();
    *d_6_1 = t_6_1;
    donnations d_6_2;
    d_6_2 = doncreer();
    *d_6_2 = t_6_2;
    donnations d_6_3;
    d_6_3 = doncreer();
    *d_6_3 = t_6_3;
    inserertab2(t_6,d_6_1,1);
    inserertab2(t_6,d_6_2,2);
    inserertab2(t_6,d_6_3,3);
    STRUCTURE hop_3 ={"Sahloul",3,"soussa",73369411};
    thestruct s_3 = {t_5,t_6,&hop_3};
    insererb(l,&s_3,3);


    //
    TAB1 t_7=tab1creer();
    needd t_7_1 ={};
    needd t_7_2 ={"bavettes",1000};
    needd t_7_3 = {"sur_chaussures",80};
    needs d_7_1;
    d_7_1 = needcreer();
    *d_7_1 = t_7_1;
    needs d_7_2;
    d_7_2 = needcreer();
    *d_7_2 = t_7_2;
    needs d_7_3;
    d_7_3 = needcreer();
    *d_7_3 = t_7_3;
    inserertab1(t_7,d_7_1,1);
    inserertab1(t_7,d_7_2,2);
    inserertab1(t_7,d_7_3,3);
    TAB2 t_8=tab2creer();
    donn t_8_1 ={};
    donn t_8_2 ={"sur_chaussure"};
    donn t_8_3 ={"bavettes",3000,"isolant_pour_transporter_les_malades_en_COVID19"};
    donnations d_8_1;
    d_8_1 = doncreer();
    *d_8_1 = t_8_1;
    donnations d_8_2;
    d_8_2 = doncreer();
    *d_8_2 = t_8_2;
    donnations d_8_3;
    d_8_3 = doncreer();
    *d_8_3 = t_8_3;
    inserertab2(t_8,d_8_1,1);
    inserertab2(t_8,d_8_2,2);
    inserertab2(t_8,d_8_3,3);
    STRUCTURE hop_4 ={"Habib thameur",4,"sfax",774241511};
    thestruct s_4 = {t_7,t_8,&hop_4};
    insererb(l,&s_4,4);

    system("cls");
                        int v;
                       do
                        {printf("saisir le numero de l'hopital que vous voulez lui modifier ses besoins \n");
                        scanf("%i",&v);}
                        while ((v<1) || (v > (l->lg)));
                        int j;
                        structureafficher(l->elments[v]->hopital);
tab1afficher(l->elments[v]->besoins);

                        do
                        {
                        printf("entrez le  numero du besoin que vous voulez modifier \n");
                        scanf("%i",&j);
                        }
                        while((j > l->elments[v]->besoins->lg)||(j<2));
                        int qu;
                        printf("donner la nouvelle quantite en ce besoin\n");
                        scanf("%i",&qu);
                        l->elments[v]->besoins->tab1[j]->quantite = qu;
structureafficher(l->elments[v]->hopital);
tab1afficher(l->elments[v]->besoins);

printf("\n\n");
}

LISTEBESOIN initialisation3 (void)
{
    LISTEBESOIN l=listebcreer();

    TAB1 t_1=tab1creer();
    needd t_1_1 ={};
    needd t_1_2 ={"gel_hydroalcoolique",90};
    needd t_1_3 ={"charlotte",70};
    needd t_1_4 ={"bavettes",120};
    needs d_1_1;
    d_1_1 = needcreer();
    *d_1_1 = t_1_1;
    needs d_1_2;
    d_1_2 = needcreer();
    *d_1_2 = t_1_2;
    needs d_1_3;
    d_1_3 = needcreer();
    *d_1_3 = t_1_3;
    needs d_1_4;
    d_1_4 = needcreer();
    *d_1_4 = t_1_4;
    inserertab1(t_1,d_1_1,1);
    inserertab1(t_1,d_1_2,2);
    inserertab1(t_1,d_1_3,3);
    inserertab1(t_1,d_1_4,4);
    TAB2 t_2=tab2creer();
    donn t_2_1 ={};
    donn t_2_2 ={"gel_hydroalcoolique"};
    donn t_2_3 ={"charlotte","appareil_respiratoire"};
    donn t_2_4 ={"bavettes",800};
    donnations d_2_1;
    d_2_1 = doncreer();
    *d_2_1 = t_2_1;
    donnations d_2_2;
    d_2_2 = doncreer();
    *d_2_2 = t_2_2;
    donnations d_2_3;
    d_2_3 = doncreer();
    *d_2_3 = t_2_3;
    donnations d_2_4;
    d_2_4 = doncreer();
    *d_2_4 = t_2_4;
    inserertab2(t_2,d_2_1,1);
    inserertab2(t_2,d_2_2,2);
    inserertab2(t_2,d_2_3,3);
    inserertab2(t_2,d_2_4,4);
    STRUCTURE hop_1 = {"Charles Nicoll",1,"tunis",71578007};
    thestruct s_1 = {t_1,t_2,&hop_1};
    insererb(l,&s_1,1);

      //
    TAB1 t_3=tab1creer();
    needd t_3_1 ={};
    needd t_3_2 ={"masque_ffp2",85};
    needd t_3_3 = {"blouse",80};
    needs d_3_1;
    d_3_1 = needcreer();
    *d_3_1 = t_3_1;
    needs d_3_2;
    d_3_2 = needcreer();
    *d_3_2 = t_3_2;
    needs d_3_3;
    d_3_3 = needcreer();
    *d_3_3 = t_3_3;
    inserertab1(t_3,d_3_1,1);
    inserertab1(t_3,d_3_2,2);
    inserertab1(t_3,d_3_3,3);
    TAB2 t_4=tab2creer();
    donn t_4_1 ={};
    donn t_4_2 ={"masque_ffp2",100};
    donn t_4_3 ={"charlotte",30};
    donnations d_4_1;
    d_4_1 = doncreer();
    *d_4_1 = t_4_1;
    donnations d_4_2;
    d_4_2 = doncreer();
    *d_4_2 = t_4_2;
    donnations d_4_3;
    d_4_3 = doncreer();
    *d_4_3 = t_4_3;
    inserertab2(t_4,d_4_1,1);
    inserertab2(t_4,d_4_2,2);
    inserertab2(t_4,d_4_3,3);
    STRUCTURE hop_2 ={"Habib Bourguiba",2,"nabeul",74241511};
    thestruct s_2 = {t_3,t_4,&hop_2};
    insererb(l,&s_2,2);

     //
    TAB1 t_5=tab1creer();
    needd t_5_1 ={};
    needd t_5_2 ={"sur_chaussure",405};
    needd t_5_3 = {"oxymere_au_doit",80};
    needs d_5_1;
    d_5_1 = needcreer();
    *d_5_1 = t_5_1;
    needs d_5_2;
    d_5_2 = needcreer();
    *d_5_2 = t_5_2;
    needs d_5_3;
    d_5_3 = needcreer();
    *d_5_3 = t_5_3;
    inserertab1(t_5,d_5_1,1);
    inserertab1(t_5,d_5_2,2);
    inserertab1(t_5,d_5_3,3);
    TAB2 t_6=tab2creer();
    donn t_6_1 ={};
    donn t_6_2 ={"sur_chaussure"};
    donn t_6_3 ={"oxymere_au_doit",3000};
    donnations d_6_1;
    d_6_1 = doncreer();
    *d_6_1 = t_6_1;
    donnations d_6_2;
    d_6_2 = doncreer();
    *d_6_2 = t_6_2;
    donnations d_6_3;
    d_6_3 = doncreer();
    *d_6_3 = t_6_3;
    inserertab2(t_6,d_6_1,1);
    inserertab2(t_6,d_6_2,2);
    inserertab2(t_6,d_6_3,3);
    STRUCTURE hop_3 ={"Sahloul",3,"soussa",73369411};
    thestruct s_3 = {t_5,t_6,&hop_3};
    insererb(l,&s_3,3);


    //
    TAB1 t_7=tab1creer();
    needd t_7_1 ={};
    needd t_7_2 ={"bavettes",1000};
    needd t_7_3 = {"sur_chaussures",80};
    needs d_7_1;
    d_7_1 = needcreer();
    *d_7_1 = t_7_1;
    needs d_7_2;
    d_7_2 = needcreer();
    *d_7_2 = t_7_2;
    needs d_7_3;
    d_7_3 = needcreer();
    *d_7_3 = t_7_3;
    inserertab1(t_7,d_7_1,1);
    inserertab1(t_7,d_7_2,2);
    inserertab1(t_7,d_7_3,3);
    TAB2 t_8=tab2creer();
    donn t_8_1 ={};
    donn t_8_2 ={"sur_chaussure"};
    donn t_8_3 ={"bavettes",3000,"isolant_pour_transporter_les_malades_en_COVID19"};
    donnations d_8_1;
    d_8_1 = doncreer();
    *d_8_1 = t_8_1;
    donnations d_8_2;
    d_8_2 = doncreer();
    *d_8_2 = t_8_2;
    donnations d_8_3;
    d_8_3 = doncreer();
    *d_8_3 = t_8_3;
    inserertab2(t_8,d_8_1,1);
    inserertab2(t_8,d_8_2,2);
    inserertab2(t_8,d_8_3,3);
    STRUCTURE hop_4 ={"Habib thameur",4,"sfax",774241511};
    thestruct s_4 = {t_7,t_8,&hop_4};
    insererb(l,&s_4,4);
    int w,test=0,i=1;
    do
                        {printf("saisir le numero de l'hopital que vous voulez lui ajouter un besoin\n");


                        scanf("%i",&w);}
                        while ((w<1) || (w > (l->lg)));
                        needd n;
                        ajout_besoin(&n);
                        printf("%i\n",inserertab1 (l->elments[w]->besoins,&n,(l->elments[w]->besoins->lg)+1));
                        TAB1 e=tab1creer();
                        e = l->elments[w]->besoins;
                        TAB2 e2= tab2creer();
                        e2= l->elments[w]->dons;
                        STRUCT e3=structurecreer();
                        e3 = l->elments[w]->hopital;
                        thestruct modif= {e,e2,e3};
                        insererb(l,&modif,w);
                        structureafficher(l->elments[w]->hopital);
tab1afficher(l->elments[w]->besoins);
tab2afficher(l->elments[w]->dons);

return l;
}


LISTEBESOIN initialisation4 (void)
{
    LISTEBESOIN l=listebcreer();

    TAB1 t_1=tab1creer();
    needd t_1_1 ={};
    needd t_1_2 ={"gel_hydroalcoolique",90};
    needd t_1_3 ={"charlotte",70};
    needd t_1_4 ={"bavettes",120};
    needs d_1_1;
    d_1_1 = needcreer();
    *d_1_1 = t_1_1;
    needs d_1_2;
    d_1_2 = needcreer();
    *d_1_2 = t_1_2;
    needs d_1_3;
    d_1_3 = needcreer();
    *d_1_3 = t_1_3;
    needs d_1_4;
    d_1_4 = needcreer();
    *d_1_4 = t_1_4;
    inserertab1(t_1,d_1_1,1);
    inserertab1(t_1,d_1_2,2);
    inserertab1(t_1,d_1_3,3);
    inserertab1(t_1,d_1_4,4);
    TAB2 t_2=tab2creer();
    donn t_2_1 ={};
    donn t_2_2 ={"gel_hydroalcoolique"};
    donn t_2_3 ={"charlotte","appareil_respiratoire"};
    donn t_2_4 ={"bavettes",800};
    donnations d_2_1;
    d_2_1 = doncreer();
    *d_2_1 = t_2_1;
    donnations d_2_2;
    d_2_2 = doncreer();
    *d_2_2 = t_2_2;
    donnations d_2_3;
    d_2_3 = doncreer();
    *d_2_3 = t_2_3;
    donnations d_2_4;
    d_2_4 = doncreer();
    *d_2_4 = t_2_4;
    inserertab2(t_2,d_2_1,1);
    inserertab2(t_2,d_2_2,2);
    inserertab2(t_2,d_2_3,3);
    inserertab2(t_2,d_2_4,4);
    STRUCTURE hop_1 = {"Charles Nicoll",1,"tunis",71578007};
    thestruct s_1 = {t_1,t_2,&hop_1};
    insererb(l,&s_1,1);

      //
    TAB1 t_3=tab1creer();
    needd t_3_1 ={};
    needd t_3_2 ={"masque_ffp2",85};
    needd t_3_3 = {"blouse",80};
    needs d_3_1;
    d_3_1 = needcreer();
    *d_3_1 = t_3_1;
    needs d_3_2;
    d_3_2 = needcreer();
    *d_3_2 = t_3_2;
    needs d_3_3;
    d_3_3 = needcreer();
    *d_3_3 = t_3_3;
    inserertab1(t_3,d_3_1,1);
    inserertab1(t_3,d_3_2,2);
    inserertab1(t_3,d_3_3,3);
    TAB2 t_4=tab2creer();
    donn t_4_1 ={};
    donn t_4_2 ={"masque_ffp2",100};
    donn t_4_3 ={"charlotte",30};
    donnations d_4_1;
    d_4_1 = doncreer();
    *d_4_1 = t_4_1;
    donnations d_4_2;
    d_4_2 = doncreer();
    *d_4_2 = t_4_2;
    donnations d_4_3;
    d_4_3 = doncreer();
    *d_4_3 = t_4_3;
    inserertab2(t_4,d_4_1,1);
    inserertab2(t_4,d_4_2,2);
    inserertab2(t_4,d_4_3,3);
    STRUCTURE hop_2 ={"Habib Bourguiba",2,"nabeul",74241511};
    thestruct s_2 = {t_3,t_4,&hop_2};
    insererb(l,&s_2,2);

     //
    TAB1 t_5=tab1creer();
    needd t_5_1 ={};
    needd t_5_2 ={"sur_chaussure",405};
    needd t_5_3 = {"oxymere_au_doit",80};
    needs d_5_1;
    d_5_1 = needcreer();
    *d_5_1 = t_5_1;
    needs d_5_2;
    d_5_2 = needcreer();
    *d_5_2 = t_5_2;
    needs d_5_3;
    d_5_3 = needcreer();
    *d_5_3 = t_5_3;
    inserertab1(t_5,d_5_1,1);
    inserertab1(t_5,d_5_2,2);
    inserertab1(t_5,d_5_3,3);
    TAB2 t_6=tab2creer();
    donn t_6_1 ={};
    donn t_6_2 ={"sur_chaussure"};
    donn t_6_3 ={"oxymere_au_doit",3000};
    donnations d_6_1;
    d_6_1 = doncreer();
    *d_6_1 = t_6_1;
    donnations d_6_2;
    d_6_2 = doncreer();
    *d_6_2 = t_6_2;
    donnations d_6_3;
    d_6_3 = doncreer();
    *d_6_3 = t_6_3;
    inserertab2(t_6,d_6_1,1);
    inserertab2(t_6,d_6_2,2);
    inserertab2(t_6,d_6_3,3);
    STRUCTURE hop_3 ={"Sahloul",3,"soussa",73369411};
    thestruct s_3 = {t_5,t_6,&hop_3};
    insererb(l,&s_3,3);


    //
    TAB1 t_7=tab1creer();
    needd t_7_1 ={};
    needd t_7_2 ={"bavettes",1000};
    needd t_7_3 = {"sur_chaussures",80};
    needs d_7_1;
    d_7_1 = needcreer();
    *d_7_1 = t_7_1;
    needs d_7_2;
    d_7_2 = needcreer();
    *d_7_2 = t_7_2;
    needs d_7_3;
    d_7_3 = needcreer();
    *d_7_3 = t_7_3;
    inserertab1(t_7,d_7_1,1);
    inserertab1(t_7,d_7_2,2);
    inserertab1(t_7,d_7_3,3);
    TAB2 t_8=tab2creer();
    donn t_8_1 ={};
    donn t_8_2 ={"sur_chaussure"};
    donn t_8_3 ={"bavettes",3000,"isolant_pour_transporter_les_malades_en_COVID19"};
    donnations d_8_1;
    d_8_1 = doncreer();
    *d_8_1 = t_8_1;
    donnations d_8_2;
    d_8_2 = doncreer();
    *d_8_2 = t_8_2;
    donnations d_8_3;
    d_8_3 = doncreer();
    *d_8_3 = t_8_3;
    inserertab2(t_8,d_8_1,1);
    inserertab2(t_8,d_8_2,2);
    inserertab2(t_8,d_8_3,3);
    STRUCTURE hop_4 ={"Habib thameur",4,"sfax",774241511};
    thestruct s_4 = {t_7,t_8,&hop_4};
    insererb(l,&s_4,4);

    int i,v,w;
                        do
                        {printf("saisir le numero de l'hopital que vous voulez lui modifier ses besoins \n");
                        scanf("%i",&v);}
                        while ((v<1) || (v > (l->lg)));
                        structureafficher(l->elments[v]->hopital);
tab1afficher(l->elments[v]->besoins);
                                do
                                    {printf("donner la position du besoin que vous voulez le supprimer \n");
                                    scanf("%i",&w);}
                                    while ((w<1)||(w>(l->elments[v]->besoins->lg)));


elemtab1supp(l->elments[v]->besoins,w);

printf("\n\napres la suppression\n");
 structureafficher(l->elments[v]->hopital);
tab1afficher(l->elments[v]->besoins);

printf("\n\n");

return l;

}




LISTEBESOIN initialisation5 (void)
{
    LISTEBESOIN l=listebcreer();

    TAB1 t_1=tab1creer();
    needd t_1_1 ={};
    needd t_1_2 ={"gel_hydroalcoolique",90};
    needd t_1_3 ={"charlotte",70};
    needd t_1_4 ={"bavettes",120};
    needs d_1_1;
    d_1_1 = needcreer();
    *d_1_1 = t_1_1;
    needs d_1_2;
    d_1_2 = needcreer();
    *d_1_2 = t_1_2;
    needs d_1_3;
    d_1_3 = needcreer();
    *d_1_3 = t_1_3;
    needs d_1_4;
    d_1_4 = needcreer();
    *d_1_4 = t_1_4;
    inserertab1(t_1,d_1_1,1);
    inserertab1(t_1,d_1_2,2);
    inserertab1(t_1,d_1_3,3);
    inserertab1(t_1,d_1_4,4);
    TAB2 t_2=tab2creer();
    donn t_2_1 ={};
    donn t_2_2 ={"gel_hydroalcoolique"};
    donn t_2_3 ={"charlotte","appareil_respiratoire"};
    donn t_2_4 ={"bavettes",800};
    donnations d_2_1;
    d_2_1 = doncreer();
    *d_2_1 = t_2_1;
    donnations d_2_2;
    d_2_2 = doncreer();
    *d_2_2 = t_2_2;
    donnations d_2_3;
    d_2_3 = doncreer();
    *d_2_3 = t_2_3;
    donnations d_2_4;
    d_2_4 = doncreer();
    *d_2_4 = t_2_4;
    inserertab2(t_2,d_2_1,1);
    inserertab2(t_2,d_2_2,2);
    inserertab2(t_2,d_2_3,3);
    inserertab2(t_2,d_2_4,4);
    STRUCTURE hop_1 = {"Charles Nicoll",1,"tunis",71578007};
    thestruct s_1 = {t_1,t_2,&hop_1};
    insererb(l,&s_1,1);

      //
    TAB1 t_3=tab1creer();
    needd t_3_1 ={};
    needd t_3_2 ={"masque_ffp2",85};
    needd t_3_3 = {"blouse",80};
    needs d_3_1;
    d_3_1 = needcreer();
    *d_3_1 = t_3_1;
    needs d_3_2;
    d_3_2 = needcreer();
    *d_3_2 = t_3_2;
    needs d_3_3;
    d_3_3 = needcreer();
    *d_3_3 = t_3_3;
    inserertab1(t_3,d_3_1,1);
    inserertab1(t_3,d_3_2,2);
    inserertab1(t_3,d_3_3,3);
    TAB2 t_4=tab2creer();
    donn t_4_1 ={};
    donn t_4_2 ={"masque_ffp2",100};
    donn t_4_3 ={"charlotte",30};
    donnations d_4_1;
    d_4_1 = doncreer();
    *d_4_1 = t_4_1;
    donnations d_4_2;
    d_4_2 = doncreer();
    *d_4_2 = t_4_2;
    donnations d_4_3;
    d_4_3 = doncreer();
    *d_4_3 = t_4_3;
    inserertab2(t_4,d_4_1,1);
    inserertab2(t_4,d_4_2,2);
    inserertab2(t_4,d_4_3,3);
    STRUCTURE hop_2 ={"Habib Bourguiba",2,"nabeul",74241511};
    thestruct s_2 = {t_3,t_4,&hop_2};
    insererb(l,&s_2,2);

     //
    TAB1 t_5=tab1creer();
    needd t_5_1 ={};
    needd t_5_2 ={"sur_chaussure",405};
    needd t_5_3 = {"oxymere_au_doit",80};
    needs d_5_1;
    d_5_1 = needcreer();
    *d_5_1 = t_5_1;
    needs d_5_2;
    d_5_2 = needcreer();
    *d_5_2 = t_5_2;
    needs d_5_3;
    d_5_3 = needcreer();
    *d_5_3 = t_5_3;
    inserertab1(t_5,d_5_1,1);
    inserertab1(t_5,d_5_2,2);
    inserertab1(t_5,d_5_3,3);
    TAB2 t_6=tab2creer();
    donn t_6_1 ={};
    donn t_6_2 ={"sur_chaussure"};
    donn t_6_3 ={"oxymere_au_doit",3000};
    donnations d_6_1;
    d_6_1 = doncreer();
    *d_6_1 = t_6_1;
    donnations d_6_2;
    d_6_2 = doncreer();
    *d_6_2 = t_6_2;
    donnations d_6_3;
    d_6_3 = doncreer();
    *d_6_3 = t_6_3;
    inserertab2(t_6,d_6_1,1);
    inserertab2(t_6,d_6_2,2);
    inserertab2(t_6,d_6_3,3);
    STRUCTURE hop_3 ={"Sahloul",3,"soussa",73369411};
    thestruct s_3 = {t_5,t_6,&hop_3};
    insererb(l,&s_3,3);


    //
    TAB1 t_7=tab1creer();
    needd t_7_1 ={};
    needd t_7_2 ={"bavettes",1000};
    needd t_7_3 = {"sur_chaussures",80};
    needs d_7_1;
    d_7_1 = needcreer();
    *d_7_1 = t_7_1;
    needs d_7_2;
    d_7_2 = needcreer();
    *d_7_2 = t_7_2;
    needs d_7_3;
    d_7_3 = needcreer();
    *d_7_3 = t_7_3;
    inserertab1(t_7,d_7_1,1);
    inserertab1(t_7,d_7_2,2);
    inserertab1(t_7,d_7_3,3);
    TAB2 t_8=tab2creer();
    donn t_8_1 ={};
    donn t_8_2 ={"sur_chaussure"};
    donn t_8_3 ={"bavettes",3000,"isolant_pour_transporter_les_malades_en_COVID19"};
    donnations d_8_1;
    d_8_1 = doncreer();
    *d_8_1 = t_8_1;
    donnations d_8_2;
    d_8_2 = doncreer();
    *d_8_2 = t_8_2;
    donnations d_8_3;
    d_8_3 = doncreer();
    *d_8_3 = t_8_3;
    inserertab2(t_8,d_8_1,1);
    inserertab2(t_8,d_8_2,2);
    inserertab2(t_8,d_8_3,3);
    STRUCTURE hop_4 ={"Habib thameur",4,"sfax",774241511};
    thestruct s_4 = {t_7,t_8,&hop_4};
    insererb(l,&s_4,4);


liste_ajout_don(l) ;


return l;

}
