#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stack;
    stack.push(12);
    stack.push(13);
    stack.push(14);
    cout << stack.top() << endl;
    cout << stack.size() << endl;
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
    return 0;
}