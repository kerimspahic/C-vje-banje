#include <iostream>
#include <functional>
#include <vector>
#include <set>
#include <queue>
#include <memory>
#include <algorithm>
#include <list>
#include <cmath>
#include <iterator>
#include <stack>
#include <iterator>
#include <string>
#include <cstring>

template <typename tip1,typename tip2> //Deklaracija sablona ( deklarisemo dva tipa: tip1 i tip2 koje cemo koristiti unutar programa) 

tip1 genericka(tip1 p1, tip1 p2, tip2 p3,tip2 p4) { //Koristeci template koji smo deklarisali na pocetku pomocu njega ubacujemo vrijednost iz main funkcije tacnije vrijednosti iz vektora koje smo deklarisali unutar glavne funkcije
 bool jeste; // deklaracija varijbale jeste tipa bool
 while(p1!=p2) { // Postavljenje while petlje: Dok je p1 razlicito od p2
  if(*p1==*p3) { // Uslov koji provjerava da li su vrijednosti na pointerima iste
   jeste=true; // Ako jesu bool je tacan
   tip1 pom1(p1); // Deklaracija pom1 pomocu sablona sa vrijednosti p1 
   tip2 pom2(p3); // Deklaracija pom2 pomocu sablona sa vrijednosti p3
   while(pom2!=p4) { //dok je pom2 razlicit od p4 ulazi u petlju
    if(*pom2!=*pom1) //uslov koji provjeruje da li su vrijednosti na poinerima razlicite 
	{jeste=false; break;} // ako jesu  jeste postaje false i izlazi iz while petlje
    pom1++; //povecavanje pom1 vrijednosti
    pom2++; //povecavanje pom2 vrijednosti
   }
  }
  if(jeste) return p1; //ako je bool tacan vraca p1
  p1++; //povecava p1 za 1
 }
 return p2; //vraca p2
}
 
 
int main() {
 
 std::vector<int> v1{1,7,3,5,2,6}; //deklaracija vektora sa unesenim prmjerima
 std::vector<int> v2{3,5,2}; //deklaracija vektora sa unesenim primjerima
 auto pok(genericka(v1.begin(),v1.end(),v2.begin(),v2.end())); //Ova funkcija sortira vectore/blokove tako sto prvo ispisuje vrijednosti iz v2, a koje se takodjer nalaze i u v1, nakon ipisvanja tih vrijednosti, ispisuje i ostale koje slijede iz v1
 while(pok!=v1.end()) //dok je pok razlicito od v1.end() ulazi u ispis
 std::cout<<*pok++<<" "; //ispisuje vrijednosti pokazivaca pok i uvecava ga za 1
 return 0; //vraca 0
}
