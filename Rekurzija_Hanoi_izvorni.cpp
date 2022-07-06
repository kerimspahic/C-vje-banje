#include <iostream> 
using namespace std; 
 
void pomakni_disk (char sa_kule, char na_kulu){        
cout<<"\t\t\t"<<sa_kule<<" -> "<<na_kulu<<endl;  
}  
 
void pomakni_kulu (int n, char A, char B, char C){       
	if (n > 0){          
	pomakni_kulu (n-1, A, C, B);          
	pomakni_disk (A, B);          
	pomakni_kulu (n-1, C, B, A);      
	}
} 
 
int main (){     
int n;    
cout<<"\n\n\tBroj diskova: ";    
cin>>n;    
system("cls");    
cout<<"\n\n\tSlijed poteza za "<<n<<" diskova: \n\n";    
	pomakni_kulu (n, 'A','B','C');     
cout<<"\n\n";    

system ("pause");    
return 0;  
}
