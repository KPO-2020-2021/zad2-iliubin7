#include "WyrazenieZesp.hh"
#include <iostream>

using namespace std;
ostream & operator << (ostream & wyj, const WyrazenieZesp  & WyrZ)
{
  wyj << WyrZ.Arg1;
  if (WyrZ.Op ==  Op_Dodaj)
    {
       cout<<"+";
    }

    if (WyrZ.Op == Op_Odejmij)
    {
             cout<<"-";
    }

    if (WyrZ.Op == Op_Mnoz)
    {
              cout<<"*";
    }

    if (WyrZ.Op == Op_Dziel)
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


void Wyswietl(WyrazenieZesp  WyrZ)
{
    std::cout << WyrZ;
}

LZespolona Oblicz(WyrazenieZesp WyrZ)
{
    LZespolona wynik;
    if (WyrZ.Op ==  Op_Dodaj)
    {
        wynik = WyrZ.Arg1 + WyrZ.Arg2;// couit<<"+";
    }

    if (WyrZ.Op == '-')
    {
        wynik = WyrZ.Arg1 - WyrZ.Arg2;
    }

    if (WyrZ.Op =='*')
    {
        wynik = WyrZ.Arg1 * WyrZ.Arg2;
    }

    if (WyrZ.Op == '/')
    {
        wynik = WyrZ.Arg1 / WyrZ.Arg2;
    }
    return wynik;
}
