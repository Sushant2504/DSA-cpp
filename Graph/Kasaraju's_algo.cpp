#include<bits/stdc++.h>
using namespace std;
//to find out no. strongly connected components
void dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj, stack<int>& s){
   
    visited[node] = 1;
    //dfs
	for(auto i:adj[node]){
		if(!visited[i]){
			dfs(i, visited, adj, s);
		}
	}

	s.push(node); // push the value in the stack for every returning call from dfs
}

//to iterate the graph in reverse order
void Revdfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj){
   
    visited[node] = 1;
    //Revdfs
	for(auto i:adj[node]){
		if(!visited[i]){
			Revdfs(i, visited, adj);
		}
	}

	
}


int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// create an adjancy list
	unordered_map<int, list<int>> adj;

	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		//for the directed graph
		adj[u].push_back(v);
	}
    //step 1) topological sort
	stack<int> s;
	unordered_map<int, bool> visited;
	int count = 0; // to count strongly connected components

	for(int i=0; i<v; i++){
       if(!visited[i]){
		   dfs(i, visited, adj, s);
	   }

	}

	//step 2) create a transpose of the graph
	unordered_map<int, list<int>> transpose;

    for(int i=0; i<v; i++){
		for(auto nbr:adj[i]){
			transpose[nbr].push_back(i);//to transpose a adjancy list
		}
	}
	
	//step 3) to count the strongly connected componenets
    unordered_map<int, bool> vis;//create a seperate visited visited map to track visited nodes of transpose of adj
	//call the dfs in stack elements order
	while(!s.empty()){
		int top = s.top();
		s.pop();

		if(!vis[top]){
			count++;
			Revdfs(top, vis, transpose);
		}
	}

	return count;
}