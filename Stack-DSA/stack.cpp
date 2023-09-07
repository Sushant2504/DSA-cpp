#include<iostream>
#include<stack>
using namespace std;

//stack implementation using array
class Stack{
   //properties
   public:
       int *arr;
       int top;
       int size;


    //behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    } 

    void push(int element){
         if(size - top > 1){
            top++;
            arr[top] = element;
         } 
         else{
            cout<<"Stack Overflow"<<endl;
         }
    }  

    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
         if(top >= 0 && top < size){
            return arr[top];
         }else{
            cout<<"Stack is Empty"<<endl;
            return -1;
         }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        } 
    }

};   

//stack implementation using Linked list
class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    } 
};

// void insertAtHead(Node* &head, int d){
           
//            //new node create
//            Node* temp = new Node(d);
//            temp -> next = head;
//            head = temp;

// }

class Stack1{
       public:
       Node* top;

       Stack1(){
        top = NULL;
       }

       void push(int element){
           Node* temp = new Node(element);

           if(!temp){
            cout<<"Stack Overflow"<<endl;
           }

           temp -> data = element;

           temp -> next = top;

           top = temp;

       }

       bool empty(){

        return top == NULL;
       }

       int peek(){
           
           if(!empty()){
               return top -> data;
           }else{
               exit(1);
           }
       }
       void pop(){
           Node* temp;

           if(top == NULL){
               cout<<"Stack Underflow"<<endl;
               exit(1);
           }else{

            temp = top;

            top = top -> next;

            free(temp);
           }


       }
      
};

int main(){

    Stack1 st;

    st.push(34);
    st.push(60);
    st.push(25);

    cout<<st.peek()<<endl;
    

    st.pop();
    st.pop();

    if(st.empty()){
        cout<<"The Stack is empty"<<endl;
    }else{
        cout<<"The Stack is not empty"<<endl;
    }

     
    /*stack<int> num;
    
    //push operation
    num.push(12);
    num.push(14);
    num.push(15);
    
    //top operation
    cout<<"The top element of the stack is "<<num.top()<<endl;
    

    //pop operation
    num.pop();
    num.pop();
    num.pop();

    if(num.empty()){
        cout<<"The stack is empty"<<endl;
    }else{
        cout<<"The stack is not empty"<<endl;
    }
    */
}