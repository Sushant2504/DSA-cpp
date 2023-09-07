#include <iostream>
#include <array>
using namespace std;

int main(){

    array<int, 4> arr = {1,2,3,4};

    int size = arr.size();

    for(int i=0; i<size; i++){
        cout<<arr[i]<<endl;
    }

    cout<<"the element at the second index"<<arr.at(2)<<endl;
    cout<<"the array is empty or not"<<arr.empty()<<endl;

    cout<<"the first element is"<<arr.front()<<endl;
    cout<<"the last element is"<<arr.back()<<endl;

    return 0;
}