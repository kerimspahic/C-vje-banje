#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <iomanip>

using namespace std;

struct Firma {
	string imeFirme;
	double osnovniKoef;
	double ukupniPorez;
	int brojRadnika;
};

struct Radnik {
	string ime;
	string prezime;
	string pozicija;
	int id;
	double osnovicaPlate;
	int staz;
};

int globalniBrojac(int brojac){
		string line;
		ifstream datoteka("obracun.txt");
	if (datoteka.is_open()) {

		while (getline(datoteka, line)) {

			brojac++;
		}
		datoteka.close();
		}
		return brojac;
}

void upisivanjeUDatoteku(struct Radnik* nizRadnik, int brojac) {
	ofstream datoteka;
	datoteka.open("obracun.txt");
	for (int i = 2; i < brojac; i++) {
		datoteka << nizRadnik[i].ime << " " << nizRadnik[i].prezime << " " << nizRadnik[i].pozicija << " " << nizRadnik[i].id << nizRadnik[i].osnovicaPlate << nizRadnik[i].staz << endl;
	}
	datoteka.close();
}

int kreiranjeDatoteke() {

	cout << "Da li bi zeljeli kreirati datoteku (Y/N): ";
	char provjera;
	cin >> provjera;

	if (provjera == 'Y' || provjera == 'y') {
		ofstream datoteka("obracun.txt");
		system("cls");
		cout << "Datoteka je kreirana!" << endl;
		cout << "Za novu datoteku treba unijeti podatke firme i njenih uposlenika:" << endl;

		return 0;
	}
	else if (provjera == 'N' || provjera == 'n') {
		cout << "Dovidenja!" << endl;
		system("pause");
		return 0;
	}
	system("cls");
	cout << "Uneseni simbol ne odgovara ponudenim odgovorima." << endl;

	kreiranjeDatoteke();
}

void unesi() {


	ofstream datoteka("obracun.txt", ios::app);

	string imeFirme;
	double osnovniKoef;
	double ukupniProcenatPoreza;
	int brojRadnika;

	cout << endl << "Unesite ime firme: ";
	cin >> imeFirme;
	cout << "Unesite osnovni koef. firme: ";
	cin >> osnovniKoef;
	cout << "Unesite ukupan procenat poreza: ";
	cin >> ukupniProcenatPoreza;
	cout << "Unesite broj radnika:";
	cin >> brojRadnika;

	datoteka << imeFirme << "  " << osnovniKoef << "  " << ukupniProcenatPoreza << "  " << brojRadnika << endl;
	cout << "Upisano u datoteku\n";

	for (int i = 0; i < brojRadnika; i++) {

		string ime;
		string prezime;
		string pozicija;
		int id;
		double osnovicaPlate;
		int staz;

		cout << endl << "Unesite ime " << i + 1 << ". radnika: ";
		cin >> ime;
		cout << "Unesite prezime " << i + 1 << ". radnika: ";
		cin >> prezime;
		cout << "Unesite poziciju " << i + 1 << ". radnika: ";
		cin >> pozicija;
		cout << "Unesite id " << i + 1 << ". radnika: ";
		cin >> id;
		cout << "Unesite osnovicu  plate " << i + 1 << ". radnika: ";
		cin >> osnovicaPlate;
		cout << "Unesite staz " << i + 1 << ". radnika (godine): ";
		cin >> staz;
		datoteka << ime << "  " << prezime << "  " << pozicija << "  " << id << "  " << osnovicaPlate << "  " << staz << endl;
		cout << "\t\nUpisano u datoteku\n";
	}
	datoteka.close();
}

int pretragaRadnika(struct Radnik* nizRadnik, int brojac) {
	system("cls");
	string pojam = "";
	int pozicija = -1;
	ifstream datoteka("obracun.txt");

	if (datoteka.is_open()) {
		cout << "\t\t\t\t*** PRETRAGA RADNIKA ***\n\n\n\n";
		cout << "\tUnesite ili ime ili prezime: ";
		cin >> pojam;
		cout << endl << endl;
		for (int i = 0; i < brojac; i++) {
			if (nizRadnik[i].ime.compare(pojam) == 0 || nizRadnik[i].prezime.compare(pojam) == 0) {
				pozicija = i;
				break;
			}
		}
		if (pozicija != -1) {
			cout << "Podaci o radniku: ";
			_sleep(1000);
			cout << "\n\n|*Ime*| " << nizRadnik[pozicija].ime;
			_sleep(1000);
			cout << "\n\nPrezime: " << nizRadnik[pozicija].prezime;
			_sleep(1000);
			cout << "\n\n" << "Pozicija: " << nizRadnik[pozicija].id;
			_sleep(1000);
			cout << "\n\n" << "Osnovica Plate: " << nizRadnik[pozicija].osnovicaPlate;
			_sleep(1000);
			cout << "\n\n" << "Staz: " << nizRadnik[pozicija].staz;
			_sleep(1000);
			cout << "\n\n";
			return pozicija;
		}
		else {
			cout << "trazeni covjek ne postoji";
			return -1;
		}
	}
	else cout << "Ne mogu da otvorim, fajl";
	datoteka.close();



}

void izmjenaInformacijaRadnika(struct Radnik* nizRadnik, int brojac) {

	string ime;
	string prezime;
	string pozicija;
	int id;
	double osnovicaPlate;
	int staz;

	cout << "\n" << "Izmjena INFO_Radnika:" << "\n";
	int a = pretragaRadnika(nizRadnik, brojac);
	if (a > -1) {
		cout << "--------------------------------------------------";
		cout << "\n--------------------------------------------------";
		cout << "\nNovo ime";
		cin >> ime;
		cout << "Novo prezime";
		cin >> prezime;
		cout << "\nNova pozicija: ";
		cin >> pozicija;
		cout << "\nNovi ID: ";
		cin >> id;
		cout << "\nNova osnovica plate: ";
		cin >> osnovicaPlate;
		cout << "\nPromjena staza: ";
		cin >> staz;
		nizRadnik[a].ime = ime;
		nizRadnik[a].prezime = prezime;
		nizRadnik[a].pozicija = pozicija;
		nizRadnik[a].id = id;
		nizRadnik[a].osnovicaPlate = osnovicaPlate;
		nizRadnik[a].staz = staz;
		upisivanjeUDatoteku(nizRadnik, brojac);
		cout << "\Datoteka je izmjenjena !!!";
	}

}

void ispisRadnika(struct Radnik* nizRadnik, int brojac) { //uredit popravit aaaaaaaaaaaaaaaaa

	string line;
	ifstream datoteka("obracun.txt");

	if (datoteka.is_open()) {

		while (getline(datoteka, line)) {

			brojac++;
		}
		datoteka.close();

		nizRadnik = new Radnik[brojac];

		datoteka.open("obracun.txt");


		for (int i = 3; i <= brojac; i++){
            datoteka >> nizRadnik[i].ime >> nizRadnik[i].prezime >> nizRadnik[i].pozicija >> nizRadnik[i].id >> nizRadnik[i].osnovicaPlate >> nizRadnik[i].staz;
			cout << nizRadnik[i].ime << " " << nizRadnik[i].prezime << " " << nizRadnik[i].pozicija << " " << nizRadnik[i].id <<" "<< nizRadnik[i].osnovicaPlate << " " << nizRadnik[i].staz <<"\n";
		}

	}
}

int dodavanjeRadnika(struct Radnik* nizRadnik, struct Firma* nizFirma, int brojac){ //uredit
	ofstream datoteka("Obracun.txt", ios::app);
	string ime;
	string prezime;
	string pozicija;
	int id;
	double osnovicaPlate;
	int staz;
	cout << "Ime novog radnika: ";
	cin >> ime;
	cout << "Prezime novog radnika: ";
	cin >> prezime;
	cout << "\nukucajte broj telefona\n" << "\n";
	cin >> pozicija;
	cout << "ukucajte mail\n";
	cin >> id;
	cout << "ukucajte mail\n";
	cin >> osnovicaPlate;
	cout << "ukucajte mail\n";
	cin >> staz;
	datoteka << ime << "  " << prezime << "  " << pozicija << "  " << id << "  "<< osnovicaPlate<<"  "<<staz<< endl;
	cout << "upisano u datoteka";
	nizFirma[0].brojRadnika++;
	datoteka.close();
	return brojac++;
}





int main() 
{
	char crta[] = "\t\t\t*-----------------------------------------------*";
	int izbor = 0;
	Firma* nizFirma = NULL;
	Radnik* nizRadnik = NULL;

	int brojac = 0;


	ifstream datoteka("obracun.txt");

	if (datoteka.is_open()) {

		brojac=globalniBrojac(brojac);
		cout<<brojac;
		nizFirma = new Firma[brojac];
		nizRadnik = new Radnik[brojac];

		datoteka.open("obracun.txt");


		for (int i = 0; i <= brojac; i++) {

			if (i == 0) {
				datoteka >> nizFirma[i].imeFirme >> nizFirma[i].osnovniKoef >> nizFirma[i].ukupniPorez >> nizFirma[i].brojRadnika;
			}
			datoteka >> nizRadnik[i].ime >> nizRadnik[i].prezime >> nizRadnik[i].pozicija >> nizRadnik[i].id >> nizRadnik[i].osnovicaPlate >> nizRadnik[i].staz;

		}
		do {
			cout << crta;
			cout << "\n\t\t\t|\t Dobrodosli u meni             \t\t|\n";
			cout << "\t\t\t|                                 \t\t|\n";
			cout << "\t\t\t|\t 1. Pretraga radnika           \t\t|\n";
			cout << "\t\t\t|\t 2. Izmjena informacija radnika\t\t|\n";
			cout << "\t\t\t|\t 3. Ispis Radnika              \t\t|\n";
			cout << "\t\t\t|\t 4. Dodavanje u datoteku       \t\t|\n";
			cout << "\t\t\t|\t 5. Ispis plata                \t\t|\n";
			cout << "\t\t\t|\t 6. Podaci Firme               \t\t|\n";
			cout << "\t\t\t|\t 7. Izmjena Firme              \t\t|\n";
			cout << "\t\t\t|\t 8. Exit Izlaz iz programa     \t\t|\n";
			cout << crta;
			cout << "\n\t\t\t\t UKUCAJTE IZBOR: ";
			cin >> izbor;


			switch (izbor) {
			case 1:	 pretragaRadnika(nizRadnik, brojac);			break;
			case 2:	 izmjenaInformacijaRadnika(nizRadnik, brojac);	break;
			case 3:	 ispisRadnika(nizRadnik, brojac);				break;
			case 4:	 dodavanjeRadnika(nizRadnik, nizFirma, brojac);	break;
			case 5:	 		break;
			case 6:				break;
			case 7:				break;
			case 8:  izbor = -1; break;
			default: cout << "Ne moze to" << endl;			break;
			}
		} while (izbor != -1);

	}
	else {
		cout << "Datoteka nije kreirana ili je pod drugim imenom." << endl;

		kreiranjeDatoteke();
		unesi();
		cout << "\nVrijednosti su unesene u datotku.\nPonovo pokreni program.";
	}
}
