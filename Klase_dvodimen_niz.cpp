#include <iostream>
#include <cstdlib>
using namespace std;
class matrica {
	/*Dualni pokazivaè na int (npr. adresa za niz nizova tipa int), za smiještanje 
	elemenata matrice.*/
 	int **elementi;
 	int redovi, kolone;
public:
		//Konstruktor sa dva parametra.
 	matrica(int redovi, int kolone);
 		//Destruktor (jer æe se kasnije koristiti dinamièka alokacija memorije).
	~matrica();
		//Metoda koja vraæa referencu na traženi element.
 	int &Elemenat(int red, int kolona);
		//Metoda koja ispunjava atribut elementi, ako joj se kao parametar zada 
		//jednodimenzionalni niz int-ova.
 	void IspuniNizom(int *niz);
		//Ispisuje matricu na ekranu.
 	void IspisiMe();
};

matrica::matrica(int redovi, int kolone)
{
		//Prvo se napravi dinamièki niz pokazivaèa na int...
	elementi = new int*[redovi];
		//pa se u njega smjeste adrese dinamièkih nizova, od kojih svaki 
		//predstavlja jedan red elemenata date matrice.
 	for(int i(0); i < redovi; i++)
 		elementi[i] = new int[kolone];
 		//Pošto su imena parametara ista kao i odreðeni atributi klase,
		//koristi se kljuèna rijeè this za pristup atributima klase.
	this->redovi = redovi;
 	this->kolone = kolone;
}

matrica::~matrica()
{
 	for(int i(0); i < redovi; i++)
 			//Prvo se brišu svi nizovi za redove elemenata...
		 delete[] elementi[i];
		 	//pa se izbriše niz koji je èuvao adrese tih redova.
 	delete[] elementi;
 			//Atribut elementi sada predstavlja nul-pokazivaè.
 	elementi = 0;
 			//Nema više redova i kolona.
 	redovi = kolone = 0;
}

int& matrica::Elemenat(int red, int kolona)
{				//Povratna vrijednost metode je referenca na varijablu tipa int.
 				//Prvo se provjerava validnost parametara...
	 if(red < 1 || red > redovi)
 		throw 				"\nGreska u broju redova!";
 	if(kolona < 1 || kolona > kolone)
 		throw 				"\nGreska u broju kolona!";
				//ako su parametri validni, vraæa se referenca na traženi elemenat matrice.
	return elementi[red-1][kolona-1];
}

void matrica::IspuniNizom(int *niz)
{			//Metoda kao parametar prima pokazivaè na int, tako da se
			//može navesti niz intova kao parametar.
 	int indeks(0);
 			//Redom se popunjavaju redovi matrice sa elementima navedenog niza. 
			//Brojaè indeks se poveæava svakim ciklusom petlje.
 	for(int red(0); red < redovi; red++)
 		for(int kol(0); kol < kolone; kol++)
 			elementi[red][kol] = niz[indeks++];
}

void matrica::IspisiMe()
{		//Metoda ispisuje redom elemente matrice. Širina svakog ispisa iznosi 5 znakova.
 	for(int r(0); r < redovi; r++) {
 		cout << endl;
 		for(int k(0); k < kolone; k++) {
 			cout.width(5);
 			cout << elementi[r][k];
 		}
 	}
cout << endl;
}

int main() {
 		// deklaracija dinamièki alocirane
 		// varijable tipa matrica
 	matrica *m = new matrica(3, 3);
 		// popunjavanje elemenata
 	int niz[] = { 3, 2, 12,
 				  1, 15, 6,
				  2, 8, 4 };
 	m->IspuniNizom(niz);
 	m->IspisiMe();
system("PAUSE");
return 0;
}
