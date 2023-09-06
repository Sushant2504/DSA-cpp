#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int d){
       this -> data = d;
       this -> prev = NULL;
       this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};


void insertAtHead(Node* &head, int d){
    cout<<"the value of the head is"<< head -> data <<endl;
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    else{
    Node* temp = new Node(d);
    
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }

}

void insertAtTail(Node* &tail,int d){

    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
    }
    Node* temp = new Node(d);

    tail -> next = temp;
    temp -> prev = tail;

    tail = temp;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){

    //insert At Start
    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    
    Node* temp = head;
          if(position == 1){
            insertAtHead(head, d);
            return;
          }

          if(temp -> next == NULL){
             insertAtTail(head, d);
             return;
          }
          
          // Node* temp = head;
          int cnt = 1;
          while(cnt < position-1){
            temp = temp -> next;
            cnt++;
          }

          //creating a node for d
          Node* nodetoinsert = new Node(d);
          
          nodetoinsert -> next = temp -> next;
          temp -> next -> prev = nodetoinsert;
          temp -> next = nodetoinsert;
          nodetoinsert -> prev = temp;

}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
         cout<< temp -> data <<" ";
         temp = temp -> next;
    }
    cout<<endl;
}

Node* reverse(Node* &head){

    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* curr = head;
    Node* temp = NULL;
    Node* forward = NULL;
    

    while(curr != NULL){
       temp = curr -> prev;
       forward = curr -> next;
       curr -> prev = forward;
       curr -> next = temp;
       curr = forward;
    }

    head = temp -> prev;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;

    insertAtHead(head, 15);
    insertAtHead(head, 25);
    insertAtHead(head, 30);
    print(head);
    reverse(head);

    print(head);
}

