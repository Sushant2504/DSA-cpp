#include<bits/stdc++.h>
using namespace std;


// bool CheckCycleDfs(unordered_map<int, bool>& visited, unordered_map<int, bool>& DFSvisited, unordered_map<int, list<int>>& adj, int node){
      

//        visited[node] = 1;
//        DFSvisited[node] = 1;

//        for(auto i:adj[node]){
//          if(!visited[i]){ // to check for cycle is there or not
//             bool Cyclefound = CheckCycleDfs(visited, DFSvisited, adj, i);
//             if(Cyclefound) return true;
//          }
//          else if(DFSvisited[i]){
//            // visited true && DFSvisited is also true
//            return true;
               
//          }
//        }

//       DFSvisited[node] = 0;
//       return false;
// }

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
     
     unordered_map<int, list<int>> adj;
    
    //create an adjlist
    for(int i=0; i<edges.size(); i++){
          int u = edges[i].first;
          int v = edges[i].second;

          adj[u].push_back(n);
    }

    //find all the indegees of all nodes
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
             indegree[j]++;
        }
    }

    //push all 0 indegree elements into a queue
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //do bfs
    int cnt = 1;

    while(!q.empty()){
        int front = q.front();
        q.pop();


        cnt++;
        
        for(auto i:adj[front]){
            indegree[i]--;
            //if the indegree of element is 0 then push it in the queue
            if(indegree[i] == 0){
                q.push(i);
               
            }
        }
    }

    
   if(cnt == n){
     return false;
   } else {
     return true;
   }
}