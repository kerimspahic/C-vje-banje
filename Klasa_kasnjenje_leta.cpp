#include <iostream> 
#include <conio.h> 
#include <string.h> 
using namespace std;
class Casovnik{
protected: 
	int sec,min,sati; 
public: 
	Casovnik(){} 
	Casovnik(int h,int m,int s):sati(h),min(m),sec(s){} 
	~Casovnik(){} 
	int Daj_s()const{return sec;} 
	int Daj_m()const{return min;} 
	int Daj_sat()const{return sati;} 
	void Otkucaj(); 
	void citaj(){cout<<sati<<" "<<min<<" "<<sec<<endl;} 
};
void Casovnik::Otkucaj(){ 
	if(sec==59){ 
		sec=0;min=min+1; 
		if(min==60){ 
			min=0; sati=sati+1; 
			if(sati==24)
				sati=0;
				}
			} 
	else 
		sec=sec+1; 
}
class Let:public Casovnik{ 
private: 
	char *naziv; 
public: 
	Let(){naziv=0;} 
	Let(char *,int,int,int); 
	Let(const Let&); 
	~Let(){delete []naziv;naziv=0;} 
	void Kasnjenje(Casovnik); 
void Citaj(){cout<<"Naziv leta je: "<<naziv<<". Vrijeme odlaska je:"; 
	Casovnik::citaj(); } 
};
Let::Let(char *ime,int h,int m,int s):Casovnik(h,m,s){ 
	naziv=new char[strlen(ime)+1]; 
	strcpy(naziv,ime); 
}
Let::Let(const Let & stara):Casovnik(stara.sati,stara.min,stara.sec){ 
	naziv=new char[strlen(stara.naziv)+1]; 
	strcpy(naziv,stara.naziv); 
}
void Let::Kasnjenje(Casovnik vrijeme){ 
	int s=0; 
	s=vrijeme.Daj_sat()*60*60+vrijeme.Daj_m()*60+vrijeme.Daj_s(); 
	for(int i=0;i<s;i++) 
		Otkucaj(); 
}
main(){ 
	Let prvi("Sarajevo-Ljubljana",20,30,0); 
	Let drugi(prvi); prvi.citaj(); 
	cout<<"Unesite kasnjenje"; 
	int h,m,s; 
	cin>>h>>m>>s; 
	prvi.Kasnjenje(Casovnik(h,m,s)); 
	prvi.Citaj(); 
	drugi.Citaj(); 
}

