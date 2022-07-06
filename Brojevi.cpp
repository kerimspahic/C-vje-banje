#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	ifstream datoteka("BROJEVI.dat");

	if (datoteka.is_open()) {

		cout << "Dobar\n";

		vector <double> brojevi;

		double unos;
		while (datoteka >> unos) {
			brojevi.push_back(unos);
		}

		for (double broj : brojevi) {
			cout << broj << "  ";
		}

		for (auto i = brojevi.begin(); i != brojevi.end(); ++i){
			if (*i < 0) {
				*i = 0;
			}
		}
		cout << endl << endl;
		for (double broj : brojevi) {
			cout << broj << "  ";
		}
		cout << endl;
		
		

		ofstream nova("POZITIVNI.txt");

		for (double broj : brojevi) {
			if (broj > 0){
				nova << broj << "  ";
			}
		}
		nova.close();
		datoteka.close();

		ofstream datoteka("BROJEVI.dat");

		for (double broj : brojevi) {
			datoteka << broj << " ";
		}
	}
	else {
		cout << "Datoteka ne postoji!\n";
	}
	system("pause");
	return 0;




}