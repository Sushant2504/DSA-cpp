#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int i = 0;
    while(i<n){

        int j = n - i;
        // int space = n - i;
        // while(space){

        //     cout<<" ";
        //     space = space - 1;
        // }

        while(j>=1){
            cout<<"*";
            j--;
        }
        cout<<endl;
        i++;
    }

    return 0;
}