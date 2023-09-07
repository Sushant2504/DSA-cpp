#include <iostream>
using namespace std;

void insertionSort(int n, int arr[]){
    
    for(int i=1; i<n; i++){
        int temp = arr[i];

        int j = i-1;
        while(j>=0){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            j--;
             
        }

        arr[j+1] = temp;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array:-"<<endl;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    insertionSort(n, arr);

    cout<<"The values of the array after the sorting"<<endl;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}