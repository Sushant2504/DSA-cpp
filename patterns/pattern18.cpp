#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int i = 1;
    while(i<=n){

        int j = 1;
        int count = i;
        int k = n - i + 1;

        while(j<=(n-i+1)){
            cout<<j;
            j++;
            
        }
        
        int start = i - 1;
        while(start){
            cout<<"*";
            start--;
        } 

        int end = i - 1;
        while(end){
            cout<<"*";
            end--;
        } 
         int z = 1;
         while(z<=(n-i+1)){
            cout<<k;
            k--;
            z++;
            
        }

        cout<<endl;
        i++;
    }

    return 0;
} 

        