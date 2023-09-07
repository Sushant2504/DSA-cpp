#include <iostream>
#include <set>
using namespace std;


int main(){

    set<int> s;

    s.insert(9);
    s.insert(5);
    s.insert(6);
    s.insert(23);

    for(int i:s){
        cout<<i<<" ";
    }cout<<endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);

    for(int i:s){
        cout<<i<<" ";
    }cout<<endl;

    set<int>::iterator itr = s.find(6);

    cout<<"The value of the itr: "<<*it<<endl;

}