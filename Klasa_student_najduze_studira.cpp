#include <iostream> 
#include <conio.h> 
#include <string.h> 
using namespace std;
class Student{ 
private: 
	char *ime; 
	char *prezime; 
	int gd_upisa; 
	int gd_studija; 
public: 
	static int ukupno; 
	Student(){ime=0; prezime=0; ukupno++;} 
	Student(int,int,char *,char *); 
	Student(const Student &); 
	~Student(){delete []ime; ime=0; delete []prezime; prezime=0;ukupno--;} 
	Student &operator=(const Student &); 
	Student &operator++(); 
	Student operator++(int); 
	friend void Pretrazi(Student *, int); 
	void citaj(){cout<<ime<<" "<<prezime<<" "<<gd_upisa<<" "<<gd_studija<<endl;} 
};
int Student::ukupno=0;
Student::Student(int a,int b,char *ime1, char *prezime1):gd_upisa(a),gd_studija(b){ 
	ime=new char[strlen(ime1)+1]; 
	strcpy(ime,ime1); 
	prezime=new char[strlen(prezime1)+1]; 
	strcpy(prezime,prezime1); 
	ukupno=ukupno++; }
Student::Student(const Student & stari):gd_studija(stari.gd_studija),gd_upisa(stari.gd_upisa){ 
	ime=new char[strlen(stari.ime)+1]; 
	strcpy(ime,stari.ime); 
	prezime=new char[strlen(stari.prezime)+1]; 
	strcpy(prezime,stari.prezime); 
	ukupno=ukupno++; }
Student &Student::operator=(const Student &stari){ 
	if(&stari!=this){ 
		delete []ime; 
		delete []prezime; 
		gd_studija=stari.gd_studija; 
		gd_upisa=stari.gd_upisa; 
		ime=new char[strlen(stari.ime)+1]; 
		prezime=new char[strlen(stari.prezime)+1]; 
		strcpy(prezime,stari.prezime); 
	} 
	return *this; }
Student &Student::operator++(){ 
	gd_studija+=1; 
	return *this; }
Student Student::operator++(int){ 
	Student temp(*this); 
	temp.gd_studija+=1; 
	return temp; }
void Pretrazi(Student *grupa,int broj){ 
	Student temp[5];
	for(int i=0;i<5;i++) 
		temp[i]=Student(2015,i+1,"Nema","studenata"); 
	for(int j=0;j<broj;j++){ 
		if(grupa[j].gd_studija==1){ 
			if(grupa[j].gd_upisa<temp[0].gd_upisa) 
				temp[0]=grupa[j];} 
		else if(grupa[j].gd_studija==2){ 
			if(grupa[j].gd_upisa<temp[1].gd_upisa) 
				temp[1]=grupa[j];} 
		else if(grupa[j].gd_studija==3){ 
			if(grupa[j].gd_upisa<temp[2].gd_upisa) 
				temp[2]=grupa[j];} 
		else if(grupa[j].gd_studija==4){ 
			if(grupa[j].gd_upisa<temp[3].gd_upisa) 
				temp[3]=grupa[j];} 
		else{ 
			if(grupa[j].gd_upisa<temp[4].gd_upisa) 
			temp[4]=grupa[j];} 
	} 
	for(int i=0;i<5;i++){ 
		cout<<"Student koji najduze studira na "<<temp[i].gd_studija<<" -oj godini se zove";
		cout<<temp[i].ime<<" "<<temp[i].prezime; 
		if(temp[i].gd_upisa!=2015) 
			cout<<" i upisao je "<<temp[i].gd_upisa<<endl; } 
}
main(){ 
	Student ps[5]; 
	int upis; 
	int gd; 
	char pom1[10]; 
	char pom2[10]; 
	ps[0]=Student(2015,1,"Namir","Neimar"); 
	cout<<"Unesite podatke za 5 studenata: godinu upisa, godinu na kojoj je"; 
	cout<<" ime i prezime"<<endl; 
	for(int i=1;i<5;i++){ 
		cin>>upis>>gd>>pom1>>pom2;; 
		ps[i]=Student(upis,gd,pom1,pom2);} 
	Student a(122,12,"Mujo","Mujiæ"); 
	Student b; b=a; b.citaj(); 
	Pretrazi(ps,5); 
	for(int i=0;i<5;i++){
		ps[i].citaj();} 
getch(); 
}

