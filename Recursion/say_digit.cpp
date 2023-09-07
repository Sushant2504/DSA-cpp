#include <bits/stdc++.h>
using namespace std;

//Important concept of the recursion..........
//Reverse stack memory calling..........

void SayDigit(int n,string s[]){

    if(n==0){
        return ;
    }


    int p = n%10;
    n = n / 10;
    
    SayDigit(n,s);

    cout<<s[p]<<" ";


}

int main(){
    int n;
    cin>>n;

    string s[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    SayDigit(n,s);
}