#include<iostream> 
using namespace std; 
 
class stud  {     
public:     
	char ime[30], klasa[10];     
	int bput, godine; 
    void unesi()      {          
		cout<<"Unesi ime studenta: ";         
		cin>>ime;                               
		cout<<"Unesi godine studenta: ";         
		cin>>godine;                                   
		cout<<"Unesi broj ponavljanja studenta: ";         
		cin>>bput;                                   
		cout<<"Unesi klasu studenta: ";         
		cin>>klasa;            }          
	void ispis()      {         
		cout<<"\nGodine\tIme\tR.No.\tKlasa";         
		cout<<"\n"<<godine<<"\t"<<ime<<"\t"<<bput<<"\t"<<klasa;      } 
}; 

int main() {     
	class stud s;     
	s.unesi();     
	s.ispis();     
	cin.get();   
} 
