#include <iostream>
#include<iomanip>
using namespace std;

struct osoba{ //struktura za identigikaciju osobe
	char ime[20];
	char prezime[20];
	int godine;
	//ova struktura ima 3 clana ime,prezime i godine (razlicite variable)
};

int main (){

	osoba ifeta ={ //imenujemo promjenjivu (ifeta) i dodjeljuje vrijednosti onako kako su deklarisane u strukturi (ime, prezime i na kraju godine) 
	"Ifeta","Rizlic"
	};
	ifeta.godine=25; //jos jena vrsta dodjeljivanja vrijednosti strukture u kojoj tacno navodima sta cemo cemu dodijeliti
	cout<<ifeta.ime<<"  "<<ifeta.prezime<<"  "<<ifeta.godine<<endl; //ispis koji se vrsi tako sto se naglasi koju promjenivu hocemo koristiti i nakon toga pisemo koju cemo variablu koristit sa tackom izmedu njih

	cout<<"Ifeta se udala i hoce promjecit precime: "; 
	cin>>ifeta.prezime; //mjenjamo vrijednost neke variable u strukturi

	cout<<"Sad se zove: "<<ifeta.ime<<"  "<<ifeta.prezime<<endl;
return 0;
}

