#include<iostream>
#include<map>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
          this-> data = data;
          this-> next = NULL;
    }

    //destructor
    ~Node(){
      int value = this -> data;
      // this -> next = NULL;
      if(this -> next != NULL){
         delete next;
         this -> next = NULL;

      }
      cout<<"memory is free for node with data "<<value<<endl;
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

void insertAtPosition(Node* &head,int position,int d){
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

          temp -> next = nodetoinsert;

}
// delete node by position
void deleteNode(int position, Node* &head){
        
        //deleting the first or start node
        if(position == 1){
          Node* temp = head;
          head = head -> next;
          // memory free start node
          temp -> next = NULL;
          delete temp;
          return;

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
          
          prev -> next = curr -> next;
          curr -> next = NULL;
          delete curr;

        }
}
//delete node by value
void delNode(int value, Node* &head){
      
      if(value == head -> data){
        Node* temp = head;
        head = head -> next;
        //memory free start node
        temp -> next = NULL;
        delete temp;
        return;
      }
      else{
         // deleting any middle node or last node
         Node* curr = head;
         Node* prev = NULL;

         int cnt = 1;
         while(curr -> data != value){
          prev = curr;
          curr = curr -> next;
         }

         prev -> next = curr -> next;
         curr -> next = NULL;
         delete curr;

      }
}

void print(Node* &head){
          Node* temp = head;

          while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;

          }
          cout<<endl;
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
            cout<<"Present at " << slow -> data <<endl;
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

void removeloop(Node* head){

   if(head == NULL)
      return;

   Node* Startofloop = getstartingNode(head);
   Node* temp = Startofloop;

   while(temp -> next != Startofloop){
          temp = temp -> next;
   }

   temp -> next = NULL;


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

void sortLinkedlist(Node* &head){
    //base case
    if(head == NULL)
       return ;


    Node* curr = head;
    int len = getlength(head);

    for(int i=0; i<len; i++){
      
    }

}

int main(){

    Node* node1 = new Node(10);
    // cout<< node1 -> data <<endl;
    // cout<< node1 -> next <<endl;

    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtHead(head, 20);
    insertAtTail(tail, 16);
    // print(head);
    insertAtTail(tail, 20);
    cout<<"head "<< head -> data <<endl;
    cout<<"tail "<< tail -> data <<endl;
  
    insertAtPosition(head, 5, 22);
    cout<<"head "<< head -> data <<endl;
    cout<<"tail "<< tail -> data <<endl;
    print(head);
    // deleteNode(1, head);
    // delNode(22, head);
    tail -> next = head -> next -> next;
    if(floydDetection(tail)){
        cout<<"Linked list is circular in nature"<<endl;
    }
    else{
        cout<<"Linked list is not circular in nature"<<endl;
    }
    
    Node* loop = getstartingNode(head);
    cout<<"The starting node is "<< loop -> data <<endl;

    removeloop(head);
    print(head);

}