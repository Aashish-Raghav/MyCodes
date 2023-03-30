#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
public:
    Node(int data) : data(data){
        left = NULL;
        right = NULL;
    }
};

int countNode(Node* tree){
        if (tree == NULL)
            return 0;
        return countNode(tree->left) + countNode(tree->right) + 1;
        
    }
    
    bool isMaxOrder(Node* tree){
        //leaf Node
        if (tree->left == NULL && tree->right == NULL)
            return true;
        //node having only left;
        else if (tree->right == NULL)
            return tree->data > tree->left->data;
        else{
            return (tree->data > tree->left->data && tree->data > tree->right->data)
                && (isMaxOrder(tree->left)) && (isMaxOrder(tree->right));
        }
    }
    bool isCBT(Node* tree,int index,int total){
        if (tree == NULL)
            return true;
        else if (index >= total)
            return false;
        else{
            return isCBT(tree->left,2*index+1,total) && isCBT(tree->right,2*index+2,total);
        }
    }
  
    bool isHeap(Node* tree) {
        int totalNode = countNode(tree);
        // cout << totalNode << endl;
        return isCBT(tree,0,totalNode) && isMaxOrder(tree);
    }

int main(){
    
    //ans : 
    //    isCBT(tree,0,countNode(tree)) && isMaxOrder(tree);
}