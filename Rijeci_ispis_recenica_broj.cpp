# include <iostream> 
# include <string> 
using namespace std; 
int main(){      
cout << "Unesi recenicu: " << endl; 
string recenica; 
getline(cin, recenica); 
 
cout << endl << "Rijeci iz recenice: " << endl << endl; 
bool istina=false; 
int br=0, br1=0; 
for (int i=0; i<=recenica.length(); i++) {     
	if (((recenica[i]>='a')&&(recenica[i]<='z'))||
	((recenica[i]>='A')&&(recenica[i]<='Z'))){ 
	cout << recenica[i]; 
	br++; 
	istina=true; 
	continue; }     
	if (istina) {
		cout << endl; 
		istina=false; 
		br1++; } 
	} 
cout << endl << "Recenica ima " << br << " slova i " << 
br1 << " rijeci!";  
return 0; 
} 
