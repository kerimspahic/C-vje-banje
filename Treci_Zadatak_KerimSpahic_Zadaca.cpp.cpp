#include <iostream>
using namespace std;

int main(){
	char recenica[60],*recBezPrve; //deklaracija recenicu i pomocnu variablu
	cout<<"Unesi neku recenicu: "; //ispis
	cin.get(recenica, 60); //unos char niza
	recBezPrve=recenica; //vrijednost char niza recenica dodjeljuju se nizu recBezPrve
	
	while (*recBezPrve == ' '){ //petlja ima ulogu pomjeranja niza naprijed ako se nade slucajno uneseni prazan prostor
		recBezPrve++;}
	while (*recBezPrve != ' '){ //petlja ima ulogu pomjeranja niza naprijed sve dok se ne ne dode do praznog prostora
		recBezPrve++;}
	while (*recBezPrve == ' '){ //petlja ima ulogu pomjeranja niza naprijed dok se ne nade nesto sto nije prazan prostor
		recBezPrve++;}
	
	//u sustini da ovaj program bude validan potrebna nam je samo druga while petlja ali radi ljepseg ispisa implementrane su i ove dvije
	
	cout<<"Recenica bez prve rijeci je:"<<endl; //ispis
	while (*recBezPrve != 0){ //petlja ima ulogu ispisa niza recBezPrve od mjesta na kojem je predhodna petlja stala
		cout<<*recBezPrve;
		recBezPrve++;}
	return 0;
}

