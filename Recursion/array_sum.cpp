#include <bits/stdc++.h>
using namespace std;


int SumArray(int *arr, int size){
   
   int p = size - 1;
   int sum = 0;
   if(size==0){
    return 0;
   }
   if(size==1){
      return arr[0];
   }
   

   int remainingPart = SumArray(arr+1, size-1);
   sum = arr[0] + remainingPart;

   return sum;
   
}


int main(){
     
     int arr[5] = {3,2,5,1,6};
     int size = 5;

     int ans = SumArray(arr, size);
     cout<<ans<<endl;

}