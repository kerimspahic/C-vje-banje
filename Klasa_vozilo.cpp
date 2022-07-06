#include <iostream>
#include <stdlib.h>
using namespace std;
class vozilo
{
 private:
 	string namjena;
 protected:
 	int broj_tockova;
 	int broj_sjedista;
 public:
 	vozilo (string N = "", int bt = 0, int bs = 0)
 	{
 	cout << "pozvan konstruktor iz osnovne klase" << endl;
 	namjena = N; broj_tockova = bt; broj_sjedista = bs;
 	}
 	void unesi_vozilo()
 	{
 	cout << "metoda iz osnovne klase" << endl;
 	cout << "Unesi namjenu vozila" << endl;
 	cin >> namjena;
 	cout << "Unesi koliko tockova ima vozilo" << endl;
 	cin >> broj_tockova;
 	cout << "Unesi koliko sjedista ima vozilo" << endl;
 	cin >> broj_sjedista;
 	}
 	void prikazi_vozilo () const
 	{
 	cout << "metoda iz osnovne klase" << endl;
 	cout << "namjena vozila: " << namjena << endl;
 	cout << "broj tockova: " << broj_tockova << endl;
 	cout << "broj sjedista: " << broj_sjedista << endl;
 	}
}; 
class putnicko_vozilo: public vozilo
	{
 private:
 	string karoserija;
 public:
 	putnicko_vozilo(string N = "", int bt = 0, int bs = 0, string k = ""):
 	vozilo (N,bt,bs), karoserija(k) {cout << "pozvan konstruktor iz izvedene klase" << endl;}
 	void unesi_putnicko_vozilo()
 	{
 	cout << "metoda iz izvedene klase" << endl;
 	unesi_vozilo();
 	cout << "unesi koji je tip karoserije: " << endl;
 	cin >> karoserija;
 	}
 	void prikazi_putnicko_vozilo() const // ????? ??????
 	{
 	cout << "metoda iz izvedene klase" << endl;
 	cout << "karoserija: " << karoserija << endl;
 	prikazi_vozilo();
 	}
};

int main()
{
 	vozilo X, A("teretno", 8, 2);
 	putnicko_vozilo Y, B("putnicko", 4, 2, "kupe");
 	cout << endl;
 	cout << "vozilo A (osnovna klasa)" << endl;
 	A.prikazi_vozilo();
 	cout << endl;
 	cout << "vozilo B (izvedena klasa)" << endl;
 	B.prikazi_putnicko_vozilo();
 	cout << endl;
 	X.unesi_vozilo();
 	cout << endl;
 	cout << "vozilo X (osnovna klasa)" << endl;
 	X.prikazi_vozilo();
 	cout << endl;
 	Y.unesi_putnicko_vozilo();
 	cout << endl;
 	cout << "vozilo Y (izvedena klasa" << endl;
 	Y.prikazi_putnicko_vozilo();
system("PAUSE");
 return 0;
}

