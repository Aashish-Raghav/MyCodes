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

int main()
{
    
    return 0;
}