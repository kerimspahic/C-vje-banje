#include<iostream>
#include<cstring>
using namespace std;
int strcmp(char*s1, char*s2) {
			/* Petlja se izvrsava do kraja kraceg stringa */
	while (*s1!='\0' && *s2!='\0') {
		if (*s1>*s2) return 1;
		if (*s1<*s2) return -1;
		s1++; s2++;
		}
		/* String koji je kraci ce pokazivati na znak \0 */
if (*s1!='\0') return 1;
if (*s2!='\0') return -1;
		/* Oba pokazuju na \0, znaci da su jednaki */
return 0;
}
int main()
{
char s1[50],s2[50];
cout<<"Unesite dvije rijeci duzine do 50 znakova.\n";
cout<<"Prva rijec: ";
cin>>s1;
cout<<"Druga rijec: ";
cin>>s2;
switch (strcmp(s1,s2)) {
case -1:
	cout<<"\nPrva je prije od druge\n";
	break;
case 1:
	cout<<"\nPrva je poslije od druge\n";
	break;
case 0:
	cout<<"\nStringovi su identicni\n";
	break;
}
return 0;
}
