#include<bits/stdc++.h>
using namespace std;



// MY IMPLEMENTATION;
void topologicalSort(unordered_map<int,bool> &vis,int node,
	stack<int> &s,unordered_map<int,list<int>> &adjList){
	
	vis[node] = true;

	for (auto nbr : adjList[node]){
		if (!vis[nbr])
			topologicalSort(vis, nbr, s, adjList);
	}
	s.push(node);
}

void dfs(unordered_map<int,bool> &vis,int node,
	unordered_map<int,list<int>> &transpose){
	vis[node] = true;
	for (auto nbr : transpose[node]){
		if (!vis[nbr]){
			dfs(vis, nbr, transpose);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adjList1;
	unordered_map<int,list<int>> transpose;
	for (auto i : edges){
		adjList1[i[0]].push_back(i[1]);
		transpose[i[1]].push_back(i[0]);
	}

	stack<int> s;
	unordered_map<int,bool> vis;
	//Step 1;
	for (int i = 0;i < v;i++)
		if (!vis[i])
			topologicalSort(vis,i,s,adjList1);

	//step 2 transpose.........


	//step 3 dfs call;
	vis.clear();
	int count = 0;
	for (int i = 0;i < v;i++){
		int top = s.top();
		// cout << top << endl;
		s.pop();
		if (!vis[top]){
			dfs(vis,top,transpose);
			count++;
		}
	}

	return count;
}



//Bhaiya implementation


void revDFS(int node, unordered_map<int, list<int>> &transpose,
unordered_map<int, bool> &vis)
{
	vis[node] = true;
	for(auto nbr: transpose[node]){
		if(!vis[nbr]){
			revDFS(nbr, transpose, vis);
		}
	}
}

void DFS(int node, stack<int> &st, unordered_map<int, bool> &vis,
unordered_map<int, list<int>> &adj)
{
	vis[node] = 1;
	for(auto nbr: adj[node]){
		if(!vis[nbr]){
			DFS(nbr, st, vis, adj);
		}
	}
	st.push(node);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int, list<int>> adj;
	for(int i=0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	//Topological Sort
	stack<int> st;
	unordered_map<int, bool> vis;
	for(int i=0; i<v; i++){
		if(!vis[i]){
			DFS(i, st, vis, adj);
		}
	}

	//Transpose graph
	unordered_map<int, list<int>> transpose;
	for(int i=0; i<v; i++){
		vis[i] = 0;
		for(auto nbr: adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	int cnt =0;
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!vis[top]){
			cnt++;
			revDFS(top, transpose, vis);
		}
	}
	return cnt;
}