#include <iostream>
using namespace std;


void saberi(int *, int *, int *);


int main() {

	int a,b,c;

	cout<<"Unesite dva broja: ";
	cin>>a>>b;
	int *p1;
	p1 = &c;
	saberi(&a,&b,p1);
	cout << *p1;


return 0;
}

void saberi(int *p1, int *p2, int *p3){
	*p3=*p1 + *p2;
}

