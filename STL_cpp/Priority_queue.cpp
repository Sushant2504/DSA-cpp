#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    //max heap
    priority_queue<int> maxi;

    //min-heap
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(1);
    maxi.push(4);
    maxi.push(6);
    maxi.push(7);
    cout<<"the size of the priority queue: "<<maxi.size()<<endl;

    int n = maxi.size();
    for(int i=0; i<n; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;
    

    mini.push(9);
    mini.push(4);
    mini.push(6);
    mini.push(0);
    mini.push(8);

    int m = mini.size();
    for(int i=0; i<m; i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;

    cout<<"size--> "<<mini.size()<<endl;


}