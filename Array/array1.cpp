#include <iostream>
using namespace std;


int main(){

    int n[10] = {1};
    int k = 10;

    for(int i=0;i<k;i++){

        n[i] = n[0];

        cout<<n[i]<<" ";
    }

    return 0;
}