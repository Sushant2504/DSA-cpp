#include <iostream>
using namespace std;


//Use case:- It is used to sort small arrays in general.
void Bubblesort(int arr[], int n){

    for(int i=1; i<n; i++){

        bool swaap = false;
        for(int j=0; j<n-i; j++){

            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swaap = true;
            }    

        }
        if(swaap == false){
                break;
            }
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

    Bubblesort(arr, n);

    cout<<"The values of the array after the sorting is:"<<endl;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}