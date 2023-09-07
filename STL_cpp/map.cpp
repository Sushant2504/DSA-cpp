#include <iostream>
#include <map>
using namespace std;


int main(){

    map<int, string> m;

    m[1] = "Sushant";
    m[5] = "rohit";
    m[8] = "manish";

    m.insert({3,"Bheem"});

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;
    

    cout<<"finding 8--> "<<m.count(8)<<endl;

    m.erase(8);
    cout<<"after the erase"<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;

    



    return 0;
}