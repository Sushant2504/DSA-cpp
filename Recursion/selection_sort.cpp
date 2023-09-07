#include <bits/stdc++.h>
using namespace std;


void selectionsort(int arr[],int n,int s){
     
    //  int a = 0;
    //base case...
    if(s==n){
        return ;
    }

        int midindex = s;
        for(int j=s+1; j<n; j++){
            if(arr[j] < arr[midindex]){
                midindex = j;
            }

        }

        swap(arr[s],arr[midindex]);

        // int temp = arr[s];
        // arr[s] = arr[midindex];
        // arr[midindex] = temp; 
     
    
    //  a++;
     selectionsort(arr,n,++s);

}

int main(){


    int arr[5] = {1,3,5,2,4};

    selectionsort(arr,5,0);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";

    }
}