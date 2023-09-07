#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<string> a;

    a.push("sushant");
    a.push("rohit");
    a.push("manish");

    cout<<"the top element is: "<<a.top()<<endl;

    a.pop();

     cout<<"the top element is: "<<a.top()<<endl;

    cout<<"the size of the stck is: "<<a.size()<<endl; 

    cout<<"Empty or not"<<a.empty();






    return 0;
}