#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

using namespace std;

class Statystyki
{
public:
        int dobrze;
    int zle;
    double procent_dobrze;
    double procent_zle;
    Statystyki()
    {
            dobrze=0;
     zle=0;
     procent_dobrze=0;
     procent_zle=0;
    }
void Wypisz();
void Oblicz();
};

#endif
