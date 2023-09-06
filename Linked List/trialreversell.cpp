#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
           
           //new node create
           Node* temp = new Node(d);
           temp -> next = head;
           head = temp;

}

void insertAtTail(Node* &tail, int d){

           Node* temp = new Node(d);
           tail -> next = temp;
           tail = tail -> next;
}    

void print(Node* &head){
          Node* temp = head;

          while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;

          }
          cout<<endl;
}

Node* reverse(Node* &head){
        if(head == NULL || head -> next == NULL){
            return head;
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;

        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }

        head = prev;
}

int main(){
     
     Node* node1 = new Node(13);

     Node* head = node1;
     Node* tail = node1;

     insertAtTail(tail, 12);
     insertAtTail(tail, 10);
     print(head);
     reverse(head);

     print(head);
     
}