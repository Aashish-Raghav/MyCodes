 #include <iostream>
#include <map>
using namespace std;
class Node_
{
public: 
    int data;
    Node_* next;
public:
    void operator+ (Node_* temp)
    {
    }
};  
struct Node
{
    int data;
    struct Node* next;
};
int lengthLL(Node* &head)
{
    int ans = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        ans++;
        temp = temp->next;
    }
    return ans;
}

void printLL(Node* &head)
{
    cout << "Your Linked List : ";
    Node* temp = head;
    while (temp!= NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<< "NULL";
    cout << endl;
}


void insertAtHead(Node* &head,int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int value)
{
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head,int value,int pos)
{
    Node* temp = head;
    int len = lengthLL(head);
    if (pos < 0 || pos > len)
    {
        cout << "Position out of range.\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = value;
    if (pos == 1)
    {
        insertAtHead(head,value);
        return;
    }
    int k = 1;
    while (k < pos)
    {
        temp = temp->next;
        k++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtHead(Node* &head)
{
    if (head == NULL){
        cout << "Empty Linked List." << endl;
        return;
    }
    
    Node* del = head;
    head = head->next;
    delete del;
}

void deleteAtPosition(Node* &head,int pos)
{
    if (pos < 0 || pos > lengthLL(head))
    {
        cout << "Position Out of range.\n" << endl;
        return;
    }
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    Node * temp = head;
    int k = 1;
    while (k++ < pos -1 )
        temp = temp->next;
    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

Node* reverseLL1(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node * forward;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return prev;
}

//reversing through recursion;
Node* reverseLL2(Node* &head)
{
    //base case;
    if (head->next == NULL || head == NULL)
        return head;
    // Node* prev = head;
    Node* temp = reverseLL2(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

Node* middleLL1(Node* head)
{
    Node* temp = head;
    int len = lengthLL(head);
    if (len % 2 != 0)
        len++;
    int k = 1;
    while (k++ < len/2)
        temp = temp->next;
    cout << temp->data << endl;
    return temp;
}

Node* middleLL2(Node* head)
{
    Node* fast = head->next;
    Node* slow = head;
    while (fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

Node* reverseK(Node* head,int k)
{
    //base case;
    if (head == NULL)
        return head;
    Node* curr = head;
    Node* prev = NULL;
    int t = 1;
    //reversed kth group
    while (t++ <= k && curr != NULL)
    {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    //recursive call;
    if (curr != NULL)
        head->next = reverseK(curr,k);

    return prev;
}

void detectLoop1(Node* head)
{
    map<Node*,bool> visited;
    Node* temp = head;
    int flag = 0;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            flag = 1;
            break;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    if (flag == 1)
        cout << "Loop present " << endl;
    else
        cout << "No loop present" << endl;
}

bool detectLoop2(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if (slow == fast){
            cout << "\nLoop present\n" << endl;
            return true;
        }
    }
    cout << "\nNo loop present\n" << endl;
    return false;
}

Node* beginOfLoop(Node* &head)
{
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
    }
    return NULL;
}

Node* removeLoop(Node* &head)
{
    Node* start = beginOfLoop(head);
    Node* temp = start->next;
    while (temp->next != start)
        temp = temp->next;
    
    temp->next = NULL;
    return head;
}

void removeDuplicateSLL(Node* &head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        Node* prev = temp;
        while (temp != NULL && temp->next->data == prev->data )
        {
            Node*del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
        if (temp != NULL)
             temp = temp->next;
    }
}

Node* removeDuplicateULL1(Node* &head)
{
    map<int,bool> visited;
    Node* prev = NULL;
    Node* curr = head;
    // cout << "in" << endl;
    while (curr != NULL)
    {
        if (visited[curr->data] != true)
        {
            // cout << "in1" << endl;
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
        else
        {
            // cout << "in2" << endl;
            Node* del = curr;
            curr = curr->next;
            prev->next = curr;
            delete del;
        }
    }
    return head;
}

Node* removeDuplicateULL2(Node* &head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        Node* prev = temp;
        Node* curr = temp->next;
        while (curr != NULL)
        {
            if (curr->data == temp->data)
            {
                Node* del = curr;
                curr = curr->next;
                prev->next = curr;
                delete del;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        // printLL(head);
        temp = temp->next;
    }
    return head;
}

Node* sort012_1(Node* &head)
{
    map<int,int> count;
    Node* temp = head;
    while (temp != NULL)
    {
        count[temp->data]++;
        temp = temp->next;
    }
    // cout << count[0] << " " << count[1] << " " << count[2] << endl;
    temp = head;
    while (count[0] != 0)
    {
        temp->data = 0;
        count[0]--;
        temp = temp->next;
    }
    // cout << count[0] << endl;
    while (count[1] != 0)
    {
        temp->data = 1;
        count[1]--;
        temp = temp->next;
    }
    // cout << count[1] << endl;

    while (count[2] != 0)
    {
        temp->data = 2;
        count[2]--;
        temp = temp->next;
    }
    // cout << count[2] << endl;
    return head;
}

Node* sort012_2(Node*&head)
{
    //have 1 dummyNode;
    Node* zeroHead = new Node;
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node;
    Node* oneTail = oneHead;
    Node* twoHead = new Node;
    Node* twoTail = twoHead;
    zeroHead->next = oneHead->next = twoHead->next = NULL;
    Node* curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            zeroTail->next = curr;
            zeroTail = curr;
        }
        else if (curr->data == 1)
        {
            oneTail->next = curr;
            oneTail = curr;
        }
        else 
        {
            twoTail->next = curr;
            twoTail = curr;
        }
        curr = curr->next;
    }
    //merging Node;
    if (oneHead->next != NULL)
        zeroTail->next = oneHead->next;
    else
        zeroTail->next = twoHead->next;
    
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    return zeroHead->next;

}

// bool isPallidrome(Node* head)
// {
//     int length = lengthLL(head);
//     if (length == 1)
//         return true;
//     Node* mid = middleLL2(head);
//     Node* rtemp = reverseLL1(head);

//     Node* temp = head;
//     while (prev != NULL)
//     {
//         if (temp->data != prev->data)
//             return false;
//         temp = temp->next;
//         prev = prev->next;
//     }
//     return true;
// }

Node* deleteNodeAtRight(Node* head)
{
    Node* tHead = reverseLL1(head);
    Node* temp = tHead;
    // cout << "in" << endl;
    // printLL(tHead);
    int max = temp->data;
    while (temp != NULL && temp->next != NULL)
    {
        if (max > temp->next->data)
        {
            Node*del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
        else{
            max = temp->next->data;
            temp = temp->next;
        }
        // printLL(tHead);
    }
    printLL(tHead);
    return reverseLL1(tHead);
}

Node* seggregate(Node* head)
{
    Node* temp = head;
    Node* oddHead = new Node;
    Node* oddTail = oddHead;
    Node* evenHead = new Node;
    Node* evenTail = evenHead;

    while (temp != NULL)
    {
        if (temp->data %2 == 0)
        {
            evenTail->next = temp;
            evenTail = temp;
        }
        else{
            oddTail->next = temp;
            oddTail = temp;
        }
        temp = temp->next;
    }
    oddTail->next = NULL;
    evenTail->next = oddHead->next;
    return evenHead->next;
}

Node* shiftRight(Node* head,int k)
{
    if (k == 0)
        return head;
    int len = lengthLL(head);
    k = k % len;
    Node* temp = head->next;
    Node* newNodeHead = head;
    Node* newNodeTail = newNodeHead;
    while (k > 1)
    {
        newNodeTail->next = temp;
        newNodeTail = newNodeTail->next;
        temp = temp->next;
        k--;
    }
    newNodeTail->next = NULL;
    Node* ans = temp;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNodeHead;
    return ans;
}

Node* mergeSortedLL1(Node* head1,Node* head2)
{
    Node* ansHead = new Node;
    Node* ansTail = ansHead;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            ansTail->next = head1;
            ansTail = head1;
            head1 = head1->next;
        }
        else
        {
            ansTail->next = head2;
            ansTail = head2;
            head2 = head2->next;
        }
    }

    while (head1 != NULL)
    {
        ansTail->next = head1;
        ansTail = head1;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        ansTail->next = head2;
        ansTail = head2;
        head2 = head2->next;
    }
    return ansHead->next;
}

Node* mergeSort(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    int mid = lengthLL(head)/2;
    Node* temp = head;
    while (mid>1)
    {
        temp = temp->next;
        mid--;
    }
    Node* right = temp->next;
    temp->next = NULL;
    Node* left = head;
    left = mergeSort(left);
    right = mergeSort(right);
    return mergeSortedLL1(left,right);
}

int main()
{
    Node* node1 = new Node;
    cout << sizeof(Node) << endl;
    cout << sizeof(node1->data) << endl;
    cout << sizeof(node1->next) << endl;
    // Node* Node1 = new Node;
    // Node1->data = 1;
    // Node1->next = NULL;
    // Node* head = Node1;
    // Node* tail = Node1;
    // printLL(head);
    // insertAtTail(tail,1);
    // printLL(head);

    // insertAtTail(tail,5);
    // printLL(head);
    // insertAtTail(tail,2);
    // printLL(head);

    // insertAtTail(tail,7);
    // printLL(head);
    // insertAtTail(tail,0);
    // printLL(head);
    // insertAtTail(tail,1);
    // printLL(head);
    // insertAtTail(tail,8);
    // printLL(head);
    // head = mergeSort(head);
    // printLL(head);



    // Node* mid = middleLL2(head);
    // cout << mid->data << endl;
    // insertAtPosition(head,5,3);
    // printLL(head);

    // deleteAtHead(head);
    // printLL(head);
    // deleteAtPosition(head,2);
    // printLL(head);

    // reverseLL1(head);
    // printLL(head);
    // head = reverseLL2(head);
    // printLL(head);
    // head = reverseK(head,2);
    // printLL(head);
    // detectLoop2(head);
    // tail->next = head;
    // cout << tail->data << endl;
    // Node* loop = beginOfLoop(head);
    // cout << loop->data << endl;
    // cout << loop << endl;
    // cout << head << endl;
    // removeLoop(head);
    // printLL(head);

    // printLL(head);
    // cout.setf(ios_base::boolalpha);
    // // cout << isPallidrome(head) << endl;
    // head = shiftRight(head,3);
    // printLL(head);

    // Node* first = new Node;
    // first->data = 9;
    // first->next = NULL;
    // insertAtHead(first,4);
    // insertAtHead(first,3);
    // insertAtHead(first,1);
    // // insertAtHead(first,1);
    // Node* second = new Node;
    // second->data = 10;
    // second->next = NULL;
    // insertAtHead(second,8);
    // insertAtHead(second,6);
    // insertAtHead(second,2);
    // printLL(first);
    // printLL(second);
    // Node* ans = mergeSortedLL1(first,second);
    // printLL(ans);
}
