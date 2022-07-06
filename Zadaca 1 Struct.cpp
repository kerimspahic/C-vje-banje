#include <iostream>
#include <cstring>
using namespace std;

struct student { 
	char ime[10]; 
	char prezime[15]; 
	int predmet; 
	int ocjena; 
} studenti[100]; 

int main (){


	int brojStudenata;
	cout<<"Unesi broj studenata: ";
	cin>>brojStudenata;

	for(int i=0; i<brojStudenata; i++){

	do{
		cin>>studenti[i].predmet;
	}while(studenti[i].predmet <= 0 || studenti[i].predmet >= 11);
	cout<<"Unesi  ocjenu "<<i+1<<". studenta: ";
	do{
		cin>>studenti[i].ocjena;
	}while(studenti[i].ocjena <= 0 || studenti[i].ocjena >= 11);
	}
	
	/*
	for(int i=0; i<brojStudenata; i++){
		cout<<studenti[i].ime<<studenti[i].prezime<<" u predmetu: "<<studenti[i].predmet<<" ima ocjenu "<<studenti[i].ocjena<<"."<<endl;
	}
	*/
	double arSredinaPredmeta[10]={0},brojPredmeta[10]={0};
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < brojStudenata; j++){
			if(studenti[j].predmet == i){
				arSredinaPredmeta[i]=arSredinaPredmeta[i]+studenti[j].ocjena;
				brojPredmeta[i]++;
			}
		}
	}
	cout<<endl<<arSredinaPredmeta[3]<<"  "<<brojPredmeta[3]<<endl;
	
	for (int i=0;i<10;i++){
		if(brojPredmeta[i] != 0){
			cout<<"Prosjecna ocjena za "<<i<<" predmet je: "<<arSredinaPredmeta[i]/brojPredmeta[i]<<endl;
		}
	}
return 0;
}

