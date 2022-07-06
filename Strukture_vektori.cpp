#include <iostream>
using namespace std;

struct Vektor {
	double x, y, z;
	};
	
void UnesiVektor(Vektor &v) {
	cout << "X = "; cin >> v.x;
	cout << "Y = "; cin >> v.y;
	cout << "Z = "; cin >> v.z;
	}

Vektor ZbirVektora(const Vektor &v1, const Vektor &v2) {
	Vektor v3;
	v3.x = v1.x + v2.x; 
	v3.y = v1.y + v2.y; 
	v3.z = v1.z + v2.z;
	return v3;
	}

Vektor VektorskiProizvod(const Vektor &v1, const Vektor &v2) {
	Vektor v3;
	v3.x = v1.y * v2.z - v1.z * v2.y;	
	v3.y = v1.z * v2.x - v1.x * v2.z;
	v3.z = v1.x * v2.y - v1.y * v2.x;
	return v3;
	}

void IspisiVektor(const Vektor &v) {
	cout << "{" << v.x << "," << v.y << "," << v.z << "}";
	}
int main() {
Vektor a, b;
cout << "Unesi prvi vektor:\n";
UnesiVektor(a);
cout << "Unesi drugi vektor:\n";
UnesiVektor(b);
cout << "Suma ova dva vektora je: ";
IspisiVektor(ZbirVektora(a, b));
cout << endl << "Njihov vektorski prozivod je: ";
IspisiVektor(VektorskiProizvod(a, b));
return 0;
}
