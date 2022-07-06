#include <iostream> 
#include <cstring> 
using namespace std; 
int main(){ 
int broj_rec; 
cout << "Unesite broj recenica: "; 
cin >> broj_rec; 
cin.ignore(10000, '\n'); 
char **recenice = new char*[broj_rec]; 
for(int i=0; i<broj_rec; i++) { 
char pom[1000]; 
cout << i+1 << ": "; 
cin.getline(pom, 1000); 
 		// Definisanje niza na niz (matrica, i to grbava) 
recenice[i] = new char[strlen(pom) + 1]; 
strcpy(recenice[i], pom); } 
string pom1, pom2; 
for (int i=0;i<broj_rec-1;i++) 
	for (int j=i+1;j<broj_rec;j++){ 
		pom1=recenice[i]; 
		pom2=recenice[j];     
		if (pom1>pom2){ 
			char pomocna[1000]; 
			strcpy(pomocna, recenice[i]); 
			strcpy(recenice[i], recenice[j]); 
			strcpy(recenice[j], pomocna); }
			} 
cout << endl << "Sortirano: " << endl; 
for(int k = 0; k < broj_rec; k++) 
	cout << k+1 << ": " << recenice[k] << endl; 
getchar(); 
return 0; 
} 
