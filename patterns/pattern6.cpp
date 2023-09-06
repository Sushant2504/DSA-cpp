#include <iostream>
using namespace std;

int main()
{
    int n = 1;

    int i;
    cin>>i;

    while(n<=i){

        int j = 1;
        while(j<=n){
            cout<<(n-j+1);

            j++;
        }

        cout<<endl;
        n++;
    }
}