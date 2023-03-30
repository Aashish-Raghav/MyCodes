//Doubly Linked list;
//either using class or structure;
//here class
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    
    //constructor;
    Node(int d) : data(d) , next(NULL), prev(NULL) {}
    ~Node()
    {
        int val = data;
        delete next;
            // next = NULL;
        cout << "Memory freed with data = " << val << endl;
    }
};

void printLL(Node* &Node1); //here refrence is not necessarry;
int lengthLL(Node* &Node1); //here refrence is not necessary;

void insertAtHead(Node* &head,int data,Node* & tail);
void insertAtTail(Node* &tail,int data,Node* &head);
void insertAtPosition(Node* &head,int data,int position,Node* &tail);

void deleteAtHead(Node* &head);
void deleteAtTail(Node* &tail);
void deleteAtPosition(Node* &head,int position,Node* &tail);

Node* reverseLL1(Node* Node1);
Node* reverseLL2(Node* Node1);

Node* kReverseLL(Node* Node1,int k);


int main()
{
    // Node* Node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,11,tail);
    insertAtHead(head,12,tail);
    insertAtTail(tail,9,head);
    insertAtTail(tail,8,head);
    insertAtPosition(head,25,3,tail);
    insertAtPosition(head,25,1,tail);

    printLL(head);

    head = reverseLL1(head);
    printLL(head);
    head = kReverseLL(head,4);
    printLL(head);

    return 0;
}

void printLL(Node* &Node1)
{
    if (lengthLL(Node1) == 0)
    {
        cout << "Empty Linked List\n";
        return;
    }
    Node* temp = Node1;
    cout << "Your data in linked list :\n";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthLL(Node* &Node1)
{
    int k = 0;
    Node* temp = Node1;
    while(temp != NULL)
    {
        k++;
        temp = temp->next;
    }
    return k;
}

void insertAtHead(Node* &head,int data,Node* & tail)
{
    Node* temp = new Node(data);
    if (head == NULL)
    {
        head = tail = temp;
        
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail,int data,Node* &head)
{
    Node* temp = new Node(data);
    if (tail == NULL)
    {
        head = tail = temp;

        return;
    }
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head,int data,int position,Node* &tail)
{
    int length = lengthLL(head);
    if (position <= 0 || position > length+1)
    {
        cout << "Position out of range\n";
        return;
    }

    if (position == 1)
    {
        insertAtHead(head,data,tail);
        return;
    }

    if (position == length+1)
    {
        insertAtTail(tail,data,head);
        return;
    }
    
    int k =1;
    Node* temp = new Node(data);
    Node *p;
    p = head;
    while(p!= NULL && k < position)
    {
        k++;
        p = p->next;
    }
    p->prev->next = temp;
    temp->prev = p->prev;
    temp->next = p;
    p->prev = temp;
    return;
}

void deleteAtHead(Node* &head)
{
    if (lengthLL(head) == 0)
    {
        cout << "Oops!Empty Linked List\nCan't delete\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    temp ->next = NULL; //impt statement for destructor to work;
    delete temp;
}

void deleteAtTail(Node* &tail)
{
    if (lengthLL(tail) == 0)
    {
        cout << "Oops!Empty Linked List\nCan't delete\n";
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;    //must set to NULL before deleting;
}

void deleteAtPosition(Node* &head,int position,Node* &tail)
{
    int length = lengthLL(head);
    if (position <= 0 || position > length)
    {
        cout << "Position out of range\nCan't delete\n";
        return;
    }
    if (position == 1)
    {
        deleteAtHead(head);
        return;
    }
    if (position == length)
    {
        deleteAtTail(tail);
        return;
    }

    int k = 1;
    Node *p= head;
    while (p != NULL && k < position)
    {
        k++;
        p = p->next;
    } 
    Node* temp = p;
    temp->prev->next = temp->next;
    temp->next->prev = temp-> prev;
    temp->next = temp->prev = NULL; //impt statement for destructor to work properly;
    delete temp;              //must set to NULL before deleting;
    return;
}

Node* reverseLL1(Node* Node1)
{
    if (Node1 == NULL || Node1->next == NULL)
        return Node1;
    
    Node* curr = Node1;
    Node *forw = NULL;
    Node* back = NULL;
    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = back;
        curr->prev = forw;  //only this step new all same;
        back = curr;
        curr = forw;
    }

    return back;
}

Node* reverseLL2(Node* Node1)
{
    if (Node1 == NULL || Node1->next == NULL)
        return Node1;
    
    Node* chotaHead = reverseLL2(Node1->next);
    // Node* forw = head->next;
    Node1->next->next = Node1;
    Node1->prev = chotaHead;
    Node1->next = NULL;

    return chotaHead;
}

Node* kReverseLL(Node* Node1,int k)
{
    if (Node1 == NULL)
        return NULL;
    
    Node* curr = Node1;
    Node* back = NULL;
    Node* forw = NULL;
    int ct = 0;

    //one case solved by us;
    while (curr != NULL && ct < k)
    {

        forw = curr->next;
        curr->next = back;
        curr->prev = forw;
        back = curr;
        curr = forw;
        ct++;
    }

    //baki recursion sambhal lega;
    if (curr != NULL)
    {
        curr->prev = Node1;
        Node1->next = kReverseLL(curr,k);
    }
    return back;
}