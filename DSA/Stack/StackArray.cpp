//impletation of stack using array;
#include <iostream>
#include <vector>
using namespace std;

class Stack{
private:
    int* v;
    int top_;
    const int max_size;
public:
    Stack(int size) :top_(-1),max_size(size) {v = new int[size];}
    ~Stack() 
    {
        delete [] v;
    }
    inline bool empty() const{    
        return (top_ == -1)? true : false;
    }

    inline bool full() const{
        return (top_ == max_size-1)? true : false;
    }

    void push(int element)
    {
        if (!this->full())
             v[++top_] = element;
        else
            cout << "Stack overflow\n";
    }
    
    

    void pop()
    {
        if (this->empty())
            cout << "Stack underflow\n";
        else
            top_--;
        
    }

    int top() const
    {
        if (this->empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return v[top_];
    }
    int size() const
    {
        return top_+1;
    }
};

int main()
{
    Stack stack(30);
    cout << "top empty stack : " << stack.top() << endl;
    stack.push(12);
    stack.push(13);
    stack.push(14);
    cout <<"top : " <<  stack.top() << endl;
    cout << "size " << stack.size() << endl;
    cout.setf(ios_base::boolalpha);
    cout << stack.empty() << endl;
    stack.pop();
    cout << stack.top() << endl;
    cout << stack.size() << endl;
    stack.pop();
    stack.pop();
    cout << stack.empty() << endl;
    cout << stack.size() << endl;
    stack.pop();
    cout << "reached" << endl;
}