#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};


int height(Node* root){
        if (root == NULL)
            return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        return max(h1,h2) + 1;
}

int main(){
    
    return 0;
}