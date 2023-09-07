#include<iostream>
#include<stack>
using namespace std;

void reverse(string arr,int n){
      stack<char> rev;
      
     for(int i=0; i<n; i++){
        rev.push(arr[i]);
     }
     
     for(int i=0; i<n; i++){
        arr[i] = rev.top();
        rev.pop();  
     }

     cout<<arr<<endl;

}

int main(){
    
    string str;
    cout<<"Enter the string:"<<endl;
    cin>>str;


    reverse(str, str.length());
}