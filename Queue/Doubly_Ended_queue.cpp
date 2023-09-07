#include<bits/stdc++.h>
using namespace std;

int main(){
    
    deque<int> d;

    d.push_front(12);
    d.push_front(25);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
}