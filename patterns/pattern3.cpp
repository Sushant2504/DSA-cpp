#include <iostream>
using namespace std;

int main(){

    int n = 1;
    int i;
    cin>>i;

    int count = 1;

    while(n<=i){

        int j = 1;
        while(j<=i){
            cout<<count<<" ";
            count += 1;

            j++;
        }
        cout<<endl;
        n++;
    }

}