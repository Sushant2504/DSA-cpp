#include <iostream>
using namespace std;

int alternate(int arr[], int n){
    int first = 0;
    int second = 1;
    
    for(int i=0; i<n; i++){
        if(second < n){
        swap(arr[first], arr[second]);
        first = first + 2;
        second = second + 2;
        } 
    }
}

int print(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int size;
    cin>>size;

    int arr[size];

    for(int i=0; i<size; i++){

        cin>>arr[i];
    }
    
    print(arr, size);
    cout<<endl;
    alternate(arr, size);
    print(arr, size);

    return 0;

}