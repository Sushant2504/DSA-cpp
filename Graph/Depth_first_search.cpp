#include<bits/stdc++.h>
using namespace std;


void AdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adj, int e){
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
}


void Dfs(vector<int> &temp, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, int node){
    

    temp.push_back(node);
    visited[node] = 1;

    //recursive call for next iterations
    for(auto i:adj[node]){
        if(!visited[i]){
            Dfs(temp, visited, adj, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adj;
    AdjList(edges, adj, E);
    
    //for all nodes call DFS if not visited previously
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> temp;
            Dfs(temp, visited, adj, i);
            ans.push_back(temp);
            temp.clear();
        }
        
    }


    return ans;

}