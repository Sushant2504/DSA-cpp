#include<iostream>
#include<map>
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
    //destructor
    ~Node(){
        int value = this -> data;
        
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;

    }
};

void insertNode(Node* &tail, int element, int d){
    //assuming that the element is present in the list

    //empty list
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp -> next = temp;
    }
    else{
        //non-empty list
        //assuming that a element is present in the list

        Node* curr = tail;

        while(curr -> data != element){

            curr = curr -> next;

        }

        //element found -> curr is representing element wala node
        Node* temp1 = new Node(d);
        temp1 -> next = curr -> next;
        curr -> next = temp1;

    }
}

void deleteNode(Node* &tail, int value){

    //empty list
    if(tail == NULL){
        cout<<"The list is empty, please check your list again."<<endl;
        return;
    }
    else{
        //non-empty case

        //assuming that the value given is present in the list
        Node* prev = tail;
        Node* curr = prev -> next;
        
        while(curr -> data != value){

            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        //1 Node Linked list
        if(curr == prev){
            tail = NULL;
        }
        //>=2 Node Linked list
        else if(tail == curr){
           tail = prev;
        }
        curr -> next = NULL;
        delete curr;

    }
}

void print(Node* tail){

    Node* temp = tail;
    if(tail == NULL){
        cout<<"List is a empty list"<<endl;
        return;
    }
    do{
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }while(tail != temp);
    cout<<endl;
}

bool isCircular(Node* &head){
        //base case
        if(head == NULL){
            return true;
        }

        // if(head -> next == head){
        //     return true;
        // }

        Node* temp = head -> next;

        while(temp != head && temp != NULL){
            temp = temp -> next;
        }

        if(temp == head){
            return true;
        }

        return false;
}

bool detectLoop(Node* head){

    if(head == NULL)
        return true;

    map<Node*, bool> visited;    

    Node* temp = head;

    while(temp != NULL){
        //It is point of the cycle
        if(visited[temp] == true){
           return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }    

    return false;

}

Node* floydDetection(Node* head){

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            cout<<"Present at" << slow -> next <<endl;
            return slow;
        }
    }

    return NULL;

}

Node* getstartingNode(Node* head){

    if(head == NULL)
      return NULL;

    Node* intersection = floydDetection(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;

    }  

    return slow;
}

int main(){
    
    Node* tail = NULL;
    
    //empty list me insert krre hai
    
    insertNode(tail, 5, 3);
    print(tail);
    /*
    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);
    */
    insertNode(tail, 3, 4);
    print(tail);
    

    if(floydDetection(tail)){
        cout<<"Linked list is circular in nature"<<endl;
    }
    else{
        cout<<"Linked list is not circular in nature"<<endl;
    }

    

}