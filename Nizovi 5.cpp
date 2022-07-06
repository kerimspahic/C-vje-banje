#include <iostream>
#include <iomanip>
using namespace std;


int main(){
	
	const int velicinaNiza = 12;
	int suma = 0, niz[velicinaNiza];
	
	for(int i=0; i<velicinaNiza; i++){
	cout<<"Unesi "<<i<<" clan niza: ";
	cin>>niz[i];
	if (niz[i]%2 != 0){
		suma+=niz[i];
		}
	}
	cout<<"Suma neparnih brojeva niza je: "<<suma;
	
	system("pause>0");
	return 0;
	
	
}
