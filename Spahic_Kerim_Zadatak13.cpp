
 #include <iostream>
 #include <ctime>
 #include <cstdlib>

 using namespace std;


void GenArray (int Array[], int n, int maxbroj){
    Array[n];
    for (int i = 0; i < n; i ++) {
        Array[i] = rand()%maxbroj + 1;                         // Funkcija koja generise niz, imamo for petlju koja ide do broja "n" kojeg korisnik unosi
        cout << "\t"<<i+1<<".clan niza: "<< Array[i] << endl;
    }
    cout << "\n\n\n"; //Prostor
 }

int sum_of_digit(int n){
    if (n == 0)
                                                // Rekurzivna funkcija koja sluzi sa sabiranje cifara od elemenata niza
    return 0;
    return (n % 10 + sum_of_digit(n / 10));
}
 void Sorting (int Array[], int n) {
    for (int i=0; i < n; i++){
            for (int j=i+1; j < n; j++){
                if (sum_of_digit(Array[j]) > sum_of_digit(Array[i])){       //Funkcija koja sluzi za sortiranje elemeneta po zbiru njihovih cifara, od najveceg zbira pa do najmanjeg
                    swap(Array[j], Array[i]);
                }
            }
        }
 }

 int main () {
    int n; // Deklaracija varijable n, koju cemo koristiti za velicinu/broj elemenata u nizu
    cout << "\tUnesite broj elemenata: "; // Ispis
    cin >> n; // Unos vrijednosti varijable n

    cout << "\n\n\n"; //Prostor

    int maxBroj; // Deklaracija varijable maxBroj koju cemo korsiti za funkciju generisanja niza. On ce oznacavati granicu tog niza koji ce se random generirati.
    cout << "\tUnesite maksimalni broj u nizu: "; // Ispis
    cin >> maxBroj; // Unos vrijednosti varijable maxBroj
    int Array[n]; // Deklaracija niza Array, koji ce imati "dimenziju" odredjenu unosom varijable n

    cout << "\n\n\n"; //Prostor

    srand((unsigned)time(0)); // Mogucnost random generisanja brojeva... Funkcija koja se poziva pomocu biblioteke ctime

    GenArray(Array, n, maxBroj); // Poziv funkcije GenArray
    Sorting(Array, n); // Poziv funkcije Sorting

    cout << "\tGenerisani niz nakon sortiranja cifara po zbiru izgleda ovako: "; // Ispis
    for (int i = 0; i < n; i++){
        cout << Array[i] << " ";  // For petlja koja nam sluzi za ispis sortinranog niza po zbiru cifara elemnata (od najveceg zbira do najmanjeg)
    }

    cout << "\n\n\n"; //Prostor

    return 0;
 }

 
