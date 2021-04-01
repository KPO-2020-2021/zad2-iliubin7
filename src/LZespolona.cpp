#include "../inc/LZespolona.hh"
#include <cmath>
#include <iostream>
#include <stdexcept>   // To use runtime_error

#define MIN_DIFF 0.00001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  LZespolona::operator == (  LZespolona  Skl2) const{

  if (abs(re - Skl2.re_get()) <= MIN_DIFF && abs(im - Skl2.im_get()) <= MIN_DIFF)
    return true;
  else
    return false;

}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re_set() = re + Skl2.re_get();
  Wynik.re_set() = im + Skl2.im_get();
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
LZespolona  LZespolona::operator - (  LZespolona  Skl2){
  LZespolona  Wynik;
  Wynik.re_set() = re - Skl2.re_get();
  Wynik.re_set() = im - Skl2.im_get();
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
LZespolona  LZespolona::operator * (  LZespolona  Skl2){
  LZespolona  Wynik;
  Wynik.re_set() = re * Skl2.re_get() -im * Skl2.im_get();
  Wynik.re_set() = re * Skl2.im_get()+ im * Skl2.re_get();
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
LZespolona  LZespolona::operator / (  double  Skl2){
  LZespolona  Wynik;
  if(Skl2 == 0)
  {
    throw std::runtime_error("Math error: Attemted to divided by Zero\n");
  }
  Wynik.re_set() = re / Skl2;
  Wynik.re_set() = im / Skl2;
  return Wynik;
}

/*!
 * Realizuje operacje sprzezenia liczby zespolonej
 * Argument:
 *    Skl1 - dzielona liczba zespolona,
 * Zwraca:
 *    Wynik sprezenia.
 */
LZespolona  LZespolona::Sprzezenie(){
 LZespolona  Wynik;
   Wynik.re_set() = re;
   Wynik.re_set() = (-1)*im;
  return Wynik;
}

/*!
 * Realizuje operacje modul do kwadratu liczby zespolonej
 */
double LZespolona::Modul2(){
   double Wynik;
   Wynik= re*re + im*im;
   return Wynik;
}

LZespolona LZespolona::operator / ( LZespolona Skl2){
  LZespolona Wynik;
  Wynik=*this*Skl2.Sprzezenie()/Skl2.Modul2();
  return Wynik;
}

LZespolona  LZespolona::operator += (  LZespolona const &Skl2){

  re += Skl2.re_get();
  im += Skl2.im_get();
  return (*this);
}

LZespolona  LZespolona::operator /= (  LZespolona const &Skl2){

  re /= Skl2.re_get();
  im /= Skl2.im_get();
  return (*this);
}

std::ostream& operator << (std::ostream &StrWyj, const LZespolona &LZesp)
{
  StrWyj.precision(2);
  StrWyj << "(" << std::fixed << LZesp.re_get() << std::showpos << LZesp.im_get() << std::noshowpos << "i)";
  return StrWyj;
}
void WczytajTenZnak(std::istream &StrWej, char Znak){
  char CzytanyZnak = ' ';
  StrWej >> CzytanyZnak;
  if (CzytanyZnak != Znak){
    StrWej.setstate(std::ios::failbit); }
}
std::istream& operator >> (std::istream &StrWej, LZespolona &LZesp){
  //W przypadku, gdy strumien jest w stanie fail, to zadna operacja czytania juz sie nie wykona
  WczytajTenZnak(StrWej, '(');
  StrWej >> LZesp.re_set();
  StrWej >> LZesp.im_set();
  WczytajTenZnak(StrWej, 'i');
  WczytajTenZnak(StrWej, ')');
  return StrWej;
}
