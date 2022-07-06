#include <iostream>

using namespace std;

	int rekurzijaStoja(int);

int main (){

	int broj;
	
	cout<<"Unesi neki broj: ";
	cin>>broj;
			cout<<rekurzijaStoja(broj);

return 0;
}

	int rekurzijaStoja(int broj){
		
		if(broj==100){
			return 0;
		}
		
		if(broj < 100){
			if (broj % 2 == 0){
				return broj + rekurzijaStoja(broj + 2);
			}else{
				return rekurzijaStoja(broj + 1);
			}
		}
		if(broj > 100){
			if (broj % 2 == 0){
				return broj + rekurzijaStoja(broj - 2);
			}else{
				return rekurzijaStoja(broj - 1);
			}
		}
		
		
	}
