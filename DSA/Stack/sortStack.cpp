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
void sortPush(stack<T> &s,int element)
{
    //base case
    if (s.empty() || s.top() <= element)
    {
        s.push(element);
        return;
    }
    // cout << "here 1" << endl;
    T temp = s.top();
    s.pop();    
    sortPush(s,element);
    s.push(temp);
}

template <typename T>
void sortStack(stack<T> &s){
    //base case;
    if (s.empty())
        return;
    T temp = s.top();
    s.pop();
    // cout << "Reached 1" << endl;
    sortStack(s);
    // cout << "Reached 2" << endl;
    sortPush(s,temp);
    // cout << "Reached 3" << endl;
}

int main()
{

    stack<int> s;
    s.push(12);
    s.push(14);
    s.push(11);
    s.push(13);
    s.push(9);

    printStack(s);
    sortStack(s);
    printStack(s);
    
    return 0;
}