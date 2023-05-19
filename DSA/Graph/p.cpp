#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;

int indegree[maxN];
int job[maxN];
unordered_map<int,list<int>> adjList;

void addEdge(int u,int v){
    adjList[u].push_back(v);
    indegree[v]++;
}

void printOrder(int n,int m){
    queue<int> q;
    for (int i = 1;i <= n;i++){
        if (indegree[i] == 0){
            q.push(i);
            job[i] = 1;
        }
    }

    while (!q.empty()){
        int front = q.front();  
        q.pop();
        for (auto i : adjList[front]){
            indegree[i]--;
            if (indegree[i] == 0){
                q.push(i);
                job[i] = job[front]+1;
            }
        }
    }

    for(int i = 1;i <= n;i++){
        cout << job[i] << " ";
    }
    cout << endl;
}

int main(){
    //nodes and edges;
    int n = 10,m = 13;
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);

    printOrder(n,m);
}