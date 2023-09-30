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
	vector<int> v(n);
    set<int> set;
	ff(i, n){
		cin>>v[i];

	}

    ff(i, n){
        set.insert(v[i]);
    }

    if(set.size() % 2 != 0){
        cout<<-1<<endl;
        return;
    }

	int c = n/2;
	int d = n - c;
    vector<int> a;
    vector<int> b;

    sort(v.begin(), v.end());

    ff(i, d){
        a.push_back(v[i]);
    }

    ff(d, n){
        b.push_back(v[d]);
    }

    sort(b.begin(), b.end(), greater<int>());

    int c=0, x = d; 

    while(c < x && d < n){
        cout<<a[c]<<" ";
        c++;
        cout<<b[d];
        d++;
    }cout<<endl;


}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}