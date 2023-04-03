#include <bits/stdc++.h>
using namespace std;
class Graph{
public:
    unordered_map<int,list<pair<int,int>>> adjList;

    void addEdges(int u,int v,int weight){
        adjList[u].push_back({v,weight});
    }


    void printAdjList(){
        for (auto i : adjList){
            cout << i.first << " -> ";
            for (auto j : i.second){
                cout << "(" << j.first << "," << j.second << ")" << " ";
            }
            cout << endl;
        }
    }

    void dfs(unordered_map<int,bool> &visited,stack<int> &s,int node){
        visited[node] = true;

        for (auto i : adjList[node]){
            if (!visited[i.first]){
                dfs(visited,s,i.first);
            }
        }
        s.push(node);
    }

    void shortestPath(int src,stack<int> &s,vector<int> &dist){
        dist[src] = 0;

        while (!s.empty()){
            int top = s.top();
            s.pop();
            if (dist[top] != INT_MAX){
                for (auto i : adjList[top]){
                    if (dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdges(0,1,5);
    g.addEdges(0,2,3);
    g.addEdges(1,2,2);
    g.addEdges(1,3,6);
    g.addEdges(2,3,7);
    g.addEdges(2,4,4);
    g.addEdges(2,5,2);
    g.addEdges(3,4,-1);
    g.addEdges(4,5,-2);

    g.printAdjList();


    //topologial sort;
    int n = 6;  //no of nodes;
    unordered_map<int,bool> visited;
    stack<int> s;
    for (int i = 0;i < n;i++){
        if (!visited[i])
            g.dfs(visited,s,i);
    }

    vector<int> dist(n,INT_MAX);

    g.shortestPath(1,s,dist);

    for (auto i : dist){
        if (i != INT_MAX)
            cout << i << " ";
        else
            cout << "INF" << " ";
    }
    cout << endl;
    
    
    return 0;
}