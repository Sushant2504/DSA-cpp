#include <iostream>
using namespace std;

int main(){

    int n = 1;
    int i;
    cin>>i;

    while(n<=i){
        
        int j = 1;
        while(j<=n){
            cout<<j;

            j++;
        }
        cout<<endl;
        n++;
    }

    return 0;
}