#include <bits/stdc++.h>
using namespace std;

//finding of the articulation point using tarjan's algorithm

void dfs(int node, int parent, unordered_map<int, bool>& vis, vector<int>& disc, vector<int>& low, vector<int>& ap, unordered_map<int, list<int>>& adj, int timer){

    vis[node] = 1;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(int nbr:adj[node]){
         if(node == parent) continue;

         if(!vis[nbr]){// if neighhbour is already not visited
            //call for the next node
            dfs(nbr, node, vis, disc, low, ap, adj, timer);
            low[node] = min(low[node], low[nbr]);
            //check for  AP or not
            if(low[nbr] >= disc[node] && parent != -1){
                ap[node] = true;
            }
            child++;
         }
         else{
            //case of the back edge
            //update its low of node
            low[node] = min(low[node], disc[nbr]);
         }
    }

    if(parent == -1 && child > 1){// starting node case
        ap[node] = 1;
    }
}


int main(){
    int n = 5;
    int e = 5;

    //list of edges
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(1, 2));

    //create adj list
    unordered_map<int, list<int>> adj;

    for(int i=0; i<e; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        //for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    //we need 3 data structure as Discovery time, Lowest Time, visited 
    //2 varibles timer and the parent

    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    int timer = 0;
    vector<int> ap(n,0);
    //intialise at start with -1
    for(int i=0; i<n; i++){
        disc[i] = -1;
        low[i] = -1;
    }

    for(int i=0; i<n; i++){
        //call for dfs  if not visited
        if(!vis[i]){
            dfs(i, -1, vis, disc, low, ap, adj, timer);
        }
    }

    //printitng the aps....
    cout<<"The required articulation points are follows: "<<endl;
    for(int i=0; i<n; i++){
        if(ap[i] != 0){
            cout<<i<<" ";
        }
    }cout<<endl;
 
}