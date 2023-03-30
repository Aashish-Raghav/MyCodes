#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

//adjaceny list from map;
template <typename T>
class Graph{
public:
    unordered_map<T,list<T> > adj;

    void addEdge(T u,T v,bool direction){
        // direction->0 if undirected map;
        //direction-> 1 if directed map;

        adj[u].push_back(v);
        if (direction == false){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for (auto i : adj){
            cout << i.first << "->";
            for (auto j : i.second)
                cout << j << ","; 
            cout << endl;
        }
    }
};


//adjacency list form vector of vectors
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    vector<int> ans[n];
    for (int i = 0; i < m; i++){
        ans[edges[i][0]].push_back(edges[i][1]);
        ans[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> adj(n);
    for (int i = 0;i < n;i++){
        adj[i].push_back(i);
        for (int j = 0;j < ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }

  return adj;
}



int main(){
    Graph<int> g1;
    int n,m;
    cout << "Enter No of Nodes : ";
    cin >> n;
    cout << "Enter No of Edges : ";
    cin >> m;
    for (int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        g1.addEdge(u,v,0);
    }

    g1.printAdjList();
}
