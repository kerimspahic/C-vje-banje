#include <iostream>
#include <fstream>
using namespace std;

	struct Apartman {
		string naziv;
		string mjesto;
		int brKreveta;
		int cijena;
	};

	
	
int main (){
	
	Apartman * nizApartman = NULL;
	
	ifstream datoteka("apartmani.txt");
	if (datoteka.is_open()){
	

	string linija;
	int brApartman=0;
	
	while (getline(datoteka, linija)){
		brApartman++;
	}	
	datoteka.close();

	nizApartman = new Apartman[brApartman];	
	
	datoteka.open("apartmani.txt");
	
	

	for (int i = 0; i < brApartman; i++){
		datoteka >>nizApartman[i].naziv >>nizApartman[i].mjesto >>nizApartman[i].brKreveta >>nizApartman[i].cijena;
		
	}
	cout<<"Ukupan broj apartmana je: "<<brApartman<<endl<<endl;
		
		int ukupanBrApartmana=0;
		for (int i = 0; i < brApartman; i++){
			ukupanBrApartmana+=nizApartman[i].brKreveta;
		}
		
		int prosjecnaCjena=0;
		for (int i = 0; i < brApartman; i++){
			prosjecnaCjena+=nizApartman[i].cijena;
		}
		cout<<"Prosjecna cjena apartmana je: "<<prosjecnaCjena/brApartman<<endl<<endl;
		

	}
	
	
	return 0;
}
