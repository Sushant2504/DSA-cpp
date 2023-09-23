#include <bits/stdc++.h>
using namespace std;
//for finding out minimum spanning tree
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

//to make the starting state
  void makeSet(vector<int> &parent, vector<int>& rank, int n){
     for(int i=0; i<n; i++){
       parent[i] = i;// make parent of each node to itself
       rank[i] = 0;// make rank of the each node to equal to 0
     }
  }

  //to find out parent of the each node recursively
  int findParent(vector<int>& parent, int node){// path comprension functionality....
         if(parent[node] == node){
           return node;
         }

         return parent[node] = findParent(parent, parent[node]);
  }

  void UnionSet(int u, int v, vector<int>& parent, vector<int>& rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){ // whichever component you making a parent increment its rank
       parent[u] = v;
       rank[v]++;
    }
    else if(rank[v] < rank[u]){
      parent[v] = u;
      rank[u]++;
    }else{
      //if the rank of the two componenets are equal
      parent[u] = v;

    }
  }


int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(), edges.end(), cmp);

  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n);

  int minweight = 0;
  
  for(int i=0; i<edges.size(); i++){
     int u = findParent(parent, edges[i][0]);//first node
     int v = findParent(parent, edges[i][1]);//neighbour node
     int w = edges[i][2];//weight betn two nodes

    if(u != v){// if the parent of the two nodes are differsnt means they are in different component so add th weight in minweight
       minweight += w;
       UnionSet(u, v, parent, rank);
    }
  }
   return minweight;
}