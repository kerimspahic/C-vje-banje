/*omoguæava pretragu imenika koji se nalazi u txt datoteci.
Imenik se sastoji od imena, prezimena, broja telefona, email-a. 
Podaci su razdvojeni sa po jednim razmakom.
U jednom redu se nalaze informacije o jednom kontaktu.
Pored pretraživanja treba omoguæiti i sljedeæe operacije
1. Izmjena podataka u imeniku
2. Ispis imenika
3. Dodavanje u imenik */
#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stdio.h>
using namespace std;

struct Covjek {
	string ime;
	string prezime;
	string brojtelefona;
	string mail;
} ;

int pretragaImenika(struct Covjek *nizCovjek, int brojac) {
	string pojam="";
	int pozicija = -1;
	ifstream fajl("imenik.txt");
	if (fajl.is_open())
	{
		cout << "\n\n\tPretraga Imenika\n";
		cout << "\nUnesite ili ime ili prezime: ";
		cin >> pojam;
		for (int i = 0; i < brojac; i++){
			if (nizCovjek[i].ime.compare(pojam) == 0 || nizCovjek[i].prezime.compare(pojam)==0){
				pozicija = i;
				break;
			}
		}
		if (pozicija != -1){
			cout << "postoji trazeni covjek u imeniku, njegovi podaci su\nime: " << nizCovjek[pozicija].ime << "\nprezime " << nizCovjek[pozicija].prezime << "\ntelefon " << nizCovjek[pozicija].brojtelefona << "\nmail " << nizCovjek[pozicija].mail<<"\n\n\n";
			return pozicija;
		}else {
			cout << "trazeni covjek ne postoji";
			return -1;
		}
	}
	else cout << "Ne mogu da otvorim, fajl";
	fajl.close();
}

void upisivanjeUfajl(struct Covjek *nizCovjek, int brojac){
	ofstream fajl;
	fajl.open("imenik.txt");
	for (int i = 0; i < brojac; i++){
		fajl << nizCovjek[i].ime << " " << nizCovjek[i].prezime << " " << nizCovjek[i].brojtelefona << " " << nizCovjek[i].mail << endl;
		}
	fajl.close();
}

void izmjenaImenika(struct Covjek *nizCovjek, int brojac){
	string ime;
	string prezime;
	string brojtelefona;
	string mail;

	cout << "\n" << "Izmjena imenika" << "\n";
	int pozicija = pretragaImenika(nizCovjek, brojac);
	if (pozicija > -1){
		cout << "ukucajte novo ime" << "\n";
		cin >> ime;
		cout << "ukucajte novo prezime" << "\n";
		cin >> prezime;
		cout << "\nukucajte novi broj telefona\n" << "\n";
		cin >> brojtelefona;
		cout << "ukucajte novi mail\n";
		cin >> mail;
			nizCovjek[pozicija].ime = ime;
			nizCovjek[pozicija].prezime = prezime;
			nizCovjek[pozicija].mail = mail;
			nizCovjek[pozicija].brojtelefona = brojtelefona;
			upisivanjeUfajl(nizCovjek, brojac);
			cout << "\nImenik je izmjenjen !!!";
	}
}

void ispisImenika(struct Covjek *nizCovjek, int brojac){
	int i = 0;
	ifstream fajl("imenik.txt");
	string line;
	if (fajl.is_open())
	{
		while (getline(fajl, line))
		{
			brojac++;
		}
		fajl.close();
	}
	else cout << "Ne mogu da otvorim, fajl";
	//ovde kreiramo niz ljudi koliko smo ih izbrojali u fajlu
	nizCovjek = new Covjek[brojac];
	fajl.open("imenik.txt");
	if (fajl.is_open())
	{
		while (getline(fajl, line))
		{
			istringstream buf(line);
			istream_iterator<string> beg(buf), end;
			vector<string> tokens(beg, end);
			nizCovjek[i].ime = tokens[0];
			nizCovjek[i].prezime = tokens[1];
			nizCovjek[i].brojtelefona = tokens[2];
			nizCovjek[i].mail = tokens[3];
			i++;
		}
		fajl.close();
		for (int i = 0; i < brojac; i++){
			cout << nizCovjek[i].ime << " " << nizCovjek[i].prezime << " " << nizCovjek[i].brojtelefona << " " << nizCovjek[i].mail << "\n";
		}
	}
}

void dodavanjeUImenika(){
	ofstream fajl("Imenik.txt", ios::app); // dodavanje na kraj fajla
	string ime;
	string prezime;
	string brojtelefona;
	string mail;
	cout << "ukucajte ime" << "\n";
	cin >> ime;
	cout << "ukucajte prezime" << "\n";
	cin >> prezime;
	cout << "\nukucajte broj telefona\n" << "\n";
	cin >> brojtelefona;
	cout << "ukucajte mail\n";
	cin >> mail;
	fajl << ime << " " << prezime << " " << brojtelefona << " " << mail << endl;
	cout << "upisano u fajl";
	fajl.close();
}

int main() {
	int izbor = 0;
	Covjek * nizCovjek = NULL;
	ifstream fajl("imenik.txt");
	int brojac = 0;
	int i = 0;
	string line;
	if (fajl.is_open())
	{
		while (getline(fajl, line))
		{
		//	cout << line << '\n';
			brojac++;
		}
		fajl.close();
	} else cout << "Ne mogu da otvorim, fajl";
	//ovde kreiramo niz od ljudi koliko smo ih izbrojali u fajlu
	nizCovjek = new Covjek[brojac];
	fajl.open("imenik.txt");
	if (fajl.is_open())
	{
		while (getline(fajl, line))
		{
			istringstream buf(line);
			istream_iterator<string> beg(buf), end;
			vector<string> tokens(beg, end);
			nizCovjek[i].ime = tokens[0];
			nizCovjek[i].prezime = tokens[1];
			nizCovjek[i].brojtelefona = tokens[2];
			nizCovjek[i].mail = tokens[3];
			i++;
		}
		fajl.close();
		while (izbor != -1){
			cout << "\n\nDobrodosli u meni\n 1. Pretrazivanje imenika\n 2.Izmjena imenika\n 3.Ispis Imenika\n 4. Dodavanje u imenik\n 5.Exit Izlaz iz programa\n UKUCAJTE IZBOR\n";
			cin >> izbor;
			switch (izbor)
			{
			case 1: pretragaImenika(nizCovjek, brojac); break;
			case 2: izmjenaImenika(nizCovjek, brojac); break;
			case 3: ispisImenika(nizCovjek, brojac); break;
			case 4: dodavanjeUImenika(); break;
			case 5:  izbor = -1; break;
			default:
				break;
			}
		}
	}
	else cout << "Ne mogu da otvorim, fajl";
}
