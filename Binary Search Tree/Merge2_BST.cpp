#include<bits/stdc++.h>
using namespace std;

class Node{

public:    
    int data;
    Node* left;
    Node* right;
    

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

void inorder(Node* root){
    //base case
    if(root == NULL){
        return ;
    }

    inorder(root -> left);
    cout<<root -> data<<endl;
    inorder(root -> right);
}

Node* insertIntoBST(Node* &root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root -> data){
        insertIntoBST(root -> right, d);
    }
    else{
        insertIntoBST(root -> left, d);
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        insertIntoBST(root, data);
        cout<<"Enter the data to insert"<<endl;
        cin>>data;
    }
}

void convertintosortedDLL(Node* root, Node* &head){
    //base case
    if(root == NULL){
        return;
    }
    //we put the right part of root node for sorting by recursion
    convertintosortedDLL(root -> right, head);

    // attach right sorted part to the root node
    root -> right = head;
    if(head -> left != NULL){
        head -> left = root;
    }

    head = root;
     // we put the left part of the root node for sorting by recursion
    convertintosortedDLL(root -> left, head);
    // return head;


}

Node* mergeLinkedList(Node* head1, Node* head2){

    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL){

        if(head1 -> data < head2 -> data){
             if(head == NULL){
                 head = head1;
                 tail = head1;
                 head1 = head1 -> right;

             }
             else{
                 tail -> right = head1;
                 head1 -> left = tail;
                 tail = head1;
                 head1 = head -> right;
             }
        }
        else{
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1 -> right;
             }
             else{
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head2 = head2 -> right;
             }

        }
    }

    while(head1 != NULL){
        tail -> right = head1;
        head1 -> left = tail;
        tail = head1;
        head1 = head -> right;
    }
 
    while(head2 != NULL){
        tail -> right = head2;
        head2 -> left = tail;
        tail = head2;
        head2 = head2 -> right;
    }

    return head;
}

int getlength(Node* root){

    Node* temp = root;
    int cnt = 0;

    while(temp != NULL){
         cnt++;
         temp = temp -> right;
    }

    return cnt;
}

Node* convertLLtoBST(Node* head, int n){
    //base case
    if(n <= 0 || head == NULL){
        return NULL;
    }     

    Node* left = convertLLtoBST(head, (n/2));
    
    Node* root = head;
    root -> left = head;

    head = head -> right;


    root -> right = convertLLtoBST(head, (n-(n/2)-1));
    return root;
}

Node* mergeBST(Node *root1, Node *root2)
{
     //step1: convert BST into Sorted DLL in-place 
     Node* head1 = NULL;
     convertintosortedDLL(root1, head1);
     head1 -> left = NULL;

     Node* head2 = NULL;
     convertintosortedDLL(root2, head2);
     head2 -> left  = NULL;
     

     //step2: merge sorted Linked List
     Node* head = mergeLinkedList(head1, head2);

     //step3: convert sorted LL into BST
     return convertLLtoBST(head, getlength(head));
     

}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;
    takeInput(root1);
    takeInput(root2);


    Node* root = mergeBST(root1, root2);
    inorder(root);
}