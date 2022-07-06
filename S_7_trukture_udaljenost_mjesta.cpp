//Napravite program koji izraèunava prosjeènu udaljenost svih naseljenih mjesta 
//Grada Zenica do Zenice
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
string mjesto[]={"Nemila", "Tetovo", "Pojske", "Perin Han"};

struct rastojanje
	{
	string mjesto;
	float rast;
	};

float s=0;
int n;
rastojanje r[100];
cout<<"unesi broj naselja "<<endl;
cin>>n;
	for(int i=0;i<n;i++)
	{
		r[i].mjesto=mjesto[i];
		cout<<r[i].mjesto<<endl;
	}
cout<<" "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" Za "<<r[i].mjesto<<" -Zenica rastojanje u kilometrima je? ";
		cin>>r[i].rast;
		s=s+r[i].rast;
	};
cout<<" "<<endl;
cout<<"Prosjecna udaljenost naseljenih mjesta do Zenice je "<<s <<endl;
system("PAUSE");
return EXIT_SUCCESS;
}

