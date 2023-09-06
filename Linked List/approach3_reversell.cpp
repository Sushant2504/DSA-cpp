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

void insertAtHead(Node* &head, int d){
           
           //new node create
           Node* temp = new Node(d);
           temp -> next = head;
           head = temp;

}

Node* reverse1(Node* head){
    //base case
    if(head==NULL || head -> next == NULL){
        return head;
    }

    Node* smallhead = reverse1(head -> next);

    head -> next -> next = head;
    head -> next = NULL;
    
    return smallhead;

}

void print(Node* &head){
          Node* temp = head;

          while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;

          }
          cout<<endl;
}

int main() {
    Node* node1 = new Node(16);
    Node* head = node1;

    insertAtHead(head, 25);
    insertAtHead(head, 23);
    insertAtHead(head, 10);

    print(head);
    cout<<reverse1(head)<<endl;

    // print(head);

}