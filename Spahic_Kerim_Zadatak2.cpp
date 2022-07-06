#include <iostream>
#include <algorithm>

using namespace std;

int brojpoz (int Array[], int n) {
    Array[n];
    int counter = 0;
    for (int i=0; i < n; i++){
            Array[n] = Array[i];    // Vrsi prebrojavanje pozitivnih elemenata unesenih u niz
            if (Array[n] > 0){
                counter ++;
            }
    }
    return counter;
}
int proizvod (int Array[], int n){
    Array[n];
    int P = 1;
    for (int i = 0; i < n; i ++){   //Vrsi izracunjavanje proizvoda svih clanova niza
        Array[n] = Array[i];
        P*=Array[n];
    }
    return P;
}
float prosjek (int Array[], int n){
    Array[n];
    float suma = 0;
    float avg;
    for (int i = 0; i < n; i ++){   //Vrsi izracunavanje prosjeka elemenata koji su uneseni u niz
        suma+=Array[i];
    }
    avg = suma/n;
    return avg;
}
int zbirparnih (int Array[], int n){
    Array[n];
    int suma = 0;
    for (int i = 0; i < n; i ++){
            Array[n] = Array[i];
            if (Array[n] % 2 == 0){
                    suma += Array[n];       //Racuna zbir parnih brojeva koji su uneseni u niza
            }
        }
    return suma;
}
int brojnula (int Array[], int n){
    Array[n];
    int counter = 0;
    for (int i = 0; i < n; i ++){      //Racuna koliko imamo elemenata koji imaju vrijednost nula, koji su prethodno uneseni u niz
        Array[n] = Array[i];
        if (Array[n] == 0){
            counter ++;
        }
    }
    return counter;
}
int brojneg (int Array[], int n){
    Array[n];
    int counter = 0;
    for (int i = 0; i < n; i ++){   //Racuna koliko je negativnih clanova uneseno u niz
        Array[n] = Array[i];
        if (Array[n] < 0){
            counter ++;
        }
    }
    return counter;
}

int main () {
    int n; //Deklaracija var n, tipa int
    do {
        cout << "Unesite prirodan broj: ";   // Petlja koja nam sluzi za unos prirodnog broja u razmaku od 0 do 100
        cin >> n;
    }while (n > 100 || n < 0);

    int Array[n]; //Deklaracija niza, koji posjeduje vrijednost/dimenziju od varijable n
    cout << "\nUnesite clanove niza: \n"; //Ispis
    for(int i = 0; i < n; i++){
        cin >> Array[i];        //For petlja koja sluzi za unos clanova niza
    }
    _sleep (800); //Tajmer
    system("cls"); // Sistem clear... Cisti nam prozor

    cout << "Vas niz izgleda ovako: \n"; // Ispis

    for (int i = 0; i < n; i++){
        cout << i+1 <<".clan niza: "<<Array[i]<<endl;   //For petlja koja nam sluzi za ispis clanova niza
    }
    


    cout <<"\nBroj pozitivnih clanova niza je: " << brojpoz (Array, n); //Ispis
    cout <<"\nProzvod svih clanova niza je: " << proizvod (Array, n); //Ispis
    cout <<"\nZbir parnih brojeva u nizu je: " << zbirparnih(Array, n); //Ispis
    cout <<"\nBroj clanova jednakih nuli: " << brojnula (Array, n); //Ispis
    cout <<"\nBroj clanova koji su negativni: " << brojneg (Array, n); //Ispis
    cout <<"\nProsjek elemenata (brojeva) koji su uneseni u niz je: " << prosjek (Array, n); //Ispis
    return 0;
}


