// reverse the linked list in the k number groups

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

};

Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node* temp = head;
    Node* forward = NULL;
    Node* prev = NULL;
    int count = 0;

    while(temp != NULL){
        forward = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = forward;
        count++;
        if(count % k == 0){
            continue;
        }

    }

}