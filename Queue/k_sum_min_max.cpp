#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int k){
       deque<int> maxi(k);
       deque<int> mini(k);

       for(int i=0; i<k; i++){
         
         while(arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
         }

         while(arr[mini.back()] >= arr[i]){
            
         }
       }
}

int main(){
      
      int arr[6] = {3,2,-1,6,-4,5};
      int k = 4;
      cout<<solve(arr, 6, k)<<endl;

}