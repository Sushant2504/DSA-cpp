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
	 int n, x;
	 cin>>n>>x;// TLE solution

	 vector<int> v(n);

	 ff(i, n){
	 	cin>>v[i];
	 }

	 int maxi = INT_MIN;

     ff(i, n){
        maxi = max(maxi, v[i]);

     }

     bool vis[maxi][maxi];

     

     ll sum = 0; 
     ll sum1 = 0;

     for(int j=1; j<=maxi; j++){
        sum = 0;
         ff(i, n){
            int a = j - v[i];
            if(a >= 0){
                sum += a;
            }
         }

         if(sum == x){
            cout<<j<<endl;
            return ;
         }
         if(sum > x){
            cout<<j-1<<endl;
            return;
         }
         sum1 = sum;
     }
     
      if(sum1 > x){
            cout<<n-1<<endl;
            return;
      }
     


     //not possible
     ll b = x - sum1;
     ll c = b/n;

     ll h = maxi + c;

    //  while(h > 0){
    //  	for(int i=0; i<n; i++){
    //        int a = h - v[i];
    //        if(a >= 0){
    //           sum += a;
    //        }

    //  	}
      
    //     if(sum == x){
    //         cout<<h<<endl;
    //         return;
    //     }
    //  	if(sum > x)  break;
    //     sum = 0;
    //     h++;
    //  } 


     cout<<h<<endl;
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