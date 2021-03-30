#include "../inc/WyrazenieZesp.hh"
#include <iostream>

using namespace std;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

void Wyswietl(WyrazenieZesp  WyrZ)
{
    std::cout << WyrZ;
}

LZespolona Oblicz(WyrazenieZesp WyrZ)
{
    LZespolona wynik;
    if (WyrZ.Op ==  Op_Dodaj)
    {
        wynik = WyrZ.Arg1 + WyrZ.Arg2;   // cout <<"+";
    }

    if (WyrZ.Op == '-')
    {
        wynik = WyrZ.Arg1 - WyrZ.Arg2;  // cout <<"-";
    }

    if (WyrZ.Op =='*')
    {
        wynik = WyrZ.Arg1 * WyrZ.Arg2;  // cout <<"*";
    }

    if (WyrZ.Op == '/')
    {
        wynik = WyrZ.Arg1 / WyrZ.Arg2;  // cout <<"/";
    }
    return wynik;
}

ostream & operator << (ostream & wyj, const WyrazenieZesp  & WyrZ)
{
  wyj << WyrZ.Arg1;
  if (WyrZ.Op ==  Op_Dodaj)
    {
       cout<<"+";
    }

    if (WyrZ.Op == '-')
    {
             cout<<"/";
    }

    if (WyrZ.Op =='*')
    {
              cout<<"*";
    }

    if (WyrZ.Op == '/')
    {
              cout<<"/";
    }
  wyj << WyrZ.Arg2;
  return wyj;
}


istream & operator >> (istream & wej,WyrazenieZesp  & lz)
{
  wej >> lz.Arg1;
  char znak;
  wej>>znak;
  if (znak ==  '+')
    {
      lz.Op=Op_Dodaj;
    }

   else if (znak == '-')
    {
               lz.Op=Op_Odejmij;
    }

   else if (znak =='*')
    {
                 lz.Op=Op_Mnoz;
    }

  else  if (znak == '/')
    {
              lz.Op=Op_Dziel;
    }
    else
    {
        wej.setstate(ios::failbit);
    }
  wej >> lz.Arg2;
  return wej;
}
