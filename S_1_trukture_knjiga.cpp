#include<iostream>>

using namespace std;
struct Knjiga 	{
	string imeKnjiga;
	string imeAutor;
	int brojStranica;
	string datumIzdavanja;
	};
int main()
{
Knjiga prva;
prva.imeKnjiga = "C++ Primjer Plus (5th Edition)";
prva.imeAutor = "Stephen Prata";
prva.brojStranica = 1224;
prva.datumIzdavanja = "25.11.2004";
Knjiga druga;
druga.imeKnjiga = "C++ Primjer Plus (6th Edition)";
druga.imeAutor = "Stephen Prata";
druga.brojStranica = 1200;
druga.datumIzdavanja = "28.10.2011";
//C++ Primjer Plus (5th Edition) - Stephen Prata
cout << prva.imeKnjiga << " - " << prva.imeAutor << endl;
//C++ Primjer Plus (6th Edition) - Stephen Prata
cout << druga.imeKnjiga << " - " << druga.imeAutor << endl;
//clanovi strukture ponasaju se kao obicne promjenjive
//nad svakom od njih mogu se izvrsiti bilo koje operacije
cout << prva.imeKnjiga << " ima " << (prva.brojStranica - druga.brojStranica)
<< " vise stranica od " << druga.imeKnjiga << endl;
//C++ Primjer Plus (5th Edition) ima 24 vise …
//stranica
{
system("PAUSE");
return 0;
}
}

