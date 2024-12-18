#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lg_max 200
#include "QTRPRIM.h"
#include"lieu.h"
//primitives de la liste qtr
int verif (char *ch )
{
    int i=0,test=0;
    int l=strlen(ch);
     while ((i<l)&&(!test))
    {
        if (((ch[i]>='a')&& (ch[i]<='z'))||((ch[i]>='A')&&(ch[i]<='Z')))
           {
            test=1;
           }
        else
            {i++;
            }
    }
    return test;
}

elemqtr ajoutqtr (listeqtr l)
{
  elemqtr e=elemqtrcreer();
   elemqtrlire(&e);
   insererqtr(l,e,e->num);
   return e;
}

listeqtr listeqtrcreer(void)
{
    listeqtr L;
    L=(listeqtr) malloc ( lg_max*sizeof(structlisteqtr) );
    if(!L)
    {
           printf("\nProbleme de memoire") ;
    }
(L->lg)=0;
}
int insererqtr (listeqtr l, elemqtr e, int pos)
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
            (l->lg)++;
           for(i=l->lg;i>=pos;i--)
                elemqtraffecter(&(l->quarantaines[i+1]),l->quarantaines[i]);
           elemqtraffecter(&(l->quarantaines[pos]),e);

        }
    }
    return succee;
}
void listeqtrafficher (listeqtr l)
{
    int i;
    for(i=1;i<=(l->lg);i++)
        {printf ("==============le quarantaine %i==============\n",i);
            elemqtrafficher(l->quarantaines[i]);
        printf("\n\n");}
}
elemqtr recupererqtr (listeqtr l,int pos)
{
    elemqtr elt;
    elt = elementcreer();
    if (l->lg==0)
    printf ("\nListe vide");
    else
    {
if ((pos < 1) || (pos > l->lg))
    {printf ("\nPosition invalide");}
    else
    elt = (l->quarantaines[pos]);
    }
return(elt);
}



//primitives de la liste des maladies
listemaladies listemaladiescreer(void)
{
    listemaladies L;
    L=(listemaladies) malloc (sizeof(structmaladies));
    if(!L)
    {
           printf("\nProbleme de memoire") ;
    }
(L->lg)=0;
}
int inserermaladies (listemaladies l, elemch e, int pos)
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
                elemchaffecter(&(l->maladies[i+1]),l->maladies[i]);
           elemchaffecter(&(l->maladies[pos]),e);
           (l->lg)++;
        }
    }
    return succee;
}
void listemaladiesafficher(listemaladies l)
{int i;
    printf("les maladies chroniques sont  :");
    for(i = 1;i <= l->lg;i++)
        elemchafficher(l->maladies[i]);
printf("\n");

}
//primitives de la liste des personnes
listepersonnes listepersonnescreer(void)
{
    listepersonnes L;
    L=(listepersonnes) malloc (sizeof(structpersonnes));
    if(!L)
    {
           printf("\nProbleme de memoire") ;
    }
(L->lg)=0;
}
void listepersonnesafficher(listepersonnes l)
{int i;
    printf("les personnes en contact sont :");

    for(i = 1;i <= l->lg;i++)
        elemchafficher(l->personnes[i]);
}
int insererpersonnes (listepersonnes l, elemch e, int pos)
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
                elemchaffecter(&(l->personnes[i+1]),l->personnes[i]);
           elemchaffecter(&(l->personnes[pos]),e);
           (l->lg)++;
        }
    }
    return succee;
}
//lieux
listelieux listelieuxcreer(void)
{
    listelieux L;
    L=(listelieux) malloc (sizeof(structlieux));
    if(!L)
    {
           printf("\nProbleme de memoire") ;
    }
(L->lg)=0;
}
int insererlieux (listelieux l, elemch e, int pos)
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
                elemchaffecter(&(l->lieux[i+1]),l->lieux[i]);
           elemchaffecter(&(l->lieux[pos]),e);
           (l->lg)++;
        }
    }
    return succee;
}
void listelieuxafficher(listelieux l)
{int i;
    printf("les lieux visites sont        :");


    for(i = 1;i <= l->lg;i++)
        elemchafficher(l->lieux[i]);


}
//
//
void testcorona (listeqtr l)
{
int i,x,j,g,num=0;

    printf("donnez votre adresse: \n");
    printf("1:tunis 2:guebes 3:nabeul 4:sfax 5:bizerte \n");
    scanf("%i",&x);
    switch (x)
    {
    case 1 : num=1;
    case 2: num=2;
    case 3: num=3;
    case 4: num=4;
    case 5: num=5;

    }
    printf("donner le nombre de lieux que vous avez visite\n");
    scanf ("%i",&x);
    for (j=0;j<x;j++)
    {
        printf("choisissez les lieux que vous avez visite:\nsupermarche:1 station de bus:2 station de train :3 pharmacie:4 \n");
        scanf("%i",&g);
        if ((num==1)||(g==1))
           {
               printf("vous risquez d'etre atteints par le corona car ce patient a visite les memes lieux que vous \n");
            //elemqtrafficher(l->quarantaines[num]);
             printf("nom                           :%s\n",l->quarantaines[num] ->nom);
    printf("prenom                        :%s\n", l->quarantaines[num]->prenom);
    Color(12,15);
    printf("adresse                       :%s\n", l->quarantaines[num]->adr);
    Color(0,15);
    printf("age                           :%i\n", l->quarantaines[num]->age);
    printf("contamination                 :%i\n", l->quarantaines[num]->contamination);
    printf("provenance                    :%i\n",l->quarantaines[num]->provenance);
    printf("date du debut du confinement  :%i/%i\n",l->quarantaines[num]->jour,l->quarantaines[num]->mois);
listepersonnesafficher(l->quarantaines[num]->personnes);
listemaladiesafficher(l->quarantaines[num]->maladies);
Color(12,15);
listelieuxafficher(l->quarantaines[num]->lieuxvisites);
Color(0,15);

           }
           else
           {
               if (((num==2)||(g==1))||(g==3)||(g==4))
               {printf("vous risquez d'etre atteints par le corona car ce patient a visite les memes lieux que vous \n");
               elemqtrafficher(l->quarantaines[2]);}
               else
               {if (((num==3)||(g==2))||(g==3)||(g==4))
               {
                  printf("vous risquez d'etre atteints par le corona car ce patient a visite les memes lieux que vous \n");
               elemqtrafficher(l->quarantaines[3]);
               }
               else
                {if (((num==4)||(g==1))||(g==3)||(g==4))
               {
                   printf("vous risquez d'etre atteints par le corona car ce patient a visite les memes lieux que vous \n");
               elemqtrafficher(l->quarantaines[4]);
               }
               else
                {if (((num==5)||(g==2))||(g==3)||(g==4))
               {
                    printf("vous risquez d'etre atteints par le corona car ce patient a visite les memes lieux que vous \n");
               elemqtrafficher(l->quarantaines[5]);
               }
                }}}
           }


    }

}

//
//
listeqtr  initqtr(void)
{
    listeqtr l =listeqtrcreer();
 elemqtr e1=elemqtrcreer();
    //
   listemaladies maladies =listemaladiescreer();
    structch maladies_1={"diabete"};
    inserermaladies(maladies,&maladies_1,1);

    //
listepersonnes persons =listepersonnescreer();
    structch personnes_1={"frere"};

    insererpersonnes(persons,&personnes_1,1);

//
listelieux lieux1 =listelieuxcreer();
    structch lieux_1={"supermarche"},lieux1_1={"pharmacie"};

    insererlieux(lieux1,&lieux_1,1);



structqtr quarantaine1 = {1,"mkaddem","rihem","tunis",18,maladies,persons,1,1,15,3,lieux1};
insererqtr (l,&quarantaine1,1);

//
//
//
//
//

elemqtr e2=elemqtrcreer();
    //
   listemaladies maladies2 =listemaladiescreer();
    structch maladies1_1={"diabete"},maladies1_2={"tension"},maladies1_3={"depression"};
    inserermaladies(maladies2,&maladies1_1,1);
inserermaladies(maladies2,&maladies1_3,1);
inserermaladies(maladies2,&maladies1_3,1);
    //
listepersonnes persons2 =listepersonnescreer();
    structch personnes1_1={"frere"},personnes1_2={"voisin"},personnes1_3={"ami"};

    insererpersonnes(persons2,&personnes1_2,1);
    insererpersonnes(persons2,&personnes1_1,1);
    insererpersonnes(persons2,&personnes1_3,1);


//
listelieux lieux2 =listelieuxcreer();
    structch lieux2_1={"supermarche"},lieux2_2={"station de train"},lieux2_3={"pharmacie"};

    insererlieux(lieux2,&lieux2_1,1);
    insererlieux(lieux2,&lieux2_2,1);
    insererlieux(lieux2,&lieux2_3,1);

structqtr quarantaine2 = {2,"naouari","karim","guebes",45,maladies2,persons2,0,1,20,4,lieux2};
insererqtr (l,&quarantaine2,1);
//
//
//
//
elemqtr e3=elemqtrcreer();
    //
   listemaladies maladies3 =listemaladiescreer();
    structch maladies3_1={"hepatite"},maladies3_2={"hypotension"},maladies3_3={"insuffisance renale"};
    inserermaladies(maladies3,&maladies3_1,1);
inserermaladies(maladies3,&maladies3_2,1);
inserermaladies(maladies3,&maladies3_3,1);
    //
listepersonnes persons3 =listepersonnescreer();
    structch personnes3_1={"medecin"},personnes3_2={"voisin"},personnes3_3={"epoux"};

    insererpersonnes(persons3,&personnes3_2,1);
    insererpersonnes(persons3,&personnes3_1,1);
    insererpersonnes(persons3,&personnes3_3,1);


//
listelieux lieux3 =listelieuxcreer();
    structch lieux3_1={"station de train"},lieux3_2={"station de bus"},lieux3_3={"pharmacie"};
    insererlieux(lieux3,&lieux3_1,1);
    insererlieux(lieux3,&lieux3_2,1);
    insererlieux(lieux3,&lieux3_3,1);

structqtr quarantaine3 = {3,"ajmi","salma","nabeul",55,maladies3,persons3,1,0,30,2,lieux3};
insererqtr (l,&quarantaine3,1);
//
//
//
//
//
elemqtr e4=elemqtrcreer();
    //
   listemaladies maladies4=listemaladiescreer();
    //
listepersonnes persons4 =listepersonnescreer();
    structch personnes4_1={"cousin"},personnes4_2={"voisin"},personnes4_3={"femme"},personnes4_4={"enfant"};

    insererpersonnes(persons4,&personnes4_2,1);
    insererpersonnes(persons4,&personnes4_1,1);
    insererpersonnes(persons4,&personnes4_3,1);
listelieux lieux4 =listelieuxcreer();
    structch lieux4_1={"supermarche"},lieux4_2={"station de bus"},lieux4_3={"pharmacie"};
    insererlieux(lieux4,&lieux4_1,1);
    insererlieux(lieux4,&lieux4_2,1);
    insererlieux(lieux4,&lieux4_3,1);

structqtr quarantaine4 = {4,"amira","fatma","sfax",60,maladies4,persons4,0,0,10,3,lieux4};
insererqtr (l,&quarantaine4,1);
//
//
//
//
elemqtr e5=elemqtrcreer();
    //
   listemaladies maladies5=listemaladiescreer();
    //
listepersonnes persons5 =listepersonnescreer();
    structch personnes5_1={"mere"},personnes5_2={"pere"},personnes5_3={"fils"},personnes5_4={"fille"};

    insererpersonnes(persons5,&personnes5_2,1);
    insererpersonnes(persons5,&personnes5_1,1);
    insererpersonnes(persons5,&personnes5_3,1);
listelieux lieux5 =listelieuxcreer();
    structch lieux5_1={"station de bus"},lieux5_2={"station de train"},lieux5_3={"supermarche"};
    insererlieux(lieux5,&lieux5_1,1);
    insererlieux(lieux5,&lieux5_2,1);
    insererlieux(lieux5,&lieux5_3,1);

structqtr quarantaine5 = {5,"belhadj","zohra","bizerte",30,maladies5,persons5,1,0,30,4,lieux5};
insererqtr (l,&quarantaine5,1);
lieux ll=lieuxcreer();

structl l1={"hotel",1,"tunis",1,0};
lieuxinserer(ll,&l1,1);
//

structl l2={"maison d'hote",2,"nabeul",2,1};
lieuxinserer(ll,&l2,2);
//

structl l3={"hotel",3,"kairouen",3,1};
lieuxinserer(ll,&l3,3);
//

structl l4={"maison des jeunes",4,"sfax",4,0};
lieuxinserer(ll,&l4,4);
//

structl l5={"hotel",5,"medenine",5,0};
lieuxinserer(ll,&l5,5);
 rotation (ll,l);
listeqtrafficher(l);
lieuxafficher(ll);
return l;
}
//
//
//
//
listeqtr  initqtr2(void)
{
   listeqtr l =listeqtrcreer();
 elemqtr e1=elemqtrcreer();
    //
   listemaladies maladies =listemaladiescreer();
    structch maladies_1={"diabete"};
    inserermaladies(maladies,&maladies_1,1);

    //
listepersonnes persons =listepersonnescreer();
    structch personnes_1={"frere"};

    insererpersonnes(persons,&personnes_1,1);

//
listelieux lieux1 =listelieuxcreer();
    structch lieux_1={"supermarche"},lieux1_1={"pharmacie"};

    insererlieux(lieux1,&lieux_1,1);

insererlieux(lieux1,&lieux1_1,1);

structqtr quarantaine1 = {1,"mkaddem","rihem","tunis",18,maladies,persons,1,1,15,3,lieux1};
insererqtr (l,&quarantaine1,1);

//
//
//
//
//

elemqtr e2=elemqtrcreer();
    //
   listemaladies maladies2 =listemaladiescreer();
    structch maladies1_1={"diabete"},maladies1_2={"tension"},maladies1_3={"depression"};
    inserermaladies(maladies2,&maladies1_1,1);
inserermaladies(maladies2,&maladies1_3,1);
inserermaladies(maladies2,&maladies1_3,1);
    //
listepersonnes persons2 =listepersonnescreer();
    structch personnes1_1={"frere"},personnes1_2={"voisin"},personnes1_3={"ami"};

    insererpersonnes(persons2,&personnes1_2,1);
    insererpersonnes(persons2,&personnes1_1,1);
    insererpersonnes(persons2,&personnes1_3,1);


//
listelieux lieux2 =listelieuxcreer();
    structch lieux2_1={"supermarche"},lieux2_2={"station de train"},lieux2_3={"pharmacie"};

    insererlieux(lieux2,&lieux2_1,1);
    insererlieux(lieux2,&lieux2_2,1);
    insererlieux(lieux2,&lieux2_3,1);


structqtr quarantaine2 = {2,"naouari","karim","guebes",45,maladies2,persons2,0,1,20,4,lieux2};
insererqtr (l,&quarantaine2,1);
//
//
//
//
elemqtr e3=elemqtrcreer();
    //
   listemaladies maladies3 =listemaladiescreer();
    structch maladies3_1={"hepatite"},maladies3_2={"hypotension"},maladies3_3={"insuffisance renale"};
    inserermaladies(maladies3,&maladies3_1,1);
inserermaladies(maladies3,&maladies3_2,1);
inserermaladies(maladies3,&maladies3_3,1);
    //
listepersonnes persons3 =listepersonnescreer();
    structch personnes3_1={"medecin"},personnes3_2={"voisin"},personnes3_3={"epoux"};

    insererpersonnes(persons3,&personnes3_2,1);
    insererpersonnes(persons3,&personnes3_1,1);
    insererpersonnes(persons3,&personnes3_3,1);


//
listelieux lieux3 =listelieuxcreer();
    structch lieux3_1={"station de train"},lieux3_2={"station de bus"},lieux3_3={"pharmacie"};
    insererlieux(lieux3,&lieux3_1,1);
    insererlieux(lieux3,&lieux3_2,1);
    insererlieux(lieux3,&lieux3_3,1);

structqtr quarantaine3 = {3,"ajmi","salma","nabeul",55,maladies3,persons3,1,0,30,2,lieux3};
insererqtr (l,&quarantaine3,1);
//
//
//
//
//
elemqtr e4=elemqtrcreer();
    //
   listemaladies maladies4=listemaladiescreer();
    //
listepersonnes persons4 =listepersonnescreer();
    structch personnes4_1={"cousin"},personnes4_2={"voisin"},personnes4_3={"femme"},personnes4_4={"enfant"};

    insererpersonnes(persons4,&personnes4_2,1);
    insererpersonnes(persons4,&personnes4_1,1);
    insererpersonnes(persons4,&personnes4_3,1);
listelieux lieux4 =listelieuxcreer();
    structch lieux4_1={"supermarche"},lieux4_2={"station de bus"},lieux4_3={"pharmacie"};
    insererlieux(lieux4,&lieux4_1,1);
    insererlieux(lieux4,&lieux4_2,1);
    insererlieux(lieux4,&lieux4_3,1);

structqtr quarantaine4 = {4,"amira","fatma","sfax",60,maladies4,persons4,0,0,10,3,lieux4};
insererqtr (l,&quarantaine4,1);
//
//
//
//
elemqtr e5=elemqtrcreer();
    //
   listemaladies maladies5=listemaladiescreer();
    //
listepersonnes persons5 =listepersonnescreer();
    structch personnes5_1={"mere"},personnes5_2={"pere"},personnes5_3={"fils"},personnes5_4={"fille"};

    insererpersonnes(persons5,&personnes5_2,1);
    insererpersonnes(persons5,&personnes5_1,1);
    insererpersonnes(persons5,&personnes5_3,1);
listelieux lieux5 =listelieuxcreer();
    structch lieux5_1={"station de bus"},lieux5_2={"station de train"},lieux5_3={"supermarche"};
    insererlieux(lieux5,&lieux5_1,1);
    insererlieux(lieux5,&lieux5_2,1);
    insererlieux(lieux5,&lieux5_3,1);

structqtr quarantaine5 = {5,"belhadj","zohra","bizerte",30,maladies5,persons5,1,0,12,4,lieux5};
insererqtr (l,&quarantaine5,1);
listeqtrafficher(l);
system("cls");
testcorona(l);
return l;
}
listeqtr  initqtr3(void)
{
    listeqtr l =listeqtrcreer();
 elemqtr e1=elemqtrcreer();
    //
   listemaladies maladies =listemaladiescreer();
    structch maladies_1={"diabete"};
    inserermaladies(maladies,&maladies_1,1);

    //
listepersonnes persons =listepersonnescreer();
    structch personnes_1={"frere"};

    insererpersonnes(persons,&personnes_1,1);

//
listelieux lieux1 =listelieuxcreer();
    structch lieux_1={"supermarche"};

    insererlieux(lieux1,&lieux_1,1);



structqtr quarantaine1 = {1,"mkaddem","rihem","tunis",18,maladies,persons,1,1,27,4,lieux1};
insererqtr (l,&quarantaine1,1);

//
//
//
//
//

elemqtr e2=elemqtrcreer();
    //
   listemaladies maladies2 =listemaladiescreer();
    structch maladies1_1={"diabete"},maladies1_2={"tension"},maladies1_3={"depression"};
    inserermaladies(maladies2,&maladies1_1,1);
inserermaladies(maladies2,&maladies1_3,1);
inserermaladies(maladies2,&maladies1_3,1);
    //
listepersonnes persons2 =listepersonnescreer();
    structch personnes1_1={"frere"},personnes1_2={"voisin"},personnes1_3={"ami"};

    insererpersonnes(persons2,&personnes1_2,1);
    insererpersonnes(persons2,&personnes1_1,1);
    insererpersonnes(persons2,&personnes1_3,1);


//
listelieux lieux2 =listelieuxcreer();
    structch lieux2_1={"supermarche"},lieux2_2={"station de train"},lieux2_3={"pharmacie"};

    insererlieux(lieux2,&lieux2_1,1);
    insererlieux(lieux2,&lieux2_2,1);
    insererlieux(lieux2,&lieux2_3,1);


structqtr quarantaine2 = {2,"naouari","karim","guebes",45,maladies2,persons2,0,1,20,4,lieux2};
insererqtr (l,&quarantaine2,2);
//
//
//
//
elemqtr e3=elemqtrcreer();
    //
   listemaladies maladies3 =listemaladiescreer();
    structch maladies3_1={"hepatite"},maladies3_2={"hypotension"},maladies3_3={"insuffisance renale"};
    inserermaladies(maladies3,&maladies3_1,1);
inserermaladies(maladies3,&maladies3_2,1);
inserermaladies(maladies3,&maladies3_3,1);
    //
listepersonnes persons3 =listepersonnescreer();
    structch personnes3_1={"medecin"},personnes3_2={"voisin"},personnes3_3={"epoux"};

    insererpersonnes(persons3,&personnes3_2,1);
    insererpersonnes(persons3,&personnes3_1,1);
    insererpersonnes(persons3,&personnes3_3,1);


//
listelieux lieux3 =listelieuxcreer();
    structch lieux3_1={"station de train"},lieux3_2={"station de bus"},lieux3_3={"pharmacie"};
    insererlieux(lieux3,&lieux3_1,1);
    insererlieux(lieux3,&lieux3_2,1);
    insererlieux(lieux3,&lieux3_3,1);

structqtr quarantaine3 = {3,"ajmi","salma","nabeul",55,maladies3,persons3,1,0,5,5,lieux3};
insererqtr (l,&quarantaine3,3);
//
//
//
//
//
elemqtr e4=elemqtrcreer();
    //
   listemaladies maladies4=listemaladiescreer();
    //
listepersonnes persons4 =listepersonnescreer();
    structch personnes4_1={"cousin"},personnes4_2={"voisin"},personnes4_3={"femme"},personnes4_4={"enfant"};

    insererpersonnes(persons4,&personnes4_2,1);
    insererpersonnes(persons4,&personnes4_1,1);
    insererpersonnes(persons4,&personnes4_3,1);
listelieux lieux4 =listelieuxcreer();
    structch lieux4_1={"supermarche"},lieux4_2={"station de bus"},lieux4_3={"pharmacie"};
    insererlieux(lieux4,&lieux4_1,1);
    insererlieux(lieux4,&lieux4_2,1);
    insererlieux(lieux4,&lieux4_3,1);

structqtr quarantaine4 = {4,"amira","fatma","sfax",60,maladies4,persons4,0,0,10,4,lieux4};
insererqtr (l,&quarantaine4,4);
//
//
//
//
elemqtr e5=elemqtrcreer();
    //
   listemaladies maladies5=listemaladiescreer();
    //
listepersonnes persons5 =listepersonnescreer();
    structch personnes5_1={"mere"},personnes5_2={"pere"},personnes5_3={"fils"},personnes5_4={"fille"};

    insererpersonnes(persons5,&personnes5_2,1);
    insererpersonnes(persons5,&personnes5_1,1);
    insererpersonnes(persons5,&personnes5_3,1);
listelieux lieux5 =listelieuxcreer();
    structch lieux5_1={"station de bus"},lieux5_2={"station de train"},lieux5_3={"supermarche"};
    insererlieux(lieux5,&lieux5_1,1);
    insererlieux(lieux5,&lieux5_2,1);
    insererlieux(lieux5,&lieux5_3,1);

structqtr quarantaine5 = {5,"belhadj","zohra","bizerte",30,maladies5,persons5,1,0,12,4,lieux5};
insererqtr (l,&quarantaine5,5);
//recherche
 lieux ll=lieuxcreer();

structl l1={"hotel",1,"tunis",1,0};
lieuxinserer(ll,&l1,1);
//

structl l2={"maison d'hote",2,"nabeul",2,1};
lieuxinserer(ll,&l2,2);
//

structl l3={"hotel",3,"kairouen",3,1};
lieuxinserer(ll,&l3,3);
//

structl l4={"maison des jeunes",4,"sfax",4,0};
lieuxinserer(ll,&l4,4);
//

structl l5={"hotel",5,"medenine",5,1};
lieuxinserer(ll,&l5,5);
elemqtr qq=ajoutqtr(l);
int a,k;
printf("1-voulez vous afficher la liste entiere ? ");
printf("2-avoir un lieu de confinement le plus proche et disponible\n ");
scanf("%i",&a);
if (a==1)
{listeqtrafficher(l);
printf("1-avoir un lieu de confinement le plus proche et disponible\n ");
scanf("%i",&k);
 int test=0;
 k=1;
 char*ch=l->quarantaines[qq->num]->adr;
system("cls");
    while ((k<=ll->lg)&&(!test))
    {
        if (strcmp(ll->tab[k]->adr, ch)==0)
        {int a=k+1;

                printf ("le lieu: \n================\n\n");
                elemlieuafficher(ll->tab[k]);
                printf("\n===================\n");
                test=1;
                if (ll->tab[k]->disponibilite==1)
                    {Color (12,15);
                    printf("est disponible\n");
                Color (0,15);}
                else
                {if(ll->tab[k]->disponibilite==0)
                Color (12,15);
                    printf("ce lieu n'est pas disponible pour le moment mais il sera disponible le %i/%i\n",(l->quarantaines[ll->tab[k]->qtr]->jour+15)-(l->quarantaines[qq->num]->jour)-7,l->quarantaines[qq->num]->mois);
                    Color (0,15);
                    elemqtrafficher(l->quarantaines[ll->tab[k]->qtr]);
                    Color (12,15);
                    printf("\n\n le lieu le plus proche a vous et disponible est:\n");
                    elemlieuafficher(ll->tab[2]);
                    Color (0,15);
                }

        }
        k++;
    }
    }
else
    {
        int test=0;
 k=1;
 char*ch=l->quarantaines[qq->num]->adr;
system("cls");
    while ((k<=ll->lg)&&(!test))
    {
        if (strcmp(ll->tab[k]->adr, ch)==0)
        {int a=k+1;

                printf ("le lieu: \n================\n\n");
                elemlieuafficher(ll->tab[k]);
                printf("\n===================\n");
                test=1;
                if (ll->tab[k]->disponibilite==1)
                    printf("est disponible\n");
                else
                {if(ll->tab[k]->disponibilite==0)
                    printf("ce lieu n'est pas disponible pour le moment mais il sera disponible le %i/%i\n",(l->quarantaines[ll->tab[k]->qtr]->jour+15)-(l->quarantaines[qq->num]->jour),l->quarantaines[qq->num]->mois);
                    elemqtrafficher(l->quarantaines[ll->tab[k]->qtr]);
                    elemlieuafficher(ll->tab[2]);
                }

        }
        k++;
    }}



return l;
}
