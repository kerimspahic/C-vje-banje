#include <iostream>
#include <iomanip>
using namespace std;

struct student 
{
    char ime[10], prezime[10];
    int predmet, ocjena;
} studenti[100];

int main(int argc, const char * argv[]) 
{
    float suma[11] = {0};
    float tracer[11] = {0};
    int n;
    cout <<"Unesi broj studenta: ";
    cin >> n;
    student studenti[n];
    cout<<endl;
    
    for(int i=0 ; i<n; i++)
	{
        cout<<"Student "<<i+1<<": "<<endl;
		cout <<"Ime studenta: ";
        cin >>studenti[i].ime;
        cout <<"Prezime studenta: ";
        cin >>studenti[i].prezime;
        cout <<"Predmet: ";
        cin >>studenti[i].predmet;
        cout <<"Ocjena: ";
        
        do
		{
            cin >>studenti[i].ocjena;
        }while(studenti[i].ocjena>10 || studenti[i].ocjena<1);
        cout<<endl;
    }
    
    for(int i=0; i<n; i++)
	{
    	cout<<"   "<<studenti[i].ime <<"   "<<studenti[i].prezime <<"   "<<studenti[i].predmet <<"   "<<studenti[i].ocjena<<endl;
    }
    
    for(int i=0; i<n; i++)
	{
        suma[studenti[i].predmet]+=studenti[i].ocjena;
    	tracer[studenti[i].predmet]++;
    }
    double ar;
    cout<<"Prosjek po predmetima: "<<endl;
    for (int i= 0; i<10; i++) 
	{
        if(tracer[i] != 0)
		{
        	ar=suma[i]/tracer[i];
            cout<<i<< "  "<<ar<<endl;
        }
    } 
 return 0; 
}
