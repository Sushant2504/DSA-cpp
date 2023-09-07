#include <iostream>
using namespace std;

// Use case :- This type of sorting is used when the size of the array is very small (4-8)
void Selectionsort(int arr[], int n){

    for(int i=0; i<n-1; i++){
       int  midIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[midIndex]){
                midIndex = j; 
            }
        }

        swap(arr[i], arr[midIndex]);
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Selectionsort(arr, n);

    cout<<"The array after sorting is done:"<<endl;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
    
}