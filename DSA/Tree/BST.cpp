//Binary search Tree
#include <iostream>
#include <queue>
using namespace std;

class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

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
    friend bool searchInBST(Node *root, int x);
    friend Node* minVal(Node* root);
    friend Node* maxVal(Node* root);
    friend void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);
    friend Node* deleteFromBST(Node* root,int key);  

    friend void inorder(Node *root,vector<int> &v);
    friend bool validateBST1(Node*root);
    friend bool solveValidateBST(Node *root,int min,int max);
    friend bool validateBST2(Node*root);

    friend int solveKthSmallest(Node* root,int k,int &i);
    friend int kthSmallest(Node* root, int k);
    friend void solvekthLargest1(Node* root,int k,int &i,int &ans);
    friend int solvekthLargest2(Node* root,int k,int &i);
    friend int kthLargest(Node *root, int k);

    friend Node* inorderToBST(vector<int> v,int s,int e);
    friend Node* balancedBst(Node* root);

    friend Node* solvePreorderToBST(vector<int> &preorder,int mini,int maxi,int &i);
    friend Node* preorderToBST(vector<int> &preorder);

    friend Node* mergeBST1(Node *root1, Node *root2);

//mergeBST2;  (efficient);
    friend void BSTtoSortedDLL(Node* root,Node* &head);
    friend Node* mergeSortedDLL(Node* &l1,Node* &l2);
    friend int lengthDLL(Node* &head);
    friend Node* sortedDLLtoBST(Node* &head, int n);
    friend Node *mergeBST(Node *root1, Node *root2);

    friend info solveLargestBST(Node* root,int &ans);
    friend int largestBST(Node* root);
};



int main(){
    cout << "Enter element to insert in Tree : ";
    Node* root = NULL;
    root = createBST(root);
    // cout << "root->data : " <<  root->data << " ";
    cout << "Printing binary tree : " << endl;
    levelOrderTraversal(root);
    // minVal(root);
    int data;
    cout << "Element to delete : ";
    cin >> data;
    deleteFromBST(root,data);
    levelOrderTraversal(root);
    
}

bool searchInBST(Node *root, int x) {
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;



    if (x < root->data)
        return searchInBST(root->left,x);
    
    else
        return searchInBST(root->right,x);
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
        if (temp != NULL){
            cout << temp->data << " ";
            if (temp->left){
                q.push(temp->left);
            }
        
            if (temp->right){
                q.push(temp->right);
            }
        }
        else{
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
    }

}

Node* minVal(Node* root){
    if (root == NULL)
        return root;
    Node* temp = root;
    while (temp->left){
        temp = temp->left;
    }
    // cout << temp->data << endl;
    return temp;
}
Node* maxVal(Node* root){
    if (root == NULL)
        return root;
    Node* temp = root;
    while (temp->right){
        temp = temp->right;
    }
    cout << temp->data << endl;
    return temp;
}


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (root == NULL){
        return;
    }
    
    if (root->data == key){
        Node* temp = NULL;
        if (root->left != NULL){
            temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }
            
            
        if (root->right){
            temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }
    
    if (root->data > key){
        suc = root;
        findPreSuc(root->left,pre,suc,key);
    }
    else{
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    }
    
    return;

}


Node* deleteFromBST(Node* root,int key){
    if (root == NULL){
        return NULL;
    }

    if (root->data == key){

        // 0 child
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        
        //left child
        if (root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child;
        if (root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return root->right;
        }
        // 2 child;
        if (root->left != NULL && root->right != NULL){
            Node* temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;
            root->data = temp->data;
            root->left = deleteFromBST(root->left,temp->data);
            
        }
    }

    else if (root->data > key){
        root->left = deleteFromBST(root->left,key);
    }
    else{
        root->right = deleteFromBST(root->right,key);
    }
}

void inorder(Node *root,vector<int> &v){
    if (root == NULL)
        return;
    
    //left call;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

bool validateBST1(Node*root) {
    if (root == NULL)
        return true;
    vector<int> v;
    inorder(root,v);

    for (int i = 0;i < v.size()-1;i++){
        if (v[i] > v[i+1])
            return false;
    }
    return true;
}

bool solveValidateBST(Node *root,int min,int max){
    
    if (root == NULL)
        return true;
    
    if (root->data <= max && root->data >= min){
        bool left = solveValidateBST(root->left,min,root->data);
        bool right = solveValidateBST(root->right,root->data,max);
        // cout << "HEERE" << endl;
        return left && right;
    }
    return false;
}

bool validateBST2(Node *root) {
    return solveValidateBST(root,INT32_MIN,INT32_MAX);
}

int solveKthSmallest(Node* root,int k,int &i){
    if (root == NULL)
        return -1;

    int left = solveKthSmallest(root->left, k, i);
    if (left != -1)
        return left;
    i++;
    if (i == k)
        return root->data;
    
    return solveKthSmallest(root->right, k, i);
}

int kthSmallest(Node* root, int k) {
    int i = 0;
    return solveKthSmallest(root,k,i);
}

int solvekthLargest2(Node* root,int k,int &i){
    if (root == NULL)
        return -1;
    
    int right = solvekthLargest2(root->right,k,i);
    if (right != -1)
        return right;
    i++;
    if (i == k){
        return root->data;
    }
    return solvekthLargest2(root->left,k,i);
}

void solvekthLargest1(Node* root,int k,int &i,int &ans){
    if (root == NULL || i >= k)
        return;
    
    solvekthLargest1(root->right,k,i,ans);
    i++;
    if (i == k){
        ans = root->data;
        return;
    }
    solvekthLargest1(root->left,k,i,ans);
}

int kthLargest(Node *root, int k)
{
    int i = 0;
    return solvekthLargest2(root,k,i);
}

Node* inorderToBST(vector<int> v,int s,int e){
    if (s > e)
        return NULL;
    int mid = (s+e)/2;
    Node* temp = new Node(v[mid]);
    temp->left = inorderToBST(v, s, mid-1);
    temp->right = inorderToBST(v, mid+1, e);

    return temp;
}

Node* balancedBst(Node* root) {
    vector<int> v;
    inorder(root, v);
    Node* Node = inorderToBST(v,0,v.size()-1);
    return Node;
}

Node* solvePreorderToBST(vector<int> &preorder,int mini,int maxi,int &i){
    if (i >= preorder.size())
        return NULL;
    if (preorder[i] > maxi || preorder[i] < mini)
        return NULL;
    
    Node* temp = new Node(preorder[i++]);
    temp->left = solvePreorderToBST(preorder,mini,preorder[i-1],i);
    temp->right = solvePreorderToBST(preorder,preorder[i-1],maxi,i);

    return temp;
}

Node* preorderToBST(vector<int> &preorder) {
    int mini = INT32_MIN;
    int maxi = INT32_MAX;
    int i = 0;
    return solvePreorderToBST(preorder,mini,maxi,i);
}

Node* mergeBST1(Node *root1, Node *root2){
    vector<int> v1;
    vector<int> v2;
    //inorder from BST
    inorder(root1,v1);
    inorder(root2,v2);

    //merge sorted arrays
    vector<int> v3;
    int i = 0,j = 0;
    while (i < v1.size() && j < v2.size()){
        if (v1[i] < v2[j])
            v3.push_back(v1[i++]);
        else
            v3.push_back(v2[j++]);
    }

    while (i < v1.size())
        v3.push_back(v1[i++]);
    
    while (j < v2.size())
        v3.push_back(v2[j++]);
    
    //inorder to bst;
    return inorderToBST(v3,0,v3.size()-1);
}

void BSTtoSortedDLL(Node* root,Node* &head){
    //base case;
    if (root == NULL)
        return;
    
    BSTtoSortedDLL(root->right,head);
    root->right = head;
    if (head != NULL)
        head->left = root;

    head = root;
    BSTtoSortedDLL(root->left,head);
}

Node* mergeSortedDLL(Node* &l1,Node* &l2){
    
    Node* head = NULL;
    Node* tail = NULL;
    while (l1 != NULL && l2 != NULL){
        if (l1->data < l2->data){
            if (head == NULL){
                head = l1;
                tail = head;
                // cout << l1->data << " ";
                l1 = l1->right;
            }
            else{
                tail->right = l1;
                l1->left = tail;
                tail = l1;
                // cout << l1->data << " ";
                l1 = l1->right;
            }
        }
        else{
            if (head == NULL){
                head = l2;
                tail = head;
                // cout << l2->data << " ";
                l2 = l2->right;
            }
            else{
                tail->right = l2;
                l2->left = tail;
                tail = l2;
                // cout << l2->data << " ";
                l2 = l2->right;
            }
        }
    }

    while (l1 != NULL){
        tail->right = l1;
        l1->left = tail;
        tail = l1;
        l1 = l1->right;
    }

    while (l2 != NULL){
        tail->right = l2;
        l2->left = tail;
        tail = l2;
        l2 = l2->right;
    }
    
    return head;
}

int lengthDLL(Node* &head){
    int count = 0;
    Node* temp = head;
    while (temp != NULL){
        temp = temp->right;
        count++;
    }
    return count;
}

Node* sortedDLLtoBST(Node* &head, int n){
    //base case;
    if (n <= 0 || head == NULL)
        return NULL;
    
    Node* left = sortedDLLtoBST(head,n/2);
    Node* root = head;
    root->left = left;

    head = head->right;
    root->right = sortedDLLtoBST(head,n-n/2-1);

    return root;
}

Node *mergeBST(Node *root1, Node *root2) {
    Node* head1 = NULL;
    Node* head2 = NULL;

    BSTtoSortedDLL(root1,head1);
    BSTtoSortedDLL(root2,head2);

    head1->left = NULL;
    head2->left = NULL;

    
    Node* head3 = mergeSortedDLL(head1,head2);
    // while (head3 != NULL){
    //     cout << head3->data << " ";
    //     head3 = head3->right;
    // }
    // cout << endl;
    int n = lengthDLL(head3);
    // cout << n << endl;
    return sortedDLLtoBST(head3,n);
}

info solveLargestBST(Node* root,int &ans){
    //base case;
    if (root == NULL){
        return {INT32_MIN,INT32_MAX,true,0};
    }

    info left = solveLargestBST(root->left,ans);
    info right = solveLargestBST(root->right,ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);
    
    if (left.isBST && right.isBST && (left.maxi < root->data && root->data < right.mini))
        currNode.isBST = true;
    else
        currNode.isBST = false;

    if (currNode.isBST){
        ans = max(ans,currNode.size);
    }
    return currNode;
    
}

int largestBST(Node* root) 
{
    int maxSize = 0;
    solveLargestBST(root,maxSize);
    return maxSize;
}