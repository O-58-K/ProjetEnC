#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include <windows.h>
#include <string.h>
#include <time.h>
#include "Couleurs.h"

Bobs JoueurBob;
Kellogg BossKellogg;

    void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
        {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
        }
Local PipBoy;
Pillards Pillard;

void main(void)
{

    JoueurBob.PointDeEXP = 1;

    JoueurBob.PointDeVie = 430;

    JoueurBob.DamageVIE = 35;

    JoueurBob.Exp = 385;

    JoueurBob.DEPLAC = 0;

    Pillard.PointDeVie = 230;

    Pillard.DamageVIE = 18;

    Pillard.PointDeEXP = 10;

    BossKellogg.PointDeVie = 1500;

    BossKellogg.DamageVIE = 150;

    BossKellogg.PointDeEXP = 40;

    PipBoy.potion = 4;


    switch(MenuFall()){

        case 1:
            printf("\nSurvivant-e, etes vous sur la liste ?  \n\n");
            scanf("%s", JoueurBob.NOM);
            printf("Effectivement...\n");
            Sleep(1500);
            printf("La guerre, la guerre ne meurt jamais, vous apparassez dans une charmante ville sous le nom de Concord completement rasee par la guerre.\n\n");
            Sleep(1500);
            printf("Un Pillard a vos alentours ! \n");
            Sleep(1500);
            printf("Faites gaffe ! \n\n");
            Sleep(1000);


            ModeCombat();
            LocalisatioN();

            case 2:
                printf("Chargement...");
                break;

            case 3:
                printf("Jeux RPG se passant dans un monde tel que vous ne l'imaginez..., par Okan et Baptiste.");
                break;

            case 4:
                exit(0);
                break;
            }

        }

    int DeplCH()
    {

    int Select3;
    Sleep(1500);
    printf("\Deplacez-vous: \n\n");

    printf("-1 Abri 101-N \n");

    printf("-2 Abri 87-S\n");

    printf("-3 Abri 34-E\n");

    printf("-4 Abri 111-O\n\n");

    scanf("%d", &Select3);
    return Select3;

    }


int LocalisatioN(){

    int pos1;
    int pos2;


    switch(DeplCH()){

        int Select1;

        do{

                case 1:
                    pos1--;
                    JoueurBob.DEPLAC = 0;

                        printf("Vous allez vers Abri 101...\n");
                        pos1 = pos1 + 1;
                        Sleep(2000);
                        printf("Vous etes a %d,%d\n\n", pos2,pos1);
                        printf("Oh non un Pillard est apparu !");
                        ModeCombat();


                    break;

                case 2:
                    pos1++;
                    JoueurBob.DEPLAC = 0;
                        pos1--;
                        printf("Vous allez vers Abri 87...");
                        pos1 = pos1 - 1;
                        Sleep(1700);
                        printf("Vous etes a %d,%d\n\n", pos2,pos1);
                        printf("Un Boss... Bien dommage!");
                        ModeCombat();

                    break;

                case 3:
                    pos2++;
                    JoueurBob.DEPLAC = 0;
                        printf("Vous allez vers Abri 34...");
                        pos2 = pos2 + 1;
                        Sleep(1700);
                        printf("Vous etes a %d,%d\n\n", pos2,pos1);
                        printf("IL NOUS AIMENT PAS DIS DONC!");
                        ModeCombat();

                    break;

                case 4:
                    pos2--;
                    JoueurBob.DEPLAC = 0;
                        printf("Vous allez vers Abri 111...");
                        pos2 = pos2 - 1;
                        Sleep(1700);
                        printf("Vous etes a %d,%d\n\n", pos2,pos1);
                        printf("Oh non un ennemi est apparu !");
                        ModeCombat();


                    break;



                    return 0;

        }while(JoueurBob.PointDeVie < 220);

    }

}

    int MenuFall()
        {

        int LesChoix;
        Color(2,0); //Permet de changer la couleur du texte et du fond de texte
        printf("\n "" ""  ******Fallout Menu******: \n\n");

        printf("1 - Nouvelle partie.\n\n");

        printf("2 - Charger une partie.\n\n");

        printf("3 - A propos du jeu.\n\n");

        printf("4 - Quitter\n\n");
        scanf("%d", &LesChoix);

        return LesChoix;
        }

int DamageVIEBob()
{
    int healthP;
    {

    srand(time(NULL));

    int healthP = rand() % 11;

    if(healthP == 10)
        {

        Pillard.PointDeVie -= JoueurBob.DamageVIE;

        }

    if(healthP > 1 && healthP < 10)
        {

        Pillard.PointDeVie -= JoueurBob.DamageVIE;

        }

    if(healthP < 2)
        {

        JoueurBob.DamageVIE += JoueurBob.DamageVIE;
        Pillard.PointDeVie -= JoueurBob.DamageVIE;

        }

    return healthP;

    }

}

int Select()
    {

    Color(2,0);
    int Select1;
    printf("\n\n*****Quel est votre choix***** \n\n");

    printf("1 - Attaquer le Pillard (attention il risque de bien se defendre)\n\n");

    printf("2 - Chercher dans votre Pip-Boy (Pratique pour ranger ce que l'on veut)\n\n");

    printf("3 - Courrez de toutes vos forces\n\n");

    printf("4 - Abandonner\n\n");
    scanf("%d", &Select1);

    return Select1;
    }

int DamageVIEPillard()
{
    srand(time(NULL));

    int healthP = rand()% 11;

    if(healthP == 10)
        {

        Pillard.DamageVIE = 0;

        JoueurBob.PointDeVie-=Pillard.DamageVIE;

        }
    if(healthP < 2)
        {

        JoueurBob.PointDeVie-=Pillard.DamageVIE;

        Pillard.DamageVIE+=Pillard.DamageVIE;

        }
    if(healthP>2 && healthP<10)
        {

        JoueurBob.PointDeVie-=Pillard.DamageVIE;

        }

    return healthP;

}

int InventairE()
    {

    int Select4;
    printf("\Pip-Boy : \n\n");

    printf("1 - Potion S.P.E.C.I.A.L (celle-ci rapporte des points de vie) : %d\n", PipBoy.potion);

    printf("4- Retour\n\n");
    scanf("%d", &Select4);

    return Select4;
    }

int DamageVIEBossKellogg()
{

    srand(time(NULL));

    int healthP = rand()% 10;

    if(healthP == 9)
        {

        BossKellogg.DamageVIE = 0;
        JoueurBob.PointDeVie -= BossKellogg.DamageVIE;

        }
    if(healthP < 2)
        {

        BossKellogg.DamageVIE += BossKellogg.DamageVIE;
        JoueurBob.PointDeVie -=Pillard.DamageVIE;

        }
    if(healthP > 1 && healthP < 9)
        {

        JoueurBob.PointDeVie -=BossKellogg.DamageVIE;

        }

    return healthP;
}

int ModeCombat()
{
    int Exp = 480;
    int XPS = 0;
    int FinJeu = 0;
    int ViePotion = 200;


    do{
        switch(Select())
        {

            case 1:
                printf("Oula! Vous claquez les Pillards maintenant ? \n");
                DamageVIEBob();
                Sleep(1000);
                printf("Il s'est prit une sale claque !\n");
                Sleep(1000);
                printf("Pas de bol d'etre tomber sur vous\n");
                Sleep(1500);
                printf("Il ne lui reste plus qu'il fasse ses prieres! il lui reste %d de vie \n" , Pillard.PointDeVie );
                Sleep(1500);


                if(Pillard.PointDeVie > 0)
                    {

                    printf("Mr.Pillard n est pas tres content! \n");
                    DamageVIEPillard();
                    Sleep(1500);
                    printf("Vous vous etes pris %d de Degats!\n", Pillard.DamageVIE);
                    printf("Il vous reste %d de vie! \n", JoueurBob.PointDeVie);

                    }

                 if(Pillard.PointDeVie <= 0)
                        {

                        printf("\nLe Pillard est off ! \n");
                        printf("Bien jouer %d XP\n", Exp);
                        XPS += Exp;
                        printf("Votre experience augmente de  %d/%d\n\n", Exp,JoueurBob.XPS);
                        FinJeu = 1;


                        if(XPS >= JoueurBob.XPS)
                            {

                            JoueurBob.PointDeEXP++;
                            printf("Votre niveau 'S.P.E.C.I.A.L' a passer le cap %d, votre experience et votre vie ont augmentees egalement ! \n", JoueurBob.PointDeEXP);
                            Sleep(1500);
                            PipBoy.potion = 1;
                            FinJeu = 1;
                            }

                 break;

                case 2:
                    switch(InventairE())
                    {

                        case 1:
                            if(PipBoy.potion == 0)
                                {
                                printf("Votre pouvoir S.P.E.C.I.A.L est epuise.");
                                }


                            if(PipBoy.potion > 0)
                                {

                                JoueurBob.PointDeVie += ViePotion;
                                PipBoy.potion --;

                                if(JoueurBob.PointDeVie > 430)
                                    {

                                    JoueurBob.PointDeVie = 430;
                                    }
                                    printf("\nVous avez %d points de vie !\n", JoueurBob.PointDeVie);
                                }


                        printf("Vous vous etes soigner,... ? \n");
                        DamageVIEBob();
                        Sleep(1000);
                        printf("Oh ! Un Raider qui attaque ! !\n");
                        Sleep(1000);



                            if(Pillard.PointDeVie > 0)
                                {

                                printf("Mr.Pillard n est pas tres content! \n");
                                DamageVIEPillard();
                                Sleep(1500);
                                printf("Vous vous etes pris %d de Degats!\n", Pillard.DamageVIE);
                                printf("Il vous reste %d de vie! \n", JoueurBob.PointDeVie);

                                }

                             if(Pillard.PointDeVie <= 0)
                                    {

                                    printf("\nLe Pillard est off ! \n");
                                    printf("Bien jouer %d XP\n", Exp);
                                    XPS += Exp;
                                    printf("Votre experience augmente de  %d/%d\n\n", Exp,JoueurBob.XPS);
                                    FinJeu = 1;


                                    if(XPS >= JoueurBob.XPS)
                                        {

                                        JoueurBob.PointDeEXP++;
                                        printf("Votre niveau 'S.P.E.C.I.A.L' a passer le cap %d, votre experience et votre vie ont augmentees egalement ! \n", JoueurBob.PointDeEXP);
                                        Sleep(1500);
                                        PipBoy.potion = 1;
                                        FinJeu = 1;
                                        }
                                        break;

                                    }

                }

                case 3:
                    printf("Vous avez reussi a vous echapper ! ");
                    break;

                case 4:
                    exit(0);
                    printf("C'est fini! ");
                    break;


                        }
        }

        }while(JoueurBob.PointDeVie > 0 && FinJeu == 0);

}
