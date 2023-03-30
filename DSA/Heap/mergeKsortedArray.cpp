#include <bits/stdc++.h> 
#include <queue>
#include <vector>

using namespace std;

class Node{
public:
    int data;
    int i;
    int j;
};

class compare{
public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& v, int k){
    priority_queue<Node*,vector<Node*>,compare> pq;
    
    for (int i = 0; i< k;i++){
      Node* temp = new Node();
      temp->data = v[i][0];
      temp->i = i;
      temp->j = 0;
      pq.push(temp);
    }

    vector<int> ans;
    // cout << pq.size() << endl;

    while (pq.size()){
        Node* temp = pq.top();
        ans.push_back(temp->data);
        pq.pop();

        if (temp->j < v[temp->i].size()-1){
            Node* newNode = new Node();
            newNode->j = temp->j+1;
            newNode->i = temp->i;
            newNode->data = v[newNode->i][newNode->j];
            pq.push(newNode);
        }
    }

    return ans;
}
