# include <iostream> 
# include <string> 
# include <vector> 
using namespace std; 
main(){  
vector<string> a; 
int n; 
cout << "Unesi broj rijeci: "; 
cin >> n; 
for (int i=0; i<n; i++){ 
	cout << i+1 << ". "; 
	string pom; 
	cin >> pom; 
	a.push_back(pom); 
	} 
 
string pom; 
for (int i=0;i<(a.size()-1);i++)     
	for (int j=i+1;j<a.size();j++)         
		if (a[j]<a[i]){             
			pom=a[i];             
			a[i]=a[j];             
			a[j]=pom; } 
 
cout << "Prva rijec je: " << a[0] << 
		" a zadnja " << a[a.size()-1] << endl; 
 
cout << endl << "Ispis rijeci: " << endl; 
a.push_back(""); 
for (int i=0, j=0; i<a.size()-1; i++){ 
	if ((a[i]!=a[i+1])) { 
		cout << j+1 << ". " << a[i] << endl; 
		j++; } 
	} 
 
return 0; 
}
