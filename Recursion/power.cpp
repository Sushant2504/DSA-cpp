#include <bits/stdc++.h>
using namespace std;

int power(int a,int b){

    //base case.....
    if(b==0){
      return 1;
    }

    if(b==1){
        return a;
    }

    //Recursive case.....
    if(b%2==0){
        return pow(a,b/2)*pow(a,b/2);
    }
    else{
        return a * pow(a,b/2)*pow(a,b/2);
    }
}

int main(){

    int a,b;
    cin >> a >> b;

    int ans = power(a,b);

    cout<< "Answer is " << ans <<endl;
}