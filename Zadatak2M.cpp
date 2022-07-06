#include <iostream>

using namespace std;

/*
Napraviti program koji ce unijeti tekst ispisat naopacke 
Sve dok se ne unese tacka
*/

	char rekurzijaTekst();
	
int main (){

	cout<<"Unesi neki tekst: ";
	
	rekurzijaTekst();

return 0;
}


	char rekurzijaTekst(){
		char tekst;
		cin>>tekst;	
		if(tekst !='.'){
			rekurzijaTekst();		
			cout<<tekst;
		}
		else{
			cout<<"Obrnuto:"<<endl;
		}

	}
