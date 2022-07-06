#include <iostream>
using namespace std;

int f1(int x, int y)
{
if(x > y)
f1(x-y, y);
else if(y > x)          // Morao sam napraviti/deklarisati dvije rekurzivne funkcije gdje se pozivaju jedna u drugu...
f1(x, y-x);         //  Drugaciji nacin ja nisam mogao odraditi. Prva funkcija predstavlja trazenje najveceg zajednickog djelioca, a druga funkcija NZS.
else
return x;
}

int f2 (int a,int b){
return (a*b) / f1(a,b);
}


int main () {
    int num1, num2, NZS; // Deklaracija varijabli tipa int
    do {
        cout << "Unesite prvi prirodan broj: ";
        cin >> num1;
    }while (num1 <= 0);
    // Dvije petlje koje nam omogucavaju da dva broja koja unosimo moraju biti pozitvini
    do {
        cout << "Unesite drugi prirodan broj: ";
        cin >> num2;
    }while (num2 <= 0);
    if (num1 > num2){
       NZS = f2(num2, num1);
    }// Pomocu ovih uslova samo imamo drugaciji poziv funkcije, odnosno drugacije uloge parametara unutar rekurzivne funkcije
    else {
        NZS = f2 (num1, num2);
    }
    cout << f2(num1, num2);
    return 0;
}
