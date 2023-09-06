#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int row = 1;

    while(row<=n){

        int j = 1;
        while(j<=row){
            
            char ch = 'A' + row - 1;
            cout<<ch;
            j++;
        }
        cout<<endl;
        row++;
    }

    return 0;
}