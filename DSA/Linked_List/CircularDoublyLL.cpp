// Circular Doubly Linked List;
//here we are using class;

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) : data(d),next(NULL),prev(NULL) {}
    ~Node()
    {
        int val = data;
        delete next;
        std::cout << "Memory freed with value : " << val;
    }
};

void printLL(Node* &tail) ;


int main()
{

}

void printLL(Node* &tail)
{
    if (tail == NULL)
    {
        cout << "Empty Linked List\n";
        return;
    }
    cout << "Your Linked List :\n";
    Node * temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
}