#include <iostream>
#include <functional>
#include <set>

#include <iterator>
#include <cstring>  

/* Za kompajliranje ovog kod potrebno je da vas program posjeduje C++11 */

using namespace std;


int prebrojiRijeci(string recenica) // Definicja funkcije
{
 int brojac(0); //Deklaracija varijbale brojac i postavljanje njene vrijednosti na 0
 
 for(int i=0;i<recenica.length();i++) //Postavljanje petlje: Deklaracija varijable i (0), dok je i manja od recenica.length, povecavamo i za 1 i ona broji koliko ima simbola u recenici
 {
 while(recenica[i]==' ' && i!=recenica.length()) // ova petlja prebrojava prazan prostor koji se ne nalazi pored nekog simbola
 i++; // uvecava i za 1
 if(i==recenica.length()) //Nakon while petlje koju smo imali prethodno, postavljamo uslov (i == recenic.length()) koji kaze da ako je i dosao do vrijednosti recenica.length(), uslov je ispunjen 
 	break; // Zaustavljanje for petlje 
 brojac++; //brojac se povcava za 1 i on ima ulogu da prikaze koliko zapravo ima unesenih rijeci
 while(recenica[i]!=' ' && i<recenica.length()) // ova petlja prebrojava unesene simbole u recenici 
 i++; //Povecavanje varijable i
 }
 return brojac; //Vracanje vrijednosti varijable brojac 
}


string DajRijec(string recenica, int n) //deklarise string funkciju
{
 if(n<1 || prebrojiRijeci(recenica)<n) //uslov koji provjerava da li je n (odnosno broj koji smo unijeli za zeljenu rijec iz recenice) manji od jedan ili je veci od broja n
 	throw n; //ako je uslov ispunjen "baci" n u catch u main funkciji
 	
 int brojac(0); //deklarise variablu brojac (0)
 for(int i=0;i<recenica.length();i++) //Postavljanje petlje: Deklaracija varijable i (0), dok je i manja od recenica.length, povecavamo i za 1 i ona broji koliko ima simbola u recenici
 {
 while(recenica[i]==' ' && i!=recenica.length()) // ova petlja prebrojava prazan prostor koji se ne nalazi pored nekog simbola
 i++;// uvecava i za 1
 if(i==recenica.length()) //Nakon while petlje koju smo imali prethodno, postavljamo uslov (i == recenic.length()) koji kaze da ako je i dosao do vrijednosti recenica.length(), uslov je ispunjen 
 break;// Zaustavljanje for petlje 
 brojac++; //brojac se povcava za 1 i on ima ulogu da prikaze koliko zapravo ima unesenih rijeci
 int tmp(i); // Deklaracija varijable tmp(i) (koja je privremena)
 int pom_brojac(0); //Deklaracija varijable pom_borja(0) (pomocni brojac)
 while(recenica[i]!=' ' && i<recenica.length()){ // ova petlja prebrojava unesene simbole u recenici
 pom_brojac++; // Povecavanje vrijednosti pomocnog brojaca
 i++; //Povecavanje varijable i
 }
 if(brojac==n){ //Ako je brojac dostigne vrijednost n (unesenog broja)
 string pom(recenica.substr(tmp,pom_brojac)); //Oduzima prostor do tmp i poslije pom_brojac
 return pom; //Vraca vrijednost pom tj. rijec koju smo selektovali
 }
 }
}
int main()
{
 int n; //Deklaracija varijable n
 string recenica,rijec; //Deklaracija stringa recenica i rijec
 cout << "\nUnesi neku recenicu(string): "; //Ispis za unos recenice
 getline(cin, recenica); //Unos recenice
 cout << "\nUnesi broj n: "; //Ispis za unos broja
 cin >> n; //Unos broja
 try // pokusati ce izvrsiti naredbe u viticastim zagradama
 {
 rijec=DajRijec(recenica,n); //dodjeljuje variabli string rijec vrijednosti iz funkcije DajRijec
 cout << rijec; //Ispis rijeci
 }
 catch(int e) //prima vrijednost n za e iz funkcije DajRijec
 {
 if(e<1) //ako je e manje od 1
 cout << "\nGreska: unio si broj koji je manji od jedan, a broj rijeci ne moze biti manji odjedan!"; //Ispis
 else //u suprotnom
 cout << "\nGreska: unio si broj koji je veci od broja rijeci u unesenoj recenici!"; //Ispis
 }
 return 0; //vraca vrijednost 0
}
