#include <iostream>
using namespace std;

bool linearsearch(int arr[], int n, int key){

    for(int j=0; j<n; j++){
        if(key == arr[j]){
            return 1;
        }
    }

    return 0;
}

int main(){
    

    int size, key;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;

    int arr[size];

    for(int i=0; i<size; i++){

        cin>>arr[i];
    }

    cout<<"Enter the key to search: "<<endl;
    cin>>key;

    int found = linearsearch(arr, size, key);

    if(found){
        cout<<"The key is found."<<endl;
    }
    else{
        cout<<"The key is not found."<<endl;
    }

return 0;
}