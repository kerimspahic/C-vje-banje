#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	ifstream datoteka("pismo.txt");

	if (datoteka.is_open()) {

		string linija;
		int brojac(0);
		//ispis 
		while (getline(datoteka, linija)) {
			cout << linija << endl;
			brojac++;
		}
		datoteka.close();

		ifstream datoteka("pismo.txt");
		
		string* niz = new string [brojac];

		//naopako
		cout << "\n\nUnesite datoteku u koju hocete napisati sa obrnutim malim i velikim slovima:\n";
		string nDatoteka;
		cin >> nDatoteka;

		ofstream fajl(nDatoteka);

		while (getline(datoteka, linija)) {
			for (int i = 0; i < linija.length(); i++) {
				niz[i] = linija;
				if (linija[i] >= 65 && linija[i] <= 90){
					fajl << char(linija[i] + 32);
				}
				else if (linija[i] >= 97 && linija[i] <= 122){
					fajl << char(linija[i] - 32);
				}
				else {
					fajl << linija[i];
				}
			}
			fajl << endl;
		}

		for (int i = brojac - 1; i >= 0; i++) {
			cout << "\n";
			for (int j = niz[i].length - 1; j >= 0; j--) {
				cout << niz[i][j] << " ";
			}
		}
	}
	else {
		cout << "Datoteka \"pismo.txt\" nije pronadena!";
	}
}
