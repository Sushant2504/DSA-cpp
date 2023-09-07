#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> v;

    v.push_back(9);
    v.push_back(5);
    v.push_back(7);
    v.push_back(3);
    v.push_back(2);


    cout<<"Finding 6-> "<<binary_search(v.begin(),v.end(),7)<<endl;;
    cout<<"lower bound "<<lower_bound(v.begin(), v.end(),7)-v.begin()<<endl;
    cout<<"upper bound "<<upper_bound(v.begin(), v.end(), 7)-v.begin()<<endl;

    int a =8;
    int b = 10;

    cout<<"The maximum value is "<<max(a, b)<<endl;

    cout<<"The minimum value is "<<min(a, b)<<endl;

    string abcd = "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"String-->  "<<abcd<<endl;

    rotate(v.begin(), v.begin()+1, v.end());

    cout<<"after the rotate "<<endl;
    for(int i:v){

        cout<<i<<" ";
    }cout<<endl;

    sort(v.begin(),v.end());

    for(int i:v){

        cout<<i<<" ";
    }cout<<endl;

}
