#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int count = 1;
    int i = 1;
    while(i<=n){

        int j = 1;
        int space = n - i;
        while(space){

            cout<<" ";
            space = space - 1;
        }

        while(j<=i){
            cout<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}