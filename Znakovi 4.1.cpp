#include <iostream>
using namespace std;

int main() {
	
	const int MaxBrojZnakova(1000);
	char znak, recenica[MaxBrojZnakova];
	int broj_znakova(0);
	
	cout << "Unesi recenicu: ";
	
	while((znak = cin.get()) != '\n' &&	broj_znakova < MaxBrojZnakova)
		recenica[broj_znakova++] = znak;
		
	cout << "Recenica izgovorena naopako glasi: ";
	for(int i = broj_znakova - 1; i >= 0; i--)
		cout << recenica[i];
		
	return 0;
}
