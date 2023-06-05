// C++ program to find maximum sum from a subset of
// Nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree Node structure */
struct Node {
	int data;
	struct Node *left, *right;
};

/* Utility function to create a new Binary Tree Node */
struct Node* newNode(int data)
{
	struct Node* temp = new struct Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

pair<int,int> solve(Node* root){
    if (root == NULL)
        return {0,0};
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> ans;
    //include curr Node;
    ans.first = root->data + left.second + right.second;
    //exclude curr Node
    ans.second = max(left.first,left.second) + max(right.first,right.second);
    cout << ans.first << " " << ans.second << endl;
    return ans;
    
}

int maxSum(Node* root){
    pair<int,int> p = solve(root);
    return max(p.first,p.second);
}

// Driver code
int main()
{
	Node* root = newNode(1);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);
    root->right = newNode(2);
    root->right->left = newNode(4);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->right = newNode(6);
	cout << maxSum(root) << endl;
	return 0;
}
