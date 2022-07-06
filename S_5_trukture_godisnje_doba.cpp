//Napravite program koji ako unesete broj izmeðu 1 i 4 izdaje adekvatno godisnje doba?
#include<iostream>

using namespace std;

struct doba
	{
	string proljece;
	string ljeto;
	string jesen;
	string zima;
	};

int main()
{
int br=0;
doba unos;
pocetak:cout<<" Unesi broj:"<<endl; cin>>br;
	switch(br)
	{
	case 1:
		unos.proljece="Proljeæe";
		cout<<unos.proljece<<endl;
	break;
	case 2:
		unos.ljeto="Ljeto";
		cout<<unos.ljeto<<endl;
	break;
	case 3:
		unos.jesen="Jesen";
		cout<<unos.jesen<<endl;
	break;
	case 4:
		unos.zima="Zima";
		cout<<unos.zima<<endl;
	break;
default:
		cout<<"Unijeli ste broj koji je > od 4";
	}
system("PAUSE");
return 0;
}

