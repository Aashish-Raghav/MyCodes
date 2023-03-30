#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // cout << "s.top() = " << s.top() << endl;
    int n = s.size();
    while (n > 0)
    {
        cout << "s.top() = " << s.top() << endl;
        s.pop();
        n--;
    }
    cout << boolalpha;
    cout << s.empty() << endl;
    

}