#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr, int start,int end, int k){

    if(start > end){
        return false; 
    }

    int mid = start+(end - start)/2;
    
    if(arr[mid]==k){
        return true; 
    }

    if(arr[mid] > k){
        return binarySearch(arr, start,mid-1,k);

    }
    else{
        return binarySearch(arr, mid+1,end,k);
    }

    
}



int main(){
     
     int arr[5] = {1,2,3,4,5};
     int size = 5;
     int key = 2;

     bool ans = binarySearch(arr,0,4,key);
     if(ans){
      cout<<"YES"<<endl;
    }
    else
      cout<<"NO"<<endl;

}