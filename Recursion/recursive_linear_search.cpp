#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int *arr, int size, int key){


    //base case
    if(size == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    }
    else{
        bool remainingPart = LinearSearch(arr+1,size-1,key);
        return remainingPart;
    }

}

int main(){
     
     int arr[5] = {3,2,5,1,6};
     int size = 5;
     int key = 2;

     int ans = LinearSearch(arr, size, key);
     if(ans){
    cout<<"YES"<<endl;
    }
    else
      cout<<"NO"<<endl;

}