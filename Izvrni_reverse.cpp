#include <iostream> 
#include <algorithm> 
using namespace std; 
 
template<typename TIP> 
void Izvrni(TIP *p1, TIP *p2){               
int br=0;            
p2--; 		// Pokazivac p2 se vrati na zadnji clan            
while(*p1!=*p2) { 
	p1++; br++; } 	// Racuna se duzina niza            
	p1-=br; 		// Pokazivac p1 se vrati gdje je i bio
					//For petlja koja okrece clanove niza      
for(int i=0; i<br/2; i++){              
	TIP pr=*p1;              
	*p1=*p2;              
	*p2=pr;              
	*p1++;              
	*p2--; 
	} 
}
// Funkcija za ispis broja 
void Ispisi(int x) {      
	cout << x << "  ";} 
 
int main(){ 
int A[100]; 
int n;  
cout << "Unesite broj clanova niza: "; 
cin >> n; 
for (int i=0; i<n; i++){     
	int br;     
	cout << i+1 << ": ";     
	cin >> br;     
	A[i]=br;     
	}
Izvrni(A, A+n); 
cout << "Izvrnuti niz: "; 
for_each(A, A+n, Ispisi); 

getchar(); 
return 0; 
} 
