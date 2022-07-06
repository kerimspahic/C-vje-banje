#include <iostream>

using namespace std;

void duzina (string word){
    cout <<"Rijec sadrzi: "<<word.length()<<" slova."; // Deklaracija funkcije duzina: Ona prima parametar tipa string i ispisuje nam njegovu duzinu
}
int izbroji(string word){
    int counter = 0;
    for (int i=0;i<word.size();i++){
        if (word[i] =='c'||word[i] =='C'){      // Deklaracija funkcije izbroji: Ona prima parametar tipa string i sadrzi for petlju pomocu koje se prebrojava slovo 'C' ili 'c'
            counter++;
        }
    }
    return counter;
}
int samogl (string word){
    int counter = 0;
    for (int i = 0; i < word.size(); i++){
        if ((word[i] =='a'||word[i]=='A')||(word[i] =='e'||word[i]=='E')){
            counter ++;
        }
        if ((word[i] =='i'||word[i]=='I')||(word[i] == 'o'||word[i]=='O')){   // Deklaracija funkcije samogl: Ona prima parametar tipa string i sadrzi for petlju pomocu koje se prebrojavaju samo glasnici pomocu 'if' petlji
            counter ++;
        }
        if ((word[i] =='u'||word[i]=='U')){
            counter ++;
        }
    }
    return counter;
}

int main () {
    string word; // Deklaracija varijable word, tipa string
    cout << "Unesite rijec: "; // Ispis
    cin >> word; // Unos varijable word
    cout << endl; // Razmak
    duzina (word); // Poziv funkcije "duzina"
    cout << "\nBroj karaktera 'c' u rijeci je: " << izbroji(word) << endl; // Ispis i poziv funkcije "izbroji"
    cout << "Broj samoglasnika u rijeci je: " << samogl (word) << endl; // Ispis i poziv funkcije "samogl"
    return 0;
}

