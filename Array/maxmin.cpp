#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

int min(int arr[], int num){

    int min = INT_MAX;

    for(int j=0; j<num; j++){
        if(arr[j] < min){
            min = arr[j];
        }
    }

    return min;
}

int max(int arr[], int num){

      int max = INT_MIN;
 
    for(int i=0; i<num ; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    
        }

        return max;
    }


int main(){

    int number[5] = {2,45,12,6,16};

    int a = max(number[5], 5);
    int b = min(number[5], 5);

    cout<<"The minimum value of the element is: "<<a<<endl;
    cout<<"The maximum value of the element is: "<<b<<endl;

    return 0;


}