#include <iostream>
#include <iomanip>
using namespace std;

struct Uplata {
	int dan, mjesec, godina;
	char uplatitelj[50];
	double iznos;
	};

void CitajUplatu(Uplata &uplata) {
	char crta; // Služi za preskakanje znaka '/' prilikom unosa datuma
	cout << "Unesi datum uplate u obliku DAN/MJ/GOD: ";
	cin >> uplata.dan >> crta >> uplata.mjesec >> crta >> uplata.godina;
	cin.ignore(1000, '\n'); // Obriši zaostalo "smeæe"
	cout << "Unesi ime uplatitelja: ";
	cin.getline(uplata.uplatitelj, sizeof uplata.uplatitelj);
	cout << "Unesi iznos uplate: ";
	cin >> uplata.iznos;
	}

void StampajUplatu(const Uplata &uplata) {
	cout << endl << uplata.uplatitelj << " je uplatio(la) iznos od "
	<< setprecision(2) << uplata.iznos << " KM dana " << uplata.dan
	<< "/" << uplata.mjesec << "/" << uplata.godina << endl << endl;
}

int main() {
	Uplata nova_uplata;
	char odgovor = 'D';
	while(odgovor == 'D' || odgovor == 'd') {
		CitajUplatu(nova_uplata);
		StampajUplatu(nova_uplata);
		cout << "Želite li još uplata (D/N)?";
		cin >> odgovor;
		cin.ignore(1000, '\n'); // Obriši eventualni višak znakova
		cout << endl;
	}
return 0;
}
