#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
     //create an adjancy list
     unordered_map<int, list<pair<int, int>>> adj;

     void addEdge(int u, int v, int w){
         //for the directed graph

         adj[u].push_back(make_pair(v, w));

     }

     void printadjList(){
       //to print the adjacenancy list
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<"("<<j.first<<" ,"<<j.second<<" ),";
            }cout<<endl;
        }
     }

    void dfs(int node, unordered_map<int, bool>& visited, stack<int>& s){

    //mark visited for current node
    visited[node] = 1;

    for(auto i:adj[node]){
        if(!visited[i.first]){
           dfs(i.first, visited, s);
        }
    }

    s.push(node);//at time of return to store topological sort in reverse order.

  }

  void shortestpath(int src, vector<int>& dist, stack<int>& s){
     //intialise dist of src == 0
    dist[src] = 0;

    while(!s.empty()){
        int top = s.top();
        s.pop();

        if(dist[top] != INT_MAX){
            for(auto i:adj[top]){
                if((dist[top] + i.second) < dist[i.first]){ // if the new distance of the node is less than previous dist then update it
                    dist[i.first] =  dist[top] + i.second;
                }
            }
        }

    }
  }
};

// void dfs(int node, unordered_map<int, bool>& visited, stack<int>& s, unordered_map<int, list<pair<int, int>>>& adj){

//     //mark visited for current node
//     visited[node] = 1;

//     for(auto i:adj[node]){
//         if(!visited[i.first]){
//            dfs(i.first, visited, s, adj);
//         }
//     }

//     s.push(node);//at time of return to store topological sort in reverse order.

// }


int main(){
    
    Graph g;
    unordered_map<int, list<pair<int, int>>> p;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    // p = g.adj;

    g.printadjList();

    int n = 6;
    unordered_map<int, bool> visited(n);
    stack<int> s; //stack to store the topological sort order
    //create a topological sort function
    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    } 

    
    vector<int> dist(n);//create distance ds to keep track of the dis of node from src node

    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
    }

    g.shortestpath(1, dist, s);

   

   cout<<"The answer is: ";
   for(int i=0; i<dist.size(); i++){
       cout<<dist[i]<<" "; //printing the dist of all nodes from source node
   }cout<<endl;

}