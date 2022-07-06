#include <iostream> 
#include <conio.h> 
#include <stdlib.h> 
using namespace std;
class 
	stek{ 
private: 
	static int ukupno; 
	static stek *vrh; 
	int broj; 
	stek *prethodni; 
public: 
	static void stavi_na_stek(int); 
	static int uzmi_sa_steka(); 
	static int prazan(){return vrh==0;} 
	static int imaih(){return ukupno;} 
	};
int stek::ukupno=0;
stek* stek::vrh=0;
void stek::stavi_na_stek(int i){ 
	stek *pom=new stek; 
	pom->prethodni=vrh; 
	pom->broj=i; 
	vrh=pom; 
	ukupno=ukupno+1; } 
int stek::uzmi_sa_steka(){ 
	if(!vrh) exit(1); 
	stek *pom; 
	pom=vrh; 
	int i=vrh->broj; 
	vrh=pom->prethodni; 
	delete pom; 
	pom=0; 
	ukupno=ukupno-1; 
	return i; }
int main(){ 
	int n; 
	cout<<"Koliko brojeva zelite da ima stek?\n"; 
	cin>>n; 
	int m; 
	cout<<"Unesite podatke koje zelite da postavite na stek"<<endl; 
	for(int i=0; i<n;i++){
		cin>>m; 
		stek::stavi_na_stek(m);} 
	cout<<"Koliko brojeva zelite da uzmete sa steka?"<<'\n'; 
	cin>>n; 
	cout<<"Uzeli ste brojeve: "; 
	for(int i=0;i<n;i++) 
		cout<<stek::uzmi_sa_steka()<<" "; 
	cout<<endl; 
	cout<<"Koliko brojeva zelite da postavite na stek?"<<'\n'; 
	cin>>n; 
	cout<<"Unesite podatke koje zelite da postavite na stek"<<endl; 
	for(int i=0;i<n;i++) {
		cin>>m; 
		stek::stavi_na_stek(m);} 
	cout<<"Ukupno je"<<stek::imaih()<<endl; 
	cout<<"Na steku su brojevi od vrha ka pocetku"; 
	while(!stek::prazan()) 
		cout<<stek::uzmi_sa_steka()<<" "; 
}

