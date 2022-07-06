#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stdio.h>
using namespace std;

struct firma{
	string imeFirme;
	double osnovniKoef;
	double ukupniProcenatPoreza;
	int brojRadnika;
	};

struct radnik{
	string ime;
	string prezime;
	string pozicija;
	int id;
	double osnovicaPlate;
	int staz;
};


int kreiranjeDatoteke ();
void unesi();

//main funkcija
int main(){
	firma firma1;

	int izbor=0;
	
	ifstream datoteka("obracun.txt");
	
	if (datoteka.is_open() ==0){
	cout<<"Datoteka nije kreirana ili je pod drugim imenom."<<endl;	
	kreiranjeDatoteke ();
	unesi ();	
	
	}

	
}

int kreiranjeDatoteke (){
	
		cout<<"Da li bi zeljeli kreirati datoteku (Y/N): ";
		char provjera;
		cin>>provjera;
		if (provjera =='Y'){
			ofstream datoteka("obracun.txt");
			system ("cls");
			cout<<"Datoteka je kreirana!"<<endl;
			cout<<"Za novu datoteku treba unijeti podatke firme i njenih uposlenika:"<<endl;
		
			return 0;	
		}
		else if (provjera =='N'){
				cout<<"Dovidenja!"<<endl;
				system ("pause");
				return 0;
			}
			system ("cls");
			cout<<"Uneseni simbol ne odgovara ponudenim odgovorima."<<endl;
	
			kreiranjeDatoteke ();
		}
		
void unesi(){
	
	
	ofstream datoteka("obracun.txt", ios::app);
	
	string imeFirme;
	double osnovniKoef;
	double ukupniProcenatPoreza;
	int brojRadnika;
	
	cout<<endl<<"Unesite ime firme: ";
	cin>>imeFirme;
	cout<<"Unesite osnovni koef. firme: ";
	cin>>osnovniKoef;
	cout<<"Unesite ukupan procenat poreza: ";
	cin>>ukupniProcenatPoreza;
	cout<<"Unesite broj radnika:";
	cin>>brojRadnika;
	
	datoteka<<imeFirme<<"  "<<osnovniKoef<<"  "<<ukupniProcenatPoreza<<"  "<<brojRadnika<<endl<<endl;
	cout << "Upisano u datoteku\n";
	
	for (int i=0; i<brojRadnika; i++){
		
		string ime;
		string prezime;
		string pozicija;
		int id;
		double osnovicaPlate;
		int staz;
		
		cout<<endl<<"Unesite ime "<< i+1 << ". radnika: ";
		cin>>ime;
		cout<<"Unesite prezime " << i+1 <<  ". radnika: ";
		cin>>prezime;
		cout<<"Unesite poziciju " << i+1 <<  ". radnika: ";
		cin>>pozicija;
		cout<<"Unesite id " << i+1 <<  ". radnika: ";
		cin>>id;
		cout<<"Unesite osnovicu  plate " << i+1 <<  ". radnika: ";
		cin>>osnovicaPlate;
		cout<<"Unesite staz " << i+1 <<  ". radnika (godine): ";
		cin>>staz;
		datoteka<<ime<<"  "<<prezime<<"  "<<pozicija<<"  "<<id<<"  "<<osnovicaPlate<<"  "<<staz<<endl;
		cout << "\t\nUpisano u datoteku\n";	
	}
	datoteka.close();	
}



