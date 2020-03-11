#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

    typedef struct Bobs Bobs;
    struct Bobs
        {

        char NOM[15];
        int PointDeVie;
        int Exp;
        int XPS;
        int DamageVIE;
        int PointDeEXP;
        int DEPLAC;

        };

    typedef struct Local Local;
    struct Local
        {

        int potion;

        };

    typedef struct Kellogg Kellogg;
    struct Kellogg
        {

        int PointDeVie;
        int PointDeEXP;
        int DamageVIE;

        };

    typedef struct Pillards Pillards;
    struct Pillards
        {

        int PointDeVie;
        int PointDeEXP;
        int DamageVIE;

        };


#endif
