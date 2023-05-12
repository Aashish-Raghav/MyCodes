//Dijktras algorithm
#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adjList;
    for (auto i : vec){
        int u = i[0];
        int v = i[1];
        int weight = i[2];

        adjList[u].push_back({v,weight});
        adjList[v].push_back({u,weight});
    }

    //creation of distance array with infinite value initially
    vector<int> dist(vertices,INT_MAX);
    //creation of set basis(distance,node)
    set<pair<int,int>> s;
    s.insert({0,source});

    //initialize set with distance adn source node
    dist[source] = 0;

    while (!s.empty()){
        //fetch top record
        pair<int,int> top = *(s.begin());
        int nodeDist = top.first;
        int topNode = top.second;
        //remove top from set
        s.erase(top);
         
        //traverse all neighbours
        for (auto i : adjList[topNode]){
            if (dist[i.first] > nodeDist + i.second){

                //why this portion
                //_________________________________________
                pair<int,int> record = {dist[i.first],topNode};               
                //if record present erase it;
                if (s.find(record) != s.end()){
                    s.erase(record);
                }
                //_________________________________________


                dist[i.first] = nodeDist + i.second;
                // cout << ans[i.first] << " ";
                s.insert({dist[i.first],i.first});
            }
        }
    }
    return dist;
}
