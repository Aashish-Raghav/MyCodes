#include <bits/stdc++.h>
using namespace std;
#define V 5

void printArr(int arr[],int n){
    for (int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSafe(int path[],bool graph[V][V],int pos,int i){

    //check adjacent;
    if (graph[path[pos-1]][i] == 0)
        return false;
    
    //already visited;
    for (int j = 0;j < pos;j++){
        if (path[j] == i) 
            return false;
    }
    return true;
}

bool hamCycleUtil(bool graph[V][V],int path[],int pos){
    //base case;
    if (pos == V){
        if (graph[path[pos-1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int i = 1;i < V;i++){
        if (isSafe(path,graph,pos,i)){
            path[pos] = i;

            if (hamCycleUtil(graph,path,pos+1) == true)
                return true;

            //back Track;
            path[pos] = -1;
        }
    }

    return false;
}

void hamCycle(bool graph[V][V]){
    int * path = new int[V];
    for (int i = 0;i < V;i++)
        path[i] = -1;

    path[0] = 0;
    if (hamCycleUtil(graph,path,1) == false){
        cout << "No Solution Exist" << endl;

    }
    else{
        printArr(path,V);
    }
}

int main()
{
    /* Let us create the following graph
        (0)--(1)--(2)
        | / \ |
        | / \ |
        | / \ |
        (3)-------(4) */
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
     
    // Print the solution
    hamCycle(graph1);
     
    /* Let us create the following graph
    (0)--(1)--(2)
    | / \ |
    | / \ |
    | / \ |
    (3) (4) */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};
 
    // Print the solution
    hamCycle(graph2);
 
    return 0;
}