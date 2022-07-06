#include <iostream>
using namespace std;

void f1 (int* p1) {
	cout << *p1;
}

int main() {

int a;
	cout << "Unesite broj: ";
	cin >> a;

	f1(&a);

return 0;
}
