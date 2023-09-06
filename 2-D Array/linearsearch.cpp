#include <iostream>
using namespace std;

bool isPresent(int arr[][4],int target,int row, int col){

    for(int i=0; i<row; i++){

        for(int j=0; j<col; j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;
}

int main(){

    int arr[3][4];

    for(int i=0; i<3; i++){

        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Enter the element to search:"<<endl;
    int n;
    cin>>n;

    if(isPresent(arr, n, 3, 4)){
        cout<<"The required element is present"<<endl;
    }
    else{
        cout<<"The required element is not present"<<endl;
    }






}