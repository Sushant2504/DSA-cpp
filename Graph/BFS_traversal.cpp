#include<bits/stdc++.h>
using namespace std;


void Bfs(vector<vector<int>> adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
      queue<int> store;
      store.push(node);
      visited[node] = 1;

      while(!store.empty()){
          int front = store.front();
          store.pop();
          //store this front value in the answer;
          ans.push_back(front);


          //traverse the all neghouring nodes of the frontnode
          for(auto i:adj[front]){
              
              if(!visited[i]){
                  store.push(i);
                  visited[i] = 1;
              }
          }

      }

}


vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    unordered_map<int, bool> visited;

    // this question is particuraly for the all connected nodes in the graph

    Bfs(adj, visited, ans, 0);

    

    return ans;

}