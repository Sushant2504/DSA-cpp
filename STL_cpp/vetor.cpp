#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v;

   
    cout<<"Size--> "<<v.capacity()<<endl;

    v.push_back(7);
    cout<<"Size--> "<<v.capacity()<<endl;

    v.push_back(6);
    cout<<"Size--> "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Size--> "<<v.capacity()<<endl;

    v.push_back(12);
    cout<<"Size--> "<<v.capacity()<<endl;

    vector<int> last(v);
    for(int i:last){
        cout<<i<<" ";
    }

    cout<<"the second element in the vector:- "<<v.at(2)<<endl;

    cout<<"front"<<v.front()<<endl;
    cout<<"back"<<v.back()<<endl;

    v.pop_back();
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<"Size--> "<<v.capacity()<<endl;

    cout<<"before clear size "<<v.size();
    v.clear();
    cout<<"after clear size "<<v.size();


    return 0;

}