#include<bits/stdc++.h>
using namespace std;

//the code for cycle detection in graph using DFS

bool iscyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    visited[node] = 1;

    for(auto i:adj[node]){
        if(!visited[i]){
            bool cycledetected = iscyclicDFS(i, node, visited, adj);
            if(cycledetected) return true;
        }else if(i != parent){
             return true;
             //cycle is present is detected
        }
    }
}

void AdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adj, int m){
    
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //create an adjency List
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    AdjList(edges, adj, m);

    //to handlle the disconnected component
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = iscyclicDFS(i, -1, visited, adj);
            if(ans) return "Yes";
        }
    }
     

    return "No"; 
}