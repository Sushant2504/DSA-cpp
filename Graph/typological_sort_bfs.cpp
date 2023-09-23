#include <bits/stdc++.h> 
using namespace std;

//Kahn's Algorithm
//there is a directed acyclic graph is needed for topological sort

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    
    //create an adjlist
    for(int i=0; i<e; i++){
          int u = edges[i][0];
          int v = edges[i][1];

          adj[u].push_back(v);
    }

    //find all the indegrees of all nodes
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
             indegree[j]++;
        }
    }

    //push all 0 indegree elements into a queue
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //do bfs
    vector<int> ans;

    while(!q.empty()){
        int front = q.front();
        q.pop();


        //store the ans
        ans.push_back(front);

        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }

    return ans;
}