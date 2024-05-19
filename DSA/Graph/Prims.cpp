
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <set>
#include <string>
#include <cctype>
#include <numeric>
#include <string>
#include <climits>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adjList;
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    //taken n+1 so that node 1 at 1 index;
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    //initial value mark kardo sabki;
    for (int i = 1;i <= n;i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    //mark the source node;
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i <= n;i++){
        int mini = INT_MAX;
        int u;
        //find min value in key and corresponding node (not visited)
        for (int j = 1;j <= n;j++){
            if (mst[j] == false && key[j] < mini){
                u = j;
                mini = key[j];
            }
        }

        //mark it as visited in mst;
        mst[u] = true;

        //traverse adjacent node;
        for (auto i : adjList[u]){
            int v = i.first;
            int w = i.second;
            if (mst[v] == false && w < key[v]){
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2;i <= n;i++){
        result.push_back({{parent[i],i},key[i]});
    }

    return result;

}
