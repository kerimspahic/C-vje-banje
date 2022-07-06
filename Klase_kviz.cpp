#include<iostream>
#include<cstring>
using namespace std;
//Ahmet Durmic
//Harun Kaknjo
 
enum godstud{PRVA=1,DRUGA,TRECA};
enum nacstud{VANREDAN=0,REDOVAN};
enum odg{NETACNO=0,TACNO};

int brpitanja=10;
int enuminputpitanje;

class Pitanja{
    public:
        Pitanja(){
            for(int i=1;i<=brpitanja;i++){
            if(i==1){
                pitanja[i]="Da li je tacno da se prilikom kreiranja dinamicnog objekta, treba po pravilu memorija dealocirati unutar destruktora? ";
               
                }
            else if(i==2){
                pitanja[i]="Da li je moguce u programskom jeziku C++ koristiti long int varijable?";
 
            }
            else if(i==3){
                pitanja[i]="Da li se za racunanje duzine STRINGA koristi genericka funkcija strlen iz built-in bibilioteke cstring?";
 
            }
            else if(i==4){
                pitanja[i]="Biblioteka fstream u sebi sadrzi funckije za ispis?";
 
            }
            else if(i==5){
                pitanja[i]="Lamda funckije je moguce koristiti u svakom od standarda C++?";
 
            }
            else if(i==6){
                pitanja[i]="Da li su sljedece relacije ekvialentne: (s+i)->Pokazivac==s[i].Pokazivac ?";
 
            }
            else if(i==7){
                pitanja[i]="Isto memorije se zauzme proslijedivanjem u argument funkcije reference i vrijednosti?";
 
            }
            else if(i==8){
                pitanja[i]="Memoizacijom se vrsi izbacivanje duplikata iz vektorski sortiranog niza ?";
 
            }
            else if(i==9){
                pitanja[i]="Za ispisivanje dinamicki alocirane memorije nije potrebno derefenrecencirati pokazivac?";
 
            }
            else if(i==10){
                pitanja[i]="Kada se kompajlira program on se nalazi i pokrece u RAMu?";
   
            }
        }
    }
    odg provjera(int brpitanja);
    odg provjera2(int brpitanja,int i,int enuminput);
    void pokreni_test(){
        int enuminput;
        for(int i=1;i<=brpitanja;i++){
            cout<<i<<". "<<pitanja[i]<<endl;
            cout<<"(0-NETACNO,1 TACNO): ";
			cin>>enuminput;cin.clear();cin.ignore(10000,'\n');
            //while(!enuminput||enuminput<0||enuminput>1){
            //	cout<<"Pogresan unos!\nUnesite odgovor na pitanje: ";cin>>enuminput;
            //	cin.clear();cin.ignore(10000,'\n');
			//}
            odg1[i]=(odg)enuminput;
        }  
    }
    void ispisi_rezultat(){
        int br=0;
        for(int i=1;i<=brpitanja;i++){
            if(odg1[i]==provjera(i)||odg1[i]==provjera2(brpitanja,i,enuminputpitanje)){
                br++;
            }
        }
        cout<<br<<endl;
    }
	void dodaj();
        
    private:
        string pitanja[100];
        odg odg1[100];
};
odg Pitanja::provjera(int brPitanja){
    if(brPitanja==1){
        return TACNO;
    }
    else if(brPitanja==2){
        return TACNO;
    }
    else if(brPitanja==3){
        return NETACNO;
    }
    else if(brPitanja==4){
        return NETACNO;
    }
    else if(brPitanja==5){
        return NETACNO;
    }
    else if(brPitanja==6){
        return TACNO;
    }
    else if(brPitanja==7){
        return NETACNO;
    }
    else if(brPitanja==8){
        return NETACNO;
    }
    else if(brPitanja==9){
        return NETACNO;
    }
    else if(brPitanja==10){
        return TACNO;
    }
}
odg Pitanja::provjera2(int dodanopitanje,int brpitanja,int input){
	if(brpitanja==dodanopitanje){
		if(enuminputpitanje==1){
			return TACNO;
		}else{
			return NETACNO;
		}
	}
}

void Pitanja::dodaj(){
	brpitanja++;int i;
	char tekstpitanja[100];
	cout<<"Unesite pitanje koje zelite dodati: ";
	cin.getline(tekstpitanja,100);
	pitanja[brpitanja]=tekstpitanja;
	cout<<"Unesite tacan odgovor za uneseno pitanje(0-NETACNO, 1-TACNO): ";cin>>enuminputpitanje;
	provjera2(brpitanja,brpitanja,enuminputpitanje);
}

class Student{
    public:
    	Pitanja P;
        Student(string ip_val="NO NAME"):
            imeprezime{ip_val}{/*cout<<"Constructor is called !"<<endl;*/}
        Student(const Student &izvor):
        	imeprezime{izvor.imeprezime}{cout<<"Copy constructor is called"<<endl;}
        ~Student(){/*cout<<"Deconstuctor is called ! "<<endl;*/}
        void unesi(){
            int enuminput;
            int enuminput1;
            cout<<"Unesite ime i prezime studenta: ";getline(cin,imeprezime);
            cout<<"Unesite godinu studija(1,2,3): ";cin>>enuminput;cin.clear();cin.ignore(10000,'\n');
            godstud1=(godstud)enuminput;
            cout<<"Unesite nacin studiranja(0-VANREDAN, 1-REDOVAN): ";cin>>enuminput1;cin.clear();cin.ignore(10000,'\n');
            nacstud1=(nacstud)enuminput1;
        }
        void ispisi(){
            cout<<imeprezime<<endl;
        }
        
        void pokreni_test(Student s[],int rb);
        void prikazi_rezultate_testa(Student s[],int rb);
        
        
    private:
        string imeprezime;
        bool radioTest=false;
        godstud godstud1;
        nacstud nacstud1;
};

void intro(){
    cout<<"===============================================\n";
    cout<<"Dobrodosli, u prilugu se nalazi mali kviz kojim\n";
    cout<<"mozete testirati svoje znanje iz predmeta \n";
    cout<<"Napredne tehnike programiranja. Na ponudena \n";
    cout<<"pitanja odgovarate na sljedeci nacin.\nUnosi se 0 za NETACNO a ";
    cout<<"1 za TACNO.\n";
    cout<<"3 tacna odgovora  :(\n";
    cout<<"5 tacnih odgovora  -.-\n";
    cout<<"7 tacnih odgovora :)\n";
    cout<<"9 ili vise tacnih odgovora :DDDDD\n";
    cout<<"                   SRETNO\n";
    cout<<"===============================================\n";
    system("pause");
    system("cls");
}  

int menu(){
    int izbor;
    do{
    	cout<<"===================================================\n";
        cout<<"\t\t\tMENU\n";
        cout<<"===================================================\n";
        cout<<"\t   0)  Ispis unesenih studenata\n";
        cout<<"\t   1)  Pokreni test\n";
        cout<<"\t   2)  Ispisi rezultate testa\n";
        cout<<"\t   3)  Dodaj studenta\n";
        cout<<"\t   4)  Dodaj pitanje\n";
        cout<<"\t   5)  Kraj\n";
        cout<<"===================================================\n";
        cout<<"Unesite izbor: ";cin>>izbor;cin.clear();cin.ignore(10000,'\n');
        return izbor;
        system("pause");
        system("cls");
    }while(izbor>-1||izbor<5);
}



void Student::pokreni_test(Student s[],int rb){
    int odgovor;
        if(s[rb].radioTest){
            cout<<"Student "<<s[rb].imeprezime<<" je vec radio test! "<<endl;
        }else{
            s[rb].P.pokreni_test();
            s[rb].radioTest=true;
        }  
 
}

void Student::prikazi_rezultate_testa(Student s[],int rb){
    int br=0;
    if(s[rb].radioTest){
        cout<<"Student "<<s[rb].imeprezime<<" je od ukupnih "<<brpitanja<<" pitanja, tacno odgovorio na ";s[rb].P.ispisi_rezultat();cout<<" pitanja "<<endl;
    }else{
        cout<<"Student "<<s[rb].imeprezime<<" nije radio test, odaberite prvo opciju 1! "<<endl;
    }     
}
 
int main(){
   
    intro();
    int n=100;
    int brStudenata=1;int izbor;
    Student s[n];
    for(int i=0;i<brStudenata;i++){
        cout<<"Unesite svoje podatke\n";
        s[i].unesi();
        system("pause");
        system("cls");
    }
   
    do{
        izbor=menu();
        if(izbor<0||izbor>4){
            break;
        }
        
        if(izbor==0){
            for(int i=0;i<brStudenata;i++){
                cout<<i+1<<".";s[i].ispisi();
            }
            system("pause");
            system("cls");
        }
        
        if(izbor==1){
            int rb;
            for(int i=0;i<brStudenata;i++){
                cout<<i+1<<".";s[i].ispisi();
            }
            cout<<"Unesite svoj redni broj za pokretanje testa: ";cin>>rb;cin.clear();cin.ignore(10000,'\n');
            if(rb>brStudenata){
            	cout <<"Ne postoji student sa tim rednim brojem"<<endl;
            	system("pause");
            	system("cls");
			}else{
           		rb=rb-1;
            	s[rb].pokreni_test(s,rb);
            	system("pause");
            	system("cls");
        	}
        }
        
        if(izbor==2){
            int rb;
            for(int i=0;i<brStudenata;i++){
                cout<<i+1<<".";s[i].ispisi();
            }
            cout<<"Unesite svoj redni broj za ispis rezultata testa: ";cin>>rb;cin.clear();cin.ignore(10000,'\n');
            if(rb>brStudenata){
            	cout <<"Ne postoji student sa tim rednim brojem! "<<endl;
            	system("pause");
            	system("cls");
			}else{
            	rb=rb-1;
            	s[brStudenata].prikazi_rezultate_testa(s,rb);
           	 	system("pause");
            	system("cls");
        	}
        }  
        
        if(izbor==3){
            cout<<"Unesite svoje podatke\n";
            s[brStudenata].unesi();
            brStudenata++;
            system("pause");
            system("cls");
        }
        
        if(izbor==4){
        	s[brStudenata].P.dodaj();
        	system("pause");
            system("cls");
		}
       
    }while(1);
   
    return 0;
}
