#include <iostream>
#include <iomanip>
using namespace std;


int main(){
	
	const int velicinaNiza = 10;
	int suma = 0, niz[velicinaNiza];
	
	for(int i=0; i<velicinaNiza; i++){
	cout<<"Unesi "<<i<<" clan niza: ";
	cin>>niz[i];
	suma+=niz[i];
	}
	cout<<"Suma niza je: "<<suma;
	
	system("pause>0");
	return 0;
	
	
}
