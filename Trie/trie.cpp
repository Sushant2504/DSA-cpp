#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
      char data;
      TrieNode* children[26];
      bool isTerminal;

      TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
      }
};

class Trie{
     public:
      TrieNode* root;

      Trie(){
        root = new TrieNode('\0');
      }

      void insertUtil(TrieNode* root, string word){
           //base case
           if(word.length() == 0){
             root -> isTerminal = true;
             return ;
           }
           //assumption, word will be in the caps
           int index = word[0] - 'a';
           TrieNode* child;

            //present
            if(root -> children[index] != NULL){
                child = root -> children[index];// it is present then go to next
            }
            else{
                //absent
                child = new TrieNode(word[0]); // for absent case create node for that character
                root -> children[index] = child;
            }

            //recursion
            insertUtil(child, word.substr(1));

      }

      void insertWord(string word){
        insertUtil(root, word);
      }

      bool searchUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            return root -> isTerminal;
        } 

        int index = word[0] - 'a';
        TrieNode* child;
        
        //element is present
        if(root -> children[index] != NULL){
           child = root -> children[index];
        }
        else{
            //element is absent
            return false;
        }

        return searchUtil(child, word.substr(1));

      }

      bool searchWord(string word){
        return searchUtil(root, word);
      }

    bool isEmpty(TrieNode* root)
    {
    for (int i = 0; i < 26; i++)
        if (root->children[i])
            return false;
    return true;
    }
    //function to remove the word
      void deleteUtil(TrieNode* root, string word){
        if(word.length() == 0){
            if(root -> isTerminal){
                root -> isTerminal = true;
            }else if(isEmpty(root)){
                delete(root);
                root = NULL;
            }
        } 

        int index = word[0] - 'A';
        TrieNode* child;
        
        //element is present
        if(root -> children[index] != NULL){
           child = root -> children[index];
        }
        else{
            //element is absent
           return ;
        }

        return deleteUtil(child, word.substr(1));

        if (isEmpty(root) && root->isTerminal == false) {
        delete (root);
        root = NULL;
        }
 

      }

      void deleteWord(string word){
         
              deleteUtil(root, word);
      }
};

int main(){
    
    Trie* T = new Trie();

    T->insertWord("coding");
    T->insertWord("coly");
    T->insertWord("code");

    cout<<"word is present or Not "<< T->searchWord("coding") << endl;
    T -> deleteWord("TIME");
    cout<<"word is present or Not "<< T->searchWord("code") << endl;
}