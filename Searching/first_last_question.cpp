#include <iostream>
using namespace std;

// Q] the index of the first and last element of the sorted array
int firstoccurance(int arr[], int n, int key){

    int s=0, e=n-1;
    int mid = (s+(e - s)/2);
    

    while(s<=e){

        if(arr[mid] == key){
            return mid;
        }

        if(arr[mid] < key){
            s = mid + 1;
        }

        if(arr[mid] > key){
            e = mid - 1;
        }

        mid = (s+(e-s)/2);
    }

    return -1;
}

int lastoccurance(int arr[], int n, int key){

    int s = n-1 , e = 0;
    int mid = (e+(s-e)/2);
    int ans;

    while(s >= e){

        if(arr[mid]==key){
            ans = mid;
            e = mid + 1;
        }

        if(arr[mid] > key){
            s = mid - 1;

        }


        mid = (e+(s - e)/2);
    }

    return ans;
}

int main(){

    int size,key;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;

    int arr[size];
    cout<<"Enter the elements of the array: "<<endl;

    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    cout<<"Enter the key to find: "<<endl;
    cin>>key;

    int first = firstoccurance(arr, size, key);
    int last = lastoccurance(arr, size, key);

    cout<<"The required indices are: "<<first<<" and "<<last<<endl;


    return 0;
}