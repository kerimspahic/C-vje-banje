#include <iostream>
#include <cstring>
using namespace std;

int main (){
	
	int broj; //deklaracija broj
	cout << "Unesite broj recenica: "; //ispis
	cin >> broj; //unos var vroj
	cin.ignore(100000, '\n'); //ignorise nepotrebne simbole  nizu
	char **recenice = new char* [broj], pom[10000]; //deklaracija dvostrukog pokazivaca i pomocne var pom
	
	for (int i=0; i<broj; i++){ //petlja je zaduzena za unosenje recenica
		cout <<i+1<<": "; //ispisuje redni broj recenice
		cin.getline(pom, 10000); //unos recenice pomocu pom variable
		
		recenice[i]=new char [strlen(pom)+1]; //deklaracija niza na niz pomocu pokazivaca
		strcpy (recenice[i], pom); //svaka unesena recenica se upisuje u recenice[i] (sa svakim unosom i se povecava za 1)
	}
	
	string pom1, pom2; //deklaracija pomocnih stringova
	
	for (int i = 0; i < broj; i++){	//inicijalizacija prvog brojaca sa i=0
		for (int j = i+1; j < broj; j++){ //inicijalizacija drugog brojaca sa j=i+1 
			
			pom1 = recenice[i]; //pom1 dobija vrijednost recenice[i]
			pom2 = recenice[j]; //pom2 dobija vrijednost recenice[j]
			
			if (pom2 < pom1) {// if uslov zaduzen za mjenjanje mjesta za dvije recenice ako recenica ako donja recenica ima manje abeceno slovo od gornje
				
				strcpy (pom, recenice[i]); 
				strcpy (recenice[i], recenice[j]); 
				strcpy (recenice [j], pom); 
			}
		}
	}
	
	cout <<"Sortirane recenice: "<<endl; //ispis
	
	for (int n = 0; n < broj; n++){ //petlja koja je zaduzena za ispisivanje sortiranog niza
		cout << n+1 << ":" << recenice[n] << endl;
	}

	
	return 0;
}
