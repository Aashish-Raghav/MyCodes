#include <bits/stdc++.h> 
using namespace std;
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src] = 0;
    //Step 1 : running n-1 times and update distance of every node

    for (int i = 1;i < n;i++){
        

        //traversing through graph;
        for (int j = 0;j < edges.size();j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
                dist[v] = dist[u] + wt;
        }
    }

    // Step 2 : detect for -ve cyle;
    bool flag = 0;
    for (int j = 0; j < edges.size(); j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && (dist[u] + wt < dist[v])){
            flag = 1;
            break;
        }
    }

    if (!flag){
        return dist[dest];
    }
    else
        return -1;
}