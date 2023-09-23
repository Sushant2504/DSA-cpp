#include <bits/stdc++.h>
using namespace std;

// this algo is used to find out the shortest path of all nodes from the source node
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //create an adjList 
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i=0; i<edges; i++){
         int u = vec[i][0];
         int v = vec[i][1];
         int w = vec[i][2];

         //for the undirected graph

         adj[u].push_back(make_pair(v, w));
         adj[v].push_back(make_pair(u, w));
    }


    vector<int> dist(vertices);
    set<pair<int, int>> s; // create set to store distancenode and nodevalue

    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }

    dist[source] = 0;
    s.insert(make_pair(0, source));

    while(!s.empty()){

        //fetch top elements record in the order

        auto top = *(s.begin());
        int nodeDistance = top.first;
        int node = top.second;
        //remove the top record now
        s.erase(s.begin());


        //traverse on the neighbours

        for(auto i:adj[node]){
            if(nodeDistance + i.second < dist[i.first]){
                //if a pair is present for same node the remove it from stack
                auto record = s.find(make_pair(dist[i.first], i.first));
                // if such record found then erase it
                if(record != s.end()){
                      s.erase(record);
                }

                //update the distance
                dist[i.first] = nodeDistance + i.second;

                //push record in the set
                s.insert(make_pair(dist[i.first], i.first));
            }
        }


    }
    
    return dist;

}
