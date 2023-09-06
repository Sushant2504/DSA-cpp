#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    

    int row = 1;

    while(row<=n){
        
        
        int j = 1;
        while(j<=n){
    
            char count = 'A' + row + j - 2;
            cout<<count;
           

            j++;
        }
        cout<<endl;
        row++;
    }

    return 0;
}