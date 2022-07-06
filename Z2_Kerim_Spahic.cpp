#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;


int f1(int a,int* b)  
{
	int c=0;     // deklarise c sa 0
	a=2;      // dodjeljuje a sa 2
	*b=3;    // pokazivac (unarni) ukazuje da vrijednost za varijablu iznosi 3
	c=a+2;  //  varijabla c se dobija novu vrijednost (4)
	return c;  // vraca c u main funkciju
}

int f2(int* p1) 
{
	int a;  // deklarise a
	p1=p1+2; // adresa p1 se povecava za 2
	a=(*p1)+2; // a postaje zbir vrijednosti p1 i 2
	return a;  // vraca a u main funkciju
}

void f3(char* p)
{
	*p='?'; //mijenja prvo slovo rijeci rijeka sa ?
	p++; //povecava adresu p za 1
	*p='?'; //mijenja drugoslovo rijeci rijeka sa ?
}


int main(){
	int A[5]={2,4,6,8,10}; // deklarise jednodimenzionalni niz
	int B[2][2]={1,3,5,7}; // deklarise dvodimenzionalni niz
	char rijeka[]="Miljacka"; // deklarise varijable tipa char
	int a=1,b=1,c=0;  // dodjeljuje vrijednost varijablama a, b, c
	int *p1=&B[0][0]; // dodjeljuje adrese pointeru na p1
	c=*(A+1)+(*(p1+2)); // c dobija vrijednost 9, jer (A+1) iznosi 4, (*(p1+2)) jer u ovom izrazu u Nizu B se poveca adresa za dva mjesta i ona iznosi 5
	cout<<c<<endl;  // ispast c vrijednost 9
	c=f1(a,&b); //c dobija vrijednost iz funkcije f1 
	cout<<a<<endl; 	// ispis a (1) 
	cout<<b<<endl;  // ispis b (3)
	cout<<c<<endl;  // ispis c (4) - iz f1 dobija vrijednost
	c=f2(&B[0][0]+1); // u funkciji f2 koristena je adresa od B[0][0] i koja je uvecata za 1 i nakon zavrsetka funkcije dodjeljena je vrijednost a (9) iz iste funkcije
	cout<<c<<endl; // ispis c (9)
	c=f2(A+1);  // u funkciju f2 unosimo 4 i nakon zavrsetka funkcije dodjeljena je vrijednost a (10) iz iste funkcije
	cout<<c<<endl; // ispis c (10)
	f3(rijeka); // poziva funkciju f3
	cout<<rijeka; //ispis rijeka (??ljacka)
	return 0; //povratna vrijednost 0
}


