#include <iostream>
using namespace std;

struct datum { // struktura sa datumom mjesecom i godinom
	int dan,mjesec,godina;
};

struct datum funkDatum (char *jmbg); //prototip stringa

int main() {
	
	struct datum datumRodjenja;	//deklaracija strukture i prima vrijednosti iz datum
	char jmbg[13]; //deklaracija char variable u kojoj unosimo maticni broj
	
	cout << "Unesi maticni broj: " << endl; //ispis
	cin >> jmbg; //unos jmbg
	
	datumRodjenja = funkDatum(jmbg); //datumRodjenjaf prima vrijednosti funkDatum
	
	cout << "Datum rodjenja: " << datumRodjenja.dan << "." << datumRodjenja.mjesec << "." << datumRodjenja.godina << endl; //ispis datuma rodenja
	
	return 0;
}

struct datum funkDatum (char *jmbg) {
	
	struct datum datumRodjenja; //deklaracija strukture  
	struct datum *dodatn; //deklaracija strukture dodatne koju cemo koristit u return

	datumRodjenja.dan=0; //da se danu i mjesecu ne dodjeljuje 0 ne bi se mogli unosti brojevi od 1-9 za mjesec i dan
	datumRodjenja.mjesec=0;
	
	if (*(jmbg+4) == 48){ //pomocu ASCII vrijednosti broja 0 gledamo 5 broj jmbg-a i pomocu njega mozemo vidjet koji je milenijum
		datumRodjenja.godina = 2000;
	}
	else{
     datumRodjenja.godina=1000;
	}
	
	for (int i=0; i<10; i++) //gleda prvi broj jmbg-a i on je zaduzen za desetice dana
		if (*jmbg==49+i)
			datumRodjenja.dan=10*(1+i);
			
	for (int i=0; i<10; i++)  //gleda drugi broj jmbg-a i on je zaduzen za jedinice dana
		if (*(jmbg+1)==49+i)
			datumRodjenja.dan+=(1+i);
			
	for (int i=0; i<10; i++)  //gleda treci broj jmbg-a i on je zaduzen za desetice mjeseca
		if (*(jmbg+2)==49+i)
			datumRodjenja.mjesec=10*(1+i);
			
	for (int i=0; i<10; i++)  //gleda cetvrti broj jmbg-a i on je zaduzen za jedinice mjeseca
		if (*(jmbg+3)==49+i)
			datumRodjenja.mjesec+=(1+i);
			
	for (int i=0; i<10; i++)  //gleda peti broj jmbg-a i on je zaduzen za stotine godine
		if (*(jmbg+4)==49+i)
			datumRodjenja.godina+=100*(1+i);
			
	for (int i=0; i<10; i++)  //gleda sesti broj jmbg-a i on je zaduzen za desetice godine
		if (*(jmbg+5)==49+i)
			datumRodjenja.godina+=10*(1+i);
			
	for (int i=0; i<10; i++)  //gleda sedmi broj jmbg-a i on je zaduzen za jedinice godine
		if (*(jmbg+6)==49+i)
			datumRodjenja.godina+=(1+i);
			
	dodatn=&datumRodjenja;  //dodatn dobija adresne vrijednosti datumRodjenja
	return *dodatn; 
}
