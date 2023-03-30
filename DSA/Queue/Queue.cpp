//Queue using linked list; & class
#include <iostream>

typedef unsigned int Item;
class Queue
{
private:
    enum {QSIZE = 10};
    struct Node
    {
        Item item;
        struct Node* next;
    };
    const int qsize;      //Maximum size of queue;
    int nelements;  //no of elements;
    Node* front;
    Node* rear;
public:
    Queue(int qs = QSIZE);
    ~Queue();
    bool isfull() const { return nelements == qsize;}
    bool isempty() const { return nelements == 0;}
    bool enqueue(const Item item);
    bool dequeue(Item &item);
    void display();
    void status() const;
};

Queue::Queue(int qs) : qsize(qs)    // a const member must be initialised this way;
{
    front = rear = 0;
    nelements = 0;
}

Queue::~Queue()
{

}

bool Queue::enqueue(const Item item)
{
    //case 1 full queue;
    if (nelements == qsize)
        return false;
    //case 2 
    Node* temp = new Node;
    temp->item = item;
    temp->next = NULL;
    if (front == NULL)
        front = temp;
    else
        rear->next = temp;
    rear = temp;
    nelements++;
    return true;
}

bool Queue::dequeue(Item &item)
{
    if (nelements == 0)
        return false;
    Node* temp = front;
    front = front->next;
    item = temp->item;
    delete temp;
    nelements--;
    return true;
}

void Queue::display()
{
    Node* temp = front;
    std::cout << "\nYour Queue:\n";
    while(temp != NULL)
    {
        std::cout << temp->item << std::endl;
        temp = temp->next;
    }
    delete temp;
}

void Queue::status() const
{
    using std::cout;using std::endl;
    cout << "\nQueue Size : " << qsize << endl;
    cout << "No of Present elements : " << nelements << endl;
    if (front == NULL)
    {
        cout << "Front : NULL"<< endl;
        cout << "Rear : NULL" << endl;
    }
    else
    {    cout << "Front : " << front->item << endl;
        cout << "Rear : " << rear->item << endl;
    }
}

inline void eatline() { while (std::cin.get() != '\n') continue;}

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Queue qOne;
    cout << "Enter Your Choice(among the following):\n";
    cout << "1: Add element to queue\t2: delete element form queue\n"
         << "3: Queue Status\t4: Display Queue\n"
         << "5: Quit\n";
    char choice;
    Item value;
    while (cin >> choice && choice != '5')
    {
        eatline();
        switch (choice)
        {
            case '1': cout << "Enter Value to add : ";
                      cin >> value;
                      if (qOne.enqueue(value))
                        cout << "\nItem succesfully added\n";
                      else  
                        cout << "\nQueue Overflow!\n";
                      break;
            case '2': if(qOne.dequeue(value))
                        cout << value << " deleted successfully;\n";
                      else
                        cout << "\nQueue Underflow!\n";
                      break;
            case '3': qOne.status();
                      break;
            case '4': if (qOne.isempty())
                        cout << "\nQueue is empty!\n";
                      else 
                        qOne.display();
                      break;
        };
        cout << "1: Add element to queue\t2: delete element form queue\n"
         << "3: Queue Status\t4: Display Queue\n"
         << "5 Quit\n";
    }
    
    return 0;
}