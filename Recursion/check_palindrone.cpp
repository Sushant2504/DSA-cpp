#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str, int s, int e){
    //base case...
    if(e<=0){
        return true;
    }
    
    if(s>e){
        return true;
    }
    //Recursive call.........
    if(str[s]==str[e]){
        s++;
        e--;
        checkPalindrome(str,s,e);
    }
    else
      return false;


}
int main(){

    string s = "abcba";


    bool Palindrome = checkPalindrome(s, 0, s.length()-1);
    if(Palindrome){
    cout<<"YES"<<endl;
    }
    else
      cout<<"NO"<<endl;
}