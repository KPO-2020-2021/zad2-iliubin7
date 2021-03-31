#include "Statystyki.hh"
#include <iostream>

void Statystyki::Wypisz()
{
    cout<< "Ilosc dobrych odpowiedzi: "<< dobrze <<endl;
    cout<< "Ilosc zlych odpowiedzi: "<< zle <<endl;
    cout <<"Wynik procentowy poprawnych odpowiedzi:" << procent_dobrze<<endl;
}

void Statystyki::Oblicz()
{
         procent_dobrze=dobrze*100.0/(dobrze+zle);
     procent_zle=dobrze*100.0/(dobrze+zle);;

}
