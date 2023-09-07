#include <iostream>
using namespace std;

int main(){

     int i = 5;

     int *ptr = 0;

     ptr = &i;

     cout<<ptr<<endl;
     cout<<*ptr<<endl;
 // coping a pointer into the another pointer.......
     int *q = ptr;

     cout<<*ptr<<" "<<*q<<endl;
     cout<<ptr<<" "<<q<<endl;

     // pointer arithmetic..............
     int *p = &i;
    
    cout<<"Before the value of pointer:"<<*p<<endl;
    *p = *p + 1;
    cout<<"After the value of the pointer:"<<*p<<endl; 
    
    cout<<"Before the value of pointer:"<<p<<endl;
    p = p + 1;
    cout<<"After the value of the pointer:"<<p<<endl; 

}