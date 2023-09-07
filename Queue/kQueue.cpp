#include<bits/stdc++.h>
using namespace std;

//Question: k Queue into a single array

class kQueue{
     public:
      int k;
      int n;
      int *arr;
      int *front;
      int *rear;
      int freeSpot;
      int *next;

    public:
      kQueue(int n, int k){
        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        arr = new int[n];
        next = new int[n];
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        freeSpot = 0;

      }  

      void enqueue(int data, int qn){
        //check for overflow
        if(freeSpot == -1){
            cout<<"no empty space is available"<<endl;
            return;
        }

        //find first free index
        int index = freeSpot;

        //update the freeSpot
        freeSpot = next[index];

        //check whether first element
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }else{//not a first element
          //link new element to the prev element
          next[rear[qn-1]] = index;

        }

        //update next
          next[index] = -1;

        //update rear
          rear[qn-1] = index;

        //push element
          arr[index] = data;    
      }

      int deque(int qn){
        //underflow
        if(front[qn-1]==-1){
            cout<<"Queue is Underflow"<<endl;
            return -1;
        }

        //find index to pop
        int index = front[qn-1];

        //front ko aage badhavo
        front[qn-1] = next[index];

        //manage the freeSlots
        next[index] = freeSpot;

        freeSpot = index;
        return arr[index];

      }
 
};

int main(){
    kQueue q(10,3);

    q.enqueue(10, 1);
    q.enqueue(25, 2);
    q.enqueue(34, 1);

    cout<<q.deque(1)<<endl;
    cout<<q.deque(2)<<endl;
    cout<<q.deque(1)<<endl;

}