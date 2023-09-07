#include <iostream>
#include <list>
using namespace std;


int main(){
    list<int> a;

    a.push_back(4);
    a.push_back(5);
    a.push_front(6);

    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;


    a.erase(a.begin());
    cout<<"after the erase"<<endl;
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;


    



    return 0;
}