//input n,m; n -> no of nodes; m -> no of edges;
// m input of edges list;

#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int adj[n+1][n+1] = {0};

    //undirected graph
    for (int i = 0; i < m;i++){
        int u,v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for (int i = 0;i <=  n;i++){
        for (int j = 0;j <= n;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}