#include <iostream>
using namespace std;

int main (){
	int niz[10];
	for (int i=0; i<10; i++){
		cout<<"Unesi "<<i+1<<". broj:";
		cin>>niz[i];
	}
	cout<<endl;
		for (int i=0; i<10; i++){
		cout<<i+1<<". broj je:"<<niz[i]<<endl;
	}
	return 0;
}
