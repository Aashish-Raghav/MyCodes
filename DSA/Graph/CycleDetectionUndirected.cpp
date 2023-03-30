#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
bool bfsDetect(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,
        unordered_map<int,int>& parent,int start){
    
    queue<int> q;
    visited[start] = true;
    q.push(start);
    parent[start] = -1;

    while (!q.empty()){
        int front = q.front();
        q.pop();

        for (auto i : adjList[front]){
            //conditon of cycle to present
            if (visited[i] == true && i != parent[front])
                return true;
            else if (visited[i] == false){
                visited[i] = true;
                q.push(i);
                parent[i] = front;
            }
        }
    }

    return false;
    
}

bool dfsDetect(unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited,
        int node,int parent){
    visited[node] = true;

    for (auto i : adjList[node]){
        if (!visited[i]){
            bool isCycle =  dfsDetect(adjList,visited,i,node);
            if (isCycle)
                return true;
        }
        else if (i != parent){
            //cycle present
            return true;
        }

    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //create adjacency list;
    unordered_map<int,list<int>> adjList;
    for (auto i : edges){
        int u = i[0];
        int v = i[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    for (int i = 1;i <= n;i++){
        if (!visited[i]){
            bool ans = bfsDetect(adjList,visited,parent,i);
            if (ans)
                return "Yes";
        }
    }

    return "No";
}
