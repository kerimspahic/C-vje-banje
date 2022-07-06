#include <iostream>
#include <unistd.h>

using namespace std;

int f1 (int n){

if (n < 10) {
cout << n;}
else {
f1 (n/10);// Rekurzivna funkcija za rastavljanje cifara.
cout <<" "<< n%10;
}}
int f2 (int n){
if (n < 10){
cout << n;
}else {
cout << n%10 << " ";// Rekurzivna funkcija za ispisivanje cifara u obrnutom redoslijedu.
f2 (n/10);
}
}


int main () {
    int num;//Deklaracija varijable num, tipa int
    cout << "Molimo vas da unesete cijeli broj: ";  //Ispis
    cin >> num; //Unos vrijednosti varijable num


    cout << "Dekadne cifre unesenog broja: "; //Ispis
    f1 (num); //Poziv funkcije
    cout << endl; //Razmak
    cout << "Dekadne cifre unesnog broja obrnuto: "; //Ispis
    f2 (num); //Poziv funkcije

    return 0;
}
