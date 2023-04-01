#include <bits/stdc++.h>
using namespace std;

//using dfs
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



//using BFS
int detectCycleInDirectedGraphUsingBFS(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> adjList;
    for (int i = 0;i < edges.size();i++){
      int u = edges[i].first-1;
      int v = edges[i].second-1;

      adjList[u].push_back(v);
    }

    vector<int> indegree(n,0);
    for (auto i : adjList){
        for (auto j : i.second){
          indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0;i < n;i++)
        if (indegree[i] == 0)
            q.push(i);
            
    int count = 0;
    while (!q.empty()){
        int value = q.front();
        q.pop();

        count++;
        for (auto i : adjList[value]){
            indegree[i]--;
            if (indegree[i] == 0)
              q.push(i);
        }

    }

    if (count == n)
        return false;
    else  
        return true;
}