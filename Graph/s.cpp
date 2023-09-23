#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define ff(i,n) for(int i=0; i<n; i++)
#define ff1(i,n) for(int i=1; i<=n; i++)
#define pb push_back
#define in insert

void solve(){
	 vector<vector<char>> v(10, vector<char>(10));
     int cnt = 0;
     for(int i=0; i<10; i++){
     	for(int j=0; j<10; j++){
     		cin>>v[i][j];
     	}
     }

	 for(int i=0; i<10; i++){
	 
	 	for(int j=0; j<10; j++){
            if(v[i][j] == 'X'){
            	if(i > 3 && i < 6 && j > 3 && j < 6){
            		cnt += 5;
            	}
            	else if(i > 2 && i < 7 && j > 2 && j < 7){
            		cnt+= 4;
            	}
            	else if(i > 1 && i < 8 && j > 1 && j < 8){
            		cnt += 3;
            	}
            	else if(i > 0 && i < 9 && j > 0 && j < 9){
            		cnt += 2;
            	}
            	else{
            		cnt += 1;
            	}
            }
	 	} 
	 }

	 cout<<cnt<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

//map -> for mapping , for counting, 
//set -> to find out unique occurance
//stack -> to reverse, for traversing reverse path, LIFO
//queue -> for countious push pop opeartions and to traverse serial wise order
//priority_queue(heap) -> to find out minimum amd maximum element of data structure
//to find out first k smallest element && find out first k largest numbers
//deque -> to reverse the data structure in certain order
//list -> to list out elements in ordered format