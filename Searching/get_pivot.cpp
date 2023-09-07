#include <iostream>
using namespace std;

int getpivot(int arr[], int n){
    int s = 0, e = n - 1;
    int mid = s+(e-s)/2;

    while(s<e){

        if(arr[mid] > arr[0]){
            s = mid + 1;
        }

        if(arr[mid] < arr[0]){
            e = mid;
        }

        mid = s+(e-s)/2;
    }

    return arr[s];
}

int main(){

    int arr[] = {7,9,10,1,2,3};

    int ans = getpivot(arr, 6);
    cout<<"The pivot is:"<<ans<<endl;

    return 0; 
}