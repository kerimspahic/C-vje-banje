#include<iostream>
using namespace std;
void Hanoi(int n, int sa, int na){			
	if (n==1) 
		cout << sa << "->" << na << endl;
	else {
		Hanoi(n-1,sa, 6-sa-na);
		cout << sa << "->" << na << endl;
		Hanoi(n-1,6-sa-na,na);
	}
}

int main(){						
	int n;
	cout << "Upisite n: ";
cin >> n;
Hanoi(n,1,3);
system("pause"); return 0;
}
