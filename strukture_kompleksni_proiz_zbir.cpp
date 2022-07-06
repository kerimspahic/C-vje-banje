#include <iostream>
using namespace std;
int main()
{
  struct kompleks { 
  double re, im; 
  };
  struct kompleks x = { 3.0, 2.0 };
  struct kompleks y = { 2.0, 3.0 };
  struct kompleks zbir, proizvod; 
  zbir.re = x.re + y.re;
  zbir.im = x.im + y.im;
  proizvod.re = x.re*y.re - x.im*y.im;
  proizvod.im = x.re*y.im + x.im*y.re;
  cout<<"Zbir je : "<<zbir.re<<"+j"<<zbir.im<<endl;
  cout<<"Proizvod je : "<<proizvod.re<<"+j"<<proizvod.im<<endl;
  return 0;
}

