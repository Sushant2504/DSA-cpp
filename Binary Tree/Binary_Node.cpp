#include<bits/stdc++.h>
using namespace std;

class node{
    public:
     int data;
     node* left;
     node* right;

     node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
     }
};

node* buildFromLevelOrder(node* root){
    queue<node*> q;
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front(); 
        q.pop();
        
        cout<<"Enter left root node for: "<< temp -> data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout<<"Enter right root node for: "<< temp -> data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    } 
} 

node* BuildTree(node* root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting at the left of"<<data<<endl;
    root -> left = BuildTree(root -> left);
    cout<<"Enter data for inserting at the right of"<<data<<endl;
    root -> right = BuildTree(root -> right);
    return root;

}

void levelorderTraversal(node* root){
     queue<node*> q;
     q.push(root); 
     q.push(NULL);

     while(!q.empty()){
         node* temp = q.front();
         q.pop();
         
         if(temp == NULL){//old level is get complete travel
                cout<<endl;
                if(!q.empty()){//queue still has some child nodes
                    q.push(NULL);

                }
         }else{
            cout<<temp -> data<<endl;
         if(temp -> left){
            q.push(temp -> left);

         }
         if(temp -> right){
            q.push(temp -> right); 
         }
         }
     }
}

void inorder(node* root){//left -> NULL -> right
    //base case
    if(root == NULL){
        return ;
    }

    inorder(root -> left);
    cout<<root -> data<<" ";

    inorder(root -> right);

}

void preorder(node* root){//NULL -> left -> right
    //base case
    if(root == NULL){
        return ;
    }

    cout<<root -> data<<" ";
    preorder(root -> left);
    preorder(root -> right);

}

void postorder(node* root){
    //base case
    if(root == NULL){
        return ;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
}

int main(){

     node* root = NULL;

    //  buildFromLevelOrder(root);
    
    //To create the binary tree
    root = BuildTree(root);

    //level order
    cout<<"Printing the level order traversal output"<<endl;
    levelorderTraversal(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    /*
    cout<<"inorder traversal is: ";
    inorder(root);
    cout<<endl;

    cout<<"preorder traversel is: ";
    preorder(root);
    cout<<endl;

    cout<<"postorder traversel is: ";
    postorder(root);
    cout<<endl;
      */
} 