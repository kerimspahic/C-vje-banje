#include <iostream> 
#include <conio.h> 
using namespace std;
class Razlomci{ 
private: 
	int brojilac; 
	int imenilac; 
public: 
	Razlomci(int=0,int=1); 
	~Razlomci(){} 
	friend Razlomci operator+(Razlomci,Razlomci); ///Ne saljem referencu jer 
	Razlomci& operator+=(const Razlomci &);//mi je potreban poziv konstruktora 
	Razlomci& operator++();// posto uzimam u obzir da mogu sabirati sa celim brojevima 
	Razlomci operator++(int); 
	void ispisi(){cout<<brojilac<<"/"<<imenilac<<endl;} 
};
Razlomci::Razlomci(int a,int b):brojilac(a),imenilac(b){}
Razlomci operator+(Razlomci r1,Razlomci r2){ 
	Razlomci temp; 
	temp.brojilac=r1.brojilac*r2.imenilac+r2.brojilac*r1.imenilac; 
	temp.imenilac=r1.imenilac*r2.imenilac;
return temp; 
}
Razlomci &Razlomci::operator+=(const Razlomci &r){ 
	brojilac=brojilac*r.imenilac+imenilac*r.brojilac; 
	imenilac=imenilac*r.imenilac; return *this; 
}
Razlomci &Razlomci::operator++(){ 
	return (*this)+=1; 
}
Razlomci Razlomci::operator++(int i){ 
	Razlomci temp(*this);//Kreira kopiju objekta koji inkrementiramo. 
	(*this)+=1;//Inkrementira vrijednost objekta. 
	return temp;//Vraca vrijednost prije inkrementiranja. 
}
main(){ 
	int b,i; 
	cout<<"Unesite vrijednosti za brojioce i imenioce razlomaka"<<endl; 
	cin>>b>>i; 
	Razlomci r1(b,i); 
	cin>>b>>i; 
	Razlomci r2(b,i); 
	Razlomci priv; 
	priv=r1+r2; 
	priv.ispisi(); r1++; 
	r1.ispisi(); 
	priv=r1++; 
	priv.ispisi(); 
	++r1; 
	r1.ispisi(); 
	r1+=r2; 
	r1.ispisi(); 
	r1+=(r2++); 
	r1.ispisi(); 
	priv=r1+r2+5; 
	priv.ispisi(); 
	(5+r2).ispisi(); 
getch(); 
}

