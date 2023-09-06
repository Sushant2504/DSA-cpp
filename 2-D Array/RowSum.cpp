#include <iostream>
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

int main(){

    int arr[3][4];
    cout<<"Enter the elements of the array:"<<endl;

    for(int i=0; i<3; i++){

        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }
    
    rowSum(arr, 3, 4);
   
}