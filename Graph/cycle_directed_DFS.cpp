#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

bool CheckCycleDfs(unordered_map<int, bool>& visited, unordered_map<int, bool>& DFSvisited, unordered_map<int, list<int>>& adj, int node){
      

       visited[node] = 1;
       DFSvisited[node] = 1;

       for(auto i:adj[node]){
         if(!visited[i]){ // to check for cycle is there or not
            bool Cyclefound = CheckCycleDfs(visited, DFSvisited, adj, i);
            if(Cyclefound) return true;
         }
         else if(DFSvisited[i]){
           // visited true && DFSvisited is also true
           return true;
               
         }
       }
      //backtracking
      DFSvisited[node] = 0;
      return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
     
     unordered_map<int, list<int>> adj;
    //create a adj list
     for(int i=0; i<n; i++){
         int u = edges[i].first;
         int v = edges[i].second;

         adj[u].push_back(v);

     }
     unordered_map<int, bool> visited;
     unordered_map<int, bool> DFSvisited;


     //dfs call for every component may be there a disconnected component
     for(int i=1; i<=n; i++){
          if(!visited[i]){
            bool Cyclefound = CheckCycleDfs(visited, DFSvisited, adj, i);
            if(Cyclefound) return true;
          }
     }


     return false;
}