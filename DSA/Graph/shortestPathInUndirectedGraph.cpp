#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>> adjList;
	for (auto i : edges){
		int u = i.first;
		int v = i.second;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	
	unordered_map<int,int> parent;
	unordered_map<int,bool> visited;
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	while (!q.empty()){
		int value = q.front();
		q.pop();
		for (auto i : adjList[value]){
			if (!visited[i]){
				q.push(i);
				visited[i] = true;
				parent[i] = value;
			} 
		}
	}

	vector<int> ans;
	int pos = t;
	ans.push_back(pos);
	while (pos != s){
		pos = parent[pos];
		ans.push_back(pos);

	}
	reverse(ans.begin(),ans.end());
	return ans;
	
}
