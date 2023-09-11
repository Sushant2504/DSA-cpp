#include<bits/stdc++.h>
using namespace std;

class Heap{
    public: 
       int arr[100];
       int size = 0;
        
       Heap(){
         arr[0] = -1;
         size = 0;
       }

       void insert(int val){
           size = size + 1;
           int index = size;
           arr[index] = val;

           while(index > 1){
              int parent = index/2;

              if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
              }else{
                return;
              }
           }
            
       }

       void print(){
        for(int i=0; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
       }

       void deletefromHeap(){
        if(size == 0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        //step1: put last element at the first place
        arr[1] = arr[size];
        //step2: to delete the the first element
        size--;
        //step 3: place the first element to its correct position
        //take root node to its correct position
        int i = 1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;


            if(leftIndex < size && arr[i] < arr[leftIndex]){

                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;  
            }
            else{
                return;
            }
        }
       }
};

//V. important
//Heapify Algorithm
//for the max Heap
void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

//for min Heap
void heapify1(vector<int> &arr, int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify1(arr, n, smallest);
    }
}

//Heap Sort
void HeapSort(int arr[], int n){

    while(n > 1){
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);

    }

}

int main(){
    
    Heap h1;

    h1.insert(40);
    h1.insert(50);
    h1.insert(70);
    h1.insert(55);
    h1.insert(80);
    h1.print();

    h1.deletefromHeap();
    h1.print();

    int arr[6] = {-1,40,50,70,55,80};
    int n = 5;
    for(int i=(n/2); i>0; i--){
        heapify(arr, n, i);
    }

    cout<<"printing the array now"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    HeapSort(arr, n);
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"using priority queue here: "<<endl;
    //max Heap
    priority_queue<int> pq;
    //min Heap
    priority_queue<int, vector<int>, greater<int>> minheap;


}