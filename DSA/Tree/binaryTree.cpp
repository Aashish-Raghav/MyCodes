#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
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

    friend Node* buildTree(Node*);

    friend void levelOrderTraversal(Node*);
    friend void inOrderTraversal(Node*);
    friend void preOrderTraversal(Node*);
    friend void postOrderTraversal(Node*);

    friend void buildTreeLevelOrder(Node* &);

    friend int countLeafNodes1(Node*);

    friend void inorder(Node*,int &);
    friend int height(Node* root);

    friend int diameter1(Node*);

    friend pair<int,int> diameterFast(Node* root);
    friend int diameter2(Node* root);

    friend vector <int> zigZagTraversal(Node* root);
    

    friend void leftTraverse(Node* root,vector<int> &v);
    friend void leafNode(Node* root,vector<int> &v);
    friend void rightTraverse(Node* root,vector<int> &v);
    friend vector <int> boundaryNode(Node *root);

    friend vector<int> verticalOrder(Node *root);

    friend vector<int> topView(Node *root);
    friend vector<int> bottomView(Node *root);
    friend vector<int> leftView(Node *root);
    friend vector<int> rightView(Node *root);

    friend int sumOfLongRootToLeafPath1(Node *root);

    friend void solve(Node* root,int sum,int &maxSum,int len,int &maxLen);
    friend int sumOfLongRootToLeafPath2(Node *root);

    friend Node* lca(Node* root ,int n1 ,int n2);   // lowest common ancestor

    friend void solveSumk(Node* root,int k,int &count,vector<int> &v);
    friend int sumK(Node *root,int k);

    friend int kthAncestor1(Node *root, int k, int node);

    friend Node* solveKthAncestor(Node* root,int &k,int node);
    friend int kthAncestor2(Node *root, int k, int node);

    friend pair<int,int> solveGetMaxSum(Node* root);
    friend int getMaxSum(Node *root);

    friend int findPosBuildTreeInPre(int in[],int size,int element);
    friend Node* solveBuildTreeInPre(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int size);
    friend Node* buildTreeInorderPreorderTraversal(int in[],int pre[], int n);

    friend void createMap(int in[],unordered_map<int,int> &m,int n);
    friend Node* solveBuildTreeInPost(int in[],int post[],int &index,int inorderStart,int inorderEnd,int n,unordered_map<int,int> &nodeToIndex);
    friend Node* buildTreeInorderPostorderTraversal(int in[], int post[], int n);
    
    friend void MorrisTraversal(Node* root);

    friend void flattenTreeToLinkedList1(Node *root);

};

int main(){
    Node* root = NULL;

    //creating a binary tree;
    // root = buildTree(root);             // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    buildTreeLevelOrder(root);   // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    cout << endl;
    // levelOrderTraversal(root);
    cout << endl << "Inorder Traversal : " << endl;
    inOrderTraversal(root);
    // cout << endl << "PreOrder Traversal : " << endl;
    // preOrderTraversal(root);
    // cout << endl << "PostOrder Traversal : " << endl;
    // postOrderTraversal(root);
    cout << endl;
    cout << "Morris Traversal : " << endl;
    MorrisTraversal(root);


    // cout << "No of Leaf Nodes : " << countLeafNodes1(root) << endl;
    // cout << diameter2(root) << endl;
    // return 0;
}

Node* buildTree(Node* root){
    cout << "Enter the data : ";
    int data;
    cin >> data;
    root = new Node(data);
    if (root->data == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of " << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << root->data << endl;
    root->right = buildTree(root->right);

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

void inOrderTraversal(Node* root){
    if (root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

void postOrderTraversal(Node* root){
    if (root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void buildTreeLevelOrder(Node* &root){
    queue<Node*> q;
    cout << "Enter Data for root : " << endl;
    int data;
    cin >> data;
    if (data == -1)
        return;

    root = new Node(data);
    q.push(root);

    while (!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter Data for left of " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter Data for Right of " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int countLeafNodes1(Node* root){
    if (root == NULL)
        return 0;
    int count = 0;
    inorder(root,count);
    return count;
}

void inorder(Node* root,int &count){
    
    if (root == NULL)
        return;

    inorder(root->left,count);
    if (root->left == NULL && root->right == NULL){
        count++;
    }
    inorder(root->right,count);
}

int height(Node* root){
        if (root == NULL)
            return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        return max(h1,h2) + 1;
}

int diameter1(Node* root){
    if (root == NULL){
        return 0;
    }

    int d1 = diameter1(root->left);
    int d2 = diameter1(root->right);
    int h = height(root->left) + height(root->right) + 1;
    return max(h,max(d1,d2));
}

pair<int,int> diameterFast(Node* root){
        if (root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int d1 = left.first;
        int d2 = right.first;
        int h = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(h,max(d1,d2));
        ans.second = max(left.second,right.second) + 1;
        
        return ans;
    }
    
    int diameter2(Node* root){
        return diameterFast(root).first;   
    }

vector <int> zigZagTraversal(Node* root)
{
    vector<int> result;
    if (root == NULL)
    	return result;
    	    
    queue<Node*> q;
    q.push(root);
    	
    bool leftToRight = 1;
    while (!q.empty()){
	    int size = q.size();
        vector<int> ans(size);
    	    
	    for (int i = 0;i < size;i++){
            Node* temp = q.front();
    	    q.pop();
    	        
    	    int index = leftToRight ? i : size - i -1;
    	    ans[index] = temp->data;
    	        
    	    if (temp->left){
    	        q.push(temp->left);
	        }
            if (temp->right){
    	        q.push(temp->right);
    	    }
	    }
        leftToRight = !leftToRight;
    	for (auto &i: ans){
    	    result.push_back(i);
	    }
    }
	return result;
}
    void leftTraverse(Node* root,vector<int> &v){
        if ((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        v.push_back(root->data);
        if (root->left)
            leftTraverse(root->left,v);
        else
            leftTraverse(root->right,v);
         
    }
    void leafNode(Node* root,vector<int> &v){
        if (root == NULL){
            return;
        }
        if (root->left == NULL && root->right == NULL){
            // cout << "reached" << endl;
            v.push_back(root->data);
            return;
        }
        leafNode(root->left,v);
        leafNode(root->right,v);
    }
    
    void rightTraverse(Node* root,vector<int> &v){
        if ((root == NULL) || (root->left == NULL && root->right == NULL)){
            return;
        }
        if (root->right){
            rightTraverse(root->right,v);
        }
        else
            rightTraverse(root->left,v);
        
        v.push_back(root->data);
    }

    vector <int> boundaryNode(Node *root)
    {
        vector<int> v;
        if (root == NULL){
            return v;
        }
        v.push_back(root->data);
        
        // left Node;
        leftTraverse(root->left,v);
        
        // leaf Node;
        leafNode(root->left,v);
        leafNode(root->right,v);
        
        
        //right Node;
        rightTraverse(root->right,v);

        return v;
    }    

    vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int> > > m;
        queue< pair<Node*,pair<int,int> > > q;
        vector<int> ans;
        
        if (root == NULL){
            return ans;
        }
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while (!q.empty()){
            pair<Node*,pair<int,int> > temp = q.front();
            q.pop();
            
            int horizontalDist = temp.second.first;
            int level = temp.second.first;
            
            m[horizontalDist][level].push_back((temp.first)->data);
            
            if ((temp.first)->left){
                q.push(make_pair((temp.first)->left,make_pair(horizontalDist-1,level+1)));
            }
            if ((temp.first)->right){
                q.push(make_pair((temp.first)->right,make_pair(horizontalDist+1,level+1)));
            }
        }
        for (auto & i : m)
            for (auto & j : i.second)
                for (auto & k : j.second)
                    ans.push_back(k);
        return ans;
        
    }

    vector<int> topView(Node *root)
    {
        map<int,int> m;
        queue<pair<Node*,int> > q;
        vector<int> v;
        vector<int> t;
        
        if (root == NULL)
            return v;
        m[0] = root->data;

        q.push(make_pair(root,0));
        while (!q.empty()){
            pair<Node*,int> frontNode = q.front();
            q.pop();
            
            Node* temp = frontNode.first;
            int hd = frontNode.second;   //horizontal distance;
            if (!m[hd]){
                m[hd] = temp->data;
            }
            if (temp->left)
                q.push(make_pair(temp->left,hd-1));
            if (temp->right)
                q.push(make_pair(temp->right,hd+1));
                
        }
        for (auto i : m){
            v.push_back(i.second);
        }
        return v;
    }

    vector<int> bottomView(Node *root)
    {
        map<int,int> m;
        queue<pair<Node*,int> > q;
        vector<int> v;
        
        if (root == NULL)
            return v;

        q.push(make_pair(root,0));
        while (!q.empty()){
            pair<Node*,int> frontNode = q.front();
            q.pop();
            
            Node* temp = frontNode.first;
            int hd = frontNode.second;   //horizontal distance;
            
            m[hd] = temp->data;
            
            if (temp->left)
                q.push(make_pair(temp->left,hd-1));
            if (temp->right)
                q.push(make_pair(temp->right,hd+1));
                
        }
        for (auto i : m){
            v.push_back(i.second);
        }
        return v;
    }

vector<int> leftView(Node *root)
{
    map<int,int> m;
    queue<pair<Node*,int> > q;
    vector<int> ans;
    if (root == NULL)
        return ans;
    
    q.push(make_pair(root,0));
    while (!q.empty()){
        pair<Node*,int> p = q.front();
        q.pop();
        
        Node* temp = p.first;
        int level = p.second;
        /*
        //Approach 1;
        m[level] = temp->data;
        if (temp->right)
            q.push(make_pair(temp->right,level+1));
        if (temp->left)
            q.push(make_pair(temp->left,level+1));
        */
       //Approach 2;
        if (!m[level])
            m[level] = temp->data;
        if (temp->left)
            q.push(make_pair(temp->left,level + 1));
        if (temp->right)
            q.push(make_pair(temp->right,level + 1));
        
    }
    for (auto i : m)
        ans.push_back(i.second);
    
    return ans;       
       
}

vector<int> rightView(Node *root)
    {
        map<int,int> m;
        queue<pair<Node*,int> > q;
        vector<int> ans;
        
        if (root == NULL)
            return ans;
        
        q.push(make_pair(root,0));
        while (!q.empty()){
            pair<Node*,int> p = q.front();
            q.pop();
            
            Node* temp = p.first;
            int level = p.second;
            //Approach 1;
            m[level] = temp->data;
            if (temp->left)
                q.push(make_pair(temp->left,level+1));
            if (temp->right)
                q.push(make_pair(temp->right,level+1));

            //Approach 2
            /*
            if (!m[level])
                m[level] = temp->data;
            
            if (temp->right)
                q.push(make_pair(temp->right,level+1));
            if (temp->left)
                q.push(make_pair(temp->left,level+1));
            */
        }
        for (auto i : m){
            ans.push_back(i.second);
        }
    }
//My NOOB approach;
int sumOfLongRootToLeafPath1(Node *root) //using level order traversal;
    {
        queue<pair<Node*,pair<int,int> > > q;   //root, level, sum;
        if (root == NULL)
            return 0;
        q.push(make_pair(root,make_pair(1,root->data)));
        int maxLevel = 0;
        int maxSum = 0;
        while (!q.empty()){
            auto frontNode = q.front();
            q.pop();
            Node* temp = frontNode.first;
            int level = frontNode.second.first;
            int sum = frontNode.second.second;
            if (level > maxLevel){
                maxSum = sum;
            }
            if (level == maxLevel){
                maxSum = max(sum,maxSum);
            }
            if (temp->left){
                q.push(make_pair(temp->left,make_pair(level+1,sum+temp->left->data)));
            }
            if (temp->right){
                q.push(make_pair(temp->right,make_pair(level+1,sum+temp->right->data)));
            }
        }
        return maxSum;
        
    }

//Love Bhaiya Pro Approach;
void solve(Node* root,int sum,int &maxSum,int len,int &maxLen){
        //base case;
        if (root == NULL){
            if (len > maxLen){
                maxSum = sum;
                maxLen = len;
            }
            if (len == maxLen){
                maxSum = max(sum,maxSum);
            }
            return;
        }
        sum += root->data;
        solve(root->left,sum,maxSum,len+1,maxLen);
        solve(root->right,sum,maxSum,len+1,maxLen);
    }
    
int sumOfLongRootToLeafPath2(Node *root) //using level order traversal;
    {
        int sum = 0;
        int maxSum = -1;
        int len = 0;
        int maxLen = 0;
        
        solve(root,sum,maxSum,len,maxLen);
        return maxSum;
        
    }


Node* lca(Node* root ,int n1 ,int n2){  //lowest common ancestor
    //base case;
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    
    Node* leftAns = lca(root->left,n1,n2);
    Node* rightAns = lca(root->right,n1,n2);
    
    if (leftAns != NULL && rightAns != NULL)
        return root;
    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    else
        return NULL;
        
}

void solveSumk(Node* root,int k,int &count,vector<int> &v){ //no o paths which has sum = k;
        if (root == NULL)
            return;
        v.push_back(root->data);
        
        solveSumk(root->left,k,count,v);
        solveSumk(root->right,k,count,v);
        
        int size = v.size();
        int sum = 0;
        for (int i = size -1; i>= 0;i--){
            sum += v[i];
            if (sum == k)
                count++;
        }
        v.pop_back();
}

int sumK(Node *root,int k){
        vector<int> path;
        int count = 0;
        if (root == NULL)
            return count;
        solveSumk(root,k,count,path);
        return count;
    }



//SC O(n^2)
//My Noob Approach

int kthAncestor1(Node *root, int k, int node){
    queue<pair<Node*,vector<int> > > q;
    vector<int> v;
    if (root == NULL)
        return 0;
    q.push(make_pair(root,v));
    while (!q.empty()){
        auto frontNode = q.front();
        q.pop();
        Node* temp = frontNode.first;
        v = frontNode.second;
        if (temp-> data == node){
            if (v.size() >= k)
                return v[v.size() - k];
            else
                return -1;
        }
        v.push_back(temp->data);
        if (temp->left)
            q.push(make_pair(temp->left,v));
        if (temp->right)
            q.push(make_pair(temp->right,v));
        return 0;
    }
}


//Bhaiya Pro approach
Node* solveKthAncestor(Node* root,int &k,int node){
    //base case;
    if (root == NULL)
        return NULL;
    if (root->data == node)
        return root;
    
    Node* leftAns = solveKthAncestor(root->left,k,node);
    Node* rightAns = solveKthAncestor(root->right,k,node);
    
    if (leftAns != NULL && rightAns == NULL){
        k--;
        if (k <= 0){
            k = INT16_MAX;
            return root;
        }
        return leftAns;
    }
    
    if (leftAns == NULL && rightAns != NULL){
        k--;
        if (k <= 0){
            k = INT16_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor2(Node *root, int k, int node){
    Node* ans = solveKthAncestor(root,k,node);
    // check ans->data == node because it ensures whether k == 0 hua bhi ya nhi ek bhi baar;
    if (ans == NULL || ans->data == node)       
        return -1;
    else
        return ans->data;
}

pair<int,int> solveGetMaxSum(Node* root){
        if (root == NULL){
            pair<int,int> p = {0,0};
            return p;
        }
        
        pair<int,int> left = solveGetMaxSum(root->left);
        pair<int,int> right = solveGetMaxSum(root->right);
        
        pair<int,int> result;
        result.first = root->data + left.second + right.second;
        result.second = max(left.first,left.second) + max(right.first,right.second);
        
        return result;
    }
    //Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root){
        pair<int,int> ans = solveGetMaxSum(root);
        return max(ans.first,ans.second);
}

int findPosBuildTreeInPre(int in[],int size,int element){
        for (int i = 0;i < size;i++){
            if (in[i] == element){
                //changing because of duplicacy of elements
                in[i] = -1;
                return i;
            }
                
        }
        return -1;
    }
    Node* solveBuildTreeInPre(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int size){
        if (index >= size || inorderStart > inorderEnd){
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        int pos = findPosBuildTreeInPre(in,size,element);
        
        //recursive calls
        root->left = solveBuildTreeInPre(in,pre,index,inorderStart,pos-1,size);
        root->right = solveBuildTreeInPre(in,pre,index,pos+1,inorderEnd,size);
        
        return root;
    }
    Node* buildTreeInorderPreorderTraversal(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        Node* ans = solveBuildTreeInPre(in,pre,preOrderIndex,0,n-1,n);
        return ans;
    }




//other approach using position finding but not efficient;
// int findPos(int in[],int size,int element){
//     for (int i = size-1;i >= 0;i--){
//         if (in[i] == element){
//             // in[i] = -1;
//             return i;
//         }
//     }
// }

void createMap(int in[],unordered_map<int,int> &m,int n){
    for (int i = 0;i < n;i++){
        m[in[i]] = i;
    }
}

Node* solveBuildTreeInPost(int in[],int post[],int &index,int inorderStart,int inorderEnd,int n,unordered_map<int,int> &nodeToIndex){
    //base case 
    if (index < 0 || inorderStart > inorderEnd)
        return NULL;
    
    int element = post[index--];
    Node* root = new Node(element);
    int pos = nodeToIndex[element];
    
    //recursive calls;
    root->right = solveBuildTreeInPost(in,post,index,pos+1,inorderEnd,n,nodeToIndex); 
    root->left = solveBuildTreeInPost(in,post,index,inorderStart,pos-1,n,nodeToIndex);
    
    
    return root;
}

Node* buildTreeInorderPostorderTraversal(int in[], int post[], int n) {
    int index = n-1;
    unordered_map<int,int> nodeToIndex;
    createMap(in,nodeToIndex,n);
    Node* ans = solveBuildTreeInPost(in,post,index,0,n-1,n,nodeToIndex);
    return ans;
}

void MorrisTraversal(Node* root){
    Node* curr = root;
    while (curr != NULL){
        if (curr->left == NULL){
            cout << curr->data << " ";
            curr = curr->right;
        }
        else{
            Node* pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
            
            if (pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

void flattenTreeToLinkedList1(Node *root)
    {
        Node* curr = root;
        while (curr != NULL){
            if (curr->left){
                Node* pred = curr->left;
                while (pred->right){
                    pred = pred->right;
                }
                
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
        
        //making left part NULL;
        // curr = root;
        // while (curr != NULL){
        //     curr->left = NULL;
        //     curr = curr->right;
        // }
    }