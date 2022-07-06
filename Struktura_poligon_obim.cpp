#include <iostream>
#include <cmath>
#define KV(x) (x)*(x)
using namespace std;

int main(){
  struct tacka { 
  	double x, y; 
	  } pol[100];
  
  double ob = 0;
  int i, n;
  do
  {
    cout<<"Broj vrhova : "; cin>>n;
  } while ((n<3) || (n>100));
  
  for (i = 1; i <= n; i++)
  {
    cout<<i<<".vrh:\n";
    cout<<"   x = "; cin>>pol[i - 1].x;
    cout<<"   y = "; cin>>pol[i - 1].y;
  }
  for (i = 1; i<n; i++)
    ob += sqrt(KV(pol[i].x - pol[i - 1].x) + KV(pol[i].y - pol[i - 1].y));
  	ob += sqrt(KV(pol[0].x - pol[n - 1].x) + KV(pol[0].y - pol[n - 1].y));
  cout<<"Obim: "<<ob<<endl;
  return 0;
}

