#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Firma {
	string imeFirme;
	double osnovniKoef;
	double ukupniPorez;
};

struct Radnik {
	string ime;
	string prezime;
	string pozicija;
	int id;
	double osnovicaPlate;
	int staz;
};

enum Izbor {
	No, Yes
};

bool provjera() {

	char provjera1;
	bool test;

	cout << "Da li bi ste zeljeli kreirati datoteku/e (Y/N): ";

	cin >> provjera1;

	if (provjera1 == 'Y' || provjera1 == 'y') {
		return 1;
	}
	else if (provjera1 == 'N' || provjera1 == 'n') {
		cout << "\nOK, LP!" << endl;
		return 0;
	}
	system("cls");
	cout << "Uneseni simbol ne odgovara ponudenim odgovorima." << endl;
	provjera();
}

void upisivanjeUDatoteku(struct Radnik* nizRadnik, int brojac) {
	ofstream datoteka;
	datoteka.open("radnici.txt");
	for (int i = 0; i < brojac; i++) {
		datoteka << nizRadnik[i].ime << "  " << nizRadnik[i].prezime << "  " << nizRadnik[i].pozicija << "  " << nizRadnik[i].id << "  " << nizRadnik[i].osnovicaPlate << "  " << nizRadnik[i].staz << endl;
	}
	datoteka.close();
}

void kreiranjeDatotekeRadnici() {

	ofstream datotekaRadnici("radnici.txt");
	system("cls");
	cout << "Datoteka je kreirana!\n\n" ;
	cout << "Za novu datoteku treba unijeti podatke njenih uposlenika.\n" ;

}

void kreiranjeDatotekeFirma() {

	ofstream datotekaFirma("firma.txt");
	system("cls");
	cout << "Datoteka je kreirana!\n\n";
	cout << "Za novu datoteku treba unijeti podatke njenih uposlenika.\n";

}

void unosDatotekeFirma() {

	ofstream datotekaFirma("firma.txt");
	string imeFirme;
	double osnovniKoef;
	double ukupniProcenatPoreza;

	cout << endl << "Unesite ime firme: ";
	cin >> imeFirme;
	cout << "Unesite osnovni koef. firme: ";
	cin >> osnovniKoef;
	cout << "Unesite ukupan procenat poreza: ";
	cin >> ukupniProcenatPoreza;


	datotekaFirma << imeFirme << "  " << osnovniKoef << "  " << ukupniProcenatPoreza << "  " << endl;
	cout << "Upisano u datoteku\n";

	datotekaFirma.close();
}

void unosDatotekeRadnici() {

	int brojRadnika;

	ofstream datotekaRadnici("radnici.txt", ios::app);

	cout << "Unesite koliko radnika zelite unijeti: ";
	cin >> brojRadnika;

	for (int i = 0; i < brojRadnika; i++) {

		string ime;
		string prezime;
		string pozicija;
		int id;
		double osnovicaPlate;
		int staz;

		char t[] = "\t\t\t\t\t\t\t\t\t\t";
		char c[] = "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT\n";
		char t2[] = "\t\t\t\t\t\t\t";
		char a[] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";

		system("cls");

		cout << t << c;
		cout << t << "T\t\tUNOS NOVOG RADNIKA              T\n";
		cout << t << c;


		cout << "\n\n " << t2 << a << "\n" << t2 << "Ime novog radnika: ";
		cin >> ime;

		cout << endl << t2 << a << endl << t2 << "Prezime novog radnika: ";
		cin >> prezime;

		cout << endl << t2 << a << endl << t2 << "Unesite poziciju radnika: ";
		cin >> pozicija;

		cout << endl << t2 << a << endl << t2 << "Unesite radnikov ID: ";
		cin >> id;

		cout << endl << t2 << a << endl << t2 << "Unesite osnovicu plate: ";
		cin >> osnovicaPlate;

		cout << endl << t2 << a << endl << t2 << "Unesite staž radnika: ";
		cin >> staz;
		cout << endl << t2 << a;

		datotekaRadnici << ime << "  " << prezime << "  " << pozicija << "  " << id << "  " << osnovicaPlate << "  " << staz << endl;
		cout << endl << t << "**Podaci su dodijeljeni datoteci.**\n\n\n";

		char g;

        char m[] = "\t\t\t\t\t\t\t\t\t\t";
        cout << "\n\n " << m << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << m << "@ Za izlaz iz program pritisnite slovo E. @\n";
        cout << m << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

		while (g != 'e') {
			g = getch();
			printf(" %c", g);
		}

	}
	datotekaRadnici.close();
}

int pretragaRadnika(struct Radnik* nizRadnik, int brojac) {

	string pojam = "";
	int pozicija = -1;

	ifstream datotekaRadnici("radnici.txt");
	system("cls");

	char crta[] = "\t\t\t\t=======================================\n";

	if (datotekaRadnici.is_open()) {

		char t[] = "\t\t\t\t\t\t\t";

		cout << t << crta;
		cout << t << "\t\t\t\t|  \t ***PRETRAGA RADNIKA***       |\n";
		cout << t << crta << "\n\n\n";
		cout << "\n\n\n" << t << "\tUnesite ili ime ili prezime: ";
		cin >> pojam;
		cout << endl << endl;

		for (int i = 0; i < brojac; i++) {
			if (nizRadnik[i].ime.compare(pojam) == 0 || nizRadnik[i].prezime.compare(pojam) == 0) {
				pozicija = i;
				break;
			}
		}

		if (pozicija != -1) {
			char t[] = "\t\t\t\t\t\t\t\t";
			char c[] = "\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

			cout << c << endl;
			cout << t << "@\t                              INFO - RADNIK                                     @\n";
			cout << c << endl;

			_sleep(1000);
			cout << "\n\n" << t << "IME (Radnik): " << nizRadnik[pozicija].ime;

			_sleep(1000);
			cout << "\n\n" << t << "PREZIME (Radnik): " << nizRadnik[pozicija].prezime;

			_sleep(1000);
			cout << "\n\n" << t << "POZICIJA (Radnik): " << nizRadnik[pozicija].pozicija;

			_sleep(1000);
			cout << "\n\n" << t << "OSNOVICA PLATE (Radnik): " << nizRadnik[pozicija].osnovicaPlate;

			_sleep(1000);
			cout << "\n\n" << t << "STAZ (Radnik): " << nizRadnik[pozicija].staz << " godina.";

			_sleep(1000);
			cout << "\n\n" << t << "ID (Radnik): " << nizRadnik[pozicija].id;
			cout << "\n\n";

			char m[] = "\t\t\t\t\t\t\t\t\t\t";
            cout << "\n\n " << m << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
            cout << m << "@ Za izlaz iz program pritisnite slovo E. @\n";
            cout << m << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

			char h;
			char Espera;

			while (h != 'e') {
				h = getch();
				printf(" %c", h);
			}

			return pozicija;
		}

		else {
			cout << "trazeni covjek ne postoji";
			return -1;
		}

	}
	else {
		cout << "Ne mogu da otvorim, fajl";
		datotekaRadnici.close();
	}
}

void izmjenaInformacijaRadnika(struct Radnik* nizRadnik, int brojac) {

	string ime;
	string prezime;
	string pozicija;
	int id;
	double osnovicaPlate;
	int staz;
	char crta[] = "\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	char al[] = "==================================\n";

	int a = pretragaRadnika(nizRadnik, brojac);

	cout << "\t\t\t\t" << crta;
	cout << "\t\t\t\t\t\t\t\t@\t\t\tIZMJENA INFO_Radnika:                      @" << "\n";
	cout << "\t\t\t\t" << crta << "\n\n\n";

	if (a > -1) {

		char t[] = "\t\t\t\t\t\t\t\t";

		cout << t << al;
		cout << t << "|      Promjeni ime radnika:     |\n";
		cout << t << al;
		cout << "\n " << t << "Novo ime: ";
		cin >> ime;

		cout << "\n" << t << al;
		cout << t << "|    Promjeni prezime radnika:   |\n";
		cout << t << al;
		cout << "\n" << t << "Novo prezime: ";
		cin >> prezime;

		cout << "\n" << t << al;
		cout << t << "|   Promjeni poziciju radnika:   |\n";
		cout << t << al;
		cout << "\n" << t << "Nova pozicija: ";
		cin >> pozicija;

		cout << "\n" << t << al;
		cout << t << "|      Promjeni ID radnika:      |\n";
		cout << t << al;
		cout << "\n" << t << "Novi ID: ";
		cin >> id;

		cout << "\n" << t << al;
		cout << t << "|   Promjeni osnovicu radnika:   |\n";
		cout << t << al;
		cout << "\n" << t << "Nova osnovica plate: ";
		cin >> osnovicaPlate;

		cout << "\n" << t << al;
		cout << t << "|    Promjeni staza radnika:     |\n";
		cout << t << al;
		cout << "\n" << t << "Promjena staza: ";
		cin >> staz;

		nizRadnik[a].ime = ime;
		nizRadnik[a].prezime = prezime;
		nizRadnik[a].pozicija = pozicija;
		nizRadnik[a].id = id;
		nizRadnik[a].osnovicaPlate = osnovicaPlate;
		nizRadnik[a].staz = staz;
		upisivanjeUDatoteku(nizRadnik, brojac);

		cout << "\Datoteka je izmjenjena !!!";

		char m[] = "\t\t\t\t\t\t\t\t\t\t";
        cout << "\n\n " << t << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << m << "@ Za izlaz iz program pritisnite slovo E. @\n";
        cout << m << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

	}
}

void ispisRadnika() {

	string line;
	ifstream datoteka("radnici.txt");
	system("cls");
	char crta[] = "\t\t=============================================================================\n";
	cout << "\t\t\t\t\t\t\t" << crta;
	cout << "\t\t\t\t\t\t\t\t\t|\t                        [RADNICI FIRME]                             |\n";
	cout << "\t\t\t\t\t\t\t" << crta << "\n\n\n";

	 char crta1[] = "\t\t\t\t-----------------------------------------------------\n";
     cout << "\t\t\t\t\t\t\t" << crta1;
     cout << "\t\t\t\t\t\t\t" << "\t\t\t\t| IME | PREZIME | POZICIJA | ID | OSN. PLATE | STAZ | \n";
     cout << "\t\t\t\t\t\t\t" << crta1 << endl;

	if (datoteka.is_open()) {

		while (getline(datoteka, line)) {
            _sleep (1000);
			cout << "\t\t\t\t\t\t\t\t\t\t\t" << line << endl << endl;
		}
		datoteka.close();
	}

	cout << "\n\n\n";
	char c;
	char Espera;

	char t[] = "\t\t\t\t\t\t\t\t\t\t";
	cout << "\n\n " << t << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << t << "@ Za izlaz iz program pritisnite slovo E. @\n";
    cout << t << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";


	while (c != 'e') {
		c = getch();
		printf(" %c", c);

		if (c == 'r') {
			scanf("%c", &Espera);
			system("cls");
		}
	}
}

void ispisFirme() {

	string line;
	ifstream datoteka("firma.txt");
	system("cls");

	int i = 0;
	char crta[] = "\t\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

	cout << "\t\t\t\t" << crta;
	cout << "\t\t\t\t\t\t\t\t\t\t$\t     PODACI FIRME            $\n";
	cout << "\t\t\t\t" << crta << "\n\n\n\n";

	 char crta1[] = "\t---------------------------------------\n";
     cout << "\t\t\t\t\t\t\t" << crta1;
     cout << "\t\t\t\t\t\t\t" << "\t| IME FIRME | OSN.KOEF | UKUPNI POREZ | \n";
     cout << "\t\t\t\t\t\t\t" << crta1 << endl;

	if (datoteka.is_open()) {

		while (getline(datoteka, line)) {
			cout << "\t\t\t\t\t\t\t\t" << line << endl;
		}
		datoteka.close();
	}
	char c;
	char Espera;

	char t[] = "\t\t\t\t\t\t\t\t\t\t";
	cout << "\n\n " << t << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << t << "@ Za izlaz iz program pritisnite slovo E. @\n";
    cout << t << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";


	while (c != 'e') {
		c = getch();
		printf(" %c", c);

		if (c == 'r') {
			scanf("%c", &Espera);
			system("cls");
		}
	}
}

int ispisPlate(struct Radnik* nizRadnik, struct Firma* nizFirma, int brojac) {

	int pin = 0;

	ifstream datotekaRadnici("radnici.txt");
	ifstream datotekaFirma("firma.txt");

	system("cls");

	if (datotekaFirma.is_open()) {
		if (datotekaRadnici.is_open()) {
			char t[] = "\t\t\t\t\t\t\t\t\t\t";
			cout << t << "******************************************************\n";
			cout << t << "*\t\t     I$PI$ PLATE:                    *\n";
			cout << t << "******************************************************\n";

			cout << "\n\n\n" << t << "Unesite ID osobe da bi dobili njihovu platu: ";
			cin >> pin;

			for (int i = 0; i < brojac; i++) {
				if (nizRadnik[i].id == pin) {

					double cjenaRada;
					double procenat1, procenat2, procenat3, konacno;
					cout << endl << t << "IME: " << nizRadnik[i].ime << "  " << endl << endl << t << "PREZIME: " << nizRadnik[i].prezime << endl;

					cjenaRada = (nizRadnik[i].osnovicaPlate * nizFirma[0].osnovniKoef);
					procenat1 = (nizRadnik[i].staz / double(100));
					procenat2 = (procenat1 * nizRadnik[i].osnovicaPlate);
					procenat3 = (cjenaRada + procenat2);
					konacno = (procenat3 - nizFirma[0].ukupniPorez);

					cout << endl << t << "PLATA Radnika iznosi: " << konacno << " KM" << endl;

					char c;
					char Espera;
					cout << "\n\n " << t << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
					cout << t << "@ Za izlaz iz program pritisnite slovo E. @\n";
					cout << t << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
					while (c != 'e') {
						c = getch();
						cout << t;
						printf(" %c", c);

						if (c == 'r') {
							scanf("%c", &Espera);
							system("cls");
						}
					}



					return 0;
				}

			}
			cout << "Nema osobe sa tim ID-om";

		}
	}

}

int main() {

	setlocale(LC_ALL, "");

	char crta[] = "\t\t\t*-----------------------------------------------*";
	int izbor = 0;
	int brojacRadnik = 0, brojacFirma(0);
	string lineRadnik, lineFirma;
	bool test;

	Firma* nizFirma = NULL;
	Radnik* nizRadnik = NULL;

	for (int x = 0; x <= 1; x++) {

		ifstream datotekaRadnici("radnici.txt");
		ifstream datotekaFirma("firma.txt");



		if (datotekaRadnici.is_open() && datotekaFirma.is_open()) {

			while (getline(datotekaRadnici, lineRadnik)) {
				brojacRadnik++;
			}
			datotekaRadnici.close();

			while (getline(datotekaFirma, lineFirma)) {
				brojacFirma++;
			}
			datotekaFirma.close();


			nizRadnik = new Radnik[brojacRadnik];
			datotekaRadnici.open("radnici.txt");

			for (int i = 0; i <= brojacRadnik; i++) {
				datotekaRadnici >> nizRadnik[i].ime >> nizRadnik[i].prezime >> nizRadnik[i].pozicija >> nizRadnik[i].id >> nizRadnik[i].osnovicaPlate >> nizRadnik[i].staz;
			}
			datotekaRadnici.close();

			nizFirma = new Firma[brojacFirma];
			datotekaFirma.open("firma.txt");
			for (int i = 0; i <= brojacFirma; i++) {
				datotekaFirma >> nizFirma[i].imeFirme >> nizFirma[i].osnovniKoef >> nizFirma[i].ukupniPorez;
			}
			datotekaFirma.close();

			do {
				system("cls");
				char t[] = "\t\t\t\t\t\t\t\t\t\t\t";
				cout << "\t\t\t\t\t\t\t\t" << crta;
				cout << "\n" << t << "|\t Dobrodosli u meni             \t\t|\n";
				cout << t << "|                                 \t\t|\n";
				cout << t << "|\t 1. Pretraga radnika           \t\t|\n";
				cout << t << "|\t 2. Izmjena informacija radnika\t\t|\n";
				cout << t << "|\t 3. Ispis Radnika              \t\t|\n";
				cout << t << "|\t 4. Dodavanje u datoteku       \t\t|\n";
				cout << t << "|\t 5. Ispis plata                \t\t|\n";
				cout << t << "|\t 6. Podaci Firme               \t\t|\n";
				cout << t << "|\t 7. Izmjena Firme              \t\t|\n";
				cout << t << "|\t 0. Exit Izlaz iz programa     \t\t|\n";
				cout << "\t\t\t\t\t\t\t\t" << crta;
				cout << "\n\n" << t << "\t UKUCAJTE IZBOR: ";
				cin >> izbor;


				switch (izbor) {
				case 1:	 pretragaRadnika(nizRadnik, brojacRadnik);				break;
				case 2:	 izmjenaInformacijaRadnika(nizRadnik, brojacRadnik);	break;
				case 3:	 ispisRadnika();										break;
				case 4:	 unosDatotekeRadnici();									break;
				case 5:	 ispisPlate(nizRadnik, nizFirma, brojacRadnik);			break;
				case 6:	 ispisFirme();											break;
				case 7:	 unosDatotekeFirma();									break;
				case 0:  return 0; 												break;
				default: cout << "Unos nije validan!" << endl;							break;
				}
			} while (true);


		}
		else if (datotekaRadnici.is_open()) {
			cout << "Datoteka sa firmom nije kreirana ili je pod drugim imenom." << endl;
			test = provjera();

			if (test == Yes) {
			kreiranjeDatotekeFirma();
			unosDatotekeFirma();
			cout << "\nVrijednosti su unesene u datotku.\nPonovo pokreni program.";
			}
			else
				return 0;

		}
		else if (datotekaFirma.is_open()) {
			cout << "Datoteka sa radnicima nije kreirana ili je pod drugim imenom." << endl;
			test = provjera();

			if (test == Yes) {
			kreiranjeDatotekeRadnici();
			unosDatotekeRadnici();
			cout << "\nVrijednosti su unesene u datotku.\nPonovo pokreni program.";
			}
			else
				return 0;

		}
		else {
			cout << "Obe datoteke nisu kreirane ili je pod drugim imenom." << endl;
			test = provjera();

			if (test == Yes) {
				kreiranjeDatotekeRadnici();
				kreiranjeDatotekeFirma();
				unosDatotekeFirma();
				unosDatotekeRadnici();
				cout << "\nVrijednosti su unesene u datotku.";
			}
			else
				return 0;
		}
	}
}
