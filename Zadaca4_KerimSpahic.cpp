#include <iostream>
#include <string>
#include <vector>

using namespace std;

main(){
	
vector<string> a; //deklaracija vektora a tipa string
int broj;  //deklaracija broja tipa int

cout << "Unesi broj rijeci: "; //ispis
cin >> broj; //unos broja
for (int i=0; i<broj; i++){ //for petlja unosi rijeci a broj unesenih rijeci je odrecen pomocu variable broj koju smo prije unijeli
	cout << i+1 << ". ";
	string pom; 
	cin >> pom;
	a.push_back(pom); 
   }
string pom; // deklaracija pomocnog stringa
for (int i=0;i<(a.size()-1);i++) //ove dvije for petlje sa if uslovom su zatuzene za sortiranje unesenih recenica po velicini pomocu ascii tabele
	for (int j=i+1;j<a.size();j++) 
		if (a[j]<a[i]){
		   	pom=a[i];
			a[i]=a[j];
		   	a[j]=pom;   
			}
cout << "Prva rijec je: " << a[0] << " a zadnja " << a[a.size()-1] << endl; //ispis
cout << endl << "Ispis rijeci: " << endl; //ispis
a.push_back(""); //pridruzujemo vektoru a unesene rijeci

for (int i=0, j=0; i<a.size()-1; i++){ //for petlja sa if uslovom je zaduzena da pronalazi iste rijeci i ako ih ima da ih ne ispisuje vise od jednom
	if ((a[i]!=a[i+1])) { 
		cout << j+1 << ". " << a[i] << endl; j++; 
		} 
	}

return 0; 
}


