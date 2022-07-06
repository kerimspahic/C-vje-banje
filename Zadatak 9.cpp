/*
U datoteci ulaz.txt nalazi se broj elemenata niza. Procitati taj broj, alocirati niz 
te dužine i unjeti vrijednosti elemenata tog niza. Izracunati prosjecnu vrijednost,
proširiti niz za jedno mjesto i ubaciti prosjek u niz. U novu datoteku Izlaz.txt 
upisati sortiran dati niz
*/

#include <bits/stdc++.h>
using namespace std;

int main () {
	
	ifstream datoteka("ulaz.txt");
	
	if (datoteka.is_open()){
		
		int velicina;
		
		datoteka>>velicina;
		
		if (velicina<1){
			cout<<"Velicina ne moze biti manja od 1.";
			return 0;
		}
		cout<<"Niz je velicine: "<<velicina<<endl;
		
		float ukupno = 0;
		float* niz = new float [velicina];
		
		for(int i = 0; i < velicina; i++ ){
			cout<<"\nUnesite "<<i+1<<" broj: ";
			cin>>niz[i];
			ukupno+=niz[i];
		}
		velicina+=1;
		
		float* noviNiz = new float[velicina];

		for (int i = 0; i < velicina - 1; i++)
		{
			noviNiz[i] = niz[i];
		}
		delete[] niz;
		
		noviNiz[velicina - 1] = ukupno / velicina;
		
		ofstream file("Izlaz.txt");
		
		for (int i = 0; i < velicina; i++){
			file << noviNiz[i] << " ";
		}
		file.close();
	}
	else{
		cout<<"\nNema ulaz.txt datoteke!\n";
	}
	
	
}
