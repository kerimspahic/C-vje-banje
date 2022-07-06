/*#pragma once
#include <string.h> 
#include <stdlib.h> 
#include <time.h>
class Slagalica { 
						/* Rijec koja se trazi */ 
//	char * tajnaRijec; 
						/* Rijec koja se ispisuje korisniku */ 
//	char * trenutnaRijec; 
						/* Duzina date rijeci */ 
//	int duzinaRijeci; 
						/* Trenutni broj pokusaja */ 
//	int brojPokusaja;
						/* Inicjalizacija vrijednosti */ 
//	void init(char * rijec); 
						/* Permutovanje karaktera date rijeci */ 
//	void permutuj(void); 
//public: 
			/* Konstruktori */ 
//	Slagalica(void); 
//	Slagalica(char * rijec); 
			/* Destruktor */ 
//	~Slagalica(void);
			/* Komande */ 
//	void zamjeni(int i, int j); 
//	void rotiraj(int i, int j);
			/* Pomocni metodi */ 
//	void ponistiBrojPokusaja(void); 
//	int getBrojPokusaja(void);
//	void postaviRijec(char * rijec); 
//	int provjeri();
			/* Vraca trenutnu rijec */ 
//	char * rijec(); 
			/* Vraca tajnu rijec */ 
//	char * Rijec();
//};
			//Slagalica.cpp 
#include "Slagalica.h"
Slagalica::Slagalica(void) { 
	tajnaRijec = NULL; 
	trenutnaRijec = NULL; 
	duzinaRijeci = 0; 
	brojPokusaja = 0; 
}
Slagalica::~Slagalica(void) { 
	if(tajnaRijec != NULL) 
		delete[] tajnaRijec; 
	if(trenutnaRijec != NULL) 
		delete[] trenutnaRijec;
}
Slagalica::Slagalica(char * rijec){ 
	tajnaRijec = NULL; 
	trenutnaRijec = NULL; 
	duzinaRijeci = 0; 
	brojPokusaja = 0;
	init(rijec); 
}
void Slagalica::permutuj(){ 
	if(duzinaRijeci == 0) 
		return; 
	if(trenutnaRijec != NULL) 
		delete[] trenutnaRijec; 
	trenutnaRijec = new char[duzinaRijeci + 1]; 
	strcpy(trenutnaRijec, tajnaRijec);
	srand((unsigned int)time(0)); 
	for(int i = 0; i < duzinaRijeci; i++){ 
		int j = rand() % (duzinaRijeci - i) + i; 
		if(i != j){ 
			char pom = trenutnaRijec[i]; 
			trenutnaRijec[i] = trenutnaRijec[j]; 
			trenutnaRijec[j] = pom; 
			} 
	} 
} 
void Slagalica::zamjeni(int i, int j){ 
	if((i < 0) || (j < 0) || (i >= duzinaRijeci) || (j >= duzinaRijeci)) 
		return; 
	char pom = trenutnaRijec[i]; 
	trenutnaRijec[i] = trenutnaRijec[j]; 
	trenutnaRijec[j] = pom;
	brojPokusaja++; 
}
void Slagalica::rotiraj(int i, int j){ 
	if((i < 0) || (j < 0) || (i >= duzinaRijeci) || (j >= duzinaRijeci)) 
		return; 
	int k; 
	char pom;
	if(i < j){ 
			/* Pomjeranje u desno */ 
		pom = trenutnaRijec[j]; 
		for(k = j - 1; k >= i; k--) 
			trenutnaRijec[k + 1] = trenutnaRijec[k]; 
		trenutnaRijec[i] = pom; 
		} 
	else{ 
			/* Pomjeranje u lijevo */ 
		pom = trenutnaRijec[j]; 
		for(k = j; k < i; k++) 
			trenutnaRijec[k] = trenutnaRijec[k + 1]; 
		trenutnaRijec[i] = pom; 
		} 
	brojPokusaja++; 
}
void Slagalica::ponistiBrojPokusaja(void) { 
	brojPokusaja = 0; 
}
int Slagalica::getBrojPokusaja(void) { 
	return brojPokusaja;
}
void Slagalica::postaviRijec(char * rijec){ 
	init(rijec); 
}
void Slagalica::init(char * rijec){ 
	int n = strlen(rijec); 
	if(n == 0) return;
	tajnaRijec = new char[n + 1]; 
	strcpy(tajnaRijec, rijec);
	duzinaRijeci = n;
	permutuj(); 
}
char * Slagalica::rijec(){ 
	return trenutnaRijec; 
}
int Slagalica::provjeri(){ 
	int rez = strcmp(trenutnaRijec, tajnaRijec); 
	return rez == 0; 
}
char * Slagalica::Rijec(){ 
	return tajnaRijec; 
}
//main.cpp 
#include <iostream> 
#include "Slagalica.h"
using namespace std;
int main(){ 
	Slagalica * s; 
	s = new Slagalica("Kombinatorika");
	char komanda[10]; 
	int i, j; 
	cout<<"Komande: "<< i<< j<<" - zamjenjuje i-ti i j-ti karakter "<< i<< j<<" \n- rotira karaktere od i do j u desno ako je i < j, a inace u lijevo\n\n";
	do{ 
		cout<<"Trenutna rijec: "<<s->rijec(); 
		cout<<"\nUnesi komandu...\n"; 
		cin>>komanda>>i>>j; 
		if(komanda[0] == 'z') 
			s->zamjeni(i, j); 
		if(komanda[0] == 'r') 
			s->rotiraj(i, j); 
		} while((!s->provjeri()) && (s->getBrojPokusaja() < 10));
	if(s->provjeri()) 
		cout<<"Cestitam, pogodili ste tajnu rijec: "<<s->rijec(); 
	else 
		cout<<"Zao mi je. Trazena rijec je "<<s->Rijec();
delete s; 
return 0; 
}

