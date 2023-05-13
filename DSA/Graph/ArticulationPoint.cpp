#include <bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,int &timer,vector<int> &disc,vector<int> &low,
        vector<bool> &ap,vector<bool> &vis,unordered_map<int,list<int>> &adj){
    
    vis[node] = true;
    disc[node] = low[node] = timer++;
    
    int child = 0;
    for (auto nbr : adj[node]){
        if (nbr == parent){
            continue;
        }
        else if (!vis[nbr]){
            dfs(nbr,node,timer,disc,low,ap,vis,adj);
            low[node] = min(low[node],low[nbr]);

            //check ap
            if (low[nbr]>= disc[node] && parent != -1)
                ap[node] = true;
            child++;
        }
        else{
            //back edge
            low[node] = min(low[node],disc[nbr]);
        }
    }
    if (parent == -1 && child > 0){
        ap[node] = 1;
    }
}

int main(){
    int n = 5,e = 5;
    vector<pair<int,int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,3});
    edges.push_back({0,2});
    edges.push_back({2,1});
    edges.push_back({3,4});
    

    unordered_map<int,list<int>> adj;
    for (auto i : edges){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    vector<int> dis(n,-1), low(n,-1);
    vector<bool> ap(n,0), vis(n,0);
    int parent = -1,timer = 0;

    for (int i = 0;i < n;i++){
        if (!vis[i]){
            dfs(i,parent,timer,dis,low,ap,vis,adj);
        }
    }


    for (int i = 0;i < n;i++){
        if (ap[i] == 1)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}