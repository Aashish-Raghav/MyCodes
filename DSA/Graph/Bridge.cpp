#include <bits/stdc++.h>
//Tarjan's Algo...................................................
using namespace std;
void dfs(int node,int parent,vector<int> &disc,vector<int> &low
    ,int &timer,unordered_map<int,list<int>> &adjList,
        unordered_map<int,bool> &vis,vector<vector<int>> &result){

    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adjList[node]){
        if (nbr == parent)
            continue;
        else if (!vis[nbr]){
            dfs(nbr,node,disc,low,timer,adjList,vis,result);
            low[node] = min(low[node],low[nbr]);
            //check if it is bridge;
            if (low[nbr] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            //node already visited and not a parent;
            //back edge condition;
            low[node] = min(low[node],disc[nbr]);
        }
    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adjList;
    for (auto &i : edges){
        int u = i[0];
        int v = i[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int,bool> vis;

    for (int i = 0;i < v;i++){
        disc[i] = low[i] = -1;
    }
    vector<vector<int>> result;
    for(int i = 0;i < v;i++){
        if (!vis[i]){
            dfs(i,parent,disc,low,timer,adjList,vis,result);
        }
    }

    return result;

}