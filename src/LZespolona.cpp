#include "LZespolona.hh"
#include <cmath>
#include <iostream>

#define MIN_DIFF 0.00001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
    return false;
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  /*
  if abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF
    return true;
  else
    return false;
  */
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;
  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Wynik mnozenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;
  Wynik.re = Skl1.re * Skl2.re -Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik;
  if(Skl2 == 0)
  {
    std::cerr<<"blad" << std::endl;
    exit(-1);
  }
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}

/*!
 * Realizuje operacje sprzezenia liczby zespolonej
 * Argument:
 *    Skl1 - dzielona liczba zespolona,
 * Zwraca:
 *    Wynik sprezenia.
 */
LZespolona  Sprzezenie(LZespolona  Skl1){
 LZespolona  Wynik;
   Wynik.re = Skl1.re;
   Wynik.im = (-1)*Skl1.im;
  return Wynik;
}

/*!
 * Realizuje operacje modul do kwadratu liczby zespolonej
 */
double Modul2(LZespolona Skl1){
   double Wynik;
   Wynik= Skl1.re*Skl1.re + Skl1.im*Skl1.im;
   return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2){
  LZespolona Wynik;
  Wynik=Skl1*Sprzezenie(Skl2)/Modul2(Skl2);
  return Wynik;
}

std::ostream& operator << (std::ostream &StrWyj, LZespolona &LZesp)
{
  StrWyj << "(" << LZesp.re << std::showpos << LZesp.im << std::noshowpos << "i)";
  return StrWyj;
}

 std::istream& operator >> (std::istream &StrWej, LZespolona &LZesp)
 {
   char nawias, litera;
   StrWej >> nawias;
   if(StrWej.fail())
   return StrWej;
  if(nawias!=')')
   {
   StrWej.setstate(std::ios::failbit);
   return StrWej;
   }
   StrWej >> LZesp.re;
   if(StrWej.fail())
   return StrWej;
   StrWej >> LZesp.im;
   if(StrWej.fail())
   return StrWej;
   StrWej >> litera;
   if(StrWej.fail())
   return StrWej;
   if(litera != 'i')
   {
   StrWej.setstate(std::ios::failbit);
   return StrWej;
   }
   StrWej >> nawias;
   if(StrWej.fail())
   return StrWej;
   if(nawias != ')')
   {
   StrWej.setstate(std::ios::failbit);
   return StrWej;
   }
   return StrWej;
 }
