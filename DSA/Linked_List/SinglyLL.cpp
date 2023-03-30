//singly linked list;
//either through class or Structure;
//here done using structure;
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};

int lengthLL(Node* &Node1);

void printLL(Node* &Node1);

void insertAtHead(Node* &head,int val);
void insertAtTail(Node* &tail,int val);
void insertAtPosition(Node* &Node1,int val,int position);

void deleteAtHead(Node* &Node1);
void deleteAtPosition(Node* &Node1,int position);

Node* reverseLL1(Node* &Node1);  //algo 1 (better)
Node* reverseLL2(Node* &Node1);  //algo 2 

Node* MiddleOfLL1(Node* Node1);  //algo 1
Node* MiddleOfLL2(Node* Node1);  //algo 2 better

Node* kReverseLL(Node* Node1,int k);

bool isCircularLL(Node* &Node1); //basic

bool detectLoop1(Node* Node1); //algo 1 (advanced and efficient);
bool detectLoop2(Node* Node1); //algo 2 (floyd cycle detection);   (better)

Node* beginOfLoop(Node* Node1); //algo   (floyd cycle detection);

Node* removeLoop(Node* Node1); //algo   (floyd cycle detection);

//remove duplicate from sorted linked list
Node* removeDuplicateSLL(Node* Node1);

//remove duplicate from unsorted linked list
Node* removeDuplicateULL1(Node* Node1); //algo 1;  
Node* removeDuplicateULL2(Node* Node1); //algo 2; (Map)

//sort 0s,1s,2s;
Node* sort012(Node * Node1);    //algo 1  (replacement of value)
Node* sort012_(Node* Node1);    //algo 1  (without)     
void insertSort012_(Node* &Tail,Node* Node);

//merge sorted LL;
Node* mergeSLL1(Node* Node1,Node* Node2);
void swap(Node* &Node1,Node* &Node2);   //we need Node1->data < Node2->data so used swap if Not;
Node* mergeSLL2(Node* left ,Node* right);

bool isPallidrome1(Node* Node1);    //algo 1   (using fast and slow ptr)
bool isPallidrome2(Node* Node1);    //algo 2    (array);

/*
Node* sum2Num(Node* Node1,Node* Node2);
int LLtoInt(Node* Node1);
int power(int,int);
*/

void insertofAdd(Node* &head,Node* &tail,int value);
Node* add(Node* first,Node* second);
Node* add2List(Node* Node1,Node* Node2);

//sort unsorted Linked List,(MERGE SORT);
Node* mergeSort(Node* head);


int main()
{

    Node* Node1 = new Node;
    Node1->data = 1;
    Node1->next = NULL;
    Node* tail1 = Node1;

    Node* Node2 = new Node;
    Node2 = NULL;
    // Node2->data = 2;
    // Node2->next = NULL;
    // Node* tail2 = Node2;
    insertAtTail(tail1,5);
    insertAtTail(tail1,8);
    insertAtTail(tail1,6);
    insertAtTail(tail1,0);
    
    printLL(Node1);
    Node1 = kReverseLL(Node1,2);
    printLL(Node1);
    // insertAtTail(tail2,9);
    // insertAtTail(tail,1);
    // insertAtTail(tail,2);
    // insertAtTail(tail,1);
    // insertAtTail(tail,1);
    // insertAtTail(tail,0);
    // insertAtTail(tail,1);

    // insertAtTail(tail,0);
    // printLL(Node1);

    // Node1 = sort012_(Node1);
    // printLL(Node1);

    // printLL(Node1);
    // printLL(Node2);


    // Node* mergeNode = mergeSLL(Node2,Node1);
    // printLL(mergeNode);
    // printLL(Node1);
    // printLL(Node2);
    // cout.setf(ios_base::boolalpha);
    // cout << isPallidrome1(Node1);

    // printLL(Node1);
    // Node1 = mergeSort(Node1);
    // printLL(Node1);
}

int lengthLL(Node* &Node1)
{
    int count = 0;
    Node* temp = Node1;
    while (temp !=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void printLL(Node* &Node1)
{
    if (Node1 == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    using std::cout;
    using std::endl;
    cout << "Your data in linked list :\n";
    cout << Node1->data << " ";
    Node* temp = Node1->next;    //created a ptr to Node;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;      //updated next to next node till NULL;
    }
    cout << endl;
}

void insertAtHead(Node* &head,int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &Node1,int val,int position)
{
    int length = lengthLL(Node1);
    if (position < 0 || position > length)
    {
        std::cout << "position out of range\n";
        return;
    }

    Node* temp = new Node;
    temp->data = val;
    if (position == 1)
    {
        insertAtHead(Node1,val);
        return;
    }
    int k = 1;
    Node* p,*q;
    p = Node1;
    while (p != NULL && k < position)
    {
        k++;
        q = p;
        p = p->next;
    }
    q->next = temp;
    temp->next = p;
}

void deleteAtHead(Node* &Node1)
{
    Node* temp = Node1;
    Node1 = Node1->next;
    delete temp;
}

void deleteAtPosition(Node* &Node1,int position)
{
    int length = lengthLL(Node1);
    if (position < 0 || position > length)
    {
        std::cout << "\nposition out of range for deletion.\n";
        return;
    }

    if (position == 1)
    {
        deleteAtHead(Node1);
        return;
    }

    int k = 1;
    Node *p,*q;
    p = Node1;
    while (p!= NULL && k < position)
    {
        k++;
        q=p;
        p = p->next;
    }
    q->next = p->next;
    delete p;
}

Node* reverseLL1(Node* &head)
{
    //base case
    if (head == NULL || head->next == NULL)
        return head;
    
    Node* chotaHead = reverseLL1(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
}

Node* reverseLL2(Node* &Node1)
{
    //base case;
    if (Node1 == NULL || Node1->next == NULL)
        return Node1;
    
    Node* curr = Node1;
    Node* prev = NULL;
    Node* forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* MiddleOfLL1(Node* Node1)
{
    // base case 
    if (Node1 == NULL || Node1->next == NULL)
        return Node1;

    int length = lengthLL(Node1);
    int middle = length / 2;
    Node* temp = Node1;
    while (middle--)
        temp = temp->next;
    return temp;
}

Node* MiddleOfLL2(Node* Node1)
{
    //base cases;
    if (Node1 == NULL || Node1->next == NULL)
        return Node1;

    Node* prev = Node1;
    Node* forw = Node1->next;

    while (forw != NULL && forw->next != NULL)
    {
        prev = prev->next;
        forw = forw->next;
        if (forw != NULL)
            forw = forw->next;
    }
    return prev;
}

Node* kReverseLL(Node* Node1,int k)
{
    if (Node1 == NULL) 
        return NULL;

    //one group reverse algorithm;
    Node* curr = Node1;
    Node* prev = NULL;
    Node* forward = NULL;
    int ct = 0;
    while (curr != NULL && ct < k)
    {
       forward = curr->next;
       curr->next = prev;
       prev = curr;
       curr = forward; 
       ct++;
    }

    //baaki recursion dekh lega;
    if (curr!= NULL)
        Node1->next = kReverseLL(curr,k);

    return prev;
}

bool isCircularLL(Node* &Node1)
{
    if (Node1 == NULL)
        return true;

    Node* temp = Node1->next;
    while( temp != NULL && temp != Node1)
        temp = temp->next;
    
    if (temp == NULL)
        return false;
    
    return true;
}

bool detectLoop1(Node* Node1)
{
    if (Node1 == NULL) 
        return 0;   //or False;
    
    std::map<Node*,bool> visited;
    Node* temp = Node1;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            std::cout << "Your Loop start from : " << temp->data << std::endl;    
            return 1;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false; 
}

bool detectLoop2(Node* Node1)
{
    if(Node1 == NULL)
        return NULL;
    
    Node* fast = Node1;
    Node* slow = Node1;
    
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;

        if (slow == fast)
            return true;
    }
    return false;
}

Node* beginOfLoop(Node* Node1)
{
    if (Node1 == NULL)
        return NULL;
    
    Node* slow = Node1;
    Node* fast = Node1;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;

        if (fast == slow)
        {
            slow = Node1;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

Node* removeLoop(Node* Node1)
{
    if (Node1 == NULL)
        return Node1;
    
    Node* begin = beginOfLoop(Node1);
    if (begin == NULL)
        return NULL;

    Node* temp = begin;
    while (temp->next != begin)
    {
        temp = temp-> next;
    }
    temp->next = NULL;
    return Node1;
}

Node* removeDuplicateSLL(Node* Node1)
{
    if (Node1 == NULL)
        return NULL;
    //Logic same;

    //My CODE
    /*
    Node* temp = Node1;
    Node* prev = NULL;
    int data;
    while (temp != NULL)
    {
        data = temp->data;
        prev = temp;
        temp = temp->next;
        while (temp != NULL && temp->data == data) //order impt***
        {
            Node* del = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete del;
        }
    }   
    */

    //Babbar Bhaiya Code;
    Node* curr = Node1;
    while (curr != NULL)
    {
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            Node* del = curr->next;
            curr->next = curr->next->next;
            delete del;
        }
        else
            curr = curr->next;
    }
    return Node1;
}

Node* removeDuplicateULL1(Node* Node1)
{
    Node* curr = Node1;
    while (curr != NULL)
    { 
        Node* temp = curr;
        while (temp->next != NULL)
        {
            if (temp->next->data == curr->data)
            {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else
                temp = temp->next;  
        }
        curr = curr->next;
    }
    return Node1;
}

Node* removeDuplicateULL2(Node* Node1)
{
    std::map<int,bool> visited;
    Node* temp = Node1->next;
    Node* prev = Node1;
    visited[Node1->data] = true;
    while (temp != NULL)
    {
        if (visited[temp->data] == true)
        {
            Node* del = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete del;
        }
        else
        {
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
    return Node1;

}

Node* sort012(Node * Node1)
{
    std::map<int,int> visited;
    if (Node1 == NULL)
        return NULL;
    Node* temp = Node1;
    while (temp != NULL)
    {
        visited[temp->data]++;
        temp = temp->next;
    }
    temp = Node1;
    while (temp != NULL) 
    {
        if (visited[0] != 0)
        {
            temp->data = 0;
            visited[0]--;
        }
        else if (visited[1] != 0)
        {
            temp->data = 1;
            visited[1]--;
        }
        else
        {
            temp->data = 2;
            visited[2]--;
        }
        temp = temp->next;
    }
    return Node1;
}

void insertSort012_(Node* &Tail,Node* Node1)
{
    Tail->next = Node1;
    Tail = Node1;
}

Node* sort012_(Node* Node1)
{
    Node* zeroHead = new Node;
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node;
    Node* oneTail =oneHead;
    Node* twoHead = new Node;
    Node* twoTail = twoHead;
    zeroHead->next = oneHead->next = twoHead->next = NULL;

    Node* temp = Node1;
    //create 3 subLinked List;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            insertSort012_(zeroTail,temp);
        }
        else if(temp->data == 1)
        {
            insertSort012_(oneTail,temp);
        }
        else
        {
            insertSort012_(twoTail,temp);
        }

        temp = temp->next;
    }

    //Merge 3 Linked List;
    if (oneHead->next != NULL)  //one ll is not empty
        zeroTail->next = oneHead->next;
    else    //one ll is empty;
        zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    Node1 = zeroHead->next;

    //delete dummy Nodes;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return Node1;
}

void swap(Node* &Node1,Node* &Node2)
{
    Node* temp = Node1;
    Node1 = Node2;
    Node2 = temp;
}

Node* mergeSLL1(Node* Node1,Node* Node2)
{
    if (Node1 == NULL)
        return Node2;
    if (Node2 == NULL)
        return Node1;

    if (Node2->data < Node1->data)
        swap(Node1,Node2);

    Node* curr = Node1->next;
    Node* prev = Node1;
    Node* temp = Node2;
    Node* forward = Node2->next;
    while (temp != NULL)
    {
        if (curr != NULL)
        {
            if (temp->data >= prev->data && temp->data <= curr->data)
            {
                forward = temp->next;
                prev->next = temp;
                temp->next = curr;
                temp = forward;  
                prev = prev->next;   
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        //if last of first Node reached;
        else
        {
            prev->next = temp;
            temp = NULL;
        }
    }
    return Node1;
}

bool isPallidrome1(Node* Node1)
{
    if (Node1 == NULL || Node1->next == NULL)
        return true;
    Node* temp = MiddleOfLL2(Node1);
    Node* rtemp = reverseLL1(temp);
    // printLL(rtemp);

    Node* curr = Node1;
    // printLL(Node1);
    while (rtemp != NULL)
    {
        if (curr->data != rtemp->data)
            return false;
        rtemp = rtemp->next;
        curr = curr->next;
    }
    return true;
}

bool isPallidrome2(Node* Node1)
{
    if (Node1 == NULL || Node1->next == NULL)
        return true;
    
    Node* temp = Node1;
    vector<int> arr;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    
    for (int i = 0,j = arr.size() - 1;i < j;i++,j--)
    {
        if (arr[i] != arr[j])
            return false;
    }
    return true;

}


/*
int LLtoInt(Node* Node1)
{
    int len = lengthLL(Node1) - 1;
    int sum = 0;
    while (Node1 != NULL)
    {
        sum = (Node1->data)*(power(10,len)) + sum;
        // cout << sum << endl;
        len--;
        Node1 = Node1->next;
    }
    return sum;

}

int power(int x,int y)
{
    int product = 1;
    while (y--)
        product = product * x;
    // cout << product << endl;
    return product;
}

Node* intToLL(int sum)
{
    Node* head = new Node;
    Node* tail = head;
    
    while (sum)
    {
        Node* temp = new Node;
        temp->data = sum % 10;
        tail->next = temp
    }
}

Node* sum2Num(Node* Node1,Node* Node2)
{
    int sum = LLtoInt(Node1) + LLtoInt(Node2);
    return intToLL(sum);
}
*/

void insertofAdd(Node* &head,Node* &tail,int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node* add(Node* first,Node* second)
{
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;
    while (first != NULL || second != NULL || carry != 0)
    {
        int v1 = 0,v2 = 0;
        if (first != NULL)
            v1 = first->data;
        if (second != NULL)
            v2 = second->data;
        
        int digit = carry + v1 + v2;
        // printLL(ansHead);
        insertofAdd(ansHead,ansTail,digit%10);
        carry = digit/10;
        if (first != NULL)
            first = first ->next;
        if (second != NULL)
            second = second->next;
    }

    return ansHead;

}

Node* add2List(Node* first,Node* second)
{
    first = reverseLL2(first);
    second = reverseLL2(second);
    
    // printLL(first);
    // printLL(second);
    Node* ans = add(first,second);
    ans = reverseLL2(ans);
    return ans;
}

Node* mergeSLL2(Node* left ,Node* right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node* ans = new Node;
    ans->data = -1;
    ans->next = NULL;

    Node* temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
            // temp->next = NULL;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    if (left != NULL)
        temp->next = left;

    if (right != NULL)
        temp->next = right;

    return ans->next;

}

Node* mergeSort(Node* head)
{
    //base case;
    if (head == NULL || head->next == NULL)
        return head;
    
    //break linked list in two halfs;
    Node* mid = MiddleOfLL2(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // printLL(left);
    // printLL(right);

    //recursive calls to sort both halves;
    left = mergeSort(left);
    right = mergeSort(right);

    //ek case hum solve karle baaki recursion sambhal lega;
    // merging left and right in sorted order;

    Node* result = mergeSLL2(left,right);

    return result;  
}
