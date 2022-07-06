#include <iostream>

using namespace std;

int main() {

	int niz[1000];
	int brojac(0);
	int unos;

	do
	{
		cout << "Unesite " << brojac + 1 << " broj: ";

		cin >> unos;

		if (unos < 0) {
			continue;
		}
		niz[brojac] = unos;

		brojac++;
	} while (unos != 0);

	int n;

	do {
		cout << "\nUnesite n broj od 1 do 10: ";
		cin >> n;
	} while (n < 1 || n > 10);

	for (int i = 0; i < brojac; i++) {
		for (int j = i + 1; j < brojac; j++) {
			if (niz[i] > niz[j]) {
				int temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << "Brojevi djeljivi sa " << i << " :";
		for (int j = 0; j < brojac; j++) {
			if (niz[j] % i == 0) {
				cout << niz[j] << "  ";
			}
		}
		cout << endl;
	}
}
