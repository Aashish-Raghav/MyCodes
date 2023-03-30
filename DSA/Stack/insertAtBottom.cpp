#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void printStack(stack<T> s)
{
    cout << "Your Stack : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

template <typename T>
void insertAtBottom(stack<T> &s,T element)
{
    //base case;
    if (s.empty()){
        s.push(element);
        return;
    }
    T temp = s.top();
    s.pop();
    insertAtBottom(s,element);
    s.push(temp);
}

int main()
{
    stack<int> stack;
    stack.push(12);
    stack.push(11);
    stack.push(2);
    stack.push(3);

    printStack(stack);
    insertAtBottom(stack,9);
    printStack(stack);

}