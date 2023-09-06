#include <iostream>
#include <limits.h>
using namespace std;

void rowSum(int arr[][4],int row, int col){
    cout<<"Printing the sum of the rows respectively:"<<endl;
    for(int i=0; i<row; i++){
        int sum = 0;
        for(int j=0; j<col; j++){
            sum += arr[i][j];
        }
        cout<<"The sum of the "<<i<<" is "<<sum<<endl;
    }

}

int LarrowSum(int arr[][4], int row, int col){
    int maxi = INT_MIN;
    int rowindex = -1;

    for(int i=0; i<row; i++){
        int sum = 0;
        for(int j=0; j<col; j++){
            sum += arr[i][j];
        }

        if(sum > maxi){
            maxi = sum;
            rowindex = i;
        }
    }

    cout<<"The maximun rowsum is:"<<maxi<<endl;
    return rowindex;


   

}

int main(){

    int arr[3][4];
    cout<<"Enter the elements of the array:"<<endl;

    for(int i=0; i<3; i++){

        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }
    
    rowSum(arr, 3, 4);
    cout<<LarrowSum(arr, 3, 4)<<endl;

    return 0;
}