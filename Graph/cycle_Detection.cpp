#include<bits/stdc++.h>
using namespace std;

//this is code for cycle detection in undirected graph
//using BFS traversal
bool isCyclicBFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    unordered_map<int, int> parent;

    parent[node] = -1;
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adj[front]){
            if(visited[i] == true && i != parent[front]){
               return true;
            }else if(!visited[i]){
                q.push(i);
                visited[i] = 1;
                parent[i] = front;
            }
        }
    }

    return false;

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
            bool ans = isCyclicBFS(i, visited, adj);
            if(ans) return "Yes";
        }
    }
     

    return "No"; 
}
