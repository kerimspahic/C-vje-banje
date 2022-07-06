#include <iostream> 
using namespace std; 
class temp 
{ 
    private: 
        int pod1; 
        float pod2; 
    public: 
       void int_pod(int d){ 
          pod1=d; 
          cout<<"Broj: "<<pod1; 
         } 
       float float_pod(){ 
           cout<<"\nUnesi podatak: "; 
           cin>>pod2; 
           return pod2; 
         } 
}; 
 int main(){ 
      temp obj1, obj2; 
      obj1.int_pod(12); 
      cout<<"Vaš unos "<<obj2.float_pod(); 
      return 0; 
 }
