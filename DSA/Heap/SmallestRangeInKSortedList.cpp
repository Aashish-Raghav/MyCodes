#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class node{
public:
    int data;
    int i;
    int j;
    node(int data, int row, int col) : data(data), i(row), j(col) {}
};

class compare{
public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &v, int k, int n) {
    priority_queue<node*,vector<node*>,compare > pq;
    //create a min Heap of node;
    int mini = INT_MAX,maxi = INT_MIN;
    for (int i = 0;i < k;i++){
        mini = min(mini,v[i][0]);
        maxi = max(maxi,v[i][0]);
        pq.push(new node(v[i][0],i,0));
    }

    //create start and end
    int start = mini;
    int end = maxi;

    //traverse all other ranges;
    while (!pq.empty()){
        node* temp = pq.top();
        pq.pop();
        //update range;
        if (maxi - temp->data < end - start){
            end = maxi;
            start = temp->data;
        }

        //next element exist;
        if (temp->j < n - 1){
            temp->j++;
            maxi = max(maxi,v[temp->i][temp->j]);
            pq.push(new node(v[temp->i][temp->j],temp->i,temp->j));
        }
        else    
            break;
    }

    return end - start + 1;
}