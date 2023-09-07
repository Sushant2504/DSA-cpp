#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key){

    int start = 0, end = size-1;
    int mid = (start + (end - start)/2);


    while(start < end){
        
        if(key==arr[mid]){
            return mid;
        }

        if(key > arr[mid]){
            start = mid + 1;
        }

        else{
            end = mid - 1;
        }
    }

    return -1;
}


int main(){

    int size, key;

    cout<<"Enter the size of the array:"<<endl;
    cin>>size;

    int arr[size];

    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    cout<<"Enter the key to find:"<<endl;
    cin>>key;

    int index = BinarySearch(arr, size, key);

    cout<<"The index of the "<<key<<" is: "<<index<<endl;

    return 0;
}