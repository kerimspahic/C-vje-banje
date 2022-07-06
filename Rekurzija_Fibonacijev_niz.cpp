#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
 
// rekurzivni potprogram koji vraca n-ti clan Fibonacijevog niza
int VratiFibonacijevClan(int brojClana);
	int main() {
  		for (int i = 1; i <= 25; i++) {
    		int fibClan = VratiFibonacijevClan(i);

			cout << "a" << i << "=" << fibClan << endl;
  		}
 
  system("Pause");
  return 0;
}
 
int VratiFibonacijevClan(int brojClana) {
  if (brojClana < 3)
    	return 1;
  else {
    	int finClan = VratiFibonacijevClan(brojClana - 1) +
        VratiFibonacijevClan(brojClana - 2);
   		return finClan;
  		}
}

