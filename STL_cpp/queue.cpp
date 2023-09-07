#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue<string> l;

    l.push("sushant");
    l.push("rohit");
    l.push("manish");

    cout<<"the first element is : "<<l.front()<<endl;
    l.pop();

    cout<<"the first element is : "<<l.front()<<endl;

    cout<<"the size of the queue: "<<l.size()<<endl;


    return 0;
}