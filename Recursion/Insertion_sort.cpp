#include <bits/stdc++.h>
using namespace std;

void insertionsort(int arr[],int n,int i){

  if(i==n){
    return ;
  } 

   int j = i-1;
   int temp = arr[i];
   //base case....
   
   while(j>=0){
   if(arr[j] > temp){
        arr[j+1] = arr[j--];
        // insertionsort(arr,n,++i);
    }
    else{
        break;
    }
    
   }
   arr[j+1] = temp;

    insertionsort(arr,n,++i);


}


int main(){
    
    int arr[5] = {1,3,5,2,4};

    insertionsort(arr,5,1);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";

    } 
}