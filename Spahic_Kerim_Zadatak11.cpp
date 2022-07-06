#include <iostream>

using namespace std;

void Unos (char recenica[]){
    cout << "Molimo vas unesite vasu recenicu: ";   // Funkcija koja se koristi za unos recenice
    cin.getline (recenica, 1000);
}

int main () {
    char sentence[1000]; // Deklaracija niza za recenicu
    Unos (sentence); // Poziv funkcije Unos
    char* ptr = sentence; // Deklaracija pointera i incializiranje na prvu memorijsku lokaciju niza recenica
    bool temp = 0; // Deklaracija ove varijable je iz razloga da nadgleda/prati dali je prva rijec u recenici prosla/zavrsila ili ne. (Koristit cemo je u while petlji)
    cout << "\t\nVasa recenica bez prve rijeci glasi: "; // Ispis
    do{
        if (*ptr == ' ' && !temp){
        temp = 1;
        ptr++;
        }// Ova petlja radi na sljedecem principu: Ako naidjemo na razmak, prva rijec postaje true, kako bi nam se ostali dio recenice ispisao.
        if (temp){// Ovaj if nam predstavlja prvu rijec, postavljeno je tako da se izvrsava samo jednom (kada naidjemo na prvi prazan prosoto u nizu)
        cout << *ptr;
        }
        ptr ++; //Posto ptr drzi memorijsku lokaciju prvog elementa niza, povecavanjem "vrijednosti" naseg pointera, pomjermao ga na drugu memorijsku lokaciju i povecavamo sve dok dodje na kraj niza tj. do 0
    } while (*ptr != 0);
    cout << endl << endl;
}


