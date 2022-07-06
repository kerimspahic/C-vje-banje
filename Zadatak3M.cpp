#include <iostream>

using namespace std;

char brojac='A';
char rekurzijaSlova(char);
	
int main (){
	
	char n;
	do {
		cout<<"Unesi neko veliko slovo: ";
		cin>>n;
	}while(n<65 || n>97);
	rekurzijaSlova(n);
	
return 0;
}
	

	char rekurzijaSlova(char slovo){
	if(brojac == slovo){
		cout<<brojac<<"  ASCII: "<<int(brojac)<<endl;
		return 0;
	}
	else{
		cout<<brojac<<"  ASCII: "<<int(brojac)<<endl;
		brojac++;
		rekurzijaSlova(slovo);
	}
}
