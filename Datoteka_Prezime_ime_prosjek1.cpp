/*Napravite program koji izra�unava srednju ocjenu iz predmeta 
ra�unari i programiranje na nivou razreda?*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
ifstream cita;
cita.open("Mtkk31.txt");
string ime, prezime;
float ocjena, socjena;
int br=0;
while(cita>>ime>>prezime>>ocjena)
{
br++;
socjena+=ocjena;
cout<<ime<<prezime<<ocjena<<endl;
}
cita.close();
socjena=socjena/br;
cout<< "srednja ocjena za Mtkk11 je "<<socjena<<endl;
return 0;
}

