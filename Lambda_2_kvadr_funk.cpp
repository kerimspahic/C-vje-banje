#include <iostream>
#include<cmath>
#include <functional>
using namespace std;
main()
{
float(*p2)(float , float , float ) = [](float a, float b, float c)
	{	float D = b*b - 4 * a*c;
		return (-b + sqrt(D)) / (2 * a); }; 

float a, b, c;
cin >> a >> b >> c;
float x2 = p2(a, b, c);
cout << x2 << endl;
}

