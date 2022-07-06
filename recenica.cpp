#include <iostream>
using namespace std;

struct Roba {
    string nazivArtikla;
    int brojSkladista;
    int kolicinaSkladista;
    int minimalnaKolicina;
    int brojArtikala;
    string imeDobavljaca;
    double cijenaArtikla;
};

int main () {
    int brojArtikala;
    cout << "Unesite broj artikala: ";
    cin >> brojArtikala;

    struct Roba* artikal {new struct Roba[brojArtikala]{}};

    system ("cls");
    for (int i = 0; i < brojArtikala; i++){

        cout << "\n" << i+1<< ". Unesite naziv artikla: ";
        getline (cin, artikal[i].nazivArtikla);

        cin.ignore(100, '\n');

        cout << "\n" << i+1 << ". Unesite cijenu artikla: ";
        cin >> artikal[i].cijenaArtikla;

    }
    cout << artikal[0].cijenaArtikla << endl;

    return 0;
}

