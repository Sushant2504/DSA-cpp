#include<bits/stdc++.h>
using namespace std;

void printEdges(vector<vector<bool>> ans, int n, int m){
      
      for(int i=0; i<n; i++){
           cout<<i<<" -> ";
        for(int j=0; j<n; j++){
             if(ans[i][j]){
                cout<<j<<",";
             }
        }cout<<endl;
      }
}

int main(){
    int n;
    cout<<"Enter the Number of the nodes: "<<endl;
    cin>>n;
    
    int m;
    cout<<"Enter the Number of the edges: "<<endl;
    cin>>m;

    bool direction;
    cout<<"Enter it undirectional or directional graph: "<<endl;
    cin>>direction;

    vector<vector<bool>> ans(n, vector<bool>(n, false));

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;

        ans[u][v] = true;
        if(direction){
            ans[v][u] = true;
        }

    }
    

    printEdges(ans, n, m);
}