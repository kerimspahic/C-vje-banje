#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int ispravna(char *adresa) //funkcija provjere maila
{
	bool prov1=0,prov2=0; //deklaracija bool variable
	do
	{
		if(adresa[0] == '@') //provjera ima li @
		{
			prov1 = 1; //prov 1 postaje 1 (rue)
		}
		if(adresa[0] == '.' & prov1 == 1 ) //provjera ima li .
		{
			adresa++; //povecava adresu adrese za 1
			if(adresa[0] == 'b') //provjera ima li b
			{
				adresa++; //povecava adresu adrese za 1
				if(adresa[0]=='a') //provjera ima li a
				{
					prov2 = 1; //prov 2 postaje 1 (true)
				}
			}
		}
		adresa++; //povecava adresu adrese za 1
	}while (adresa[0] != '\0'); //radi sve dok ne dode do zadnje mem adrese u var adresa
	
	if(prov1 == 1 and prov2 ==1 ) //provjerava da li su oba uslova ispunjena
	{
		return 1; //vraca 1 u main
	}
	else{ 
		return 0; //vraca 0 u main
	}
}
int main(){
	
    string mail; //deklarise string var
    cin>>mail; //unoci vriednost za mail
    int n = mail.length(); //n-u dodjeljuje velicinu stringa
    char adresa[n + 1];  //deklarise adresu i daje joj velicinu n+1
    strcpy(adresa, mail.c_str()); //pomocu adresa kopira vrijenosti iz jedne u drugu
    
    cout<<ispravna(adresa); //ispisuje 1 ili 0 ovisno sta je korisnik unjeo uz pomoc ispravna(char *adresa)

	return 0;
}
