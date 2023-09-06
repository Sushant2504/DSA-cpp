#include <iostream>
using namespace std;

int main()
{
    
    int n = 1;

    
    int i;
    cin>>i;

    while(n<=i){

        int m = 1;

        while(m<=i){
            cout<<i-m+1;

            m++;
        }
       cout<<endl;
        n++;
    }
}