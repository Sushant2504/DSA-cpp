#include <bits/stdc++.h> 
using namespace std;

void Typo_sort(unordered_map<int, list<int>> &adj, int &node, vector<bool> &visited, stack<int>& store){

    visited[node] = 1;

    for(auto i:adj[node]){
        if(!visited[i]){
            Typo_sort(adj, i, visited, store);
            
        }
    }
   
    // at the time of the return call we have to store the nodes for typological order
    //imp step
    store.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    vector<bool> visited(v);
    vector<int> ans;
    stack<int> store;

    for(int i=0; i<e; i++){
          int u = edges[i][0];
          int v = edges[i][1];

          adj[u].push_back(v);
    }

    for(int i=0; i<v; i++){
        if(!visited[i]){
            Typo_sort(adj, i, visited, store);
        }
    }

    while(!store.empty()){
        ans.push_back(store.top());
        store.pop();
    }

    return ans;
}