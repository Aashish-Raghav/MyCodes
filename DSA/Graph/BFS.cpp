#include <bits/stdc++.h> 
using namespace std;
void prepareAdjacencyList(vector<pair<int, int>> &edges,unordered_map<int,set<int>> &adjList){
    for (auto i : edges){
        int u = i.first;
        int v = i.second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    while (!q.empty()){
        int frontNode = q.front();
        visited[frontNode] = true;
        ans.push_back(frontNode);
        q.pop();
        
        for (auto i : adjList[frontNode]){
            if (visited[i] != true){
                q.push(i);
                visited[i] = true;
            }
        }

    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    //we have adjacency list;
    prepareAdjacencyList(edges,adjList);

    vector<int> ans;
    unordered_map<int,bool> visited;

    //since it is disconnected graph using loop;
    for (int i = 0;i < vertex;i++){
        if (visited[i] == 0){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;

}