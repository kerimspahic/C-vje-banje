/*Program koji tra�i od korisnika da unese spisak rije�i 
(broj rije�i se prethodno unosi sa tastature), 
a zatim ispisuje na ekran prvu i poslednju rije� iz spiska po 
abecednom poretku, kao i popis svih unesenih rije�i, 
ali bez ispisivanja duplikata (tj. bez ispisivanja rije�i koje 
su se ve� jednom ispisale). Program realizirati kori�tenjem 
vektora stringova, odnosno vektora �iji su elementi tipa "string".*/
# include <iostream>
# include <string>
# include <vector>
using namespace std;
main(){
// Unos broja rijeci a zatim unos rijeci u vektor...
vector<string> a;
int n;
cout << "Unesi broj rijeci: "; cin >> n;
for (int i=0; i<n; i++){
cout << i+1 << ". ";
string pom;
cin >> pom;
a.push_back(pom);
}
// Sortiranje imena
string pom;
for (int i=0;i<(a.size()-1);i++)
for (int j=i+1;j<a.size();j++)
if (a[j]<a[i]){
pom=a[i];
a[i]=a[j];
a[j]=pom;
}
// Ispis prve i zadnje rijeci
cout << "Prva rijec je: " << a[0] << " a zadnja " << a[a.size()-1] << endl;
// Ispis svih rijeci
cout << endl << "Ispis rijeci: " << endl;
a.push_back("");
for (int i=0, j=0; i<a.size()-1; i++){
if ((a[i]!=a[i+1])) { cout << j+1 << ". " << a[i] << endl; j++; }
}
return 0;
}

