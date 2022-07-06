#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct mjerenja {
	float u9, u13, u16, u20;
} sarajevo[731];

int main() {

	int dani = 0, brojac1, brojac2;
	ifstream datoteka("mjerenja-sarajevo.txt");

	if (datoteka.is_open()) {

		while (!datoteka.eof() && dani < 731) {
			datoteka >> sarajevo[dani].u9 >> sarajevo[dani].u13 >> sarajevo[dani].u16 >> sarajevo[dani].u20;
			dani++;
		}

		datoteka.close();

		cout << "Iz datoteke su ucitani podaci za: " << dani << " dana.\n";
		brojac1 = brojac2 = 0;

		for (int i = 0; i < dani; i++) {
			if (sarajevo[i].u9 > sarajevo[i].u13 || sarajevo[i].u9 > sarajevo[i].u16 || sarajevo[i].u9 > sarajevo[i].u20)
				brojac1++;
			if (sarajevo[i].u13 < sarajevo[i].u9 || sarajevo[i].u13 < sarajevo[i].u16 || sarajevo[i].u13 < sarajevo[i].u20)
				brojac2++;
		}

		cout << "Od toga, ima " << brojac1 << " dana u kojima temperatura u 9 nije najmanja, a " << brojac2 << " dana u kojima temperatura u 13 nije najveca.\n\n";

		ofstream datoteka1("sortirano13-sarajevo.txt");

		for (int i = 0; i < dani; i++) {
			for (int j = i + 1; j < dani; j++) {
				if (sarajevo[i].u13 > sarajevo[j].u13) {
					struct mjerenja temp = sarajevo[i];
					sarajevo[i] = sarajevo[j];
					sarajevo[j] = temp;
				}
			}
		}

		for (int i = 0; i < dani; i++){
			cout << sarajevo[i].u9 << "  " << sarajevo[i].u13 << "  " << sarajevo[i].u16 << "  " << sarajevo[i].u20 << endl;
			datoteka1 << sarajevo[i].u9 << "  " << sarajevo[i].u13 << "  " << sarajevo[i].u16 << "  " << sarajevo[i].u20 << endl;
		}
		datoteka1.close();
	}
	else {
		cout << "Datoteka nije pronadena!";
	}
	return 0;
}
