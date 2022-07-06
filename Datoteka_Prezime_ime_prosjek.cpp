#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
int i, n;
string ime;
string prezime;
float ocjena;
ofstream izlaz;
izlaz.open("Mtkk31.txt");
cout<<"Unesi broj uèenika u odjeljenju"<<endl;
cin>>n;
for (i=1;i<=n;i++)
{
	cout<<"unesi ime ucenika br "<<i<<endl;
	cin>> ime;
	cout<<"unesi prezime ucenika br "<<i<<endl;
	cin>> prezime;
	cout<<"unesi prosjeènu ocjenu za uèenika br "<<i<<endl;
	cin>> ocjena;
	izlaz<<ime<<prezime<<ocjena<<endl;
}
izlaz.close();
return 0;
}
