#include <iostream> 
#include <iomanip> 
using namespace std; 
 
 
 
int main () { 
	int const velicina_niza =5; 
	int niz[velicina_niza]={0,1,2,3,4}, i; 
	 
	cout<<"Vrijednosti orginalnog niza: "; 
	 
	for (i =0; i<velicina_niza; i++) 
		cout<<setw(3)<<niz[i]; 
	  
	for(int j=0; j<velicina_niza;j++)  	 	
	niz[j]*=2;
	 
	cout<<endl<<"Vrijednosti modificiranog niza:  "; 
	 
	for(i =0; i<velicina_niza; i++)
	cout<<setw(3)<<niz [i]; cout<<endl; system("pause>null"); 
	return 0; 
} 

