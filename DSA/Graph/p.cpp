#include <iostream>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    int adjMatrix[n][m];
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            adjMatrix[i][j] = 0;
        }
    }
    for (int i = 0;i < m;i++){
        int u,v; cin >>u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

}