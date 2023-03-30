//Circular Singly Linked List;
// using classes;

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    
    //constructor;
    Node(int d) : data(d) , next(NULL) {}
    ~Node()
    {
        int val = data;
        delete next;
        cout << "Memeory freed from node with value = " << val << endl;
    }
};

void printLL(Node* &tail);

void insert(Node* &tail,int element,int value);
void insertAtTail(Node* &tail,int value);

void delete_(Node* &tail,int value);
void deleteAtTail(Node* &tail); 

bool isCircularLL(Node* &tail);

int main()
{
    Node* tail = NULL;
    // printLL(tail);
    insert(tail,5,12);  //here we get tail as starting point of circular LL
    // printLL(tail);       // we have to add 12 after element 5 in list;
    insert(tail,12,105);
    insert(tail,12,125);
    insert(tail,12,130);
    insert(tail,12,155);
    insertAtTail(tail,126);
    printLL(tail);

    if (isCircularLL(tail))
        cout << "Linked List is circular in nature\n";
    
    // printLL(tail);
    // cout << "tail -> data = " << tail->data << endl;
    // insert(tail,126,150);


    // deleteAtTail(tail);
    // printLL(tail);
    // cout << "tail -> data = " << tail->data << endl;
    
    // // printLL(tail);
    // // cout << "tail -> data = " << tail->data << endl;
    // delete_(tail,126);
    // printLL(tail);
    // cout << "tail -> data = " << tail->data << endl;
    // delete_(tail,150);
    // printLL(tail);
    // cout << "tail -> data = " << tail->data << endl;

}

void printLL(Node* &tail)
{
    if (tail == NULL)
    {
        cout << "Empty Linked List!\n";
        return;
    }

    //first element processed;
    Node* temp = tail;
    cout << "Your Linked List:\n";
    cout << temp->data << " ";
    temp = temp->next;

    //remaining element;
    while(temp!= tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert(Node* &tail,int element,int value)
{
    Node* temp= new Node(value);
    //if empty linked list;
    if (tail == NULL)
    {
        tail = temp;
        temp->next = temp;
        return;
    }

    //if non-empty Linked List;
    
    //check if element to be inserted just after tail;
    if (tail->data == element)
    {
        insertAtTail(tail,value);
        return;
    }
    Node* p = tail;
    p = p->next;
    //check if element to be inserted other than just after tail;
    while(p != tail)    
    {
        if (p->data == element) //check if element after which to be added is present or not;
        {
            temp->next = p->next;
            p->next = temp;
            return;
        }
        p = p->next;
    }  
    cout << "Element " << element << " not in LL\n";
    cout << "Insertion Aborted.\n";
    return;
}

void insertAtTail(Node* &tail,int value)
{
    Node* temp = new Node(value);
    temp->next = tail->next;
    tail->next = temp;
    return;
}

void delete_(Node* &tail,int value)
{
    if (tail == NULL)
    {
        cout << "Oops!Empty Linked List\n";
        cout << "Can't delete\n";
        return;
    }
    
    
    if (tail->data == value)
    {
        deleteAtTail(tail);
        return;
    }
    Node*p = tail->next;
    Node*q = tail;
    int flag = 0;
    do
    {
        if (p->data == value)
        {
            flag = 1;
            break;
        }
        q = p;
        p = p->next;
    } while (p != tail);
    if (flag == 0)
    {
        cout << "Element not in Linked List\n";
        cout << "Can't delete\n";
        return;
    }
    q->next = p->next;
    p->next = NULL;
    delete p;
}

void deleteAtTail(Node* &tail)
{
    Node* q = tail;
    while(q->next != tail)
    {
        q = q->next;
    }
    Node* p = tail;
    q->next = p->next;
    tail = q;
    p->next = NULL;
    delete p;
}

bool isCircularLL(Node* &tail)
{
    if (tail == NULL)
        return true;

    Node* temp = tail->next;
    while( temp != NULL && temp != tail)
        temp = temp->next;
    
    if (temp == NULL)
        return false;
    
    return true;
}