#include <bits/stdc++.h>
using namespace std;

//topological sort using bfs;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
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