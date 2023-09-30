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

void levelorderTraversal(Node* root){
     queue<Node*> q;
     q.push(root); 
     q.push(NULL);

     while(!q.empty()){
         Node* temp = q.front();
         q.pop();
         
         if(temp == NULL){//old level is get complete travel
                cout<<endl;
                if(!q.empty()){//queue still has some child nodes
                    q.push(NULL);

                }
         }else{
            cout<<temp -> data<<" ";
         if(temp -> left){
            q.push(temp -> left);

         }
         if(temp -> right){
            q.push(temp -> right); 
         }
         }
     }
}

void inorder(Node* root){//left -> NULL -> right
    //base case
    if(root == NULL){
        return ;
    }

    inorder(root -> left);
    cout<<root -> data<<" ";

    inorder(root -> right);

}

void preorder(Node* root){//NULL -> left -> right
    //base case
    if(root == NULL){
        return ;
    }

    cout<<root -> data<<" ";
    preorder(root -> left);
    preorder(root -> right);

}

void postorder(Node* root){
    //base case
    if(root == NULL){
        return ;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
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
        cin>>data;
    }
}

Node* MinofBST(Node* root){
     Node* temp = root;

     while(temp -> left != NULL){
        temp = temp -> left;
     }

     return temp;
}

Node* MaxofBST(Node* root){
    Node* temp = root;

    while(temp -> right != NULL){
        temp = temp -> right;
    }

    return temp;
}

void findPreSuc(Node* root,Node* &pre, Node* &suc , int key){
      //base case
      if(root == NULL){
         return ;
      }
      
      if(root -> data == key){
           
           //the maximum value in left subtree is predecessor
           if(root -> left != NULL){
             Node* temp = root -> left;
             while(temp -> right){
                temp = temp -> right;
             }

             pre = temp;

           }

           //the minimum value in right subtreee is sucessor
           if(root -> right != NULL){
             Node* temp = root -> right;

             while(temp -> left){
                  temp = temp -> left;
             }

             suc = temp;
           }

           return ;
      }

      //if the key is smaller than root,s data, got to left subtree
      if(root -> data > key){
         
         suc = root;
         findPreSuc(root -> right, pre, suc, key);
      }
      else{
        findPreSuc(root -> left, pre, suc, key);
      }

}

Node* minvalue(Node* root){
      
      while(root -> left){
          root = root -> left;
      }

      return root;
}

Node* maxvalue(Node* root){

    while(root -> right){
        root = root -> right;
    }

    return root;
}

Node* deleteFromBST(Node* root, int val){
    //base case
    if(root == NULL){
        return root;
    }

    if(root -> data == val){
        //0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        //right child
        if(root -> right != NULL && root -> left == NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        //2 child
        if(root -> left != NULL && root -> right != NULL){
            int mini = minvalue(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }


    }else if(root -> data > val){
        //left part
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }else{
        //right part
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

int main(){
     
     Node* root = NULL;

     cout<<"Enter the data to create bst: "<<endl;
     takeInput(root);

     cout<<"The lavel order traversal of the tree is: "<<endl;
     levelorderTraversal(root);

     cout<<"The inorder traversal of the tree is:"<<endl;
     inorder(root);
     cout<<endl;
     cout<<"Minimum value in BST is:"<<endl;
     cout<<MinofBST(root) -> data<<endl;;

     cout<<"Maximum value in BST is:"<<endl;
     cout<<MaxofBST(root) -> data<<endl;

     deleteFromBST(root, 50);
     
     cout<<"The inorder traversal of the tree is:"<<endl;
     inorder(root);
     
     cout<<"The lavel order traversal of the tree is: "<<endl;
     levelorderTraversal(root);

}