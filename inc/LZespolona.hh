#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <ostream>
#include <istream>
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class  LZespolona {
      public:
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

      LZespolona(double _re=0,double _im=0){im=_im;re=_re;}
    bool  operator == (  LZespolona  Skl2) const;

LZespolona  operator + (  LZespolona  Skl2);

LZespolona operator - ( LZespolona Skl2);

LZespolona operator * ( LZespolona Skl2);

LZespolona operator / ( double Skl2);

LZespolona Sprzezenie();

double Modul2();

LZespolona operator / ( LZespolona Skl2);
const double   re_get()const{return re;};
const double   im_get()const{return re;};

  double  & re_set(){return re;};
  double   &im_set(){return re;};
};





std::ostream& operator << (std::ostream&, const LZespolona&);

std::istream& operator >> (std::istream&, LZespolona&);

#endif
