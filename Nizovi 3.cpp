#include <iostream>
#include <iomanip>
using namespace std;


int main(){
	
	const int velicinaNiza = 10;
	int parnNiz [velicinaNiza];
	
	for (int i=0; i<velicinaNiza; i++){
		parnNiz[i] = i*2+2;
	}
	
	cout<<"Element"<<setw(13)<<"Vrijednost"<<endl;
	
	for (int i=0; i<velicinaNiza; i++){
		cout<<setw(7)<<i<< setw(13)<<parnNiz[i]<<endl; 
	}
	system("pause>0");
	return 0;
	
	
}
