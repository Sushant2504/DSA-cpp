#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;

    int arr[size];

    for(int j=0; j<size; j++){
        cin>>arr[j];
    }

    int sum =0;

    for(int i=0; i<size; i++){

        sum = sum + arr[i];
    }

    cout<<"The sum of the all the elements of the array is: "<<sum<<endl;

    return 0;
}