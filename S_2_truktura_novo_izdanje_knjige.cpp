//Napravi program koji izdaje informacije o najnovijem izdanju knjege?
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct autor
	{
	string ime;
	string prezime;
	};

struct knjiga
	{
	string ime;
	autor a;
	int godi;
	int brs;
	};

int main()
{
knjiga nova;
cout<<"Unesi informacije o novoj knjizi:"<<endl;
cout<<"Naslov:"; cin>>nova.ime;
cout<<""<<endl;
cout<<"Ime i prezime autora knjige: "; cin>>nova.a.ime>>nova.a.prezime;
cout<<"Godina izdavamja knjige:"; cin>>nova.godi;
cout<<""<<endl;
cout<<"Unesi broj stranica knjige:"; cin>>nova.brs;
cout<<""<<endl;
cout<<" Autor knjige "<<nova.ime<<" je "<<nova.a.prezime<<endl;
cout<<" Novo izdanje knjige izdato"<<nova.godi<< " ima "<<nova.brs<<" stranica"<<endl;
system("PAUSE");
return EXIT_SUCCESS;
}

