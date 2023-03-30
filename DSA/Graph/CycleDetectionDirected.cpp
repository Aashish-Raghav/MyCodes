#include <bits/stdc++.h>
using namespace std;
bool dfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited
    ,unordered_map<int,bool> &dfsVisited,int node){

  visited[node] = true;
  dfsVisited[node] = true;
  for (auto i : adjList[node]){
    if (!visited[i]){
      bool isCycle = dfs(adjList,visited,dfsVisited,i);
      if (isCycle)
        return true;
    }
    else if (dfsVisited[i] == true)
      return true;
  }

  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adjList;
  for (auto p : edges){
    adjList[p.first].push_back(p.second);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsVisited;
  for (int i = 1;i <= n;i++){
      if (!visited[i]){
        bool ans = dfs(adjList,visited,dfsVisited,i);
        if (ans)
          return true;
      }
  }
  return false;
}