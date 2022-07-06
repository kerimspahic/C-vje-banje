#include <iostream>
#define MAX 20
using namespace std;
struct datum { 
	int dan, mjesec, godina; 
	};

typedef struct osoba {
  char  prezime[16];
  char  ime[16];
  struct datum rodjen;
} OSOBA;

int main() {
  int n, i, j;
  OSOBA osobe[MAX], pom;
  do{ 
  	cout<<"Unesite n: "; cin>>n; 
	  } while (n < 1 || n > MAX);
  
  for (i = 0; i<n; i++){
    cout<<"Podaci o "<<i+1<<". osobi:\n"; 
	cout<<"Ime: "; cin>>osobe[i].ime;
    cout<<"Prezime: "; cin>>osobe[i].prezime;
    cout<<"Datum rodjenja: "; 
    cin>>osobe[i].rodjen.dan; cout<<" ";
	cin>>osobe[i].rodjen.mjesec; cout<<" ";
	cin>>osobe[i].rodjen.godina;
	}
  // sortiranje
  for (i = 0; i < n - 1; ++i)
    for (j = i + 1; j < n; ++j)
      if (osobe[i].rodjen.godina>osobe[j].rodjen.godina ||
        (osobe[i].rodjen.godina == osobe[j].rodjen.godina
          && osobe[i].rodjen.mjesec>osobe[j].rodjen.mjesec)
            || (osobe[i].rodjen.godina == osobe[j].rodjen.godina
              && osobe[i].rodjen.mjesec == osobe[j].rodjen.mjesec
                && osobe[i].rodjen.dan>osobe[j].rodjen.dan))
      	{
        pom = osobe[i];
        osobe[i] = osobe[j];
        osobe[j] = pom;
      	}
  cout<<"\nRB.  PREZIME         IME        RODJEN\n";
  cout<<"===  ============  ===============  ===========\n";
  for (i = 0; i<n; ++i)
    cout<<i + 1<<"   "<<osobe[i].prezime<<"\t\t"<<
      osobe[i].ime<<"\t\t"<<osobe[i].rodjen.dan<<"."<<osobe[i].rodjen.mjesec<<"."<<
        osobe[i].rodjen.godina<<"\n";
    cout<<"===  ============  ===============  ===========";
  return 0;
}
