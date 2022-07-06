//Unijeti broj studenata, te podatke o studentima: ime, prezime, godina, prosjek
//Ispisati studenta sa najveæim prosjekom.
#include <iostream>
#include <fstream>
using namespace std;
 
struct Student {
	char ime[15], prezime[15];
	int godina;
	float prosjek;
	};

int main() {
	int n;
	cout << "Unesi broj studenata ";
	cin >> n;
Student studenti[n];
	for (int i = 0; i < n; i++) {
		cout << "Unesi ime " << i + 1 << " studenta:";
		cin >> studenti[i].ime;
		cout << "Unesi prezime " << i + 1 << " studenta:";
		cin >> studenti[i].prezime;
		cout << "Unesi godine " << i + 1 << " studenta:";
		cin >> studenti[i].godina;
		cout << "Unesi prosjek " << i + 1 << " studenta:";
		cin >> studenti[i].prosjek;
	}
int maxIndex = 0;
float max = 0;
	for (int i = 0; i < n; i++) {
		if (studenti[i].prosjek > max) {
			max = studenti[i].prosjek;
			maxIndex = i;
		}
	cout << endl;
	}
cout << "Student sa najvecim prosjekom je: " << endl;
cout << studenti[maxIndex].ime << " " << studenti[maxIndex].prezime << " "
<< studenti[maxIndex].godina << " " << studenti[maxIndex].prosjek
<< endl;
system("pause");
return 0;
}

