#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
private:
    int data;
    Node* left;
    Node* right;
public:
    Node(int data) : data(data){
        left = NULL;
        right = NULL;
    }

    friend Node* insertInBST(Node* root,int data);
    friend Node* createBST(Node* root);

    friend void levelOrderTraversal(Node* root);
    friend void inOrderTraversal(Node* root,vector<int> &v);
    friend void preOrderTraversal(Node* root,vector<int> &v,int &i);
};

int main(){
    Node* root = NULL;
    root = createBST(root);
    levelOrderTraversal(root);
    vector<int> v;
    inOrderTraversal(root,v);
    int i = 0;
    preOrderTraversal(root,v,i);
    levelOrderTraversal(root);

    return 0;
}

Node* insertInBST(Node* root,int data){
    if (root == NULL){
        root = new Node(data);
        return root;
    }
    if (data < root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }

    return root;
}

Node* createBST(Node* root){
    int data;
    cin >> data;
    while (data != -1){
        root = insertInBST(root,data);
        cin >> data;
    }
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        Node* temp = q.front();
        q.pop();

        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(Node* root,vector<int> &v){
    if (root == NULL)
        return;
    
    inOrderTraversal(root->left,v);
    v.push_back(root->data);
    inOrderTraversal(root->right,v);
}

void preOrderTraversal(Node* root,vector<int> &v,int &i){
    if (root == NULL)
        return;

    root->data = v[i++];
    preOrderTraversal(root->left,v,i);
    preOrderTraversal(root->right,v,i);
}