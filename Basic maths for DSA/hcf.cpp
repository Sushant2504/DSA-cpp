#include <iostream>
using namespace std;

int Hcf(int n, int m){

    while(n != m){
        if(n > m){
            n = n - m;
        }
        else{
            m = m - n;
        }
        return n;
    }
}

int main(){
    
    int n,m;
    cout<<"Enter the two numbers: "<<endl;
    cin>>n>>m;

    cout<<"The HCF of the given two numbers is "<<Hcf(n,m)<<endl;
}