#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,
        vector<int> &temp,int index){
    //store ans;
    temp.push_back(index);

    //mark visited
    visited[index] = true;

    //hr node ke lie if not visited ek recursive call;
    for (auto i : adjList[index]){
        if (visited[i] != true){
            dfs(adjList,visited,temp,i);
        }
    }

}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //prepare adjList;
    unordered_map<int,list<int>> adjList;
    for (auto i : edges){
        int u = i[0];
        int v = i[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    vector<vector<int>> ans;
    //loop for traversing disconnected component of graph
    for (int i = 0; i < V;i++){
      if (visited[i] != true) {
            vector<int> temp;
            dfs(adjList, visited, temp, i);
            ans.push_back(temp);
      }
    }

    return ans;
}