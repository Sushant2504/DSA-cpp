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
	int n;
	cin>>n;
    deque<int> d;

    if(n <= 3){
    	cout<<-1<<endl;
    	return;
    }

    int j = 0;

    int c = n - (n/2) + 1;

    for(int i=n; i>=c; i--){
       d.push_front(i);
    }

    for(int i=1; i<c; i++){
    	d.push_back(i);
    }

    while(!d.empty()){
    	cout<<d.front()<<" ";
        d.pop_front();
    }cout<<endl;

   

}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}