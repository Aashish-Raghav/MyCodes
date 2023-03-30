#include <bits/stdc++.h> 
using namespace std;
//using dfs;
void dfs(unordered_map<int,list<int>> &adjList,vector<bool> &visited,
    vector<int> &ans,int node){
    visited[node] = true;

    for(auto i : adjList[node]){
        if (!visited[i]){
            dfs(adjList,visited,ans,i);
        }
    }
    ans.push_back(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adjList;
    for (auto i : edges){
        int u = i[0];
        int v = i[1];
        adjList[u].push_back(v);
    }

    vector<bool> visited(v);
    vector<int> ans;
    for (int i = 0;i < v;i++){
        if (!visited[i]){
            dfs(adjList,visited,ans,i);
        }
    }

    //rather than this can use stack and copy all elements to vector
    reverse(ans.begin(),ans.end());
    return ans;
}




//using BFS
vector<int> topologicalSort2(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adjList;
    
    for (int i = 0;i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
    vector<int> indegree(v,0);
    for (auto i : adjList){
        for (int j : i.second){
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 0;i < v;i++){
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty()){
        int value = q.front();
        q.pop();
        ans.push_back(value);

        for (auto neighbour : adjList[value]){
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return ans;
}