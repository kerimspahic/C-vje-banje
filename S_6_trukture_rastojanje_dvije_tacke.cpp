//Napravi program koji izraèunava rastojanje izmeðu dvije tacke cije su koordinate poznate?
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct tacka
	{
	int x;
	int y;
	};

int main()
{
	float d;
	tacka A,B;
	cout<<"Unesi koordinate tacke A i B"<<endl;
	cout<<"Unesi x koordinatu tacke A"<<endl; cin>>A.x;
	cout<<"Unesi y koordinatu tacke A"<<endl; cin>>A.y;
	cout<<"Unesi x koordinatu tacke B"<<endl; cin>>B.x;
	cout<<"Unesi y koordinatu tacke B"<<endl; cin>>B.y;
d=sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
	cout<<"Rastojanje izmegu tacke A("<<A.x<<","<<A.y<<") i tacke B("<<B.x<<","<<B.y<<") je d="<<d<<endl;
system("PAUSE");
return 0;
}
