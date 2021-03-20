#include "Statystyki.hh"

void Statystyka(int good, int bad){
    double percent=(good*100)/(good + bad);
    cout << "Ilosc dobrych odpowiedzi:" << good << enld;
    cout << "Ilosc zlych odpowieedzi:" << bad << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi:" << percent << endl;
}
