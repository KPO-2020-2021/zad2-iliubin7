#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.hh"
using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }



  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
LZespolona odp;
Statystyki st;
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << "Podaj wynik operacji: "<<WyrZ_PytanieTestowe << "\n";
    for(int i=0; i<1; i++)
    {
       cout << "Wpisana odpowiedz: ";
       cin>>odp;
       if(cin.good())
       {
           break;
       }
       cin.clear();
       cin.ignore(1024,'\n');
    }
    if(Oblicz(WyrZ_PytanieTestowe)==odp)
    {
        cout<<"odpowiedz poprawna\n"<<endl;
        st.dobrze++;
    }
    else
    {
          cout<<"Blad. Prawidlowym wynikiem jest:"<< odp << "\n" <<endl;
          st.zle++;
    }

     }

st.Oblicz();
st.Wypisz();

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
