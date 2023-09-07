#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    } 
};

class Queue{


};
int main(){
    //create a queue
    queue<int> q;

    q.push(78);
    q.push(19);
    q.push(24);


    q.pop();

    
    
    cout<<q.size()<<endl;

    cout<<q.front()<<endl;

    if(q.empty()){
        cout<<"Queue is Empty."<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }
}