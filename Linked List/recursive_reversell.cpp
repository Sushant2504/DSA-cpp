#include<bits/stdc++.h>
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

void reverse(Node* &head, Node* &curr, Node* &prev){

    //base case
    if(curr == NULL){
        head = prev;
        return;
    }
    
    Node* forward = curr -> next;
    reverse(head, forward, prev);
    curr -> next = prev;    

}

Node* reverse(Node* &head){

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    reverse(head, curr, prev);
    return head;


        /*if(head == NULL || head -> next == NULL){
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

        head = prev;*/
}

void print(Node* &head){
          Node* temp = head;

          while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;

          }
          cout<<endl;
}

void insertAtHead(Node* &head, int d){
           
           //new node create
           Node* temp = new Node(d);
           temp -> next = head;
           head = temp;

}

int main(){

    Node* node1 = new Node(13);
    Node* head = node1;

    insertAtHead(head, 15);
    print(head);

    cout<<reverse(head)<<endl;
    print(head);
    
}