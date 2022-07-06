#include <iostream> 
#include <string.h> 
#include <conio.h> 
using namespace std;
class Text{ 
private: 
	char *p;
public: 
	Text(){p=0;} //Dodeljujemo pokazivacu vrijednost 0 
	Text(const char *);//da upotrebom destruktora ne bismo brisali 
	~Text(); //pokazivac slucajnog sadrazaja i sam sadrzaj, delete. 
	int tLength(); 
	char tRead(int); 
	void tWrite(int, char); 
}; 
Text::Text(const char* m){ 
	p=new char[strlen(m)+1]; 
	strcpy(p,m);
	}
Text::~Text(){ 
	delete []p; 
	p=0; 
	}
char Text::tRead(int i){ 
	return p[i]; 
	}
void Text::tWrite(int i, char c){ p[i]=c; }
int Text::tLength(){ return strlen(p);}
int main(){ 
char *ch={"dobar dan"}; 
Text T(ch); 
cout<<"Koji karakter zelite da zamjenite?"<<endl; 
int j; 
cin>>j; 
cout<<"Koji karakter zelite da postavite"<<endl; 
char c; 
cin>>c; 
T.tWrite(j,c); 
cout<<"Novi tekst je: "<<endl; 
int l=T.tLength(); 
for(int i=0; i<=l;i++) 
	cout<<T.tRead(i); 
	cout<<endl; 
getch(); 
}
