#include <bits/stdc++.h>
using namespace std;

void ReverseString(string& str,int s,int e){
    if(s > e){
        return ;
    }
    
    int a = s;
    int b = e;

    swap(str[s],str[e]);
    ReverseString(str,a+1,b-1);
}

int main(){

    string s = "sushant";
    int size = 7;

    ReverseString(s,0,size-1);

    cout<<s<<endl;

}