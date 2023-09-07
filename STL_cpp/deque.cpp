#include <iostream>
#include <deque>
using namespace std;

int main(){

    deque<int> a;

    a.push_back(2);
    a.push_back(4);
    a.push_back(5);

    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;

    // a.pop_back();
    a.pop_front();
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"before the erase"<<a.size()<<endl;
    a.erase(a.begin(), a.begin()+1);
    cout<<"after the erase"<<a.size()<<endl;

    for(int i:a){
        cout<<i<<" ";
    }

}