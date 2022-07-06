#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define min 0 
#define max 1000
int vel_niza(10);

int sumaCifri (int broj){

	int suma (0);

	while (broj > 0) {

		suma += broj % 10;
		broj /= 10;
	}
	return suma;
}

void sortNiza(int* niz, int vel_niza) {

	for (int i = 0; i < vel_niza; i++) {
		for (int j = 0; j < vel_niza; j++) {
			if (sumaCifri(niz[i]) > sumaCifri(niz[j])) {

				int temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;

			  }
		}
	}
}

int main() {

	srand(time(NULL));

	int *niz = new int[vel_niza];

	for (int i = 0; i < vel_niza; i++) {

		niz[i] = rand() % max + min;
		cout << niz[i] << "  ";

	}

	sortNiza(niz, vel_niza);

	cout << "\n\nSortirani po sumi:\n\n";

	for (int i = 0; i < vel_niza; i++) {

		cout << niz[i] << "  ";

	}
}
