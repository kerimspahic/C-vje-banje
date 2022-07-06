/*
	Napisati program koji za uneseni tekst
	prebroji koliko ima rijeci.
	
	Potrebna nam je varijabla string tekst,
	u koju cemo unositi nas tekst.
	
	potrebna nam je duzina tog teksta,
	koju pozivamo tekst.lenght();
	
	funkcija getline(cin,tekst); sprema u varijablu
	tekst, sve ono što se unese sa tastature
	Za rasliku od cin, koji ce spremiti samo prvu rijec
*/
#include <iostream>
using namespace std;

int main(){
	string tekst;
	cout<<"Unesi svoj tekst:"<<endl;
	getline(cin,tekst);
	
	int brojRijeci = 1,brRazmaka = 0;
	
	for(int i = 0; i < tekst.length();i++){
		if(tekst[i] == ' ' && tekst[i+1]!=' '){
			brojRijeci++;
		}
		
		if(tekst[i]==' '){
			brRazmaka++;
		}
	}
	
	cout<<"Uneseni tekst ima "<<brojRijeci<<" rijeci"<<endl;
	cout<<"i taj tekst ima "<<tekst.length()-brRazmaka<<" slova"<<endl;

	return 0;
}
