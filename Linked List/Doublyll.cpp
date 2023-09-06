#include<iostream>
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

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
         cout<< temp -> data <<" ";
         temp = temp -> next;
    }
    cout<<endl;
}

void deleteNode(int position, Node* &head){
        
        //deleting the first or start node
        if(position == 1){
          Node* temp = head;
          temp -> next -> prev = NULL;
          head = temp -> next;
          temp -> next = NULL;
          delete temp;
        
        }
        else{
          //deleting any middle node or last node
          Node* curr = head;
          Node* prev = NULL;

          int cnt = 1;
          while(cnt <= position){
             prev = curr;
             curr = curr -> next;
          }
          
          curr -> prev = NULL;
          prev -> next = curr -> next;
          curr -> next = NULL;
          delete curr;

        }
}

int getlength(Node* &head){
    Node* temp = head;
    
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }

    return len;
}

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

int main(){
    Node* node1 = new Node(12);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<getlength(head)<<endl;
    cout<<" head "<<head -> data<<endl;
    cout<<" tail "<<tail -> data<<endl;

    insertAtHead(head, 14);
    cout<<" head "<<head -> data<<endl;
    cout<<" tail "<<tail -> data<<endl;

    insertAtTail(tail, 30);
    cout<<" head "<<head -> data<<endl;
    cout<<" tail "<<tail -> data<<endl;

    insertAtPosition(tail, head, 2, 100);
    cout<<" head "<<head -> data<<endl;
    cout<<" tail "<<tail -> data<<endl;
    print(head);

    insertAtPosition(tail, head, 1, 101);
    cout<<" head "<<head -> data<<endl;
    cout<<" tail "<<tail -> data<<endl;
    deleteNode(1, head);
    print(head);
    cout<<endl;
    deleteNode(3, head);
    print(head);


}    
    